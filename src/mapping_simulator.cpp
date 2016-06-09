/**
 *  @file mapping_simulator.cpp
 *  @brief Mapping Simulator Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Mapping Simulator Class implementation
 */

#include <iostream>
#include <string>
#include "mapping_simulator.hpp"

// Constructor
MappingSimulator::MappingSimulator(unsigned _cache_sz, double _max_rate)
    : m_cache(_cache_sz), m_max_miss_rate(_max_rate), m_miss_cnt(0u),
      m_access_cnt(0u), m_current_map(0u) {}

// Destructor
MappingSimulator::~MappingSimulator() {}

// Function to access a value on Cache
void MappingSimulator::access(std::string _val) {
    m_access_cnt++;
    unsigned pos;
    double miss_rate = static_cast<double>(m_miss_cnt)/m_access_cnt;

    if (search_val(m_current_map, _val, pos) == -1) {
        m_miss_cnt++;
        miss_rate = static_cast<double>(m_miss_cnt)/m_access_cnt;

        std::cout << "[Miss] - Miss rate: " << miss_rate * 100 << '%' << std::endl;

        // Add element to cache
        m_cache.setValue(pos, _val);

        // If the current miss rate pass the limit, switch the associativity
        if (miss_rate > m_max_miss_rate)
            m_current_map++, m_miss_cnt = 0, m_access_cnt = 0;
        return;
    }

    std::cout << "[Hit] - Miss rate: " << miss_rate * 100 << '%' << std::endl;
}
// Shows the Cache on screen
void MappingSimulator::show() const {
    m_cache.show();
}

// Search for a value on cache
int MappingSimulator::search_val(unsigned _m, std::string _val, unsigned &_lpos) const {
    bool changed    = false;
    int dec_val     = strtol(_val.c_str(), NULL, 16);
    std::string aux = "-";
    unsigned b_val  = dec_val % m_cache.getSize();
    unsigned ini    = (dec_val % 4) * (m_cache.getSize()/4);
    unsigned end    = ini + (m_cache.getSize()/4);
    unsigned i      = 0;

    if (m_cache.getSize() % 4 != 0)
        end += (dec_val % 4 == 3) ? (m_cache.getSize() % 4) : 0;

    switch (_m % 3) {
        // Direct
        case 0:
            std::cout << "Direct Mapping ";
            if (m_cache.getValue(b_val, aux) && aux == _val)
                return b_val;
            _lpos = b_val, changed = true;
            break;
        // Partially Associative
        case 1:
            std::cout << "Partially Associative Mapping ";
            i = _lpos = ini;
            while (i < end) {
                if (m_cache.getValue(i, aux) && aux == _val)
                    return b_val;
                if (!changed && aux == "-")
                    _lpos = i, changed = true;
                i++;
            }
            if (!changed)
                _lpos += (m_access_cnt % (m_cache.getSize()/4)), changed = true;
            break;
        // Totally Associative
        case 2:
            std::cout << "Totally Associative Mapping ";
            while (i < m_cache.getSize()) {
                if (m_cache.getValue(i, aux) && aux == _val)
                    return i;
                if (!changed && aux == "-")
                    _lpos = i, changed = true;
                i++;
            }
            if (!changed)
                _lpos = m_access_cnt % m_cache.getSize(), changed = true;
            break;
    }

    return -1;
}
