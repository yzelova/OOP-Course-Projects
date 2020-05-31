#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLChildCommand
class XMLChildCommand : public XMLCommand
{
public:
	/**XMLChildCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * String is element id,
	 * int is which child to choose
	 */
	XMLChildCommand(XMLTree*, const String&, int);
	virtual void execute() final;

private:
	String m_id{};
	int m_n{};
};