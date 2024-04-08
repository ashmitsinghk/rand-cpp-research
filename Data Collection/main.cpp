#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Function to generate random numbers using a given seed and store them in a CSV file
void generateRandomNumbers(int seed, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    // Seed the random number generator
    srand(seed);

    // Write header to CSV file
    outFile << "Random Number" << std::endl;

    // Generate and write random numbers to CSV file
    for (int i = 0; i < 10000; ++i) {
        outFile << rand() << std::endl;
    }

    outFile.close();
}

int main() {
    // Seeds for the experiment
    int seeds[] = {415742775, 129944475, 255472122, 913743874, time(NULL)};
    const int numSeeds = sizeof(seeds) / sizeof(seeds[0]);

    // Generate random numbers for each seed and store them in CSV files
    for (int seed : seeds) {
        std::string filename = "random_numbers_seed_" + std::to_string(seed) + ".csv";
        generateRandomNumbers(seed, filename);
        std::cout << "Generated random numbers for seed " << seed << " and saved to " << filename << std::endl;
    }

    return 0;
}
