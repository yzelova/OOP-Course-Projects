#include "JSONSearchCommand.hpp"

JSONSearchCommand::JSONSearchCommand(JSONStructure* str, const String& key) :
	JSONCommand(str),
	m_key{key}
{

}

void JSONSearchCommand::execute()
{

}