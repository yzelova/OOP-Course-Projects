#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLCloseCommand
class XMLCloseCommand : public XMLCommand
{
public:
	XMLCloseCommand() = default;
	/**XMLCloseCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree
	 */
	XMLCloseCommand(XMLTree*);
	virtual void execute() final;
	virtual ~XMLCloseCommand() = default;
};

