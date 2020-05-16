#include "Core.hpp"
#include "CommandParser.hpp"
#include <iostream>

void Core::start()
{
	String line{};
	while (std::getline(std::cin, line))
	{
		CommandParser parser{ line, &m_tree };
		ICommand* cmd = parser.parse_command();
		cmd->execute();
		if (dynamic_cast<const ExitCommand*>(cmd) != nullptr)
		{
			delete cmd;
			break;
		}
		delete cmd;
	}
}