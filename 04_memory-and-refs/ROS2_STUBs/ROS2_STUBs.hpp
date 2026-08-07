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

/************************************/

namespace example_interface {
    namespace srv {
        struct AddTwoInts {
            struct Request {
                using SharedPtr = std::shared_ptr<Request>;
                int64_t a{0};
                int64_t b{0};
            };

            struct Response {
                using SharedPtr = std::shared_ptr<Response>;
                int64_t sum{0};
            };
        };
    } // namespace srv
} // namespace example_interface

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
                typename SrvType::Response::SharedPtr _response = std::make_shared<SrvType<Response>>;
                typename SrvType::Response::SharedPtr get() { return _response; }
            };

            bool service_is_ready() const { return true; }

            void async_send_request(typename SrvType::Request::SharedPtr request, 
                                    std::function<void(SharedFuture)> callback)
            {
                (void) request;
                SharedFuture future;
                callback(future);
            }

            void configure_introspection(void * clock, SystemDefaultsQoS qos, rcl_service_introspection_state_t state) 
            { (void) clock; (void) qos; (void) state; }
    };
} // namespace rclcpp

/**********************************************/
namespace rcl_interfaces { namespace msg {

// defining struct 'SetParametersResult' in namespace 'rcl_interfaces::msg'
// mirrors real rcl_interfaces::msg::SetParametersResult — returned by parameter validation callbacks
struct SetParametersResult
{
    bool        successful{true};  // member variable 'successful' of type bool — true = change accepted
    std::string reason;            // member variable 'reason' of type std::string — rejection message if not successful
};

}} // namespace rcl_interfaces::msg
struct rmw_request_id_t {
    uint8_t writer_guid[16];
    int64_t sequence_number;
};

/**********************************************/

namespace rclcpp {
    class Node {
        private:
            std::string node_name_;
            Logger logger_;
        public:
            explicit Node(const std::string & name, const NodeOptions & = NodeOptions{})
            : node_name_(name) { logger_.name_ = node_name_; }
            virtual ~Node() = default;

            Logger      get_logger() const { return logger_; }
            const char* get_name  () const { return node_name_.c_str(); }
            void*       get_clock ()       { return nullptr; }

            template<typename MsgType>
            typename Publisher<MsgType>::SharedPtr create_publisher(const std::string & topic_name, size_t qos_depth) {
                (void) topic_name; (void) qos_depth;
                return std::make_shared<Publisher<MsgType>>();
            }
            template<typename MsgType>
            typename Subscription<MsgType>::SharedPtr create_subscription(const std::string & topic_name, size_t qos_depth,
            std::function<void(typename MsgType::SharedPtr)> callback) {
                (void) topic_name; (void) qos_depth; (void) callback;
                return std::make_shared<Subscription<MsgType>>();
            }
            template<typename SrvType>
            typename Client<SrvType>::SharedPtr create_client(const std::string & service_name) {
                (void) service_name;
                return std::make_shared<Client<SrvType>>();
            }
            template<typename SrvType>
            typename Service<SrvType>::SharedPtr create_service(const std::string & service_name,
            std::function<void(
                std::shared_ptr<rmw_request_id_t>,
                std::shared_ptr<typename SrvType::Request>,
                std::shared_ptr<typename SrvType::Response>
            )> callback) {
                (void) service_name; (void) callback;
                return std::make_shared<Service<SrvType>>();
            }

            TimerBase::SharedPtr create_wall_timer(std::chrono::milliseconds period, std::function<void()> callback) {
                (void) period; (void) callback;
                return std::make_shared<TimerBase>();
            }

            void declare_parameter(const std::string & name, const std::string & default_value)
            { (void) name; (void) default_value; }
            void declare_parameter(const std::string & name, double              default_value) 
            { (void) name; (void) default_value; }

            node_interfaces::OnSetParametersCallbackHandle::SharedPtr 
            add_on_set_parameters_callback_handle(
                std::function<rcl_interfaces::msg::SetParametersResult(std::vector<Parameter>)> callback
            ) {
                (void) callback;
                return std::make_shared<node_interfaces::OnSetParametersCallbackHandle>();
            }
            node_interfaces::PostSetParametersCallbackHandle::SharedPtr
            add_post_set_parameters_callback_handle(
                std::function<void(std::vector<Parameter> &)> callback
            ) {
                (void) callback;
                return std::make_shared<node_interfaces::PostSetParametersCallbackHandle>();
            }

            std::shared_ptr<Node> shared_from_this() { return std::shared_ptr<Node>(this, [](Node*){}); }
    };
} // namespace rclcpp 