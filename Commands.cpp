#include "Commands.hpp"

OpenCommand::OpenCommand(const String &file_name) : m_file_name{file_name}
{
}

String OpenCommand::get_file_name() const
{
    return m_file_name;
}

void OpenCommand::set_file_name(const String &file_name)
{
    m_file_name = file_name;
}

SaveAsCommand::SaveAsCommand(const String &file_name) : m_file_name{file_name}
{
}

String SaveAsCommand::get_file_name() const
{
    return m_file_name;
}

void SaveAsCommand::set_file_name(const String &file_name)
{
    m_file_name = file_name;
}