#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "pixel.h"
#include "pixel_generator.h"

void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list){
	for (auto &p : pixel_list){
		p.y = 255 - p.y;
		}
	}

int main(int argc, char* argv[]) {
	
		std::string filename = "pixels.dat";
		generate_pixels_file("pixels.dat");
    std::vector<Pixel> pixel_list;
    std::ifstream infile(filename);

		
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    int line_num = 0;
    while (std::getline(infile, line)) {
        line_num++;
        if (line.empty()) continue; // skip empty lines

        std::stringstream ss(line);
        std::string token;
        Pixel p;

        // Parse x
        if (!std::getline(ss, token, ',')) {
            std::cerr << "Malformed line " << line_num << std::endl;
            continue;
        }
        p.x = std::stoi(token);

        // Parse y
        if (!std::getline(ss, token, ',')) {
            std::cerr << "Malformed line " << line_num << std::endl;
            continue;
        }
        p.y = std::stoi(token);

        // Parse r
        if (!std::getline(ss, token, ',')) {
            std::cerr << "Malformed line " << line_num << std::endl;
            continue;
        }
        p.r = std::stof(token);

        // Parse g
        if (!std::getline(ss, token, ',')) {
            std::cerr << "Malformed line " << line_num << std::endl;
            continue;
        }
        p.g = std::stof(token);

        // Parse b
        if (!std::getline(ss, token, ',')) {
            std::cerr << "Malformed line " << line_num << std::endl;
            continue;
        }
        p.b = std::stof(token);
     pixel_list.push_back(p);
    }

    infile.close();
    std::cout << "Loaded " << pixel_list.size() << " pixels." << std::endl;

    // Compute average colors
    average_colors(pixel_list);

    // Flip pixels vertically
    flip_vertically(pixel_list);
    // Save flipped pixels to file
    std::ofstream outfile("flipped.dat");
    if (!outfile.is_open()) {
        std::cerr << "Error creating output file." << std::endl;
        return 1;
    }

    for (const auto &p : pixel_list) {
        outfile << p.x << "," << p.y << ","
                << p.r << "," << p.g << "," << p.b << "\n";
    }

    outfile.close();
    std::cout << "Flipped image saved to flipped.dat" << std::endl;

    return 0;
}

// Function to compute average colors
void average_colors(std::vector<Pixel> &pixel_list) {
    double sum_r = 0;
    double sum_g = 0;
    double sum_b = 0;

    for (const auto &p : pixel_list) {
        sum_r += p.r;
        sum_g += p.g;
        sum_b += p.b;
    }

    int total = pixel_list.size();
    if(total > 0){
	std::cout << "Average R: " << sum_r / total
              	  << ", G: " << sum_g / total
	          << ", B: " << sum_b / total << std::endl;
	}
}
 
	
