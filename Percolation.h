#pragma once
#include <vector>
#include "UnionFind.h"

class Percolation {
private:
    enum class SiteStatus {
        Open, Blocked, Full
    };
    int m_numberOfOpenSites;
    int const m_N;
    std::vector<std::vector<SiteStatus>> m_Cells;
    UnionFind m_UF;
    int cell(int row, int col) const;
public:
    Percolation(int n);
    void open(int row, int col);
    bool isOpen(int row, int col) const;
    bool isFull(int row, int col);
    int numberOfOpenSites() const;
    bool percolates();
    void draw() const;
};