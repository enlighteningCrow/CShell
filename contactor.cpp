#include "contactor.h"

// Contactor::Contactor()
// {

// }


#include <pstreams/pstream.h>
#include <sys/inotify.h>
#include "stdc++.h"

bool        Commu::m_changed{false};
std::string Commu::m_message{""};
Info        Commu::m_info{""};


std::string        wholeText{""}, wholeTextw{""};
extern std::string message_receiver;

// int contactor() {
//     std::size_t ospos{ 0 }, oepos{ 0 }, espos{ 0 }, eepos{ 0 };
//     std::cout << "Starting up now!\n";
//     // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
//     static pstream child("stdbuf --output=0 bash"/* "export
//     PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer bash" *//* , mode */); char
//     buf[1024]; for (int i{ 0 };i < 1024; ++i) {
//         buf[i] = 0;
//     }
//     std::streamsize n;
//     std::string a;
//     std::string cDir;
//     // Info inf_prev{ Commu::info() };
//     std::stringstream ss;
//     bool finished[2] = { false, false };
//     child << ("");
//     while (!finished[0] || !finished[1]) {
//         while (!Commu::hasChanged()) {
//             // std::cout << "Not changed!\n";
//             usleep(10000);
//         }
//         Commu::info().clear();
//         child << "echo $PWD" << std::endl;
//         usleep(1000);
//         std::getline(child.out(), cDir);
//         Commu::info().path = ":" + cDir + "$\t";
//         // std::cout << ":" << cDir << "$\t";
//         // std::getline(std::cin, a);
//         a = Commu::getMessage();
//         a += "\necho ____ENDOFRESPONSE____\n";
//         a = "echo ____STARTOFRESPONSE____\n" + a;
//         // std::cout << "Sending out: " << a << ". \n";


//         //TODO: Also make it echo ENDOFRESPONSE and check it at the end of each command to check if terminated.


//         child.write(a.c_str(), a.size()).flush();
//         // usleep(100000);
//         ospos = std::string::npos;
//         oepos = std::string::npos;
//         espos = std::string::npos;
//         eepos = std::string::npos;
//     before:
//         usleep(100000);
//         if (!finished[0]) {
//             while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
//                 // ss.write(buf, n);
//                 // Commu::info().message_err += ss.str();
//                 // ss.clear();
//                 Commu::info().message_err += buf;
//                 // std::cerr.write(buf, n);
//             }
//             if (child.eof()) {
//                 finished[0] = true;
//                 if (!finished[1])
//                     child.clear();
//             }
//         }

//         if (!finished[1]) {
//             while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
//                 // ss.write(buf, n);
//                 // Commu::info().message_out += ss.str();
//                 // ss.clear();
//                 Commu::info().message_out += buf;
//                 // std::cout.write(buf, n).flush();
//             }
//             if (child.eof()) {
//                 finished[1] = true;
//                 if (!finished[0])
//                     child.clear();
//             }
//         }
//         // std::cout << "The whole message:\t" << Commu::info();

//         if (((ospos == std::string::npos) || (oepos == std::string::npos)) && ((espos == std::string::npos) || (eepos
//         == std::string::npos))) {
//             if (ospos == std::string::npos) {
//                 ospos = Commu::info().message_out.find("____STARTOFRESPONSE____");
//             }
//             if (espos == std::string::npos) {
//                 espos = Commu::info().message_err.find("____STARTOFRESPONSE____");
//             }
//             if (ospos != std::string::npos) {
//                 if (oepos == std::string::npos) {
//                     oepos = Commu::info().message_out.rfind("____ENDOFRESPONSE____");
//                 }
//             }
//             if (espos != std::string::npos) {
//                 if (eepos == std::string::npos) {
//                     eepos = Commu::info().message_err.rfind("____ENDOFRESPONSE____");
//                 }
//             }
//             if (((ospos == std::string::npos) || (oepos == std::string::npos)) && ((espos == std::string::npos) ||
//             (eepos == std::string::npos))) {
//                 goto before;
//             }
//         }
//         if (!((ospos == std::string::npos) || (oepos == std::string::npos))) {
//             Commu::info().message_out = Commu::info().message_out.substr(ospos + 24, oepos - 25);
//         }
//         else if (!((espos == std::string::npos) || (eepos == std::string::npos))) {
//             Commu::info().message_err = Commu::info().message_err.substr(espos + 24, eepos - 25);
//         }
//         else {
//             goto before;
//         }
//         Commu::info().complete = true;

