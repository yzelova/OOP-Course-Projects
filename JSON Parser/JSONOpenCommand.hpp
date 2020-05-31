#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

///Implementing Command Patter JSONOpenCommand
class JSONOpenCommand :public JSONCommand
{
public:
	/**JSONOpenCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * String holds file name
	 */
	JSONOpenCommand(const String&, JSONStructure*);
	virtual void execute() final;
private:
	String m_file_name{};
};