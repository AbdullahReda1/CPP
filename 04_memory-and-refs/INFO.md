# C++ Memory & References

---

## 1. References (`const T&` and `T&`)

---

## What

A reference is an **alias** — a second name for a variable that already exists.
It is not a copy. It is not a new object. It is the same object under a different name.

```cpp
int velocity = 42;
int & velocity_ref = velocity;   // variable int& 'velocity_ref' is an alias for 'velocity'

velocity_ref = 100;              // modifying through the alias
// velocity is now 100 — same object, same memory address
```

---

## Why

Without references, every function call **copies** its arguments.
For small things like `int`, that is fine.
For large things like sensor point clouds or message buffers, copying wastes time and memory — unacceptable in a real-time robot.

```cpp
// BAD — copies the entire message every call (slow, wastes memory)
void process_scan(sensor_msgs::msg::LaserScan scan) { }

// GOOD — passes a reference, zero copy
void process_scan(const sensor_msgs::msg::LaserScan & scan) { }
```

---

## How

There are two kinds you will see constantly:

### `const T&` — read-only reference (most common)

The function can read the object but cannot modify it.
This is the default way ROS 2 passes messages into callbacks.

```cpp
// parameter const sensor_msgs::msg::LaserScan& 'scan_msg' is a
// read-only alias for the incoming laser message passed by the subscriber
void scan_callback(const sensor_msgs::msg::LaserScan & scan_msg)
{
    float range = scan_msg.ranges[0];   // reading is allowed
    // scan_msg.ranges[0] = 0.0f;       // ERROR — cannot modify a const ref
}
```

### `T&` — mutable reference

The function can both read AND modify the original object.
Used when a function needs to fill or update something in-place.

```cpp
// parameter rcl_interfaces::msg::SetParametersResult& 'result' is a
// mutable alias for the result object being filled by this function
void fill_result(rcl_interfaces::msg::SetParametersResult & result)
{
    result.successful = true;   // modifying the original directly
    result.reason = "ok";
}
```

---

## Memory View

```text
Without reference (copy):

  caller memory          function memory
  ┌──────────────┐       ┌──────────────┐
  │  scan_msg    │  -->  │  scan_copy   │   <-- separate object, RAM used twice
  │  (10 KB)     │       │  (10 KB)     │
  └──────────────┘       └──────────────┘

With const reference (no copy):

  caller memory
  ┌──────────────┐
  │  scan_msg    │   <-- function reads directly from HERE, no copy made
  │  (10 KB)     │
  └──────────────┘
        ↑
   function sees this exact address — zero extra RAM used
```

---

## When in ROS 2

| Situation                               | Type                                       | Example                                        |
| --------------------------------------- | ------------------------------------------ | ---------------------------------------------- |
| Subscriber callback receiving a message | `const MsgType &`                          | `const sensor_msgs::msg::LaserScan & msg`      |
| Parameter callback receiving param list | `const std::vector<rclcpp::Parameter> &`   | post-set callback                              |
| Iterating a vector without copying      | `const T &` in range-for                   | `for (const rclcpp::Parameter & p : params)`   |
| Function filling a struct in-place      | `T &`                                      | `SetParametersResult &`                        |

---

---

## 2. Smart Pointers ⭐⭐⭐

---

## What:-

A smart pointer is a **wrapper object that owns a raw pointer** and automatically
frees the memory when it is no longer needed.

Think of it as a pointer that cleans up after itself.

There are three kinds:

| Type                   | Ownership                 | Use in ROS 2                     |
| ---------------------- | ------------------------- | -------------------------------- |
| `std::shared_ptr<T>`   | shared — multiple owners  | everywhere — the default         |
| `std::unique_ptr<T>`   | exclusive — one owner     | internal helpers, rarely exposed |
| `std::weak_ptr<T>`     | non-owning observer       | breaking circular ownership      |

---

## Why:-

In embedded and robotics code, objects like nodes, publishers, and services
must stay alive for as long as they are needed — but must also be cleaned up
when the node shuts down. Doing this by hand with raw pointers leads to:

