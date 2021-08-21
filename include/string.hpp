#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>



namespace teg {

	class String {

	public:
		String();
		String(const char* str);
		String(const String& other);
		String(String&& other) noexcept;
		~String();

		void clear();
		bool empty() const;
		std::size_t size() const;
		std::size_t length() const;

		operator const char* () const;

		const char& operator[](std::size_t idx) const;
		char& operator[](std::size_t idx);

		String& operator=(const String& other);
		String& operator=(String&& other) noexcept;

		String& operator+(const String& other);
		String& operator+(const char* other);

	public:
		friend bool operator==(const String& lhv, const String& rhv);
		friend bool operator!=(const String& lhv, const String& rhv);
		friend bool operator>(const String& lhv, const String& rhv);
		friend bool operator<(const String& lhv, const String& rhv);
		friend bool operator>=(const String& lhv, const String& rhv);
		friend bool operator<=(const String& lhv, const String& rhv);

		friend void swap(String& lhv, String& rhv) noexcept;
		friend std::ostream& operator<<(std::ostream& os, const String& string);
		friend std::istream& operator>>(std::istream& is, String& string);

	private:
		char* m_buffer;
		std::size_t m_size;

	};

	std::ostream& operator<<(std::ostream& os, const String& string);
	std::istream& operator>>(std::istream& is, String& string);
	void swap(String& lhv, String& rhv) noexcept;

}

#endif // !STRING_HPP