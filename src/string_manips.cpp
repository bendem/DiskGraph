#include "string_manips.hpp"

string displayGraph(unsigned percent, unsigned width, char graphChar) {
    if(width <= 2) {
        return "";
    }
    ostringstream ss;
    ss << '[' << GREEN;
    bool empty = false;
    for(unsigned i = 0; i < width-2; ++i) {
        if(!empty) {
            if (i > width / 4 * 3) {
                // More than 75%
                ss << RED;
            } else if (i >= width / 2) {
                // More than 50%
                ss << YELLOW;
            }
            if (i > percent * width / 100) {
                empty = true;
            }
        }
        ss << (empty ? ' ' : graphChar);
    }
    ss << RESET << ']';
    return ss.str();
}

pair<float, string> humanReadable(unsigned size) {
    if(size < 1024) {
        return pair<float, string> { size, human_readable_sizes[0] };
    }
    float res = size;
    unsigned i;
    for(i = 1; i < human_readable_sizes.size(); ++i) {
        res /= 1024;
        if(res < 1) {
            break;
        }
    }
    return pair<float, string>{ res*1024, human_readable_sizes[i] };
}

unsigned parseInt(string str) {
    unsigned res = 0;
    for(unsigned i = 0; i < str.length(); ++i) {
        if(str[i] < '0' || str[i] > '9') {
            throw invalid_argument("NaN");
        }
        res = res * 10 + str[i] - '0';
    }
    return res;
}

vector<string> split(string str, char sep, unsigned default_size) {
    istringstream ss(str);
    string part;
    vector<string> vector;

    if(default_size != 0) {
        vector.reserve(default_size);
    }

    while(ss.peek() != EOF) {
        getline(ss, part, sep);
        if(part.length() != 0) {
            vector.push_back(part);
        }
    }

    return vector;
}
