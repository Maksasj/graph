#include <vector>
#include <iostream>

#include "graph.h"

int main() {
    using namespace std;
    using namespace graph;

    Graph<int> g;

    g.add_vertex(); // 0
    g.add_vertex(); // 1
    g.add_vertex(); // 2
    g.add_vertex(); // 3
    g.add_vertex(); // 4
    g.add_vertex(); // 5
    g.add_vertex(); // 6

    g.add_no_direct_edge(0, 1);
    g.add_no_direct_edge(0, 3);
    g.add_no_direct_edge(1, 2);
    g.add_no_direct_edge(1, 4);
    g.add_no_direct_edge(2, 5);
    g.add_no_direct_edge(2, 6);
    g.add_no_direct_edge(4, 5);

    g.traverse();

    std::cout << "Greedy: "<< Algorithm::vertex_cover_greedy_algorithm(g) << "\n";
    std::cout << "Brute force: "<< Algorithm::vertex_cover_brute_force_algorithm(g) << "\n";

    return 0;
}