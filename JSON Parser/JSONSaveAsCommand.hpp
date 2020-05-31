#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>
#include <optional>

template<typename T>
using Optional = std::optional<T>;

///Implementing Command Patter JSONSaveAsCommand
class JSONSaveAsCommand :public JSONCommand
{
public:
	/**JSONSaveAsCommand ctor()
	 * String is file name
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	JSONSaveAsCommand(const String&, JSONStructure*);
	/**JSONSaveAsCommand ctor()
	 * first String is file name
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * second String is <path> variable
	 */
	JSONSaveAsCommand(const String&, JSONStructure*, const String&);
	virtual void execute() final;
private:
	String m_file_name{};
	Optional<String> m_path{};
};