#pragma once
#include "JSONCommand.hpp"

class InvalidCommand : public JSONCommand
{
public:
	InvalidCommand() = default;
	InvalidCommand(const String&);
	virtual void execute() final;

private:
	String m_message{ "Invalid operation." };
};