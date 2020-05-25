#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>


class JSONCloseCommand :public JSONCommand
{
public:
	JSONCloseCommand(const Pointer<JSONStructure>&);
	virtual void execute() final;
};