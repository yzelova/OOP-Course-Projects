#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLSetCommand
class XMLSetCommand : public XMLCommand
{
public:
	/**XMLSetCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * first String is element id,
	 * second String is attribute key,
	 * third String is attribute value
	 */
	XMLSetCommand(XMLTree*, const String&, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_key{};
	String m_value{};
};