#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

///Implementing Command Patter JSONCloseCommand
class JSONCloseCommand :public JSONCommand
{
public:
	/**JSONCloseCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	JSONCloseCommand(JSONStructure*);
	virtual void execute() final;
};