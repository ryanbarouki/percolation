#include "PercolationStats.h"
#include "Percolation.h"
#include <stdlib.h>
#include <time.h>
#include <numeric>
#include <math.h>
#include <iostream>

PercolationStats::PercolationStats(int n, int trials):m_N(n), m_trials(trials)
{
    srand(time(NULL));
    for (int i = 0; i < trials; ++i) 
    {
        Percolation perc(n);
        while (!perc.percolates())
        {
            OpenRandomCell(perc);
        }
        double result = static_cast<double>(perc.numberOfOpenSites()) / (n*n);
        percResults.push_back(result);
    }
}

double PercolationStats::mean() 
{
    return std::accumulate(percResults.begin(), percResults.end(), 0.0) / m_trials;
}

double PercolationStats::variance() 
{
    double xbar = mean();
    std::vector<double> diffSq;

    for (auto res : percResults)
    {
        diffSq.push_back((res - xbar)*(res - xbar));
    }

    return std::accumulate(diffSq.begin(), diffSq.end(), 0.0) / (m_trials - 1);
}

double PercolationStats::confidenceHi() 
{
    double s = std::sqrt(variance());
    double xbar = mean();

    return xbar + 1.96*s / std::sqrt(m_trials);
}

double PercolationStats::confidenceLo() 
{
    double s = std::sqrt(variance());
    double xbar = mean();

    return xbar - 1.96*s / std::sqrt(m_trials);  
}

void PercolationStats::OpenRandomCell(Percolation& perc) 
{
    int row = rand() % m_N; //number between 0 and m_N - 1 
    int col = rand() % m_N; //number between 0 and m_N - 1 
    if (perc.isOpen(row, col)) return;
    perc.open(row, col);
}
