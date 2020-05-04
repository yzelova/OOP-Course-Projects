#include "CommandParser.hpp"
#include "XMLCommands.hpp"
#include "XMLTree.hpp"
#include "../Parser.hpp"
#include <string>
#include <algorithm>
#include <iostream>

CommandParser::CommandParser(const String &raw_string, XMLTree *tree) : Parser(raw_string)

{
    m_tree = tree->clone();
}
ICommand *CommandParser::parse_command() const
{
    size_t pos{find_next_pos(0)};
    String operation{find_string(pos)};
    if (operation == "open")
    {
        pos = find_next_pos(pos + operation.length());
        String file_name{find_string(pos)};
        if (file_name == "")
            return new InvalidCommand{};
        else
            return new XMLOpenCommand{file_name, m_tree};
    }
    if (operation == "close")
    {
        return new XMLCloseCommand{m_tree};
    }
    if (operation == "save")
    {
        pos = find_next_pos(pos + operation.length());
        String save_as{find_string(pos)};
        if (save_as == "")
            return new XMLSaveCommand{};
        else
        {
            pos = find_next_pos(pos + save_as.length());
            String file_name{find_string(pos)};
            return new XMLSaveAsCommand{file_name, m_tree};
        }
    }
    if (operation == "help")
    {
        return new XMLHelpCommand{};
    }
    if (operation == "exit")
    {
        return new ExitCommand{};
    }
    return new InvalidCommand{};

    //TO-DO: XML Commands Parse
}

CommandParser &CommandParser::operator=(const CommandParser &other)
{
    CommandParser temp{other};
    using std::swap;
    swap(temp.m_tree, m_tree);
    return *this;
}
CommandParser::CommandParser(const CommandParser &other) : Parser{}, m_tree{other.m_tree->clone()}
{
}