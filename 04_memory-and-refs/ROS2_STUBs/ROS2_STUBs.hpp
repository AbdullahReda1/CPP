#include <memory>       // std::shared_ptr, std::unique_ptr, std::weak_ptr, std::make_shared, std::make_unique
#include <vector>       // std::vector
#include <string>       // std::string
#include <mutex>        // std::mutex, std::lock_guard
#include <fstream>      // std::ofstream
#include <functional>   // std::function
#include <chrono>       // std::chrono::milliseconds
#include <cstdint>      // int64_t, uint8_t, size_t
#include <cinttypes>    // PRId64  — portable format macro for int64_t
#include <iostream>     // std::cout
#include <cstdio>       // printf


// ╔══════════════════════════════════════════════════════════╗
// ║  PART A — ROS2 STUB TYPES                                ║
// ║  These replace every #include "rclcpp/rclcpp.hpp" etc.   ║
// ║  Each stub mirrors the real type: same field names,      ║
// ║  same method names, same ::SharedPtr alias.              ║
// ╚══════════════════════════════════════════════════════════╝

// ── stub: rclcpp::Logger ─────────────────────────────────────────────────
namespace rclcpp
{

// defining struct 'Logger' in namespace 'rclcpp'
// mirrors real rclcpp::Logger — the logging interface returned by Node::get_logger()
struct Logger
{
    std::string name_;   // member variable 'name_' of type std::string — the logger/node name shown in log output
};

} // namespace rclcpp

// ── logging macros ───────────────────────────────────────────────────────

// macro 'RCLCPP_INFO' — mirrors real RCLCPP_INFO(logger, fmt, ...)
// routes to printf in this stub; real version routes to rcl logging backend
#define RCLCPP_INFO(logger,  fmt, ...) printf("[INFO][%s] "  fmt "\n", (logger).name_.c_str(), ##__VA_ARGS__)

// macro 'RCLCPP_WARN' — same pattern for warnings
#define RCLCPP_WARN(logger,  fmt, ...) printf("[WARN][%s] "  fmt "\n", (logger).name_.c_str(), ##__VA_ARGS__)

// macro 'RCLCPP_ERROR' — same pattern for errors
#define RCLCPP_ERROR(logger, fmt, ...) printf("[ERROR][%s] " fmt "\n", (logger).name_.c_str(), ##__VA_ARGS__)

// macro 'RCLCPP_DEBUG' — same pattern for debug messages
#define RCLCPP_DEBUG(logger, fmt, ...) printf("[DEBUG][%s] " fmt "\n", (logger).name_.c_str(), ##__VA_ARGS__)

// ── stub: rclcpp::NodeOptions ─────────────────────────────────────────────
namespace rclcpp
{

// defining struct 'NodeOptions' in namespace 'rclcpp'
// mirrors real rclcpp::NodeOptions — configuration struct passed into every node constructor
struct NodeOptions {};

} // namespace rclcpp

// ── stub: rclcpp::ParameterType and rclcpp::Parameter ───────────────────
namespace rclcpp
{

// defining enum class 'ParameterType' in namespace 'rclcpp'
// mirrors real rclcpp::ParameterType — identifies what value type a Parameter holds
enum class ParameterType
{
    PARAMETER_NOT_SET,    // enum value — no type assigned yet
    PARAMETER_BOOL,       // enum value — holds a bool
    PARAMETER_INTEGER,    // enum value — holds an int64_t
    PARAMETER_DOUBLE,     // enum value — holds a double
    PARAMETER_STRING,     // enum value — holds a std::string
    PARAMETER_BYTE_ARRAY, // enum value — holds a byte array
};

// defining class 'Parameter' in namespace 'rclcpp'
// mirrors real rclcpp::Parameter — one named ROS2 parameter with its value and type
class Parameter
{
public:
    // defining constructor for string parameters
    // parameter 'name' of type const std::string& — parameter name in snake_case
    // parameter 'value' of type const std::string& — the string value
    Parameter(const std::string & name, const std::string & value)
    : name_(name), str_value_(value), type_(ParameterType::PARAMETER_STRING) {}

    // defining constructor for double parameters
    Parameter(const std::string & name, double value)
    : name_(name), dbl_value_(value), type_(ParameterType::PARAMETER_DOUBLE) {}

    // defining member function 'get_name' with return type const std::string&
    // mirrors real rclcpp::Parameter::get_name() — returns parameter name string
    const std::string & get_name()  const { return name_; }