- **Memory leaks** — forgot to `delete`, RAM fills up over a long mission
- **Dangling pointers** — pointer used after the object was already deleted (crash)
- **Double-free** — deleting the same object twice (crash)

Smart pointers eliminate all three problems automatically.

---

## How — `std::shared_ptr<T>` (most important)

`shared_ptr` keeps a **reference count** — an internal counter of how many
`shared_ptr` objects currently point to the same thing.
When the count reaches zero, the object is automatically deleted.

```cpp
// create a shared_ptr owning a new Publisher object
// rclcpp::Publisher<std_msgs::msg::String>::SharedPtr 'publisher_' is a
// shared owner of the publisher object, keeping it alive as long as this node lives
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

// inside the constructor:
publisher_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);
//           ^^^ returns a shared_ptr — ref count becomes 1
```

ROS 2 defines a type alias so you don't have to type the full template each time:

```cpp
// these two are identical:
std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr      // <-- ROS2 alias, used everywhere
```

### Creating a shared_ptr manually

```cpp
// std::make_shared is the correct way to create a shared_ptr
// auto 'request' is a shared owner of a new AddTwoInts::Request object
auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
request->a = 2;
request->b = 3;
// when 'request' goes out of scope, the object is deleted automatically
```

### Passing shared_ptr to a function

```cpp
// passing by value — increases the ref count (both caller and callee own it)
void send(std::shared_ptr<MyMsg> msg);

// passing by const ref — does NOT increase ref count (read only, no ownership transfer)
void log(const std::shared_ptr<MyMsg> & msg);
```

In ROS 2 callbacks, messages arrive as `shared_ptr` so they can be kept alive
if you store them, or released automatically if you don't.

---

## Memory View — Reference Counting

```text
After:  auto ptr_a = std::make_shared<LaserScan>();

  Heap memory
  ┌─────────────────────────┐
  │  LaserScan object       │  <-- ref count: 1
  │  ranges: [0.5, 1.2 ...] │
  └─────────────────────────┘
         ↑
       ptr_a

After:  auto ptr_b = ptr_a;   // second owner

  ┌─────────────────────────┐
  │  LaserScan object       │  <-- ref count: 2
  └─────────────────────────┘
         ↑           ↑
       ptr_a       ptr_b

ptr_a goes out of scope:      ref count: 1  (object still alive, ptr_b holds it)
ptr_b goes out of scope:      ref count: 0  --> object DELETED automatically
```

---

## How — `std::unique_ptr<T>`

`unique_ptr` has exclusive ownership — only ONE pointer can own the object at a time.
It cannot be copied, only moved.

```cpp
// std::unique_ptr<rclcpp::Node> 'node_' is the sole owner of this node object
std::unique_ptr<rclcpp::Node> node_ = std::make_unique<rclcpp::Node>("my_node");

// moving ownership to another unique_ptr
std::unique_ptr<rclcpp::Node> other_ = std::move(node_);
// node_ is now null — it no longer owns anything
```

Used in ROS 2 for: executor ownership, internal helper classes, factory patterns.

---

## How — `std::weak_ptr<T>`

`weak_ptr` observes an object owned by a `shared_ptr` **without preventing deletion**.
You must call `.lock()` to get a temporary `shared_ptr` to access it — and check if it succeeded.

```cpp
// std::weak_ptr<rclcpp::Node> 'node_observer_' is a non-owning watcher of the node
std::weak_ptr<rclcpp::Node> node_observer_ = node_shared_ptr_;

// to use it safely:
if (auto node = node_observer_.lock()) {   // lock() returns shared_ptr or nullptr
    RCLCPP_INFO(node->get_logger(), "Node still alive");
} else {
    // node was already deleted — safe, no crash
}
```

Used in ROS 2 for: callback handles that must not keep nodes alive after shutdown.

---

## When in ROS2

