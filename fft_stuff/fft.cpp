#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

// Practice FFT implementation, just using a recursive approach
// Just for testing power of two lengths, for 1D now

// Decimation in Time (DIT) splits by even and odd samples
std::vector<std::complex<double>> dit(std::vector<std::complex<double>>& input)
{
    size_t N = input.size();
    // Base case
    if(N == 1)
    {
        return input;
    }

    // Prepare halves
    size_t                            num_elems = N / 2;
    std::vector<std::complex<double>> h1(num_elems);
    std::vector<std::complex<double>> h2(num_elems);
    for(size_t i = 0; i < num_elems; i++)
    {
        h1[i] = input[2 * i];
        h2[i] = input[2 * i + 1];
    }

    auto even = dit(h1);
    auto odd  = dit(h2);

    std::vector<std::complex<double>> freq_bins(N, 0);
    for(size_t k = 0; k < N / 2; k++)
    {
        std::complex<double> z(0, -2 * M_PI * k / N);
        std::complex<double> w   = std::exp(z); // -j * 2pi * k / N
        auto                 rhs = w * odd[k]; // Account for extra term attached to odd side
        // std::complex<double> rhs = std::polar(1.0, -2 * M_PI * k / N) * odd[k];
        freq_bins[k]         = even[k] + rhs;
        freq_bins[k + N / 2] = even[k] - rhs; // Account for symmetry relation
    }

    return freq_bins;
}

// Decimation in Frequency (DIF) splits by first and second halves
std::vector<std::complex<double>> dif(std::vector<std::complex<double>>& input)
{
    size_t N = input.size();
    // Base case
    if(N == 1)
    {
        return input;
    }

    // Prepare halves
    size_t num_elems = N / 2;

    auto h1 = std::vector<std::complex<double>>(input.begin(), input.begin() + num_elems);
    auto h2 = std::vector<std::complex<double>>(input.begin() + num_elems, input.end());

    auto even = dif(h1);
    auto odd  = dif(h2);

    std::vector<std::complex<double>> freq_bins(N, 0);
    for(size_t k = 0; k < N / 2; k++)
    {
        std::complex<double> rhs = std::polar(1.0, -2 * M_PI * k / N) * odd[k];
        freq_bins[k]             = even[k] + rhs;
        freq_bins[k + N / 2]     = even[k] - rhs; // Account for symmetry relation
    }

    return freq_bins;
}

int main()
{
    // std::vector<std::complex<double>> input
    //     = {{0, 1}, {10, 12}, {4.5578, -7.92125}, {0.000123, -0.0009783}};

    std::vector<std::complex<double>> input;
    double                            tmp1, tmp2;
    while(std::cin >> tmp1 >> tmp2)
    {
        input.push_back({tmp1, tmp2});
    }

    auto dit_output = dit(input);

    for(auto& i : dit_output)
        std::cout << i << " ";
    std::cout << std::endl;

    auto dif_output = dif(input);

    for(auto& i : dit_output)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
