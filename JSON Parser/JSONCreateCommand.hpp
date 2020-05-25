#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

class JSONCreateCommand :public JSONCommand
{
public:
	JSONCreateCommand(const Pointer<JSONStructure>&, const String&, const String&);
	virtual void execute() final;
private:
	String m_string{};
	String m_path{};
};