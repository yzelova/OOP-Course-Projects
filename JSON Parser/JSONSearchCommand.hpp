#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Implementing Command Patter JSONSearchCommand
class JSONSearchCommand :public JSONCommand
{
public:
	/**JSONSearchCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * String is <key> variable
	 */
	JSONSearchCommand(JSONStructure*, const String&);
	virtual void execute() final;
private:
	String m_key{};
};