//         // && ((espos == std::string::npos) || (eepos == std::string::npos))


//             //TODO: Check if the (one of the )string ends with the todo above.


//             // if ((Commu::info().message_err == "") && (Commu::info().message_out == "")) {
//                 // goto before;
//             // }
//             // else {
//             //     if (Commu::info() == inf_prev) {
//             //     }
//             // }
//         // Commu::info().;
//     }
//     Commu::info().terminated = true;
//     return 1;
// }


// int contactor() {
//     std::size_t ospos{ 0 }, oepos{ 0 }, espos{ 0 }, eepos{ 0 };
//     std::cout << "Starting up now!\n";
//     // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
//     static pstream child("stdbuf --output=0 bash"/* "export
//     PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer bash" *//* , mode */); char
//     buf[1024]; for (int i{ 0 };i < 1024; ++i) {
//         buf[i] = 0;
//     }
//     std::streamsize n;
//     std::string a;
//     std::string cDir;
//     // Info inf_prev{ Commu::info() };
//     std::stringstream ss;
//     bool finished[2] = { false, false };
//     child << ("");
//     bool isInBash{ false };
//     while (!finished[0] || !finished[1]) {
//         while (!Commu::hasChanged()) {
//             // std::cout << "Not changed!\n";
//             usleep(10000);
//         }
//         Commu::info().clear();


//         if (isInBash) {
//             child << "echo $PWD" << std::endl;
//             usleep(1000);
//             std::getline(child.out(), cDir);
//             Commu::info().path = ":" + cDir + "$\t";
//             // std::cout << ":" << cDir << "$\t";
//             // std::getline(std::cin, a);
//             a = Commu::getMessage();
//             a += "\necho ____ENDOFRESPONSE____\n";
//             a = "echo ____STARTOFRESPONSE____\n" + a;
//             child.write(a.c_str(), a.size()).flush();
//             // usleep(100000);
//             ospos = std::string::npos;
//             oepos = std::string::npos;
//             espos = std::string::npos;
//             eepos = std::string::npos;
//         before:
//             usleep(100000);
//             if (!finished[0]) {
//                 while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
//                     // ss.write(buf, n);
//                     // Commu::info().message_err += ss.str();
//                     // ss.clear();
//                     Commu::info().message_err += buf;
//                     // std::cerr.write(buf, n);
//                 }
//                 if (child.eof()) {
//                     finished[0] = true;
//                     if (!finished[1])
//                         child.clear();
//                 }
//             }

//             if (!finished[1]) {
//                 while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
//                     // ss.write(buf, n);
//                     // Commu::info().message_out += ss.str();
//                     // ss.clear();
//                     Commu::info().message_out += buf;
//                     // std::cout.write(buf, n).flush();
//                 }
//                 if (child.eof()) {
//                     finished[1] = true;
//                     if (!finished[0])
//                         child.clear();
//                 }
//             }
//             // std::cout << "The whole message:\t" << Commu::info();

//             if (((ospos == std::string::npos) || (oepos == std::string::npos)) && ((espos == std::string::npos) ||
//             (eepos == std::string::npos))) {
//                 if (ospos == std::string::npos) {
//                     ospos = Commu::info().message_out.find("____STARTOFRESPONSE____");
//                 }
//                 if (espos == std::string::npos) {
//                     espos = Commu::info().message_err.find("____STARTOFRESPONSE____");
//                 }
//                 if (ospos != std::string::npos) {
//                     if (oepos == std::string::npos) {
//                         oepos = Commu::info().message_out.rfind("____ENDOFRESPONSE____");
//                     }
//                 }
//                 if (espos != std::string::npos) {
//                     if (eepos == std::string::npos) {
//                         eepos = Commu::info().message_err.rfind("____ENDOFRESPONSE____");
//                     }
//                 }
//                 if (((ospos == std::string::npos) || (oepos == std::string::npos)) && ((espos == std::string::npos)
//                 || (eepos == std::string::npos))) {
//                     goto before;
//                 }
//             }
//             if (!((ospos == std::string::npos) || (oepos == std::string::npos))) {
//                 Commu::info().message_out = Commu::info().message_out.substr(ospos + 24, oepos - 25);
//             }
//             else if (!((espos == std::string::npos) || (eepos == std::string::npos))) {
//                 Commu::info().message_err = Commu::info().message_err.substr(espos + 24, eepos - 25);
//             }
//             else {
//                 goto before;
//             }
//             Commu::info().complete = true;
//         }


