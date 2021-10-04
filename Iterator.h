#ifndef DIFFICULTMOMENTSCPP_ITERATOR_H
#define DIFFICULTMOMENTSCPP_ITERATOR_H

#include <vector>


class Iterator {
private:
    class InnerIterator {
public:
    InnerIterator(size_t idx, std::vector<int> val);
    int operator*() const;
    InnerIterator &operator++();
    bool operator !=(const InnerIterator& rhs) const;

private:
    size_t m_Idx;
    std::vector<int> m_Val;
};
public:
    explicit Iterator(std::vector<int> values);

    [[nodiscard]] InnerIterator begin() const;
    [[nodiscard]] InnerIterator end() const;
private:
    std::vector<int> m_Values;
};


#endif //DIFFICULTMOMENTSCPP_ITERATOR_H
