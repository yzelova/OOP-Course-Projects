#include "JSONOpenCommand.hpp"
#include "JSONParser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

JSONOpenCommand::JSONOpenCommand(const String& file_name, const Pointer<JSONStructure>& str) :
	JSONCommand(str),
	m_file_name{ file_name }
{

}

void JSONOpenCommand::execute()
{
	try
	{
		std::ifstream in{ m_file_name };
		std::stringstream buffer;
		buffer << in.rdbuf();
		String content = buffer.str();

		JSONParser parser{ content };
		auto structure = parser.parse();
		if (!structure)
		{
			throw std::runtime_error("An error while reading has occurred.");
		}
		std::cout << "Successfully opened " << m_file_name << ".\n";
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}