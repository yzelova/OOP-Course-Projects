#include "Parser.hpp"
#include "XMLTree.hpp"

struct XPathParser : public Parser
{
public:
	XPathParser(const XMLElement&, const String& );
	Vector<XMLElement> parse();
private:
	Vector<XMLElement> parse_from(size_t position);
	XMLElement m_element{};
	String m_query{};
};