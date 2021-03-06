#ifndef LOGGER_SINGLETON_H
#define LOGGER_SINGLETON_H

#include <memory>
#include "base.hpp"

namespace log {
    class Logger
    {
    private:
        Logger();
        static Logger* const _instance;
        std::unique_ptr<BaseLogger> _global_logger;
        Logger(const Logger&) = delete;
        Logger& operator= (const Logger) = delete;
    public:
        ~Logger();
        static Logger* const get_instance();
        void set_global_logger(std::unique_ptr<BaseLogger> &other);
        BaseLogger* get_global_logger();
    };
};

#endif