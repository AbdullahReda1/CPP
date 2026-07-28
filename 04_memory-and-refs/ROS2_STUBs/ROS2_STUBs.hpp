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
