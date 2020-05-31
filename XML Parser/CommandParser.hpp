#pragma once
#include "XMLCommand.hpp"
#include "XMLTree.hpp"
#include "Parser.hpp"

using String = std::string;

///class for parsing command line commands
class CommandParser : public Parser
{
public:
	/**CommandParser ctor()
	 * String is raw command,
	 * XMLTree* is pointer to currently loaded XML Tree
	 */
	CommandParser(const String&, XMLTree*);
	virtual ~CommandParser() = default;

	///parses command line command
	XMLCommand* parse_command();

private:
	XMLTree* m_tree{};
};