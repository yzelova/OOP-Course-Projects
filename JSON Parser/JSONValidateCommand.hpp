#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

///Implementing Command Patter JSONValidateCommand
class JSONValidateCommand :public JSONCommand
{
public:
	/**JSONValidate ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	JSONValidateCommand(JSONStructure*);
	virtual void execute() final;
};