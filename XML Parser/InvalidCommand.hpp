#pragma once
#include "XMLCommand.hpp"

///class for handling invalid behaviour
class InvalidCommand : public XMLCommand
{
public:
	InvalidCommand() = default;
	///InvalidCommand ctor() with message to show on console
	InvalidCommand(const String&);
	virtual void execute() final;

private:
	String m_message{ "Invalid operation." };
};