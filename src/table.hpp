#ifndef TABLE_HPP
#define TABLE_HPP

#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Table {

private:
    const unsigned columns;
    vector< vector<string> > lines;
    vector<unsigned> line_sizes;

public:
    Table(unsigned);
    Table& addLine(vector<string>);
    unsigned getWidth(unsigned) const;
    unsigned getTotalWidth() const;
    string getLine(unsigned) const;
    string toString() const;

};

#endif
