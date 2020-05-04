#include "ICommand.hpp"
#include <string>
#include <fstream>

#pragma once

using String = std::string;

class OpenCommand : public ICommand
{
public:
    OpenCommand() = default;
    OpenCommand(const String &);
    virtual ~OpenCommand() = default;

protected:
    String get_file_name() const;
    void set_file_name(const String &);

private:
    String m_file_name{};
};

class CloseCommand : public ICommand
{
public:
    virtual ~CloseCommand() = default;
};

class SaveCommand : public ICommand
{
public:
    virtual ~SaveCommand() = default;
};

class SaveAsCommand : public ICommand
{
public:
    SaveAsCommand() = default;
    SaveAsCommand(const String &);
    virtual ~SaveAsCommand() = default;

protected:
    String get_file_name() const;
    void set_file_name(const String &);

private:
    String m_file_name{};
};

class HelpCommand : public ICommand
{
public:
    virtual ~HelpCommand() = default;
};

class ExitCommand : public ICommand
{
public:
    virtual ~ExitCommand() = default;
};