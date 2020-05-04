#include "XMLCommands.hpp"
#include <iostream>

XMLOpenCommand::XMLOpenCommand(const String &file_name, XMLTree *tree) : OpenCommand(file_name),
                                                                         m_tree{tree->clone()}
{
}

void XMLOpenCommand::execute()
{
    String file_name = get_file_name();
    std::ifstream in{file_name};
    m_tree->set_open_file_name(file_name);
    m_tree->parse(in);
    in.close();
}

XMLCloseCommand::XMLCloseCommand(XMLTree *tree) : m_tree(tree->clone())
{
}
void XMLCloseCommand::execute()
{
    m_tree->erase();
}

void XMLExitCommand::execute()
{
}