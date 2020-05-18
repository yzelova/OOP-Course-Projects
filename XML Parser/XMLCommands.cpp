#include "XMLCommands.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

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

XMLChildCommand::XMLChildCommand(XMLTree* tree, const String& id, int n) : XMLCommand{ tree },
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
	if (m_tree->empty())
	{
		String file_name = get_file_name();
		std::ifstream in{ file_name };
		m_tree->set_open_file_name(file_name);
		m_tree->parse(in);
	}
	else
	{
		InvalidCommand cmd{ "Another file is currently open. Plase close it." };
		cmd.execute();
	}
}

void XMLCloseCommand::execute()
{
	if (!m_tree->empty())
	{
		m_tree->erase();
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLSaveCommand::execute()
{
	if (!m_tree->empty())
	{
		m_tree->save();
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLSaveAsCommand::execute()
{
	if (!m_tree->empty())
	{
		m_tree->save_as(m_file_name);
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLHelpCommand::execute()
{
	//TO-DO: Instructions
}

void XMLPrintCommand::execute()
{
	if (!m_tree->empty())
	{
		std::cout << *m_tree;
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLSelectCommand::execute()
{
	if (!m_tree->empty())
	{
		auto element = m_tree->get_element_by_id(m_id);
		auto attr_value = element.get_attribute_by_key(m_key);
		std::cout << "Attribute \"" << m_key << "\" value: " << attr_value << std::endl;
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}

}

void XMLSetCommand::execute()
{
	if (!m_tree->empty())
	{
		XMLElement& el = m_tree->get_element_by_id(m_id);
		el.set_attribute_by_key(m_key, m_value);
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLChildrenCommand::execute()
{
	if (!m_tree->empty())
	{
		XMLElement element = m_tree->get_element_by_id(m_id);
		Vector<XMLElement> children = element.get_children();
		std::for_each(children.begin(), children.end(), [](const XMLElement& el) {
			std::cout << el;
		});
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}

}

void XMLChildCommand::execute()
{
	if (!m_tree->empty())
	{
		XMLElement element = m_tree->get_element_by_id(m_id);
		Vector<XMLElement> children = element.get_children();
		if (m_n > children.size())
		{
			InvalidCommand cmd{ "Element does not have that many children." };
			cmd.execute();
			return;
		}
		XMLElement child = children[children.size() - m_n];
		std::cout << "ID: " << child.get_id() << std::endl;
		std::cout << "Name: " << child.get_name() << std::endl;
		Vector<Pair> attr = child.get_attributes();
		if (!attr.empty())
		{
			std::cout << "Attributes: ";
			std::for_each(attr.begin(), attr.end(), [](const Pair& p)
			{
				std::cout << p.first << "=" << p.second << " ";
			});
			std::cout << std::endl;
		}
		String text = child.get_text();
		if (!text.empty())
		{
			std::cout << "Text: " << text << std::endl;
		}
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLTextCommand::execute()
{
	if (!m_tree->empty())
	{
		XMLElement element = m_tree->get_element_by_id(m_id);
		std::cout << element.get_text() << std::endl;
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}

void XMLNewChildCommand::execute()
{
	XMLElement& el = m_tree->get_element_by_id(m_id);
	el.add_child();
	
}

void XMLDeleteCommand::execute()
{
	XMLElement& el = m_tree->get_element_by_id(m_id);
	el.remove_attribute(m_key);
	
}

void XMLXPathCommand::execute()
{
	//TO-DO
	//Get Elements: slelect element & vector<XMLElement> elements = element.xpath();
	//std::cout << elements;
}