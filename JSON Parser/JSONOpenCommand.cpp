#include "JSONOpenCommand.hpp"

JSONOpenCommand::JSONOpenCommand(const String& file_name, const Pointer<JSONStructure>& str) :
	JSONCommand(str),
	m_file_name{ file_name }
{

}

void JSONOpenCommand::execute()
{
	
}