#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLTextCommand
class XMLTextCommand : public XMLCommand
{
public:
	/**XMLTextCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * String is element id
	 */
	XMLTextCommand(XMLTree*, const String&);
	virtual void execute() final;

private:
	String m_id{};
};