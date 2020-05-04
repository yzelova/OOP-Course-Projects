#include "XMLCommands.hpp"
#include <iostream>

//Rule of 3 - XMLCommand
XMLCommand::XMLCommand(XMLTree *tree) : m_tree{tree->clone()}
{
}
XMLCommand &XMLCommand::operator=(const XMLCommand &other)
{
    XMLCommand temp{other};
    std::swap(temp.m_tree, m_tree);
    return *this;
}
XMLCommand::XMLCommand(const XMLCommand &other) : m_tree{other.m_tree->clone()}
{
}
XMLCommand::~XMLCommand()
{
    delete m_tree;
}

//Ctors
XMLOpenCommand::XMLOpenCommand(const String &file_name, XMLTree *tree) : OpenCommand(file_name),
                                                                         XMLCommand(tree)
{
}

XMLCloseCommand::XMLCloseCommand(XMLTree *tree) : XMLCommand(tree)
{
}

XMLSaveCommand::XMLSaveCommand(XMLTree *tree) : XMLCommand(tree)
{
}

XMLSaveAsCommand::XMLSaveAsCommand(const String &file_name, XMLTree *tree) : SaveAsCommand(file_name),
                                                                             XMLCommand(tree)
{
}

//execute
void XMLOpenCommand::execute()
{
    String file_name = get_file_name();
    std::ifstream in{file_name};
    m_tree->set_open_file_name(file_name);
    m_tree->parse(in);
    in.close();
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