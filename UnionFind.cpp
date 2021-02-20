#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
    // initialise the sites to all point to themselves so we have N disconnected components
    for (int i = 0; i < n; i++)
    {
        sites.push_back(i);
        sizeOfComponents.push_back(1);
    }   
}

void UnionFind::merge(int n1, int n2)
{
    int p = root(n1);
    int q = root(n2);
    // with weighting we need the sized of the component trees
    if (p == q) return;
    if (sizeOfComponents[p] >= sizeOfComponents[q])
    {
        sites[q] = p;
        sizeOfComponents[p] += sizeOfComponents[q];
    }
    else
    {
        sites[p] = q;
        sizeOfComponents[q] += sizeOfComponents[p];
    }
}

bool UnionFind::connected(int n1, int n2) 
{
    return root(n1) == root(n2);
}

int UnionFind::root(int n) 
{
    while (sites[n] != n)
    {
        // set index equal to the grandparent of n
        sites[n] = sites[sites[n]];
        n = sites[n];
    }
    return n;
}