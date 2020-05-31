#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

///Implementing Command Patter JSONSetCommand
class JSONSetCommand :public JSONCommand
{
public:
	/**JSONSaveAsCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * first String is <path> variable,
	 * second String is <string> varable
	 */
	JSONSetCommand(JSONStructure*, const String&, const String&);
	virtual void execute() final;
private:
	String m_string{};
	String m_path{};
};