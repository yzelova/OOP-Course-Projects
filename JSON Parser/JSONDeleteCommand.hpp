#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

class JSONDeleteCommand :public JSONCommand
{
public:
	JSONDeleteCommand(const Pointer<JSONStructure>&, const String&);
	virtual void execute() final;
private:
	String m_path{};
};