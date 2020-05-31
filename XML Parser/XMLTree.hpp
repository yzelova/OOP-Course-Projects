#pragma once
#include <string>
#include "XMLElement.hpp"

#pragma once

using String = std::string;

///class to represent XML Tree
class XMLTree
{
public:
	XMLTree() = default;
	/** XMLTree ctor(),
	 * String is file name to be associated with the tree
	 */
	XMLTree(const String&);

	///erases all tree contents
	void erase();
	///parses input stream content to XML tree
	void parse(std::istream&);
	///saves loaded tree to currently open file
	void save();
	///saves loaded tree to file with name String
	void save_as(const String&);

	///checks if the tree is empty
	bool empty() const;

	///sets root of tree
	void set_root(const XMLElement&);

	///finds suitable ids for all elements
	void set_ids();

	///gets reference to element with id equal to String
	XMLElement& get_element_by_id(const String&);

	friend std::ostream& operator<<(std::ostream&, const XMLTree&); 

	///mutator for file name
	void set_open_file_name(const String&);
	///accessor for file name
	String get_open_file_name() const;

private:

	String open_file_name{ "" };
	XMLElement m_root{};
};