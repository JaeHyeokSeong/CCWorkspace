#ifndef PRIM_HPP
#define PRIM_HPP
#include <vector>

namespace my_algorithm {
    int prim(std::vector<std::pair<int,int> >* edges, int totalNodeNumber, int startNode);
}

#endif // PRIM_HPP