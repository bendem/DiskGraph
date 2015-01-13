#ifndef TERM_HPP
#define TERM_HPP

#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

#include "string_manips.hpp"

using namespace std;

struct TermSize {
    unsigned width;
    unsigned height;
};

const string RESET       = "\033[0m";
const string BLACK       = "\033[30m";
const string RED         = "\033[31m";
const string GREEN       = "\033[32m";
const string YELLOW      = "\033[33m";
const string BLUE        = "\033[34m";
const string MAGENTA     = "\033[35m";
const string CYAN        = "\033[36m";
const string WHITE       = "\033[37m";
const string BOLDBLACK   = "\033[1m\033[30m";
const string BOLDRED     = "\033[1m\033[31m";
const string BOLDGREEN   = "\033[1m\033[32m";
const string BOLDYELLOW  = "\033[1m\033[33m";
const string BOLDBLUE    = "\033[1m\033[34m";
const string BOLDMAGENTA = "\033[1m\033[35m";
const string BOLDCYAN    = "\033[1m\033[36m";

vector<string> exec(const string&);
TermSize termSize();

#endif
