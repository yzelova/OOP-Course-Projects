#include "JSONDeleteCommand.hpp"

JSONDeleteCommand::JSONDeleteCommand(JSONStructure* str, const String& path) :
	JSONCommand(str),
	m_path{ path }
{

}

void JSONDeleteCommand::execute()
{

}