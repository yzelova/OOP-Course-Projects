#include "JSONMoveCommand.hpp"

JSONMoveCommand::JSONMoveCommand(JSONStructure* str, const String& from, const String& to) :
	JSONCommand(str),
	m_from{ from },
	m_to{ to }
{

}

void JSONMoveCommand::execute()
{

}