#include "Percolation.h"
#include <iostream>
#include <numeric>

Percolation::Percolation(int n) :m_numberOfOpenSites(0), m_N(n), m_UF(n*n), m_Cells(n, std::vector<SiteStatus>(n, SiteStatus::Blocked))
{
    for (int i = 0; i < n - 1; i++) 
    {
        // merge top row together
        m_UF.merge(cell(0,i), cell(0,i+1));
        // merge bottom row
        m_UF.merge(cell(m_N - 1, i), cell(m_N - 1, i+1));
    }
}

void Percolation::open(int row, int col) {
    m_Cells[row][col] = SiteStatus::Open;
    m_numberOfOpenSites++;
    if (row < m_N - 1 && m_Cells[row + 1][col] == SiteStatus::Open) m_UF.merge(cell(row,col), cell(row + 1, col));
    if (row > 0 && m_Cells[row - 1][col] == SiteStatus::Open) m_UF.merge(cell(row,col), cell(row - 1, col));
    if (col < m_N - 1 && m_Cells[row][col + 1] == SiteStatus::Open) m_UF.merge(cell(row,col), cell(row, col + 1));
    if (col > 0 && m_Cells[row][col - 1] == SiteStatus::Open) m_UF.merge(cell(row,col), cell(row, col - 1));
}

bool Percolation::isOpen(int row, int col) const 
{
    return m_Cells[row][col] == SiteStatus::Open;    
}

bool Percolation::isFull(int row, int col)
{
    return m_UF.connected(cell(row, col), cell(0,0));
}

int Percolation::numberOfOpenSites() const 
{
    return m_numberOfOpenSites; 
}

bool Percolation::percolates() 
{
    return m_UF.connected(cell(m_N-1, m_N-1), cell(0,0));    
}

int Percolation::cell(int row, int col) const 
{
    return row*m_N + col;
}

void Percolation::draw() const 
{
    bool first = true;
    std::cout << "+";
    for(int i = 0; i < m_N; i++) 
        {
            std::cout << "---+";
        }
    std::cout << std::endl;
    for (auto row : m_Cells){
        for (auto cell : row){
            if (first)
            {
                std::cout << "|";
                first = false;    
            } 
            if (cell == SiteStatus::Open) {
                std::cout << " * ";
            } 
            else
            {
                std::cout << "   ";
            }
            std::cout << "|";    
        }
        first = true;
        std::cout << std::endl;
        std::cout << "+";
        for(int i = 0; i < m_N; i++) 
        {
            std::cout << "---+";
        }
        std::cout << std::endl;
    }
}
