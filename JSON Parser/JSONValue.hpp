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
	JSONValue(const Vector<Pair<String, Pointer<JSONValue>>>&);
	JSONValue(const Vector<JSONValue>&);
	JSONValue(const JSONValue&);
	JSONValue& operator=(const JSONValue&);
	~JSONValue() = default;
	std::variant<
		bool,
		String,
		double,
		Vector<Pair<String, Pointer<JSONValue>>>,
		Vector<JSONValue>> get_value();
	Pointer<JSONValue> clone() const;
	void print_tabs(std::ostream&, size_t depth) const;
	void print(std::ostream&, size_t) const;
private:
	enum class Type
	{
		b, 
		s,
		n,
		obj,
		ar,
		nul
	};
	Type t{ Type::n };
	bool boolean{};
	String string{};
	double number{};
	Vector<Pair<String, Pointer<JSONValue>>> object{};
	Vector<JSONValue> arr{};
};