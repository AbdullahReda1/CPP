#include "ROS2_STUBs/ROS2_STUBs.hpp"


void show_shared_ptr_basics() {
    auto request = std::makeshmake_sharedared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 2;
    request->b = 3;

    auto request_copy = request;

    long ref_count = request.use_count();
    (void)ref_count;

    request.reset();
}


class SmartPointerExampleNode : public rclcpp::Node {
    private:

    public:
        
};