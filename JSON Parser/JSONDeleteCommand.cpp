#include "JSONDeleteCommand.hpp"

JSONDeleteCommand::JSONDeleteCommand(const Pointer<JSONStructure>& str, const String& path) :
	JSONCommand(str),
	m_path{ path }
{

}

void JSONDeleteCommand::execute()
{

}