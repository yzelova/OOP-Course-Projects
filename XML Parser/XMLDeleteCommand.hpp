#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLDeleteCommand
class XMLDeleteCommand : public XMLCommand
{
public:
	/**XMLDeleteCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * first String is element id,
	 * second String is attribute key 
	 */
	XMLDeleteCommand(XMLTree*, const String&, const String&);
	virtual void execute() final;

private:
	String m_id{};
	String m_key{};
};