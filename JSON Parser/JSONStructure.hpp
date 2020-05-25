#pragma once
#include "JSONValue.hpp"
#include <memory>

template <typename T>
using Pointer = std::unique_ptr<T>;

class JSONStructure
{
public:
	JSONStructure() = default;
	JSONStructure(const JSONValue&);
	Pointer<JSONStructure> clone() const;
private:
	JSONValue m_base{};
};