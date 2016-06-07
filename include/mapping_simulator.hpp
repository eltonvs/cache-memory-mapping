/**
 *  @file mapping_simulator.hpp
 *  @brief The Mapping Simulator Class
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Mapping Simulator Class
 */

#ifndef _mapping_simulator_hpp_
#define _mapping_simulator_hpp_

#include "cache.hpp"

class MappingSimulator {
 public:
    /**
     * @brief The MappingSimulator Constructor
     * @param _cache_sz The Cache's size
     * @param _max_rate The maximum miss rate
     */
    MappingSimulator(unsigned _cache_sz, double _max_rate);

    /**
     * @brief The MappingSimulator Destructor
     */
    ~MappingSimulator();

 private:
    Cache m_cache;              //<! The Cache to be used
    double m_max_miss_rate;     //<! The maximum miss rate
    unsigned m_miss_counter;    //<! The miss counter
    unsigned m_access_counter;  //<! The access counter
    unsigned m_current_map;     //<! The current mapping function to be used
};

#endif
