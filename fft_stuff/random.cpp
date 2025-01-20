#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    // Seed the random number generator
    std::srand(std::time(0));

    // Create a vector of complex floats
    std::vector<std::complex<float>> random_vector(N);

    // Generate random floats and fill the vector
    for(auto& num : random_vector)
    {
        num = {-1.0f + 2.0f * static_cast<float>(std::rand()) / RAND_MAX,
               -1.0f + 2.0f * static_cast<float>(std::rand()) / RAND_MAX};
    }

    // // Print the vector
    // for(const auto& num : random_vector)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    std::ofstream file("random_input.txt");

    if(!file)
        throw std::runtime_error("could not create file");

    for(auto& complex : random_vector)
        file << complex.real() << " " << complex.imag() << "\n";
    file.close();
    return 0;
}
