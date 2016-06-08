/**
 *  @mainpage Simulador de Associatividade Adaptativa
 *  @author Elton de Souza Vieira
 *  @date June, 2016
 *  @copyright Copyright &copy; 2016. All rights reserved.
 *  @version 1.0
 *
 *  @file memory_mapping.cpp
 *  @brief Main File
 *
 *  File with the main function
 */

#include <iostream>
#include "mapping_simulator.hpp"

int main(int argc, char const *argv[]) {
    auto cache_sz = 16u;
    auto max_miss = 0.5;
    std::string n = "0xFF";

    MappingSimulator map(cache_sz, max_miss);

    // Testing
    map.access(n);
    map.access(n);
    map.access(n);

    std::cout << "Exiting with Success...\n";

    return EXIT_SUCCESS;
}
