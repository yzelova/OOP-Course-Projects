#pragma once
#include <memory>

template <typename T>
using Pointer = std::unique_ptr<T>;

class JSONStructure
{
public:
	Pointer<JSONStructure> clone() const;
};