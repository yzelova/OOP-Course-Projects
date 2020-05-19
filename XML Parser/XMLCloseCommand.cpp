#include "XMLCloseCommand.hpp"
#include "InvalidCommand.hpp"

XMLCloseCommand::XMLCloseCommand(XMLTree* tree) : XMLCommand(tree)
{
}

void XMLCloseCommand::execute()
{
	if (!m_tree->empty())
	{
		m_tree->erase();
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}