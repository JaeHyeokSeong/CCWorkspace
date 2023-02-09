#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

namespace my_algorithm{
    int getParent(int* parents, int node);
    void unionParent(int* parents, int node1, int node2);
    bool unionFind(int* parents, int node1, int node2);
}

#endif // UNION_FIND_HPP