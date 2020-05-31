#pragma once
#include "JSONCommand.hpp"
#include "JSONStructure.hpp"
#include "Parser.hpp"

///class for parsing command line commands
class CommandParser : public Parser
{
public:
	/**CommandParser ctor()
	 * String is raw command,
	 * JSONStructure* is pointer to currently loaded JSON Structure
	 */
	CommandParser(const String&, JSONStructure*);
	///CommandParser ~dtor()
	virtual ~CommandParser() = default;

	///parses command line command
	Pointer<JSONCommand> parse_command();

private:
	JSONStructure* m_structure{};
};