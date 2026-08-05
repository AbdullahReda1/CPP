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

namespace rclcpp { struct NodeOptions {}; }

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
}

/***************************************************************/

namespace rclcpp {
    struct TimerBase {
        using SharedPtr = std::shared_ptr<TimerBase>;

        virtual ~TimerBase() = default;
    };
}

/*******************************/

namespace rclcpp {
    struct Qos {
        explicit Qos(size_t depth = 10) : _depth(depth) {};
        size_t _depth;
    };

    struct SystemDefaultsQoS : public Qos { SystemDefaultsQoS() : Qos(10) {} };
}

/*******************************/

namespace rclcpp {
    namespace node_interfaces {
        struct OnSetParametersCallbackHandle {
            using SharedPtr = std::shared_ptr<OnSetParametersCallbackHandle>;
        };

        struct PostSetParametersCallbackHandle {
            using SharedPtr = std::shared_ptr<PostSetParametersCallbackHandle>;
        };
        
    }
}

/********************************/

namespace rclcpp {
    template<typename MsgType>
    class Publisher{
        public:
            using SharedPtr = std::shared_ptr<Publisher<MsgType>>;
            void Publish(const MsgType & msg) { (void)msg; }
    };
}

namespace rclcpp {
    template<typename MsgType>
    class Subscription{
        public:
            using SharedPtr = std::shared_ptr<Subscription<MsgType>>;
    };
}

/********************************/

enum rcl_service_introspection_state_t
{
    RCL_SERVICE_INTROSPECTION_OFF,       // constant — introspection disabled
    RCL_SERVICE_INTROSPECTION_METADATA,  // constant — log timing and request IDs only
    RCL_SERVICE_INTROSPECTION_CONTENTS,  // constant — log full request and response data
};

namespace rclcpp {
    template<typename SrvType>
    class Service {
        public:
            using SharedPtr = std::shared_ptr<Service<SrvType>>;
            void configure_introspection(void * clock, SystemDefaultsQoS qos, rcl_service_introspection_state_t state) {
                (void) clock;
                (void) qos;
                (void) state;
            }
    };
} // namespace rclcpp


namespace rclcpp {
    template<typename SrvType>
    class Client {
        public:
            using SharedPtr = std::shared_ptr<Client<SrvType>>;
            struct SharedFuture {
                
            };
    };
} // namespace rclcpp


