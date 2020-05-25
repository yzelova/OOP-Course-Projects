#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

class JSONPrintCommand :public JSONCommand
{
public:
	JSONPrintCommand(const Pointer<JSONStructure>&);
	virtual void execute() final;
};