| Object                                                               | Smart Pointer Type         | Why                                         |
| -------------------------------------------------------------------- | -------------------------- | ------------------------------------------- |
| `publisher_`, `subscription_`, `srv_`, `client_`, `timer_`           | `SharedPtr`                | owned by the node, shared with ROS2 runtime |
| Incoming message in a callback                                       | `SharedPtr`                | ROS2 passes messages this way               |
| Outgoing service request                                             | `make_shared<Request>()`   | runtime expects a shared_ptr                |
| `on_set_parameters_callback_handle_`                                 | `SharedPtr`                | must be kept alive or callback unregisters  |
| Internal helper object, one owner                                    | `unique_ptr`               | cleaner ownership semantics                 |
| Watching a node without owning it                                    | `weak_ptr`                 | prevents keeping dead nodes alive           |

---

---

## 3. Raw Pointers (`T*` and `nullptr`)

---

## What :-

A raw pointer holds a **memory address** pointing to an object.
It has no ownership — it does not manage the lifetime of what it points to.

```cpp
int velocity = 42;
int * velocity_ptr = &velocity;   // variable int* 'velocity_ptr' holds the address of 'velocity'

*velocity_ptr = 100;              // dereference to access/modify the value
// velocity is now 100
```

---

## Why (they still exist)

Raw pointers appear in ROS 2 code for two reasons:

1. **C interoperability** — ROS 2's underlying C layer (`rcl`, `rmw`) uses raw pointers everywhere.
   The `rmw_request_id_t *` in service callbacks is an example.
2. **Legacy code** — older ROS 1 and early ROS 2 code used raw pointers before smart pointers became standard.

In **new code you write**, prefer smart pointers. Use raw pointers only when
forced to by a C API or a framework you cannot change.

---

## How:-

```cpp
// (void)request_header — casting an unused raw pointer to void
// to intentionally suppress the "unused variable" compiler warning
void handle_service(
    const std::shared_ptr<rmw_request_id_t> request_header,   // raw pointer inside shared_ptr
    const std::shared_ptr<AddTwoInts::Request> request,
    std::shared_ptr<AddTwoInts::Response> response)
{
    (void)request_header;   // "I know this exists, I am ignoring it on purpose"
    response->sum = request->a + request->b;
}
```

### `nullptr` — the safe null value

Always use `nullptr` (not `NULL` or `0`) to represent "no object":

```cpp
rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_ = nullptr;

if (publisher_ != nullptr) {
    publisher_->publish(msg_);
}
```

---

## Memory View:-

```text
Raw pointer — no ownership, no ref counting:

  Stack
  ┌─────────────┐         Heap
  │  ptr  0x4A2 │ ──────> │  object │   <-- ptr just knows the address
  └─────────────┘         └─────────┘
                                ↑
                   Who owns this? Nobody knows.
                   Who deletes this? You have to track it manually.
                   Forgot to delete? Memory leak.
                   Deleted twice? Crash.

Smart pointer — owns the object:

  Stack
  ┌──────────────────────┐     Heap
  │  shared_ptr          │ --> │  object  │  ref count: 1
  │  ptr: 0x4A2          │     └──────────┘
  │  ref_count_ptr: 0x8B │ --> │  count=1 │
  └──────────────────────┘
  Goes out of scope? count→0, object deleted. Automatically. Always.
```

---

## When in ROS2:-

| Situation                                  | Raw Pointer Usage                                      |
| ------------------------------------------ | ------------------------------------------------------ |
| `rmw_request_id_t *` in service callback   | passed in by RCL layer, wrapped in`shared_ptr`         |
| `(void)unused_param`                       | silencing unused C-API parameters                      |
| Iterating C arrays from hardware drivers   | embedded sensor reading loops                          |
| Plugin base class return                   | `pluginlib` loads plugins via raw pointer internally   |

---

---

## 4. RAII — Resource Acquisition Is Initialization

---

## What  :-

RAII is a **design pattern** (not a keyword) that ties a resource's lifetime
to the lifetime of a C++ object:

- **Acquire** the resource in the constructor
- **Release** the resource in the destructor

