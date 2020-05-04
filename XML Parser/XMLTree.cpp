#include "XMLTree.hpp"

XMLTree::XMLTree(const String &file_name) : open_file_name{file_name}
{
}
XMLTree *XMLTree::clone() const
{
    return new XMLTree{open_file_name};
}

void XMLTree::erase()
{
}

void XMLTree::parse(std::istream &)
{
}

void XMLTree::set_open_file_name(const String &file_name)
{
    open_file_name = file_name;
}
String XMLTree::get_open_file_name() const
{
    return open_file_name;
}