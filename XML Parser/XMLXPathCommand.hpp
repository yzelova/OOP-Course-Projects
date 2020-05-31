#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLXPathCommand
class XMLXPathCommand : public XMLCommand
{
public:
	/**XMLXPathCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * first String is element id,
	 * second String is attribute xpath
	 */
	XMLXPathCommand(XMLTree*, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_xpath{};
};