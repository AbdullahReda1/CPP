#include "ROS2_STUBs/ROS2_STUBs.hpp"


// ── SECTION 1.1 — Basic reference syntax ────────────────────────────────

// defining function 'show_basic_reference' with return type void
// purpose: demonstrate at the most basic level what a reference is
void show_basic_reference()
{
    int velocity = 42;              // initializing variable 'velocity' of type int with value 42

    int & velocity_ref = velocity;  // declaring reference 'velocity_ref' of type int& — alias for 'velocity', same memory address, no copy

    velocity_ref = 100;             // assigning 100 through reference 'velocity_ref' of type int& — writes to the same memory cell as 'velocity'

    // 'velocity' is now 100 — only one int exists in memory, two names for it
}

// ── SECTION 1.2 — const T& (read-only reference — most common in ROS2) ──

// defining function 'process_scan' with return type void
// parameter 'scan_msg' of type const sensor_msgs::msg::LaserScan& — read-only reference to incoming laser scan
// WHY const ref: a LaserScan with 1080 beams is ~4KB. Passing by value copies it every call. Const ref = zero copy.
void process_scan(const sensor_msgs::msg::LaserScan & scan_msg)
{
    // reading field 'angle_min' of type float from 'scan_msg' through const ref — no copy of the message
    float angle_min = scan_msg.angle_min;   // initializing variable 'angle_min' of type float

    // reading first element of 'ranges' of type std::vector<float> in 'scan_msg' through const ref
    float first_range = scan_msg.ranges.empty() ? 0.0f : scan_msg.ranges[0];  // initializing 'first_range' of type float

    (void)angle_min; (void)first_range;  // suppressing unused variable warnings in this example

    // scan_msg.ranges[0] = 0.0f;   // COMPILE ERROR — cannot modify through a const reference
    //                               // this protects the caller's message from accidental changes
}

// ── SECTION 1.3 — T& (mutable reference — fills a struct in-place) ───────

// defining function 'fill_parameter_result' with return type void
// parameter 'result' of type rcl_interfaces::msg::SetParametersResult& — mutable ref to result struct
// parameter 'success' of type bool — whether the parameter change should be accepted
// WHY mutable ref: avoids returning SetParametersResult by value — writes directly into caller's object
void fill_parameter_result(rcl_interfaces::msg::SetParametersResult & result, bool success)
{
    // assigning field 'successful' of type bool in struct 'result' through mutable ref
    result.successful = success;

    // assigning field 'reason' of type std::string in struct 'result' through mutable ref
    result.reason = success
                    ? "parameter accepted"
                    : "parameter rejected — invalid value";
}

// ── SECTION 1.4 — const T& in range-based for loop ───────────────────────

// defining function 'iterate_parameters' with return type void
// parameter 'parameters' of type const std::vector<rclcpp::Parameter>& — read-only ref to parameter vector
// called by parameter callbacks — iterates without copying the vector or any element
void iterate_parameters(const std::vector<rclcpp::Parameter> & parameters)
{
    // range-based for — loop variable 'param' of type const rclcpp::Parameter&
    // each iteration: 'param' is a read-only alias to one element in 'parameters'
    // no copy of any Parameter object is made
    for (const rclcpp::Parameter & param : parameters)
    {
        // calling method 'get_name()' on const ref 'param' of type rclcpp::Parameter
        // returns const std::string& — the parameter's name string
        std::string param_name = param.get_name();  // initializing variable 'param_name' of type std::string

        if (param_name == "wheel_radius")
        {
            // calling method 'as_double()' on const ref 'param' — returns double value
            double value = param.as_double();  // initializing variable 'value' of type double
            (void)value;
        }
    }
}

// ── SECTION 1.5 — Subscriber callback — the actual ROS2 pattern ──────────

// defining class 'ReferenceExampleNode' inheriting from base class 'rclcpp::Node'
class ReferenceExampleNode : public rclcpp::Node
{
public:
    // defining constructor of class 'ReferenceExampleNode'
    // parameter 'options' of type const rclcpp::NodeOptions& — read-only reference to node config
    explicit ReferenceExampleNode(const rclcpp::NodeOptions & options)
    : rclcpp::Node("reference_example_node", options)  // calling base class constructor — sets node name to "reference_example_node"
    {
        // calling 'create_subscription' — template arg: sensor_msgs::msg::LaserScan
        // returns rclcpp::Subscription<LaserScan>::SharedPtr — stored in member 'scan_subscription_'
        // topic name string: "scan", queue depth int: 10
        scan_subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
            "scan",
            10,
            // lambda callback — parameter 'msg' of type const sensor_msgs::msg::LaserScan::SharedPtr
            // ROS2 delivers messages as SharedPtr (shared_ptr) — the subscription keeps it alive
            [this](const sensor_msgs::msg::LaserScan::SharedPtr msg)
            {
                // dereferencing shared_ptr 'msg' with operator '*' to get the LaserScan object
                // passing the result as const ref to function 'process_scan'
                // this is the bridge from SharedPtr (ROS2 delivery) to const T& (efficient reading)
                process_scan(*msg);
            }
        );
    }

private:
    // declaring member variable 'scan_subscription_' of type rclcpp::Subscription<LaserScan>::SharedPtr
    // trailing underscore '_' — ROS2 naming convention for all member variables
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_subscription_;
};