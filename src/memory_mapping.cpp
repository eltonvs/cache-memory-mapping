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
    int choice = 0;
    std::string n[10] = {"0x0", "0x2", "0x4", "0x6", "0x8", "0x0", "0x2", "0x4", "0x6", "0x8"};

    MappingSimulator map(cache_sz, max_miss);

    // Testing
    for (int i = 0; i < 10; i++) {
        std::cout << "Accessing the element " << n[i] << std::endl;
        map.access(n[i]);
        do {
            std::cout << "Do you wanna view the current cache content? [1 - Yes | 0 - No] ";
            std::cin >> choice;
        } while (choice != 0 && choice != 1);
        if (choice == 1) map.show();
        std::cout << std::endl;
    }

    std::cout << "Exiting with Success...\n";

    return EXIT_SUCCESS;
}
