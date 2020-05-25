#pragma once

#include <string>
#include <variant>
#include <vector>
#include <memory>

using String = std::string;

template <typename T>
using Pointer = std::unique_ptr<T>;

template <typename T>
using Vector = std::vector<T>;

template <typename T, typename U>
using Pair = std::pair<T, U>;

class JSONValue
{
public:
	JSONValue();
	JSONValue(bool);
	JSONValue(const String&);
	JSONValue(double);
	JSONValue(const Pair<String, Pointer<JSONValue>>&);
	JSONValue(const Vector<JSONValue>&);
	JSONValue(const JSONValue&);
	JSONValue& operator=(const JSONValue&);
	~JSONValue() = default;
	std::variant<
		bool,
		String,
		double,
		Pair<String, Pointer<JSONValue>>,
		Vector<JSONValue>> get_value() const;
	Pointer<JSONValue> clone() const;
private:
	enum Type
	{
		b, 
		s,
		n,
		obj,
		ar,
		nul
	};
	Type t;
	bool boolean;
	String string;
	double number;
	Pair<String, Pointer<JSONValue>> object;
	Vector<JSONValue> arr;
};