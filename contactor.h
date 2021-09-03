#ifndef CONTACTOR_H
#define CONTACTOR_H


// class Contactor
// {
// public:
//     Contactor();
// };



#include <bits/stdc++.h>
#include <sys/inotify.h>
#include <pstreams/pstream.h>

using redi::pstreams;
using redi::pstream;
using redi::ipstream;

#include <boost/thread.hpp>

struct Info {
public:
    std::string message_out;
    std::string message_err;
    std::string path;
    bool terminated;
    bool isComplete() {
        return (((message_out != "") || (message_err != "")) && (path != ""));
    }
    void clear() {
        message_out = "";
        message_err = "";
        path = "";
    }
};

class Commu {
protected:
    static bool m_changed;
    static std::string m_message;
    static Info m_info;
public:
    Commu() {}
    // Commu() : m_message{ "" }, m_changed{ false } {}
    // Commu(std::string message) : m_message{ message }, m_changed{ true } {}
    static Info& info() {
        return m_info;
    }
    operator bool() {
        return m_changed;
    }
    static bool hasChanged() {
        return m_changed;
    }
    static Info& sendMessagef(const std::string& message) {
        m_changed = true;
        m_message = message;
        // boost::thread thread1{}
        while (!m_info.isComplete()) {
            usleep(10000);
        }
        /**
         * @brief
         * Main process should handle this termination (if unexpected).
         */
         // if (m_info.terminated) {
             // 
         // }
        return m_info;
    }
    static void setMessage(const std::string& message) {
        m_changed = true;
        m_message = message;
        return;
    }
    static std::string& getMessage() {
        m_changed = false;
        return m_message;
    }
};

// Commu communicator1{};

int contactor();

#endif // CONTACTOR_H