    // defining member function 'get_type' with return type rclcpp::ParameterType
    // mirrors real rclcpp::Parameter::get_type() — returns the type enum
    ParameterType       get_type()  const { return type_; }

    // defining member function 'as_string' with return type const std::string&
    // mirrors real rclcpp::Parameter::as_string()
    const std::string & as_string() const { return str_value_; }

    // defining member function 'as_double' with return type double
    // mirrors real rclcpp::Parameter::as_double()
    double              as_double() const { return dbl_value_; }

    // defining member function 'as_int' with return type int64_t
    // mirrors real rclcpp::Parameter::as_int()
    int64_t             as_int()    const { return int_value_; }

    // defining member function 'as_bool' with return type bool
    // mirrors real rclcpp::Parameter::as_bool()
    bool                as_bool()   const { return bool_value_; }

private:
    std::string   name_;         // member variable 'name_' of type std::string
    std::string   str_value_;    // member variable 'str_value_' of type std::string — string storage
    double        dbl_value_{};  // member variable 'dbl_value_' of type double — double storage
    int64_t       int_value_{};  // member variable 'int_value_' of type int64_t — integer storage
    bool          bool_value_{}; // member variable 'bool_value_' of type bool — bool storage
    ParameterType type_;         // member variable 'type_' of type ParameterType — active type tag
};

} // namespace rclcpp

// ── stub: rcl_interfaces::msg::SetParametersResult ──────────────────────
namespace rcl_interfaces { namespace msg {

// defining struct 'SetParametersResult' in namespace 'rcl_interfaces::msg'
// mirrors real rcl_interfaces::msg::SetParametersResult — returned by parameter validation callbacks
struct SetParametersResult
{
    bool        successful{true};  // member variable 'successful' of type bool — true = change accepted
    std::string reason;            // member variable 'reason' of type std::string — rejection message if not successful
};

}} // namespace rcl_interfaces::msg

// ── stub: rcl_service_introspection_state_t ──────────────────────────────

// defining C-style enum 'rcl_service_introspection_state_t' (no namespace — matches real RMW C header)
// mirrors real rcl_service_introspection_state_t — controls how much detail is logged for service calls
enum rcl_service_introspection_state_t
{
    RCL_SERVICE_INTROSPECTION_OFF,       // constant — introspection disabled
    RCL_SERVICE_INTROSPECTION_METADATA,  // constant — log timing and request IDs only
    RCL_SERVICE_INTROSPECTION_CONTENTS,  // constant — log full request and response data
};

// ── stub: rmw_request_id_t ───────────────────────────────────────────────

// defining C-style struct 'rmw_request_id_t' (no namespace — mirrors real RMW C type from rmw/types.h)
// carries metadata about a service request coming from the middleware layer
struct rmw_request_id_t
{
    uint8_t writer_guid[16];  // member array 'writer_guid' of type uint8_t[16] — unique ID of the calling client
    int64_t sequence_number;  // member variable 'sequence_number' of type int64_t — monotonically increasing request counter
};

// ── stub: rclcpp::QoS and rclcpp::SystemDefaultsQoS ─────────────────────
namespace rclcpp
{

// defining struct 'QoS' in namespace 'rclcpp'
// mirrors real rclcpp::QoS — Quality of Service policy (reliability, durability, history depth)
struct QoS
{
    explicit QoS(size_t depth = 10) : depth_(depth) {}  // constructing QoS with history queue depth
    size_t depth_;   // member variable 'depth_' of type size_t — message queue depth
};

// defining struct 'SystemDefaultsQoS' in namespace 'rclcpp' inheriting from 'QoS'
// mirrors real rclcpp::SystemDefaultsQoS — uses RMW middleware default QoS settings
struct SystemDefaultsQoS : public QoS { SystemDefaultsQoS() : QoS(10) {} };

} // namespace rclcpp

// ── stub: rclcpp::TimerBase ───────────────────────────────────────────────
namespace rclcpp
{

// defining struct 'TimerBase' in namespace 'rclcpp'
// mirrors real rclcpp::TimerBase — base class for all ROS2 timer objects
struct TimerBase
{
    // defining type alias 'SharedPtr' as std::shared_ptr<TimerBase>
    // mirrors real rclcpp::TimerBase::SharedPtr — used when declaring timer member variables
    using SharedPtr = std::shared_ptr<TimerBase>;

    virtual ~TimerBase() = default;  // virtual destructor — ensures derived timer types clean up correctly
};

} // namespace rclcpp

