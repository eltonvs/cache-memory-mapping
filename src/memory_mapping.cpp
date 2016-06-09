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
#include <fstream>
#include <string>
#include <vector>
#include "mapping_simulator.hpp"

int main(int argc, char const *argv[]) {
    auto cache_sz = 0u;
    auto max_miss = 1.0;
    int choice = 0;
    std::vector<std::string> addresses;

    if (argc > 1) {
        std::string input_file = argv[1];
        std::ifstream file(input_file);

        if (!file.is_open()) {
            std::cerr << "The file specified doens't exists" << std::endl;
            return EXIT_FAILURE;
        }

        file >> cache_sz;
        file >> max_miss;
        std::string line;
        while (std::getline(file, line))
            if (line != "") addresses.push_back(line);
    } else {
        std::cerr << "No input file specified" << std::endl;
        return EXIT_FAILURE;
    }

    MappingSimulator map(cache_sz, max_miss);

    for (auto address : addresses) {
        std::cout << "Accessing the element " << address << std::endl;
        std::cout << "Using: ";
        map.access(address);
        do {
            std::cout << "Show the current cache content? [1 - Yes | 0 - No] ";
            std::cin >> choice;
        } while (choice != 0 && choice != 1);
        std::cout << std::endl << ">>> ";
        if (choice == 1) map.show();
        std::cout << std::endl;
    }

    std::cout << "Exiting with Success...\n";

    return EXIT_SUCCESS;
}
