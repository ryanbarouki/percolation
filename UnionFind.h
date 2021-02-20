#pragma once
#include <vector>

class UnionFind {
private:
    std::vector<int> sites;
    std::vector<int> sizeOfComponents; // we use this for path weighting

    int root(int n);
public:
    UnionFind(int n);
    void merge(int n1, int n2);
    bool connected(int n1, int n2);
};