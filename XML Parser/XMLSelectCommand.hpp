#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLSelectCommand
class XMLSelectCommand : public XMLCommand
{
public:
	/**XMLSelectCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * first String is element id,
	 * second String is attribute key
	 */
	XMLSelectCommand(XMLTree*, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_key{};
};