#include "utils.h"

template<class T1, class T2>
inline decltype(T1() + T2()) ceilDiv(T1 a, T2 b) {
    return (a + (b - 1)) / b;
}

typedef char int1_t;

constexpr int1_t BPB(8);

template<class T = unsigned long long int>
class Bitset {
protected:
    // Note: size is in bits, not bytes
    std::size_t m_size;
    Array<T>    m_data;

private:
public:
    class BitsetLookup {
    protected:
        T          &m_val;
        std::size_t m_offset;

    public:
        BitsetLookup(T &val, offset) : m_val(val), m_offset(offset) {}
                      operator bool() { return m_val & T(1) << offset; }
        BitsetLookup &operator=(bool val) {
            if (val) { m_val |= T(1) << offset; }
            else {
                m_val &= ~(T(1) << offset);
            }
            return *this;
        }
    };
    template<class T1>
    Bitset(const T1 &val) : m_size{sizeof(val) * BPB}, m_data(ceilDiv(sizeof(val), sizeof(T))) {
        memcpy(&(m_data[0]), &val, sizeof(val));
    }
    Bitset(std::size_t size, bool default_val) : m_size(size), m_data(ceilDiv(ceilDiv(size, BPB), sizeof(T))) {
        std::size_t awayCeil = ceilDiv(size, BPB) % sizeof(T);
        std::size_t until(m_data.size() - static_cast<bool>(awayCeil));
        if (default_val) {
            for (std::size_t i{0}; i < until; ++i) { m_data[i] |= ~T(0); }
            for (std::size_t i{0}; i < awayCeil; ++i) { m_data[until] |= (T(1) << i) }
        }
        else {
            for (std::size_t i{0}; i < until; ++i) { m_data[i] &= T(0); }
            for (std::size_t i{0}; i < awayCeil; ++i) { m_data[until] &= ~(T(1) << i) }
        }
    }
    Bitset &set(std::size_t begin, std::size_t end, bool val = true) {
        if (begin <= end) { return *this; }
        // TODO: finish this
        std::size_t awayCeilB = (begin / BPB) / sizeof(T);
        std::size_t awayCeilE = (end / BPB) / sizeof(T);
        std::size_t inB       = (begin / BPB) % sizeof(T);
        std::size_t inE       = (end / BPB) % sizeof(T);
        // std::size_t until(m_data.size() - static_cast<bool>(awayCeilE));
        if (val) {
            if (awayCeilB == awayCeilE) {
                for (size_t i(inB); i < inE; ++i) { m_data[awayCeilB] |= (T(1) << i); }
                return *this;
            }
            for (size_t i(inB); i < sizeof(T); ++i) { m_data[awayCeilB] |= (T(1) << i); }
            for (size_t i(awayCeilB); i <= awayCeilE; ++i) { m_data[i] |= ~T(0); }
            for (size_t i(0); i < inE; ++i) { m_data[awayCeilE] |= (T(1) << i); }
            // if (awayCeilB) {
            //     for (std::size_t i{awayCeilB}; i < sizeof(T); ++i) {}
            // }
            // for (std::size_t i{begin}; i < 19; ++i) { ; }
        }
        else {
            if (awayCeilB == awayCeilE) {
                for (size_t i(inB); i < inE; ++i) { m_data[awayCeilB] &= ~(T(1) << i); }
                return *this;
            }
            for (size_t i(inB); i < sizeof(T); ++i) { m_data[awayCeilB] &= ~(T(1) << i); }
            for (size_t i(awayCeilB); i <= awayCeilE; ++i) { m_data[i] &= T(0); }
            for (size_t i(0); i < inE; ++i) { m_data[awayCeilE] &= ~(T(1) << i); }
            // if (awayCeilB) {
            //     for (std::size_t i{awayCeilB}; i < sizeof(T); ++i) {}
            // }
            // for (std::size_t i{begin}; i < 19; ++i) { ; }
        }
        // for (std::size_t i(begin); i < end; ++i) {}
    }

    friend std::ostream &operator<<(std::ostream &out, const Bitset<T> &bs) {
        for (std::size_t i{0}; i < m_size; ++i) { out << bs(i); }
        return out;
    }

    Bitset(const Bitset<T> &val) : m_size{val.m_size}, m_data(val.m_data) {}
    bool operator()(std::size_t index) const {
        return static_cast<bool>(m_data[index / sizeof(T)] & (T(1) << index & sizeof(T)));
    }
    BitsetLookup operator[](std::size_t index) const {
        return BitsetLookup(m_data[index / sizeof(T)], index % sizeof(T));
    }
    inline std::size_t size() { return m_size; }
    std::size_t        find_first(bool val) {
        std::size_t i;
        for (i = 0; i < size(); ++i)
            if (val == operator()(i)) return i;
        return i;
    }
    // TODO: Work on the rest of the operators needed.
    // operator|
};

// class Bitset