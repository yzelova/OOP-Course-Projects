#pragma once

#include "XMLCommand.hpp"

///Implementing Command Patter XMLSaveAsCommand
class XMLSaveAsCommand : public XMLCommand
{
public:
	XMLSaveAsCommand() = default;
	/**XMLSaveAsCommand ctor()
	 * XMLTree* is pointer to currently loaded XML Tree,
	 * String is file name
	 */
	XMLSaveAsCommand(const String&, XMLTree*);
	virtual void execute() final;
	virtual ~XMLSaveAsCommand() = default;

	String get_file_name() const;
	void set_file_name(const String&);

private:
	String m_file_name;
};