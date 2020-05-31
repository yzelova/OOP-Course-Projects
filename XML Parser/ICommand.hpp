#pragma once

///Interface for implementing Command Pattern
class ICommand
{
public:
	///executes command
	virtual void execute() = 0;
	virtual ~ICommand() = default;
};