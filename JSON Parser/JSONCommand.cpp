#include "JSONCommand.hpp"

JSONCommand::JSONCommand(const Pointer<JSONStructure>& str) : m_str{ str->clone() }
{

}