When the object goes out of scope, its destructor runs automatically — guaranteed.
The resource is always cleaned up, even if an exception is thrown.

---

## Why :-

Robots run for hours or days. A memory leak or unclosed file handle that is
harmless in a 10-second program becomes fatal in a 6-hour autonomous mission.
RAII makes cleanup **impossible to forget** because the language does it for you.

---

## How :-

### Example 1 — smart pointer IS RAII for heap memory

```cpp
{
    // publisher_ptr acquires ownership of the publisher object here (constructor)
    auto publisher_ptr = std::make_shared<rclcpp::Publisher<std_msgs::msg::String>>(...);

    publisher_ptr->publish(msg_);

}   // <-- publisher_ptr destructor runs HERE automatically
    //     ref count drops to 0, publisher object is deleted
    //     no delete needed, no leak possible
```

### Example 2 — RAII mutex lock (critical for multi-threaded nodes)

```cpp
std::mutex data_mutex_;
std::vector<float> shared_ranges_;

void scan_callback(const sensor_msgs::msg::LaserScan & msg)
{
    // std::lock_guard<std::mutex> 'lock' acquires 'data_mutex_' here
    // and releases it automatically when 'lock' goes out of scope
    std::lock_guard<std::mutex> lock(data_mutex_);

    shared_ranges_ = msg.ranges;   // safe — mutex is held

}   // <-- lock destructor runs, mutex released automatically
    //     even if an exception is thrown inside the callback
```

### Example 3 — RAII callback handle (ROS 2 specific)

```cpp
// The callback handle MUST be stored as a member variable.
// If it goes out of scope, its destructor unregisters the callback automatically.

// WRONG — handle dies immediately, callback never fires
{
    auto handle = this->add_on_set_parameters_callback(my_cb);
}   // handle destroyed here, callback unregistered, bug!

// CORRECT — handle stored as member, lives as long as the node
rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr
    on_set_parameters_callback_handle_;   // member variable with trailing _

on_set_parameters_callback_handle_ =
    this->add_on_set_parameters_callback(my_cb);
// now the handle lives as long as the node — callback stays registered
```

---

## Memory View — Scope and Destructor Timing

```cpp
void my_function()
{
    // --> constructor called, resource acquired
    std::lock_guard<std::mutex> lock(mutex_);
    std::shared_ptr<MyMsg> msg = std::make_shared<MyMsg>();

    do_work();   // resources are held safely here

}   // <-- function scope ends
    //     destructors called IN REVERSE ORDER of construction:
    //     1. msg destructor  → ref count 0 → MyMsg deleted
    //     2. lock destructor → mutex released
    //     Automatic. Guaranteed. Even if do_work() threw an exception.
```

---

## When in ROS2 :-

| Resource                            | RAII Mechanism                                           |
| ----------------------------------- | -------------------------------------------------------- |
| Heap-allocated node objects         | `shared_ptr` / `unique_ptr`                              |
| Mutex protecting shared sensor data | `std::lock_guard`                                        |
| Parameter callback registration     | stored`SharedPtr` handle — destructor unregisters        |
| File handles (logging, map saving)  | `std::fstream` — destructor closes the file              |
| Hardware serial/socket connections  | custom RAII wrapper class                                |
| Timer registration                  | `TimerBase::SharedPtr` — destructor cancels the timer    |

---

---

## Quick Concept Map

```text
You want to...                       Use...
─────────────────────────────────────────────────────
Pass a large message without copy    const MsgType & msg
Modify a struct inside a function    MsgType & result
Own a ROS2 publisher/service/timer   SharedPtr  (shared_ptr)
Create a one-time request object     make_shared<Request>()
Own something exclusively            unique_ptr
Watch without owning                 weak_ptr
Interface with C drivers/rcl layer   raw pointer T*
Mark unused C-API param              (void)param_name
Guarantee cleanup on scope exit      RAII — smart pointer or lock_guard
Keep a callback alive                store its handle as a SharedPtr member
```
