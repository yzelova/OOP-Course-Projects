#include "Parser.hpp"
#include <string>
#include <cctype>

using String = std::string;

Parser::Parser(const String &raw_string) : m_raw_string{raw_string}
{
}

String Parser::find_string(size_t from) const
{
    static String rt{};
    if (iswspace(m_raw_string[from]))
        return rt;
    rt += m_raw_string[from];
    return find_string(from + 1);
}

size_t Parser::find_next_pos(size_t from) const
{
    if (iswspace(m_raw_string[from]))
    {
        return find_next_pos(from + 1);
    }
    else
    {
        return from;
    }
}