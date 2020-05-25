#include "JSONStructure.hpp"

JSONStructure::JSONStructure(const JSONValue& value) : m_base{value}
{
}

Pointer<JSONStructure> JSONStructure::clone() const
{
	return std::make_unique<JSONStructure>(m_base);
}