#include "XMLTree.hpp"
#include "XMLParser.hpp"
#include <iostream>

XMLTree::XMLTree(const String& file_name) : open_file_name{ file_name }
{
}

void XMLTree::print() const
{
	m_root.print(0);
}

void XMLTree::erase()
{
	open_file_name = "";
	//TO-DO: Deleting active tree
}

void XMLTree::parse(std::istream& in)
{
	XMLParser parser{};
	parser.read(in);
	parser.parse(this);
	print();
}

void XMLTree::set_open_file_name(const String& file_name)
{
	open_file_name = file_name;
}
String XMLTree::get_open_file_name() const
{
	return open_file_name;
}

void XMLTree::set_root(const XMLElement& root)
{
	m_root = root;
}

//TO-DO: more getters&setters

void XMLTree::save()
{
	//TO-DO: write to current file
}

void XMLTree::save_as(const String& file_name)
{
	set_open_file_name(file_name);
	save();
}

std::ostream& operator<<(std::ostream& out, const XMLTree&)
{
	return out;
}