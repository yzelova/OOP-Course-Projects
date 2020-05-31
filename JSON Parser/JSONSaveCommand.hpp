#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include <string>
#include <memory>
#include <optional>

template<typename T>
using Optional = std::optional<T>;

///Implementing Command Patter JSONSaveCommand
class JSONSaveCommand :public JSONCommand
{
public:
	/**JSONSaveCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	JSONSaveCommand(JSONStructure*);
	/**JSONSaveCommand ctor()
	 * JSONStructure* is pointer to currently loaded JSON Structure,
	 * String is <path> variable
	 */
	JSONSaveCommand(JSONStructure*, const String&);
	virtual void execute() final;
private:
	Optional<String> m_path{};
};