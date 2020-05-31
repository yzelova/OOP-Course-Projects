#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Implementing Command Patter JSONMoveCommand
class JSONMoveCommand :public JSONCommand
{
public:
	/**JSONMoveCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * first String holds <from> variable,
	 * second String holds <to> variable
	 */
	JSONMoveCommand(JSONStructure*, const String&, const String&);
	virtual void execute() final;
private:
	String m_from{};
	String m_to{};
};
