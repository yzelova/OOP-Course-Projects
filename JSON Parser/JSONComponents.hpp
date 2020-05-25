#pragma once

#include <variant>
#include <memory>
#include <string>
#include <vector>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

template<typename T>
using Vector = std::vector<T>;

class JSONValue;
class JSONElement;

class JSONArray
{
public:
	JSONArray() = default;
	JSONArray(Vector<Pointer<JSONElement>>&);
	Pointer<JSONArray> clone() const;
private:
	Vector<Pointer<JSONElement>> m_elements{};
};

class JSONElement
{
public:
	JSONElement() = default;
	JSONElement(const Pointer<JSONValue>&);
	Pointer<JSONElement> clone() const;
private:
	Pointer<JSONValue> m_value;
};


class JSONMember
{
public:
private:
	String key{};
	Pointer<JSONElement> element{};
};

class JSONObject
{
public:
private:
	Vector<Pointer<JSONMember>> memebers{};
};


class JSONValue
{
public:
	JSONValue() = default;
	JSONValue(const std::variant<JSONArray, JSONObject, String, double, bool>&);
	Pointer<JSONValue> clone() const;
private:
	std::variant<JSONArray, JSONObject, String, double, bool> m_value{};
};