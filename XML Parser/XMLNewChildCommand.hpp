#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLNewChildCommand
class XMLNewChildCommand : public XMLCommand
{
public:
	/**XMLNewChildCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * String is element id
	 */
	XMLNewChildCommand(XMLTree*, const String&);
	virtual void execute() final;

private:
	String m_id{};
};