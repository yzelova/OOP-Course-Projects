#include "JSONSetCommand.hpp"

JSONSetCommand::JSONSetCommand(const Pointer<JSONStructure>& str, const String& string, const String& path) :
	JSONCommand(str),
	m_string{ string },
	m_path{ path }
{

}

void JSONSetCommand::execute()
{

}