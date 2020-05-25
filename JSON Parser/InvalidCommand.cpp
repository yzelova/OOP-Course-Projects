#include "InvalidCommand.hpp"
#include <iostream>

InvalidCommand::InvalidCommand(const String& message) : m_message{ message }
{
}

void InvalidCommand::execute()
{
	std::cout << m_message << "\n";
}