//         else {
//             a = Commu::getMessage();
//             a += "\n";
//             std::cout << "The message now is " << a << std::endl;
//             child.write(a.c_str(), a.size()).flush();
//             // usleep(100000);
//             std::string string_was_o{ "" }, string_was_e{ "" };
//         before2:
//             usleep(100000);
//             if (!finished[0]) {
//                 while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
//                     // ss.write(buf, n);
//                     // Commu::info().message_err += ss.str();
//                     // ss.clear();
//                     Commu::info().message_err += buf;
//                     // std::cerr.write(buf, n);
//                 }
//                 if (child.eof()) {
//                     finished[0] = true;
//                     if (!finished[1])
//                         child.clear();
//                 }
//             }

//             if (!finished[1]) {
//                 while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
//                     // ss.write(buf, n);
//                     // Commu::info().message_out += ss.str();
//                     // ss.clear();
//                     Commu::info().message_out += buf;
//                     // std::cout.write(buf, n).flush();
//                 }
//                 if (child.eof()) {
//                     finished[1] = true;
//                     if (!finished[0])
//                         child.clear();
//                 }
//             }
//             // std::cout << "The whole message:\t" << Commu::info();
//             if ((Commu::info().message_out != string_was_o) || (Commu::info().message_err != string_was_e)) {
//                 string_was_o = Commu::info().message_out;
//                 string_was_e = Commu::info().message_err;
//                 goto before2;
//             }
//             Commu::info().message_out = Commu::info().message_out.substr(0, 1000000);
//             Commu::info().message_err = Commu::info().message_err.substr(0, 1000000);
//             Commu::info().complete = true;

//         }
//     }
//     Commu::info().terminated = true;
//     return 1;
// }


class Comparer {
    std::string                 wasBefore;
    std::string                 isNow;
    std::string                 difference;
    std::deque<std::streamsize> locations;
    std::size_t                 index, indexB;

public:
    Comparer(std::string str1 = "") : wasBefore{str1}, isNow{""}, difference{""}, locations{}, index{0}, indexB{0} {
    }
    Comparer& operator<<(std::string& st) {
        locations.push_back(st.size());
        isNow += st;
        return *this;
    }
    std::string findSubs(std::string& newIsNow) {
        isNow = newIsNow;
        for (int i{0}; (i < locations.size()); ++i) {
            index = wasBefore.rfind(isNow.substr(0, locations[i]));
            if (index = -1) {
                break;
            }
            indexB = index;
        }
        difference = wasBefore.substr(0, index);
        wasBefore  = isNow;
        return difference;
    }
};

// class PReader : public redi::pstreambuf {
// public:
//     void getContents(const char*& start, const char*& end) {
//         // this->buf
//         try {
//             // this->wbuffer_;
//             // this->wpipe();

//             // this->eback();
//             // this->
//             std::cout << this->wpipe();
//             this->wbuffer_;
//             egptr();
//             gptr();
//             // pstreams::fd_type
//             // this->wpipe();
//             start = gptr();
//             end = egptr();
//         }
//         catch (std::exception& e) {
//             std::cerr << e.what();
//             start = nullptr;
//             end = nullptr;
//         }
//     }
// };

// int contactor() {
//     std::size_t ospos{ 0 }, oepos{ 0 }, espos{ 0 }, eepos{ 0 };
//     std::cout << "Starting up now!\n";
//     // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
//     static pstream child("stdbuf --output=0 bash"/* "export
//     PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer bash" *//* , mode */); char
//     buf[1024], * firstInOutput{ nullptr }, * lastInOutput{ nullptr }; for (int i{ 0 };i < 1024; ++i) {
//         buf[i] = 0;
//     }


//     Comparer comparer{};


//     std::streamsize n;
//     std::string message;
//     std::string remainingOutput;
//     std::string cDir;
//     std::string difference, diffb;
//     // Info inf_prev{ Commu::info() };
//     std::stringstream ss;
//     bool finished[2] = { false, false };
//     child << ("");
//     bool isReadMode{ true };

//     const char* current, * end;

//     bool isFirst{ true };

//     //TODO: This takes care of the text box from Qt.
//     std::string wholeText{ "" };

