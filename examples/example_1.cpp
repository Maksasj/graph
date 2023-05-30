#include <vector>
#include <iostream>

#include "graph.h"

int main() {
    using namespace std;
    using namespace graph;

    Graph<int> g;

    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();

    g.add_no_direct_edge(0, 2);
    g.add_no_direct_edge(1, 2);
    g.add_no_direct_edge(3, 2);

    auto n = g.get_neighbour_vertex(2);
    for(auto& i : n) {
        cout << "i:" << i << " ";
    } 
    cout << "\n";

    g.traverse();

    g.erase_vertex(1);

    g.traverse();
    
    g.add_no_direct_edge(1, 1);

    g.traverse();

    std::cout << g.count_no_direct_edges(2) << "\n";
    std::cout << g.edge_size() << "\n";

    g.erase_vertex(1);
    
    g.traverse();

    std::cout << g.edge_size() << "\n";

    return 0;
}