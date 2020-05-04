#include <string>

#pragma once

using String = std::string;

class XMLTree
{
public:
    XMLTree() = default;
    XMLTree(const String &);
    XMLTree *clone() const;

    void erase();

    void parse(std::istream &);

    void save();
    void save_as(const String &);

    void set_open_file_name(const String &);
    String get_open_file_name() const;

private:
    String open_file_name{};
};