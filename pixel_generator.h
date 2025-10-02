#ifndef PIXEL_GENERATOR_H
#define PIXEL_GENERATOR_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

inline void generate_pixels_file(const std::string &filename, int width = 512, int height = 256) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }

    srand(static_cast<unsigned>(time(0))); // seed RNG

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float r = static_cast<float>(rand()) / RAND_MAX;
            float g = static_cast<float>(rand()) / RAND_MAX;
            float b = static_cast<float>(rand()) / RAND_MAX;

            outfile << x << "," << y << ","
                    << std::setprecision(16) << r << ","
                    << std::setprecision(16) << g << ","
                    << std::setprecision(16) << b << "\n";
        }
    }

    outfile.close();
    std::cout << "Generated " << width * height << " pixels in " << filename << std::endl;
}

#endif
