#include "Core.hpp"
#include "CommandParser.hpp"
#include <iostream>

void Core::start() 
{
    String line{};
    while (std::getline(std::cin, line))
    {
        CommandParser parser{line, &m_tree};
        ICommand *cmd = parser.parse_command();
        if (dynamic_cast<const XMLExitCommand *>(cmd) != nullptr)
            break;
        cmd->execute();
    }
}