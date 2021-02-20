#include <iostream>
#include <vector>
#include "PercolationStats.h"

int main() {
    int n, trials;
    std::cout << "Percolation point calculator!" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Specify an integer N for an NxN grid:" << std::endl;
    std::cin >> n; 
    std::cout << "How many trials do you want to perform?" << std::endl;
    std::cin >> trials;

    PercolationStats PercStats(n, trials);    

    std::cout << "Mean: " << PercStats.mean() << ", Variance: " << PercStats.variance() << ", 95% Confidence Interval: " 
                << PercStats.confidenceLo() << ", " << PercStats.confidenceHi() << std::endl;
    return 0;
}