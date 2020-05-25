#include "JSONSaveCommand.hpp"

JSONSaveCommand::JSONSaveCommand(const Pointer<JSONStructure>& str) :
	JSONCommand(str),
	m_path{}
{

}

JSONSaveCommand::JSONSaveCommand(const Pointer<JSONStructure>& str, const String& path) :
	JSONCommand(str),
	m_path{ path }
{
}

void JSONSaveCommand::execute()
{

}