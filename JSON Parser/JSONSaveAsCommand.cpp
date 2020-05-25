#include "JSONSaveAsCommand.hpp"

JSONSaveAsCommand::JSONSaveAsCommand(const String& file_name, const Pointer<JSONStructure>& str) :
	JSONCommand(str),
	m_file_name{ file_name },
	m_path{}
{

}

JSONSaveAsCommand::JSONSaveAsCommand(const String& file_name, const Pointer<JSONStructure>& str, const String& path) :
	JSONCommand(str),
	m_file_name{file_name},
	m_path{ path }
{
}

void JSONSaveAsCommand::execute()
{

}