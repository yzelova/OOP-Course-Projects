#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLSaveCommand
class XMLSaveCommand : public XMLCommand
{
public:
	XMLSaveCommand() = default;
	/**XMLSaveAsCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree
	 */
	XMLSaveCommand(XMLTree*);
	virtual void execute() final;
	virtual ~XMLSaveCommand() = default;
};