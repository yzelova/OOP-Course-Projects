#include "JSONSaveCommand.hpp"

JSONSaveCommand::JSONSaveCommand(JSONStructure* str) :
	JSONCommand(str),
	m_path{}
{

}

JSONSaveCommand::JSONSaveCommand(JSONStructure* str, const String& path) :
	JSONCommand(str),
	m_path{ path }
{
}

void JSONSaveCommand::execute()
{

}