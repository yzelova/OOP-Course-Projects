#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter ExitCommand
class ExitCommand : public XMLCommand
{
public:
	ExitCommand() = default;
	virtual void execute() final;
};