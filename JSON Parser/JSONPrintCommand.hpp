#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Implementing Command Patter JSONPrintCommand
class JSONPrintCommand :public JSONCommand
{
public:
	/**JSONPrintCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	JSONPrintCommand(JSONStructure*);
	virtual void execute() final;
};