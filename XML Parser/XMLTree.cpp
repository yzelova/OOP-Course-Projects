#include "XMLTree.hpp"

XMLTree::XMLTree(const String &file_name) : open_file_name{file_name}
{
    //TO-DO: reconstruct ctor
}
XMLTree *XMLTree::clone() const
{
    return new XMLTree{open_file_name};
}

void XMLTree::erase()
{
    //TO-DO: Deleting active tree
}

void XMLTree::parse(std::istream &)
{
    //TO-DO: Parsing from stream to tree
}

void XMLTree::set_open_file_name(const String &file_name)
{
    open_file_name = file_name;
}
String XMLTree::get_open_file_name() const
{
    return open_file_name;
}

//TO-DO: more getters&setters

void XMLTree::save()
{
    //TO-DO: write to current file
}

void XMLTree::save_as(const String &file_name)
{
    set_open_file_name(file_name);
    save();
}