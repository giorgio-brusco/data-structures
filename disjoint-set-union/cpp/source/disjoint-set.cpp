#include "disjoint-set.hpp"
#include <algorithm>
#include <numeric>

using namespace std;


dsu::dsu(int n) 
{
    parent.resize(n);
    size.resize(n,1);
    max_size = 1;
    iota(parent.begin(), parent.end(), 0);
}

dsu::dsu(const vector<int>& parent_init) : parent(parent_init) {
    size_t parent_size = parent.size();
    size.resize(parent_size);
    // Compute size of each disjoint set without modifying parent
    for (size_t i = 0; i < parent_size; ++i) {
        int root = parent[i];
        size[root]++;
    }
    max_size = *max_element(size.begin(), size.end());
}

const vector<int>& dsu::getParent(){
    return parent;
}

/*
int find(int x) {
    
    while(parent[numToPos[x]] != numToPos[x]) {
        x = parent[numToPos[x]];
    }
    return numToPos[x];
}
*/

// preprocessor directive to switch between the recursive and iterative implementations
int dsu::find(int x) {
#ifdef RECURSIVE_FIND
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
#else
    while (parent[x] != x) {
        int tmp = parent[x];
        parent[x] = parent[parent[x]];
        x = tmp;
    }
    return parent[x];
#endif
}

void dsu::unite(int x, int y) {
    
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX == rootY) return;
    
    if (size[rootX] < size[rootY]) swap(rootX, rootY);
    size[rootX] += size[rootY];
    parent[y] = rootX;
    if(size[rootX] > max_size) max_size = size[rootX];
}

int dsu::maxSize() {
    return max_size;
}
