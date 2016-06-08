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

    if (search_val(m_current_map, _val) == -1) {
        std::cout << "Miss" << std::endl;

        m_miss_cnt++;

        //
        // Add element to cache
        //

        // If the current miss rate pass the limit, switch the associativity
        if (static_cast<double>(m_miss_cnt)/m_access_cnt > m_max_miss_rate)
            m_current_map++, m_miss_cnt = 0, m_access_cnt = 0;
        return;
    }

    std::cout << "Hit" << std::endl;
}

// Search for a value on cache
int MappingSimulator::search_val(unsigned _m, std::string _val) const {
    int dec_val     = strtol(_val.c_str(), NULL, 16);
    std::string aux = "-";
    unsigned b_val  = dec_val % m_cache.getSize();
    unsigned ini    = (dec_val % 4) * (m_cache.getSize()/4);
    unsigned end    = ini + (m_cache.getSize()/4);

    switch (_m % 3) {
        // Direct
        case 0:
            std::cout << ">>> Direct" << std::endl;
            if (m_cache.getValue(b_val, aux) && aux == _val)
                return b_val;
            break;
        // Partially Associative
        case 1:
            std::cout << ">>> Partially" << std::endl;
            while (ini < end) {
                if (m_cache.getValue(ini, aux) && aux == _val)
                    return b_val;
                ini++;
            }
            break;
        // Totally Associative
        case 2:
            std::cout << ">>> Totally" << std::endl;
            auto i(0u);
            while (i < m_cache.getSize()) {
                if (m_cache.getValue(i, aux) && aux == _val)
                    return i;
                i++;
            }
            break;
    }

    return -1;
}
