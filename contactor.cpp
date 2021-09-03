#include "contactor.h"

// Contactor::Contactor()
// {

// }


#include <bits/stdc++.h>
#include <sys/inotify.h>
#include <pstreams/pstream.h>

bool Commu::m_changed{ false };
std::string Commu::m_message{ "" };
Info Commu::m_info{ "" };

int contactor() {
    // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
    static pstream child("stdbuf --output=0 bash"/* "export PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer bash" *//* , mode */);
    char buf[1024];
    for (int i{ 0 };i < 1024; ++i) {
        buf[i] = 0;
    }
    std::streamsize n;
    std::string a;
    std::string cDir;
    std::stringstream ss;
    bool finished[2] = { false, false };
    child << ("");
    while (!finished[0] || !finished[1]) {
        while (!Commu::hasChanged()) {
            usleep(10000);
        }
        Commu::info().clear();
        child << "echo $PWD" << std::endl;
        std::getline(child.out(), cDir);
        Commu::info().path = ":" + cDir + "$\t";
        // std::cout << ":" << cDir << "$\t";
        std::getline(std::cin, a);
        a += '\n';
        // std::cout << "Sending out: " << a << ". \n";
        child.write(a.c_str(), a.size()).flush();
        usleep(100000);
        if (!finished[0]) {
            while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
                // ss.write(buf, n);
                // Commu::info().message_err += ss.str();
                // ss.clear();
                Commu::info().message_err += buf;
                // std::cerr.write(buf, n);
            }
            if (child.eof()) {
                finished[0] = true;
                if (!finished[1])
                    child.clear();
            }
        }

        if (!finished[1]) {
            while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
                // ss.write(buf, n);
                // Commu::info().message_out += ss.str();
                // ss.clear();
                Commu::info().message_out += buf;
                // std::cout.write(buf, n).flush();
            }
            if (child.eof()) {
                finished[1] = true;
                if (!finished[0])
                    child.clear();
            }
        }
    }
    Commu::info().terminated = true;
    return 1;
}
