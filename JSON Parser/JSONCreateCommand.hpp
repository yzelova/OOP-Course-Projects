#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Implementing Command Patter JSONCreateCommand
class JSONCreateCommand :public JSONCommand
{
public:
	/**JSONCreateCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * first String holds <path> variable,
	 * second String holds <string> variable
	 */
	JSONCreateCommand(JSONStructure*, const String&, const String&);
	virtual void execute() final;
private:
	String m_string{};
	String m_path{};
};