//     goto first;

//     while (!finished[0] || !finished[1]) {
//         // while (!Commu::hasChanged()) {
//         //     // std::cout << "Not changed!\n";
//         //     usleep(10000);
//         // }

//         if (!finished[0]) {
//             while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
//                 // ss.write(buf, n);
//                 // Commu::info().message_err += ss.str();
//                 // ss.clear();
//                 Commu::info().message_err += buf;
//                 // std::cerr.write(buf, n);
//             }
//             if (child.eof()) {
//                 finished[0] = true;
//                 if (!finished[1])
//                     child.clear();
//             }
//         }

//         if (!finished[1]) {
//             while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
//                 // ss.write(buf, n);
//                 // Commu::info().message_out += ss.str();
//                 // ss.clear();
//                 Commu::info().message_out += buf;
//                 // std::cout.write(buf, n).flush();
//             }
//             if (child.eof()) {
//                 finished[1] = true;
//                 if (!finished[0])
//                     child.clear();
//             }
//         }
//         wholeText += (Commu::info().message_err + Commu::info().message_out);
//     first:
//         do {
//             if (Commu::hasChanged()) {
//                 isFirst = false;
//                 Commu::info().clear();
//                 message += (Commu::getMessage() + '\n');
//                 // a += "\n";
//                 std::cout << "The message now is " << message << std::endl;
//                 child.write(message.c_str(), message.size()).flush();
//                 // usleep(100000);
//                 // std::string string_was_o{ "" }, string_was_e{ "" };
//             }
//         } while (isFirst);
//         // while (!isReadMode) {
//         ;
//         // std::string a{ child.rdbuf()->pubseekpos(-1)., child.rdbuf()->pubseekpos(100) };
//         // std::stringstream b;
//         // std::cout.rdbuf()->
//         // b << child.rdbuf()->;
//         // child.out()
//         // b.str();

//         // popen
//         // pstreams::p
//         // std::string{ child.rdbuf() };
//         child.rdbuf();
//         std::stringstream pbuf_conts;
//         if (child.rdbuf()->in_avail()) {
//             // std::tie(current, end) = dynamic_cast<PReader*>(child.rdbuf())->getContents();
//             // auto&& a = dynamic_cast<PReader*>(child.rdbuf())->getContents();
//             // current = std::get<0>(a);
//             // end = std::get<0>(a);


//             auto abcde = child.tellp();
//             dynamic_cast<PReader*>(child.rdbuf())->getContents(current, end);
//             std::string CurrentRemaining{ current, end };
//             pbuf_conts << CurrentRemaining;
//             // pbuf_conts << pstreams::pstdout;


//             std::cout << CurrentRemaining;
//             // std::cout << pstreams::pstdout;
//             pbuf_conts.str();
//         }
//         do {
//             difference += (diffb = comparer.findSubs(remainingOutput = pbuf_conts.str()));
//         } while (diffb != "");
//         diffb = "";
//         wholeText += difference;
//         difference = "";


//         pbuf_conts >> child.rdbuf();
//         // popen()
//         // if (child.rdbuf()->gptr() > _IO_buf_base != firstInOutput) {
//             // do {
//                 // lastInOutput = stdout->_IO_buf_base;
//                 // usleep(10000);
//             // } while (stdout->_IO_buf_base != lastInOutput);
//             // wholeText += std::string(firstInOutput, lastInOutput);
//             // firstInOutput = stdout->_IO_buf_base;
//         // }
//         Commu::info().complete = true;
//         // }

//         // before2:
//         // std::cout << "The whole message:\t" << Commu::info();
//         // if ((Commu::info().message_out != string_was_o) || (Commu::info().message_err != string_was_e)) {
//         //     string_was_o = Commu::info().message_out;
//         //     string_was_e = Commu::info().message_err;
//         //     goto before2;
//         // }
//         // Commu::info().message_out = Commu::info().message_out.substr(0, 1000000);
//         // Commu::info().message_err = Commu::info().message_err.substr(0, 1000000);
//         // Commu::info().complete = true;

//     }
//     Commu::info().terminated = true;
//     return 1;
// }


