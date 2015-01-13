#include "term.hpp"

vector<string> exec(const string& cmd) {
    FILE* pipe = popen(cmd.c_str(), "r");
    if(!pipe) {
        throw exception();
    }
    char buffer[256];
    string result;
    while(!feof(pipe)) {
        if(fgets(buffer, 256, pipe) != NULL) {
            result += buffer;
        }
    }
    pclose(pipe);
    return split(result, '\n');
}

TermSize termSize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    TermSize ts;
    ts.height = w.ws_row;
    ts.width = w.ws_col;
    return ts;
}
