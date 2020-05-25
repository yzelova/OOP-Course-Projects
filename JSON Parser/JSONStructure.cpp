#include "JSONStructure.hpp"

Pointer<JSONStructure> JSONStructure::clone() const
{
	return std::make_unique<JSONStructure>(*this);
}