// ── stub: rclcpp::node_interfaces callback handles ──────────────────────
namespace rclcpp { namespace node_interfaces {

// defining struct 'OnSetParametersCallbackHandle' in namespace 'rclcpp::node_interfaces'
// mirrors real OnSetParametersCallbackHandle — RAII handle for pre-set parameter validation callbacks
// when this object is destroyed, the callback is automatically unregistered
struct OnSetParametersCallbackHandle
{
    using SharedPtr = std::shared_ptr<OnSetParametersCallbackHandle>;  // type alias 'SharedPtr'
};

// defining struct 'PostSetParametersCallbackHandle' in namespace 'rclcpp::node_interfaces'
// mirrors real PostSetParametersCallbackHandle — RAII handle for post-set parameter effect callbacks
struct PostSetParametersCallbackHandle
{
    using SharedPtr = std::shared_ptr<PostSetParametersCallbackHandle>;  // type alias 'SharedPtr'
};

}} // namespace rclcpp::node_interfaces

// ── stub: sensor_msgs::msg::LaserScan ────────────────────────────────────
namespace sensor_msgs { namespace msg {

// defining struct 'LaserScan' in namespace 'sensor_msgs::msg'
// mirrors real sensor_msgs::msg::LaserScan — one full sweep of a 2D laser rangefinder
struct LaserScan
{
    using SharedPtr = std::shared_ptr<LaserScan>;  // type alias 'SharedPtr' — used in subscription callbacks

    float              angle_min{0.0f};       // member variable 'angle_min' of type float — scan start angle in radians
    float              angle_max{0.0f};       // member variable 'angle_max' of type float — scan end angle in radians
    float              angle_increment{0.0f}; // member variable 'angle_increment' of type float — angular step between measurements
    float              range_min{0.0f};       // member variable 'range_min' of type float — minimum valid range in meters
    float              range_max{0.0f};       // member variable 'range_max' of type float — maximum valid range in meters
    std::vector<float> ranges;                // member variable 'ranges' of type std::vector<float> — distance measurements in meters
    std::vector<float> intensities;           // member variable 'intensities' of type std::vector<float> — optional signal strength per beam
};

}} // namespace sensor_msgs::msg

// ── stub: std_msgs::msg::String and std_msgs::msg::Float32 ───────────────
namespace std_msgs { namespace msg {

// defining struct 'String' in namespace 'std_msgs::msg'
// mirrors real std_msgs::msg::String — simplest ROS2 text message
struct String
{
    using SharedPtr = std::shared_ptr<String>;  // type alias 'SharedPtr'
    std::string data;   // member variable 'data' of type std::string — the text payload
};

// defining struct 'Float32' in namespace 'std_msgs::msg'
// mirrors real std_msgs::msg::Float32 — single float value message
struct Float32
{
    using SharedPtr = std::shared_ptr<Float32>;  // type alias 'SharedPtr'
    float data{0.0f};  // member variable 'data' of type float — the float payload
};

}} // namespace std_msgs::msg

// ── stub: example_interfaces::srv::AddTwoInts ────────────────────────────
namespace example_interfaces { namespace srv {

// defining struct 'AddTwoInts' in namespace 'example_interfaces::srv'
// mirrors the type generated from AddTwoInts.srv by rosidl — wraps Request and Response
struct AddTwoInts
{
    // defining nested struct 'Request' — input side of the service call
    struct Request
    {
        using SharedPtr = std::shared_ptr<Request>;  // type alias 'SharedPtr'
        int64_t a{0};  // member variable 'a' of type int64_t — first integer operand
        int64_t b{0};  // member variable 'b' of type int64_t — second integer operand
    };

    // defining nested struct 'Response' — output side of the service call
    struct Response
    {
        using SharedPtr = std::shared_ptr<Response>;  // type alias 'SharedPtr'
        int64_t sum{0};  // member variable 'sum' of type int64_t — result of a + b
    };
};

}} // namespace example_interfaces::srv

// ── stub: rclcpp::Publisher<MsgType> ────────────────────────────────────
namespace rclcpp
{

// defining template class 'Publisher' in namespace 'rclcpp'
// template parameter 'MsgType' — the message type this publisher sends on a topic
template<typename MsgType>
class Publisher
{
public:
    // type alias 'SharedPtr' — mirrors real rclcpp::Publisher<MsgType>::SharedPtr
    using SharedPtr = std::shared_ptr<Publisher<MsgType>>;

    // defining member function 'publish' with return type void
    // parameter 'msg' of type const MsgType& — read-only reference to message to send
    // mirrors real rclcpp::Publisher::publish() — sends via DDS middleware
    void publish(const MsgType & msg) { (void)msg; }  // stub body — real impl serializes and sends
};

} // namespace rclcpp

