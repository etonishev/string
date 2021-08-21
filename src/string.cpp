#include <iostream>

#include "../string.hpp"



teg::String::String() noexcept :
	m_buffer(nullptr), m_size(0) { }

teg::String::String(const char* str) :
	m_buffer(nullptr), m_size(0) {

	if (str == nullptr)
		return;

	m_buffer = new char[std::strlen(str) + 1];
	m_size = std::strlen(str);
	std::strcpy(m_buffer, str);

}

teg::String::String(const std::string& str) :
	String(str.c_str()) { }

teg::String::String(const String& other) :
	m_buffer(nullptr), m_size(0) {

	if (other.empty())
		return;

	m_buffer = new char[other.size() + 1];
	std::strcpy(m_buffer, other);
	m_size = other.size();

}

teg::String::String(String&& other) noexcept :
	m_buffer(nullptr), m_size(0) {

	swap(*this, other);

}

teg::String::~String() noexcept {

	clear();

}

void teg::String::clear() noexcept{

	delete[] m_buffer;
	m_buffer = nullptr;
	m_size = 0;

}

bool teg::String::empty() const noexcept {

	return m_size == 0;

}

std::size_t teg::String::size() const noexcept {

	return m_size;

}

std::size_t teg::String::length() const noexcept {

	return size();

}

teg::String::operator const char* () const noexcept {

	return m_buffer;

}

const char& teg::String::operator[](std::size_t idx) const noexcept {

	return m_buffer[idx];

}

char& teg::String::operator[](std::size_t idx) noexcept {

	return m_buffer[idx];

}

teg::String& teg::String::operator=(const String& other) {

	if (&other == this)
		return *this;

	clear();

	if (other.empty())
		return *this;

	m_buffer = new char[other.size() + 1];
	std::strcpy(m_buffer, other);
	m_size = other.m_size;

	return *this;

}

teg::String& teg::String::operator=(String&& other) noexcept {

	if (&other == this)
		return *this;

	clear();
	swap(*this, other);

	return *this;

}

teg::String& teg::String::operator+(const String& other) {

	if (other.empty())
		return *this;

	std::size_t newSize = m_size + other.size();
	char* newBuffer = new char[newSize + 1];

	if (!empty())
		std::strcpy(newBuffer, m_buffer);

	std::strcat(newBuffer, other);

	clear();
	std::swap(m_buffer, newBuffer);
	std::swap(m_size, newSize);

	return *this;

}

teg::String& teg::String::operator+(const char* other) {

	if (other == nullptr)
		return *this;

	std::size_t newSize = m_size + std::strlen(other);
	if (newSize == m_size)
		return *this;

	char* newBuffer = new char[newSize + 1];

	if (!empty())
		std::strcpy(newBuffer, m_buffer);

	std::strcat(newBuffer, other);

	clear();
	std::swap(m_buffer, newBuffer);
	std::swap(m_size, newSize);

	return *this;

}

bool teg::operator==(const String& lhv, const String& rhv) noexcept {

	return std::strcmp(lhv, rhv) == 0;

}

bool teg::operator!=(const String& lhv, const String& rhv) noexcept {

	return !(lhv == rhv);

}

bool teg::operator>(const String& lhv, const String& rhv) noexcept {
	
	return std::strcmp(lhv, rhv) > 0;

}

bool teg::operator<(const String& lhv, const String& rhv) noexcept {

	return !(lhv > rhv) && (lhv != rhv);

}

bool teg::operator>=(const String& lhv, const String& rhv) noexcept {

	return (lhv > rhv) || (lhv == rhv);

}

bool teg::operator<=(const String& lhv, const String& rhv) noexcept {

	return (lhv < rhv) || (lhv == rhv);

}

void teg::swap(String& lhv, String& rhv) noexcept {
	std::swap(lhv.m_buffer, rhv.m_buffer);
	std::swap(lhv.m_size, rhv.m_size);
}

std::ostream& teg::operator<<(std::ostream& os, const String& string) {

	if (string.empty())
		return os;

	os << string.m_buffer;
	return os;

}

std::istream& teg::operator>>(std::istream& is, String& string) {

	string.clear();

	constexpr std::size_t bufferSize = 1024;
	char buffer[bufferSize];

	while (is.get(buffer, bufferSize))
		string = string + buffer;

	is.clear();
	while (is.get() != '\n');

	return is;

}