int contactor() {
    std::size_t ospos{0}, oepos{0}, espos{0}, eepos{0};
    std::cout << "Starting up now!\n";
    // const pstreams::pmode mode = pstreams::pstdout | pstreams::pstderr;
    static pstream child(
        "stdbuf --output=0 bash" /* "export
                                    PATH=\"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH\";unbuffer
                                    bash" */
        /* , mode */);
    char buf[1024], *firstInOutput{nullptr}, *lastInOutput{nullptr};
    for (int i{0}; i < 1024; ++i) {
        buf[i] = 0;
    }


    Comparer comparer{};


    std::streamsize n;
    std::string     message;
    std::string     remainingInput;
    std::string     wholeInput{""}, wholeInputw{""};
    std::string     cDir;
    std::string     difference, diffb;
    // Info inf_prev{ Commu::info() };
    std::stringstream ss;
    bool              finished[2] = {false, false};
    child << ("");
    bool isReadMode{true}, is_in_program{true};

    const char *current, *end;

    bool isFirst{true};

    goto first;

    while (!finished[0] || !finished[1]) {

        if (!finished[0]) {
            while ((n = child.err().readsome(buf, sizeof(buf))) > 0) {
                Commu::info().message_err += buf;
            }
            if (child.eof()) {
                finished[0] = true;
                if (!finished[1])
                    child.clear();
            }
        }

        if (!finished[1]) {
            while ((n = child.out().readsome(buf, sizeof(buf))) > 0) {
                Commu::info().message_out += buf;
            }
            if (child.eof()) {
                finished[1] = true;
                if (!finished[0])
                    child.clear();
            }
        }


        if (((ospos == std::string::npos) || (espos == std::string::npos)) && (!is_in_program)) {
            if (ospos == std::string::npos) {
                ospos = Commu::info().message_out.find("____STARTOFRESPONSE____");
            }
            if (espos == std::string::npos) {
                espos = Commu::info().message_err.find("____STARTOFRESPONSE____");
            }
            if (ospos != std::string::npos) {
                if (oepos == std::string::npos) {
                    oepos = Commu::info().message_out.rfind("____ENDOFRESPONSE____");
                }
            }
            if (espos != std::string::npos) {
                if (eepos == std::string::npos) {
                    eepos = Commu::info().message_err.rfind("____ENDOFRESPONSE____");
                }
            }
            if (((ospos != std::string::npos) && (oepos == std::string::npos)) ||
                ((espos != std::string::npos) && (eepos == std::string::npos))) {
                is_in_program = true;
            }
        }
        else if (((oepos == std::string::npos) || (eepos == std::string::npos)) && (is_in_program)) {
            if (oepos == std::string::npos) {
                oepos = Commu::info().message_out.rfind("____ENDOFRESPONSE____");
            }
            if (eepos == std::string::npos) {
                eepos = Commu::info().message_err.rfind("____ENDOFRESPONSE____");
            }
            if ((oepos != std::string::npos) || (eepos != std::string::npos)) {
                is_in_program = true;
            }
        }
        if (!((ospos == std::string::npos))) {
            Commu::info().message_out = Commu::info().message_out.substr(ospos + 24);
        }
        else if (!((espos == std::string::npos))) {
            Commu::info().message_err = Commu::info().message_err.substr(espos + 24);
        }
        if (!((oepos == std::string::npos))) {
            Commu::info().message_out = Commu::info().message_out.substr(0, oepos - ospos - 24);
        }
        else if (!((eepos == std::string::npos))) {
            Commu::info().message_err = Commu::info().message_err.substr(0, eepos - espos - 24);
        }


        wholeText += (Commu::info().message_err + Commu::info().message_out);
        Commu::info().clear();

    first:
        do {
            if (Commu::hasChanged()) {
                isFirst = false;
                Commu::info().clear();
                message =
                    ((!is_in_program ? "echo ____STARTOFRESPONSE____;" : "") + Commu::getMessage() +
                     (!is_in_program ? ";echo ____ENDOFRESPONSE____" : "") + '\n');
                child.write(message.c_str(), message.size()).flush();
                wholeInput += message;
            }
        }
        while (isFirst);
        ;
        std::stringstream pbuf_conts;

        difference = wholeInput;
        wholeText += difference;
        wholeInput = "";

        message_receiver       = wholeText;
        Commu::info().complete = true;

        if (wholeText != wholeTextw) {
            usleep(100000);
        }
        wholeTextw = wholeText;
        ospos = oepos = espos = eepos = std::string::npos;
    }
    Commu::info().terminated = true;
    return 1;
}