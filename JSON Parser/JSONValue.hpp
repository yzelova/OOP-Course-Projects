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

enum class Type
{
	b,
	s,
	n,
	obj,
	ar,
	nul
};

///class for JSON Value
class JSONValue
{
public:
	///JSONValue ctor() with all possible value types
	JSONValue(Type, bool, const String&, double, const Vector<Pair<String, Pointer<JSONValue>>>&, const Vector<JSONValue>&);
	JSONValue();
	///JSONValue ctor() with boolean value
	JSONValue(bool);
	///JSONValue ctor() with string value
	JSONValue(const String&);
	///JSONValue ctor() with number value
	JSONValue(double);
	///JSONValue ctor() with JSON object value
	JSONValue(const Vector<Pair<String, Pointer<JSONValue>>>&);
	///JSONValue ctor() with JSON array value
	JSONValue(const Vector<JSONValue>&);
	///copy ctor()
	JSONValue(const JSONValue&);
	///copy-assignment operator
	JSONValue& operator=(const JSONValue&);
	///operator ==
	bool operator==(const JSONValue&) const;
	///JSONValue ~dtor()
	~JSONValue() = default;
	///returns object's value
	std::variant<
		bool,
		String,
		double,
		Vector<Pair<String, Pointer<JSONValue>>>,
		Vector<JSONValue>> get_value();
	///clones object
	Pointer<JSONValue> clone() const;
	///prints tabs depending on depth of object
	void print_tabs(std::ostream&, size_t) const;
	///prints object
	void print(std::ostream&, size_t) const;
	///returns all deeper elements that have a key equal to String
	Vector<JSONValue> search(const String&);
	///returns pointer to object's child with key equal to String
	JSONValue* get_object_by_key(const String&);
	///returns pointer to array's n-th element (n being the int)
	JSONValue* get_array_element(int);
	///sets value parsed from String
	void set_value(const String&);
	///adds new empty object to key-value pair with key String
	JSONValue* add_new_object(const String&);
	///adds array element up to n-th position (n being the int)
	JSONValue* add_array_element(int);
	///sets value parsed from String if it doesn's already exist
	bool set_value_check(const String&);
	///deletes element equal to JSONValue
	bool delete_el(JSONValue);
	///writes to file loaded to the std::ostream, size_t is the current depth (needed for printing tabs) 
	void write_to_file(std::ofstream&, size_t);
private:

	Type t{ Type::n };
	bool boolean{};
	String string{};
	double number{};
	Vector<Pair<String, Pointer<JSONValue>>> object{};
	Vector<JSONValue> arr{};
};