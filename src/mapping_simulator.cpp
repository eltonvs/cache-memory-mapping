/**
 *  @file mapping_simulator.cpp
 *  @brief Mapping Simulator Implementations
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Mapping Simulator Class implementation
 */

#include "mapping_simulator.hpp"

MappingSimulator::MappingSimulator(unsigned _cache_sz, double _max_rate)
    : m_cache(_cache_sz), m_max_miss_rate(_max_rate), m_miss_counter(0u),
      m_access_counter(0u), m_current_map(0u) {}

MappingSimulator::~MappingSimulator() {}