// ── stub: rclcpp::Subscription<MsgType> ─────────────────────────────────
namespace rclcpp
{

// defining template class 'Subscription' in namespace 'rclcpp'
// template parameter 'MsgType' — the message type this subscription receives
template<typename MsgType>
class Subscription
{
public:
    using SharedPtr = std::shared_ptr<Subscription<MsgType>>;  // type alias 'SharedPtr'
};

} // namespace rclcpp

// ── stub: rclcpp::Service<SrvType> ──────────────────────────────────────
namespace rclcpp
{

// defining template class 'Service' in namespace 'rclcpp'
// template parameter 'SrvType' — the service type (wraps Request + Response)
template<typename SrvType>
class Service
{
public:
    using SharedPtr = std::shared_ptr<Service<SrvType>>;  // type alias 'SharedPtr'

    // defining member function 'configure_introspection' with return type void
    // parameter 'clock' of type void* — stub for rclcpp::Clock::SharedPtr
    // parameter 'qos' of type SystemDefaultsQoS — QoS for the introspection topic
    // parameter 'state' of type rcl_service_introspection_state_t — new introspection level
    void configure_introspection(void * clock, SystemDefaultsQoS qos, rcl_service_introspection_state_t state)
    { (void)clock; (void)qos; (void)state; }
};

} // namespace rclcpp

// ── stub: rclcpp::Client<SrvType> ────────────────────────────────────────
namespace rclcpp
{

// defining template class 'Client' in namespace 'rclcpp'
// template parameter 'SrvType' — the service type this client calls
template<typename SrvType>
class Client
{
public:
    using SharedPtr = std::shared_ptr<Client<SrvType>>;  // type alias 'SharedPtr'

    // defining nested struct 'SharedFuture' — mirrors real rclcpp::Client<SrvType>::SharedFuture
    // a shared_ptr-like handle to the eventual service response
    struct SharedFuture
    {
        // member variable 'response_' of type std::shared_ptr<SrvType::Response>
        typename SrvType::Response::SharedPtr response_ =
            std::make_shared<typename SrvType::Response>();

        // defining member function 'get' — mirrors std::shared_future::get()
        // returns the response shared_ptr — blocks in real impl until server replies
        typename SrvType::Response::SharedPtr get() { return response_; }
    };

    // defining member function 'service_is_ready' with return type bool
    // mirrors real rclcpp::Client::service_is_ready() — true if a server is connected
    bool service_is_ready() const { return true; }

    // defining member function 'async_send_request' with return type void
    // parameter 'request' of type SharedPtr<Request> — the request to send
    // parameter 'callback' of type std::function<void(SharedFuture)> — called when response arrives
    // mirrors real rclcpp::Client::async_send_request() — non-blocking
    void async_send_request(
        typename SrvType::Request::SharedPtr request,
        std::function<void(SharedFuture)> callback)
    {
        (void)request;
        SharedFuture future;
        callback(future);   // stub calls immediately; real impl calls when server replies
    }

    // defining member function 'configure_introspection' — mirrors real Client::configure_introspection
    void configure_introspection(void * clock, SystemDefaultsQoS qos, rcl_service_introspection_state_t state)
    { (void)clock; (void)qos; (void)state; }
};

} // namespace rclcpp

// ── stub: rclcpp::Node ───────────────────────────────────────────────────
namespace rclcpp
{

// defining class 'Node' in namespace 'rclcpp'
// mirrors real rclcpp::Node — the base class every ROS2 node inherits from via 'class MyNode : public rclcpp::Node'
class Node
{
public:
    // defining constructor of class 'Node'
    // parameter 'node_name' of type const std::string& — the node name string in snake_case
    // parameter 'options' of type const NodeOptions& — node configuration (default: empty options)
    explicit Node(const std::string & node_name, const NodeOptions & = NodeOptions{})
    : node_name_(node_name)                  // initializing member 'node_name_' with given name
    { logger_.name_ = node_name_; }          // assigning 'logger_.name_' so log output shows node name

    virtual ~Node() = default;   // virtual destructor — subclasses clean up correctly via base pointer

    // defining member function 'get_logger' with return type rclcpp::Logger
    // mirrors real rclcpp::Node::get_logger() — pass result to RCLCPP_INFO/WARN/ERROR macros
    Logger      get_logger() const { return logger_; }

    // defining member function 'get_name' with return type const char*
    // mirrors real rclcpp::Node::get_name()
    const char* get_name()   const { return node_name_.c_str(); }

