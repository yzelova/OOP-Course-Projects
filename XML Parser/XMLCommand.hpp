#pragma once
#include "ICommand.hpp"
#include "XMLTree.hpp"

///Interface for implementing XML Commands
class XMLCommand : public ICommand
{
public:
	XMLCommand() = default;
	/**XMLCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree
	 */
	XMLCommand(XMLTree*);
	virtual void execute() = 0;
	virtual ~XMLCommand() = default;

protected:
	XMLTree* m_tree{};
};