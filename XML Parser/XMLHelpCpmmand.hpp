#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLHelpCommand
class XMLHelpCommand : public XMLCommand
{
public:
	virtual void execute() final;
	virtual ~XMLHelpCommand() = default;
};