    // defining member function 'get_clock' with return type void*
    // stub for real rclcpp::Node::get_clock() which returns rclcpp::Clock::SharedPtr
    void*       get_clock()        { return nullptr; }

    // defining template member function 'create_publisher'
    // returns rclcpp::Publisher<MsgType>::SharedPtr
    // parameter 'topic_name' of type const std::string& — topic name in snake_case
    // parameter 'qos_depth' of type size_t — history queue depth
    template<typename MsgType>
    typename Publisher<MsgType>::SharedPtr
    create_publisher(const std::string & topic_name, size_t qos_depth)
    { (void)topic_name; (void)qos_depth; return std::make_shared<Publisher<MsgType>>(); }

    // defining template member function 'create_subscription'
    // returns rclcpp::Subscription<MsgType>::SharedPtr
    // parameter 'callback' of type std::function<void(MsgType::SharedPtr)> — message handler lambda
    template<typename MsgType>
    typename Subscription<MsgType>::SharedPtr
    create_subscription(
        const std::string & topic_name, size_t qos_depth,
        std::function<void(typename MsgType::SharedPtr)> callback)
    { (void)topic_name; (void)qos_depth; (void)callback; return std::make_shared<Subscription<MsgType>>(); }

    // defining template member function 'create_client'
    // returns rclcpp::Client<SrvType>::SharedPtr
    template<typename SrvType>
    typename Client<SrvType>::SharedPtr
    create_client(const std::string & service_name)
    { (void)service_name; return std::make_shared<Client<SrvType>>(); }

    // defining template member function 'create_service'
    // returns rclcpp::Service<SrvType>::SharedPtr
    // parameter 'callback' of type std::function<void(shared_ptr<header>, shared_ptr<Request>, shared_ptr<Response>)>
    template<typename SrvType>
    typename Service<SrvType>::SharedPtr
    create_service(
        const std::string & service_name,
        std::function<void(
            std::shared_ptr<rmw_request_id_t>,
            std::shared_ptr<typename SrvType::Request>,
            std::shared_ptr<typename SrvType::Response>)> callback)
    { (void)service_name; (void)callback; return std::make_shared<Service<SrvType>>(); }

    // defining member function 'create_wall_timer'
    // returns rclcpp::TimerBase::SharedPtr
    // parameter 'period' of type std::chrono::milliseconds — timer interval
    // parameter 'callback' of type std::function<void()> — called every period
    TimerBase::SharedPtr
    create_wall_timer(std::chrono::milliseconds period, std::function<void()> callback)
    { (void)period; (void)callback; return std::make_shared<TimerBase>(); }

    // defining member function 'declare_parameter' for string default
    // mirrors real rclcpp::Node::declare_parameter() — registers parameter with default value
    void declare_parameter(const std::string & name, const std::string & default_value)
    { (void)name; (void)default_value; }

    // overload of 'declare_parameter' for double default
    void declare_parameter(const std::string & name, double default_value)
    { (void)name; (void)default_value; }

    // defining member function 'add_on_set_parameters_callback'
    // returns OnSetParametersCallbackHandle::SharedPtr — RAII handle; destroy it to unregister
    // mirrors real rclcpp::Node::add_on_set_parameters_callback()
    node_interfaces::OnSetParametersCallbackHandle::SharedPtr
    add_on_set_parameters_callback(
        std::function<rcl_interfaces::msg::SetParametersResult(std::vector<Parameter>)> callback)
    { (void)callback; return std::make_shared<node_interfaces::OnSetParametersCallbackHandle>(); }

    // defining member function 'add_post_set_parameters_callback'
    // returns PostSetParametersCallbackHandle::SharedPtr — RAII handle
    node_interfaces::PostSetParametersCallbackHandle::SharedPtr
    add_post_set_parameters_callback(
        std::function<void(const std::vector<Parameter> &)> callback)
    { (void)callback; return std::make_shared<node_interfaces::PostSetParametersCallbackHandle>(); }

    // defining member function 'shared_from_this' — stub for std::enable_shared_from_this
    // returns std::shared_ptr<Node> to this node — used when assigning to weak_ptr members
    std::shared_ptr<Node> shared_from_this()
    { return std::shared_ptr<Node>(this, [](Node*){}); }  // non-owning stub

private:
    std::string node_name_;   // member variable 'node_name_' of type std::string — the node's name
    Logger      logger_;      // member variable 'logger_' of type rclcpp::Logger — the node's logger object
};

} // namespace rclcpp
