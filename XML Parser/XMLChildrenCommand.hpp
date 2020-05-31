#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLChildrenCommand
class XMLChildrenCommand : public XMLCommand
{
public:
	/**XMLChildrenCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * String is element id
	 */
	XMLChildrenCommand(XMLTree*, const String&);
	virtual void execute() final;

private:
	String m_id{};
};