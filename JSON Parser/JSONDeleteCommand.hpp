#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Implementing Command Patter JSONDeleteCommand
class JSONDeleteCommand :public JSONCommand
{
public:
	/**JSONDeleteCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * String holds <path> variable
	 */
	JSONDeleteCommand(JSONStructure*, const String&);
	virtual void execute() final;
private:
	String m_path{};
};