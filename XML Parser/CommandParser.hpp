#include "XMLCommands.hpp"
#include "XMLTree.hpp"
#include "../Parser.hpp"

#pragma once

using String = std::string;

class CommandParser : public Parser
{
public:
    CommandParser(const String &, XMLTree *);
    virtual ~CommandParser() = default;

    ICommand *parse_command();

private:
    XMLTree *m_tree{};
};