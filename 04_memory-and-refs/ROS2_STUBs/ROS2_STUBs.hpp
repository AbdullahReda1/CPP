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

namespace rclcpp
{
    struct Logger
    {
        std::string name_;
    };
    
} // namespace rclcpp

#define RCLCPP_INFO(logger, fmt, ...) printf("[INFO][%s]" fmt "\n", (logger).name_.c_str(), ##__VA_ARGS__)

#define RCLCPP_DEBUG(logger, fmt, ...) printf("[DEBUG][%s]" fmt "\n", (logger).name.c_str(), ##__VA__ARGS__)

//

//

/*******************************************************/

namespace rclcpp { struct NodeOptions {}; };

namespace rclcpp {
    enum class ParameterType {
        PARAMETER_NOT_SET,
        PARAMETER_BOOLEAN,
        PARAMETER_DOUBLE,
        PARAMETER_INTEGER,
        PARAMETER_STRING
    };

    class Parameter {
        private:
            std::string name_;
            std::string string_parameter;
            double double_var{};
            int64_t interger_var{};
            bool Boolian_var{};
            ParameterType type_;
        
        public:
            Parameter(const std::string & name, const std::string & value) 
            : name_(name), string_parameter(value), type_(ParameterType::PARAMETER_STRING) {}

            Parameter(const std::string & name, double value)
            : name_(name), double_var(value), type_(ParameterType::PARAMETER_DOUBLE) {}
    };
};