#ifndef STRING_MANIPS_HPP
#define STRING_MANIPS_HPP

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "term.hpp"

using namespace std;

const vector<string> human_readable_sizes { "B", "KB", "MB", "GB", "TB" };

string displayGraph(unsigned, unsigned, char);

pair<float, string> humanReadable(unsigned);

unsigned parseInt(string);

vector<string> split(string, char, unsigned = 0);

template<class T>
string toString(const T& p) {
    ostringstream ss;
    ss << p;
    return ss.str();
}

#endif
