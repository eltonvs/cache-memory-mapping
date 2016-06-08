/**
 *  @file mapping_simulator.hpp
 *  @brief The Mapping Simulator Class
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *
 *  File with the Mapping Simulator Class
 */

#ifndef _mapping_simulator_hpp_
#define _mapping_simulator_hpp_

#include <string>
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

    /**
     * @brief Function to access a value into the cache
     * @param _val The value to be accessed
     */
    void access(std::string _val);

    /**
     * @brief Shows the Cache on console (using the default method)
     */
    void show() const;

 private:
    /**
     * @brief Function to search a value on Cache
     * @param _m The type of mapping to be used
     * @param _val To value to be searched
     * @param _lpos The last visited position (to insert the element on cache)
     * @return The position where the value is located
     */
    int search_val(unsigned _m, std::string _val, unsigned &_lpos) const;

    Cache m_cache;           //<! The Cache to be used
    double m_max_miss_rate;  //<! The maximum miss rate
    unsigned m_miss_cnt;     //<! The miss counter
    unsigned m_access_cnt;   //<! The access counter
    unsigned m_current_map;  //<! The current mapping function to be used
};

#endif
