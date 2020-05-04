#include "../Commands.hpp"
#include "XMLTree.hpp"

#pragma once

class XMLOpenCommand : public OpenCommand
{
public:
    XMLOpenCommand() = default;
    XMLOpenCommand(const String &, XMLTree *);
    virtual void execute() final;
    virtual ~XMLOpenCommand() = default;

private:
    String file_name{};
    XMLTree *m_tree{};
};

class XMLCloseCommand : public CloseCommand
{
public:
    XMLCloseCommand() = default;
    XMLCloseCommand(XMLTree *);
    virtual void execute() final;
    virtual ~XMLCloseCommand() = default;

private:
    XMLTree *m_tree{};
};

class XMLExitCommand : public ExitCommand
{
public:
    XMLExitCommand() = default;
    virtual void execute() final;
    virtual ~XMLExitCommand() = default;
};