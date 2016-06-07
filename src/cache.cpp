/**
 *  @file cache.cpp
 *  @brief Cache Memory Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Cache Memory Class implementation
 */

#include <iostream>
#include <iomanip>
#include "cache.hpp"

// Constructor
Cache::Cache(unsigned _sz) : m_size(_sz), m_memory(_sz, "-") {}

// Destructor
Cache::~Cache() {}

// Gets the cache value in a position
bool Cache::getValue(unsigned _pos, std::string &_val) const {
    // Verify if the _pos is invalid or if isn't filled
    if (_pos >= m_size || m_memory[_pos] == "-")
        return false;

    _val = m_memory[_pos];
    return true;
}

// Sets a value in a cache position
bool Cache::setValue(unsigned _pos, std::string _val) {
    // Verify if the _pos is invalid
    if (_pos >= m_size)
        return false;

    m_memory[_pos] = _val;
    return true;
}

// Show the Cache Memory
void Cache::show() const {
    std::cout << "[ ";
    for (auto it = m_memory.begin(); it != m_memory.end(); it++)
        std::cout << *it << (it + 1 == m_memory.end() ? " ]\n" : " | ");
}