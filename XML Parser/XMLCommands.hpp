#include "XMLTree.hpp"
#include "ICommand.hpp"

#pragma once

class XMLCommand
{
public:
	XMLCommand() = default;
	XMLCommand(XMLTree*);
	virtual ~XMLCommand() = default;

protected:
	XMLTree* m_tree;
};

class InvalidCommand : public ICommand
{
public:
	InvalidCommand() = default;
	InvalidCommand(const String&);
	virtual void execute() final;

private:
	String m_message{ "Invalid operation." };
};

class ExitCommand : public ICommand
{
public:
	ExitCommand() = default;
	virtual void execute() final;
};

class XMLOpenCommand : public ICommand,
	public XMLCommand
{
public:
	XMLOpenCommand() = default;
	XMLOpenCommand(const String&, XMLTree*);
	virtual void execute() final;
	virtual ~XMLOpenCommand() = default;

	String get_file_name() const;
	void set_file_name(const String&);

private:
	String m_file_name;
};

class XMLCloseCommand : public ICommand, public XMLCommand
{
public:
	XMLCloseCommand() = default;
	XMLCloseCommand(XMLTree*);
	virtual void execute() final;
	virtual ~XMLCloseCommand() = default;
};

class XMLSaveCommand : public ICommand, public XMLCommand
{
public:
	XMLSaveCommand() = default;
	XMLSaveCommand(XMLTree*);
	virtual void execute() final;
	virtual ~XMLSaveCommand() = default;
};

class XMLSaveAsCommand : public ICommand, public XMLCommand
{
public:
	XMLSaveAsCommand() = default;
	XMLSaveAsCommand(const String&, XMLTree*);
	virtual void execute() final;
	virtual ~XMLSaveAsCommand() = default;

	String get_file_name() const;
	void set_file_name(const String&);

private:
	String m_file_name;
};

class XMLHelpCommand : public ICommand
{
public:
	virtual void execute() final;
	virtual ~XMLHelpCommand() = default;
};

class XMLPrintCommand : public ICommand, public XMLCommand
{
public:
	XMLPrintCommand() = default;
	XMLPrintCommand(XMLTree*);
	virtual void execute() final;
	virtual ~XMLPrintCommand() = default;
};

class XMLSelectCommand : public ICommand, public XMLCommand
{
public:
	XMLSelectCommand(XMLTree*, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_key{};
};

class XMLSetCommand : public ICommand, public XMLCommand
{
public:
	XMLSetCommand(XMLTree*, const String&, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_key{};
	String m_value{};
};

class XMLChildrenCommand : public ICommand, public XMLCommand
{
public:
	XMLChildrenCommand(XMLTree*, const String&);
	virtual void execute() final;

private:
	String m_id{};
};

class XMLChildCommand : public ICommand, public XMLCommand
{
public:
	XMLChildCommand(XMLTree*, const String&, size_t);
	virtual void execute() final;

private:
	String m_id{};
	size_t m_n{};
};

class XMLTextCommand : public ICommand, public XMLCommand
{
public:
	XMLTextCommand(XMLTree*, const String&);
	virtual void execute() final;

private:
	String m_id{};
};

class XMLDeleteCommand : public ICommand, public XMLCommand
{
public:
	XMLDeleteCommand(XMLTree*, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_key{};
};

class XMLNewChildCommand : public ICommand, public XMLCommand
{
public:
	XMLNewChildCommand(XMLTree*, const String&);
	virtual void execute() final;

private:
	String m_id{};
};

class XMLXPathCommand : public ICommand, public XMLCommand
{
public:
	XMLXPathCommand(XMLTree*, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_xpath{};
};