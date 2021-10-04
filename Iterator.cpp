
#include "Iterator.h"



Iterator::InnerIterator::InnerIterator(const size_t idx, std::vector<int> val) : m_Idx(idx), m_Val(std::move(val)){}

int Iterator::InnerIterator::operator*() const {
    return m_Val[m_Idx];
}

Iterator::InnerIterator &Iterator::InnerIterator::operator++() {
    ++m_Idx;
    return *this;
}

bool Iterator::InnerIterator::operator!=(const Iterator::InnerIterator &rhs) const {
    return m_Idx != rhs.m_Idx;
}

Iterator::Iterator(std::vector<int> values) : m_Values(std::move(values)){}

Iterator::InnerIterator Iterator::begin() const {
    return InnerIterator{0, m_Values};
}

Iterator::InnerIterator Iterator::end() const {
    return InnerIterator{m_Values.size(), m_Values};
}
