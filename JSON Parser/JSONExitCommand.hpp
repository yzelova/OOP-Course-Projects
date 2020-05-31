#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

///Implementing Command Patter JSONExitCommand
class JSONExitCommand :public JSONCommand
{
public:
	virtual void execute() final;
};