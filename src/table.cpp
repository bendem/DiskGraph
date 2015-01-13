#include "table.hpp"

Table::Table(unsigned columns) : columns(columns) {
    this->line_sizes.reserve(columns);
    for(unsigned i = 0; i < columns; ++i) {
        this->line_sizes.push_back(0);
    }
    this->lines.reserve(columns);
}

Table& Table::addLine(vector<string> line) {
    if(line.size() != this->columns) {
        throw invalid_argument("invalid number of columns");
    }
    this->lines.push_back(line);
    for(unsigned i = 0; i < this->columns; ++i) {
        if(this->line_sizes[i] < line[i].length()) {
            this->line_sizes[i] = line[i].length();
        }
    }
    return *this;
}

unsigned Table::getWidth(unsigned column) const {
    return this->line_sizes[column];
}

unsigned Table::getTotalWidth() const {
    return accumulate(this->line_sizes.begin(), this->line_sizes.end(), 0) + this->columns;
}

string Table::getLine(unsigned column) const {
    ostringstream ss;
    for(unsigned i = 0; i < this->columns; ++i) {
        ss << ' ';
        ss << this->lines[column][i];
        int diff = (int) (this->line_sizes[i] - this->lines[column][i].length());
        if(diff > 0) {
            for (; diff != 0; --diff) {
                ss << ' ';
            }
        }
    }
    return ss.str();
}

string Table::toString() const {
    ostringstream ss;

    for(unsigned i = 0; i < this->columns; ++i) {
        ss << getLine(i) << endl;
    }

    return ss.str();
}
