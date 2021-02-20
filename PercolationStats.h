#pragma once
#include <vector>
#include "Percolation.h"

class PercolationStats {
private:
    int m_trials;
    int m_N;
    std::vector<double> percResults;

    void OpenRandomCell(Percolation& perc);
public:
    PercolationStats(int n, int trials);
    double mean();
    double variance();
    double confidenceHi();
    double confidenceLo();
};