#include "XMLSaveCommand.hpp"
#include "InvalidCommand.hpp"

XMLSaveCommand::XMLSaveCommand(XMLTree* tree) : XMLCommand(tree)
{
}


void XMLSaveCommand::execute()
{
	if (!m_tree->empty())
	{
		m_tree->save();
	}
	else
	{
		InvalidCommand cmd{ "No file is currently open." };
		cmd.execute();
	}
}