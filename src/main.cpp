#include <iostream>
#include <map>
#include <vector>
#include <string.h>

#include "string_manips.hpp"
#include "table.hpp"
#include "term.hpp"

#ifndef VERSION
# define VERSION "1.0"
#endif

#define GRAPH_CHAR '='

using namespace std;

int main(int argc, char** argv) {
    if(argc == 2) {
        if(strcmp("-v", argv[1]) == 0) {
            cout << " Disk graphs by bendem, v" << VERSION << endl;
            return 0;
        }
        if(strcmp("-h", argv[1]) == 0) {
            cout << " Remove that '-h', just '" << argv[0] << "'..." << endl;
            return 0;
        }
    }
    vector<string> output(exec("df --portability"));
    Table t(4);
    vector<unsigned> percents;
    bool first = true;

    // Parsing output and preparing formatting
    for(string line : output) {
        if(first) {
            // Ignoring header line
            first = false;
            continue;
        }

        vector<string> fields = split(line, ' ', 6);
        if(fields[0].substr(0, 5) != "/dev/") {
            continue;
        }

        percents.push_back(parseInt(fields[4].substr(0, fields[4].length()-1)));
        unsigned usedBytes = parseInt(fields[2]);
        unsigned availBytes = parseInt(fields[3]);
        auto used = humanReadable(usedBytes);
        auto total = humanReadable(availBytes + usedBytes);
        t.addLine({
            toString(used.first) + toString(used.second),
            "/",
            toString(total.first) + toString(total.second),
            fields[5]
        });
    }

    cout << ' ' << percents.size() << " disks:" << endl;

    const unsigned width = t.getTotalWidth();
    const TermSize ts = termSize();
    const unsigned graphWidth = ts.width - width - 2;
    for(unsigned i = 0; i < percents.size(); ++i) {
        cout << ' ' << displayGraph(percents[i], graphWidth, GRAPH_CHAR) << t.getLine(i) << endl;
    }
    return 0;
}
