#include "XMLCommands.hpp"
#include "XMLTree.hpp"
#include "../Parser.hpp"

#pragma once

using String = std::string;

class CommandParser : public Parser
{
public:
    CommandParser() = default;
    CommandParser(const String &, XMLTree *);
    CommandParser &operator=(const CommandParser &);
    CommandParser(const CommandParser &);
    virtual ~CommandParser() = default;
    ICommand *parse_command() const;

private:
    XMLTree *m_tree{};
};