#include "JSONSearchCommand.hpp"

JSONSearchCommand::JSONSearchCommand(const Pointer<JSONStructure>& str, const String& key) :
	JSONCommand(str),
	m_key{key}
{

}

void JSONSearchCommand::execute()
{

}