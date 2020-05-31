#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLOpenCommand
class XMLOpenCommand : public XMLCommand
{
public:
	XMLOpenCommand() = default;
	/**XMLOpenCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * String is element file name
	 */
	XMLOpenCommand(const String&, XMLTree*);
	virtual void execute() final;
	virtual ~XMLOpenCommand() = default;

	///file name accessor
	String get_file_name() const;
	///file name mutator
	void set_file_name(const String&);

private:
	String m_file_name;
};