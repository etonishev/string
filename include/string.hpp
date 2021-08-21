#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>



namespace teg {

	class String {

	public:
		String() noexcept;
		String(const char* str);
		String(const String& other);
		String(String&& other) noexcept;
		~String() noexcept;

		void clear() noexcept;
		bool empty() const noexcept;
		std::size_t size() const noexcept;
		std::size_t length() const noexcept;

		operator const char* () const noexcept;

		const char& operator[](std::size_t idx) const noexcept;
		char& operator[](std::size_t idx) noexcept;

		String& operator=(const String& other);
		String& operator=(String&& other) noexcept;

		String& operator+(const String& other);
		String& operator+(const char* other);

	public:
		friend bool operator==(const String& lhv, const String& rhv) noexcept;
		friend bool operator!=(const String& lhv, const String& rhv) noexcept;
		friend bool operator>(const String& lhv, const String& rhv) noexcept;
		friend bool operator<(const String& lhv, const String& rhv) noexcept;
		friend bool operator>=(const String& lhv, const String& rhv) noexcept;
		friend bool operator<=(const String& lhv, const String& rhv) noexcept;

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