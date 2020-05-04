#include <string>

#pragma once

using String = std::string;

class Parser
{
public:
    Parser() = default;
    Parser(const String &);
    virtual ~Parser() = default;

protected:
    String find_string(size_t) const;
    size_t find_next_pos(size_t) const;

private:
    String m_raw_string{};
};