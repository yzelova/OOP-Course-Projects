#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLPrintCommand
class XMLPrintCommand : public XMLCommand
{
public:
	XMLPrintCommand() = default;
	/**XMLPrintCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree
	 */
	XMLPrintCommand(XMLTree*);
	virtual void execute() final;
	virtual ~XMLPrintCommand() = default;
};