#pragma once
#include "ICommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Interface for JSON Command
class JSONCommand : public ICommand
{
public:
	JSONCommand() = default;
	/**JSONCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	JSONCommand(JSONStructure*);
protected:
	JSONStructure* m_str{};
};