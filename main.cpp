#include <iostream>



class String {

public:
    String()
        : m_buffer(nullptr), m_size(0) { }

    String(std::size_t length) :
        m_buffer(new char[length + 1]), m_size(length) {

        m_buffer[m_size] = '\0';

    }

    String(const char* string)
        : m_buffer(nullptr), m_size(0) {

        if (string == nullptr)
            return;

        while (string[m_size++] != '\0');
        --m_size;

        m_buffer = new char[m_size + 1];
        for (std::size_t i = 0; i < m_size; ++i)
            m_buffer[i] = string[i];
        m_buffer[m_size] = '\0';

    }

    String(const String& other) :
        m_buffer(new char[other.m_size + 1]), m_size(other.m_size) {

        for (std::size_t i = 0; i < m_size; ++i)
            m_buffer[i] = other.m_buffer[i];
        m_buffer[m_size] = '\0';

    }

    String(String&& other) noexcept :
        m_buffer(other.m_buffer), m_size(other.m_size) {

        other.m_buffer = nullptr;
        other.m_size = 0;

    }

    ~String() {

        clear();

    }

    void clear() {

        delete[] m_buffer;
        m_buffer = nullptr;
        m_size = 0;

    }

    std::size_t size() const {

        return m_size;

    }

    bool empty() const {

        return m_size == 0;

    }

    char& operator[](std::size_t idx) {

        return m_buffer[idx];

    }

    const char& operator[](std::size_t idx) const {

        return m_buffer[idx];

    }

    operator const char* () const {

        return m_buffer;

    }

    String& operator=(const String& other) {

        if (this == &other)
            return *this;

        delete[] m_buffer;
        m_size = other.m_size;

        m_buffer = new char[m_size + 1];
        for (std::size_t i = 0; i < m_size; ++i)
            m_buffer[i] = other.m_buffer[i];
        m_buffer[m_size] = '\0';

        return *this;

    }

    String& operator=(String&& other) noexcept {

        if (this == &other)
            return *this;

        delete[] m_buffer;
        m_buffer = other.m_buffer;
        m_size = other.m_size;

        other.m_buffer = nullptr;
        other.m_size = 0;

        return *this;

    }

    String& operator+(const String& other) {

        if (other.empty())
            return *this;

        std::size_t newSize = m_size + other.size();
        char* newBuffer = new char[newSize + 1];

        for (std::size_t i = 0; i < m_size; ++i)
            newBuffer[i] = m_buffer[i];
        delete[] m_buffer;
        m_buffer = nullptr;

        for (std::size_t i = 0; i < other.size(); ++i)
            newBuffer[i + m_size] = other[i];

        newBuffer[newSize] = '\0';

        std::swap(m_buffer, newBuffer);
        m_size = newSize;

        return *this;

    }

    String& operator+(const char* other) {

        std::size_t otherSize = 0;
        while (other[otherSize++] != '\0');
        --otherSize;

        if (otherSize == 0)
            return *this;

        std::size_t newSize = m_size + otherSize;
        char* newBuffer = new char[newSize + 1];

        for (std::size_t i = 0; i < m_size; ++i)
            newBuffer[i] = m_buffer[i];
        delete[] m_buffer;
        m_buffer = nullptr;

        for (std::size_t i = 0; i < otherSize; ++i)
            newBuffer[i + m_size] = other[i];

        newBuffer[newSize] = '\0';

        std::swap(m_buffer, newBuffer);
        m_size = newSize;

        return *this;

    }

public:
    friend bool operator==(const String& lhv, const String& rhv) {

        if (lhv.size() != rhv.size())
            return false;

        for (std::size_t i = 0; i < lhv.size(); ++i)
            if (lhv[i] != rhv[i])
                return false;

        return true;

    }

    friend bool operator!=(const String& lhv, const String& rhv) {

        return !(lhv == rhv);

    }

    friend bool operator>(const String& lhv, const String& rhv) {

        std::size_t idx = 0;
        while (idx < lhv.size() && idx < rhv.size()) {

            if (lhv[idx] > rhv[idx])
                return true;
            else if (lhv[idx] < rhv[idx])
                return false;

            ++idx;

        }

        return lhv.size() > rhv.size();

    }

    friend bool operator<(const String& lhv, const String& rhv) {

        return !(lhv > rhv) && (lhv != rhv);

    }

    friend bool operator>=(const String& lhv, const String& rhv) {

        return (lhv > rhv) || (lhv == rhv);

    }

    friend bool operator<=(const String& lhv, const String& rhv) {

        return (lhv < rhv) || lhv == rhv;

    }

    friend std::ostream& operator<<(std::ostream& os, const String& string) {

        if (string.empty())
            return os;

        os << string.m_buffer;
        return os;

    }

    friend std::istream& operator>>(std::istream& is, String& string) {

        string.clear();

        const std::size_t bufferSize = 1024;
        char buffer[bufferSize];

        while (is.get(buffer, bufferSize))
            string = string + buffer;

        is.clear();
        while (std::cin.get() != '\n');

        return is;

    }

private:
    char* m_buffer;
    std::size_t m_size;

};