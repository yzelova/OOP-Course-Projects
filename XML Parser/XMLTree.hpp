#include <string>

#pragma once

using String = std::string;

class XMLTree
{
public:
    XMLTree() = default;
    XMLTree(const String &);

    void erase();
    void parse(std::istream &);
    void save();
    void save_as(const String &);

    friend std::ostream &operator<<(std::ostream &, const XMLTree &);

    void set_open_file_name(const String &);
    String get_open_file_name() const;

    XMLTree *clone() const;

private:
    String open_file_name{""};
    
};