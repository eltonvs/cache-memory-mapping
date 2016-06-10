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

/**
 * @brief The main function thar runs the program
 * @param argc The cli arguments counter
 * @param argv The cli arguments values
 * @return EXIT_SUCESS if all succeed, EXIT_FAILURE otherwise
 */
int main(int argc, char const *argv[]) {
    auto cache_sz = 16u;
    auto max_miss = 1.0;
    int choice    = 0;
    std::vector<std::string> addresses;

    if (argc > 2) {
        // Input 1: File
        std::string input_file = argv[1];
        // Input 2: miss rate
        max_miss = std::stof(argv[2]);
        // Input 3: cache_sz
        if (argc > 3)
            cache_sz = std::stoul(argv[3]);
        // Verify if the cache's size is a valid size
        if (cache_sz < 4)
            cache_sz = 4;

        // Open the file
        std::ifstream file(input_file);
        // Verify if the file was successfully opened
        if (!file.is_open()) {
            std::cerr << "The file specified doens't exists" << std::endl;
            return EXIT_FAILURE;
        }

        std::string line;
        // Copy the file addesses to a vector of strings
        while (std::getline(file, line))
            if (line != "")
                addresses.push_back(line);
    } else {
        std::cerr << "Missing parameters" << std::endl;
        return EXIT_FAILURE;
    }

    // Initializes the MappingSimulator class
    MappingSimulator map(cache_sz, max_miss);

    std::cout << std::string(30, '-') << "\n";
    std::cout << "Memory Mapping Simulator" << "\n";
    std::cout << "  >>> Maximum miss rate: " << max_miss * 100 << '%' << "\n";
    std::cout << "  >>> Cache's size: " << cache_sz << "\n";
    std::cout << std::string(30, '-') << "\n\n";

    // For each address in addresses, try to access him
    for (auto address : addresses) {
        std::cout << "Accessing the element " << address << std::endl;
        std::cout << "Using ";
        map.access(address);

        // Show the current cache status on terminal
        do {
            std::cout << ">>> Show the current cache content? [1-Yes | 0-No] ";
            std::cin >> choice;
        } while (choice != 0 && choice != 1);
        if (choice == 1) {
            std::cout << std::endl << ">>> ";
            map.show();
        }

        // Separator line
        std::cout << "\n" << std::string(80, '-') << "\n";
    }

    std::cout << "\n\nExiting with Success...\n";

    return EXIT_SUCCESS;
}
