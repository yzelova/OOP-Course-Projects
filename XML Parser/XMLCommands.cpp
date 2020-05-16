#include "XMLCommands.hpp"
#include <iostream>
#include <fstream>

//Ctors
InvalidCommand::InvalidCommand(const String& message) : m_message{ message }
{
}
XMLCommand::XMLCommand(XMLTree* tree) : m_tree{ tree }
{
}

XMLOpenCommand::XMLOpenCommand(const String& file_name, XMLTree* tree) : XMLCommand{ tree },
m_file_name{ file_name }
{
}

XMLCloseCommand::XMLCloseCommand(XMLTree* tree) : XMLCommand(tree)
{
}

XMLSaveCommand::XMLSaveCommand(XMLTree* tree) : XMLCommand(tree)
{
}

XMLSaveAsCommand::XMLSaveAsCommand(const String& file_name, XMLTree* tree) : XMLCommand{ tree },
m_file_name{ file_name }

{
}

XMLPrintCommand::XMLPrintCommand(XMLTree* tree) : XMLCommand{ tree }
{
}

XMLSelectCommand::XMLSelectCommand(XMLTree* tree, const String& id, const String& key) : XMLCommand{ tree },
m_id{ id },
m_key{ key }
{
}

XMLSetCommand::XMLSetCommand(XMLTree* tree, const String& id, const String& key, const String& value) : XMLCommand{ tree },
m_id{ id },
m_key{ key },
m_value{ value }
{
}

XMLChildrenCommand::XMLChildrenCommand(XMLTree* tree, const String& id) : XMLCommand{ tree },
m_id{ id }
{
}

XMLChildCommand::XMLChildCommand(XMLTree* tree, const String& id, size_t n) : XMLCommand{ tree },
m_id{ id },
m_n{ n }
{
}

XMLTextCommand::XMLTextCommand(XMLTree* tree, const String& id) : XMLCommand{ tree },
m_id{ id }
{
}

XMLNewChildCommand::XMLNewChildCommand(XMLTree* tree, const String& id) : XMLCommand{ tree },
m_id{ id }
{
}

XMLDeleteCommand::XMLDeleteCommand(XMLTree* tree, const String& id, const String& key) : XMLCommand{ tree },
m_id{ id },
m_key{ key }
{
}

XMLXPathCommand::XMLXPathCommand(XMLTree* tree, const String& id, const String& xpath) : XMLCommand{ tree },
m_id{ id },
m_xpath{ xpath }
{
}

//accessors
String XMLOpenCommand::get_file_name() const
{
	return m_file_name;
}
String XMLSaveAsCommand::get_file_name() const
{
	return m_file_name;
}

//mutators
void XMLOpenCommand::set_file_name(const String& file_name)
{
	m_file_name = file_name;
}
void XMLSaveAsCommand::set_file_name(const String& file_name)
{
	m_file_name = file_name;
}

//execute
void InvalidCommand::execute()
{
	std::cout << m_message << "\n";
}
void ExitCommand::execute()
{
	std::cout << "Goodbye!\n";
}
void XMLOpenCommand::execute()
{
	String file_name = get_file_name();
	std::ifstream in{ file_name };
	m_tree->set_open_file_name(file_name);
	m_tree->parse(in);
}

void XMLCloseCommand::execute()
{
	m_tree->erase();
}

void XMLSaveCommand::execute()
{
	m_tree->save();
}

void XMLSaveAsCommand::execute()
{
	m_tree->save_as(get_file_name());
}

void XMLHelpCommand::execute()
{
	//TO-DO: Instructions
}

void XMLPrintCommand::execute()
{
	std::cout << *m_tree << std::endl;
}

void XMLSelectCommand::execute()
{
	//TO-DO
	// Select Element: XMLElement element = m_tree->select_element(id, key);
	// Print Element: std::cout<<element<<std::endl;
}

void XMLSetCommand::execute()
{
	//TO-DO
	//Set Element
}

void XMLChildrenCommand::execute()
{
	//TO-DO
	//Get Children: vector<XMLElement> children = m_tree->get_children(id);
	//override vector<XMLElement> << operator
	//std::cout << children;
}

void XMLChildCommand::execute()
{
	//TO-DO
	//Get Child: Element child = m_tree->get_child(id, n);
	//std::cout << child;
}

void XMLTextCommand::execute()
{
	//TO-DO
	//Get Text: String text = m_tree->get_text(id);
	//std::cout << text;
}

void XMLNewChildCommand::execute()
{
	//TO-DO
	//Create Child: select element & element.create_child();
}

void XMLDeleteCommand::execute()
{
	//TO-DO
	//Delete Attribute: select element & element.delete_attribute();
}

void XMLXPathCommand::execute()
{
	//TO-DO
	//Get Elements: slelect element & vector<XMLElement> elements = element.xpath();
	//std::cout << elements;
}