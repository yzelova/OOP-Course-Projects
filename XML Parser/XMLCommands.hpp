#include "../Commands.hpp"
#include "XMLTree.hpp"

#pragma once

class XMLCommand
{
public:
    XMLCommand() = default;
    XMLCommand(XMLTree *);
    XMLCommand &operator=(const XMLCommand &);
    XMLCommand(const XMLCommand &);
    virtual ~XMLCommand();

protected:
    XMLTree *m_tree;
};

class XMLOpenCommand : public OpenCommand, public XMLCommand
{
public:
    XMLOpenCommand() = default;
    XMLOpenCommand(const String &, XMLTree *);
    virtual void execute() final;
    virtual ~XMLOpenCommand() = default;
};

class XMLCloseCommand : public CloseCommand, public XMLCommand
{
public:
    XMLCloseCommand() = default;
    XMLCloseCommand(XMLTree *);
    virtual void execute() final;
    virtual ~XMLCloseCommand() = default;
};

class XMLSaveCommand : public SaveCommand, public XMLCommand
{
public:
    XMLSaveCommand() = default;
    XMLSaveCommand(XMLTree *);
    virtual void execute() final;
    virtual ~XMLSaveCommand() = default;
};

class XMLSaveAsCommand : public SaveAsCommand, public XMLCommand
{
public:
    XMLSaveAsCommand() = default;
    XMLSaveAsCommand(const String &, XMLTree *);
    virtual void execute() final;
    virtual ~XMLSaveAsCommand() = default;
};

class XMLHelpCommand : public HelpCommand, public XMLCommand
{
public:
    XMLHelpCommand() = default;
    virtual void execute() final;
    virtual ~XMLHelpCommand() = default;
};