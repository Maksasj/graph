#include <iostream>
#include <string>

#include "graph.h"

void test_case(const std::string& name, const graph::Graph<int>& graph, const size_t expect) {
    using namespace std;
    using namespace graph;
    
    cout << "Test case: \"" << name << "\"\n";
    cout << "    Expected result: " << expect << "\n";
    {
        auto v = Algorithm::vertex_cover_greedy_algorithm(graph); 
        cout << "    Greedy result: " << v << "\n";
    }
    {
        auto v = Algorithm::vertex_cover_brute_force_algorithm(graph); 
        cout << "    Brute force result: " << v << "\n";

        if(v != expect) {
            cout << "    FAILED";
        }
    }
    cout << "\n";
}

int main() {
    using namespace std;
    using namespace graph;

    {
        Graph<int> g;
        g.add_vertex();
        g.add_no_direct_edge(0, 0);

        test_case("Single vertex loop #1", g, 1);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);

        test_case("Single edge #2", g, 1);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_edge(0, 1);
        g.add_edge(0, 2);
        g.add_edge(1, 2);

        test_case("Single polygon #3", g, 2);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 0);

        test_case("Single square #4", g, 2);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(0, 2);

        test_case("Short line #5", g, 1);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);

        test_case("Mediums line #6", g, 2);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);

        test_case("Long line #7", g, 2);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        test_case("No edge polygon #8", g, 0);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 1);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(4, 0);

        test_case("Two merged polygons #9", g, 3);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(5, 2);
        g.add_no_direct_edge(2, 6);
        g.add_no_direct_edge(6, 0);

        test_case("Two merged squares #10", g, 3);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(5, 2);
        g.add_no_direct_edge(2, 6);
        g.add_no_direct_edge(6, 0);

        test_case("Two merged squares 1 #10", g, 3);
    }

    {
        Graph<int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 0);
        g.add_no_direct_edge(3, 1);


        test_case("Merged polygon and square #11", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(5, 0);
        g.add_no_direct_edge(1, 4);

        test_case("Two merged squares 2 #12", g, 3);
    }


    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 0);

        test_case("Pentagon #13", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 0);

        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(5, 3);

        g.add_no_direct_edge(3, 0);
        g.add_no_direct_edge(4, 1);
        g.add_no_direct_edge(5, 2);

        test_case("3d Triangle #14", g, 4);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(3, 5);
        g.add_no_direct_edge(5, 6);
        g.add_no_direct_edge(6, 2);

        test_case("Shape 1 #15", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(5, 0);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(2, 4);

        test_case("Shape 2 #16", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 5);
        g.add_no_direct_edge(5, 1);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(4, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(5, 6);
        g.add_no_direct_edge(0, 6);

        test_case("Three polygons #17", g, 4);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 0);
        g.add_no_direct_edge(1, 3);

        test_case("Weird 1 #18", g, 2);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(0, 2);
        g.add_no_direct_edge(0, 3);

        test_case("Weird 2 #19", g, 1);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(4, 3);
        g.add_no_direct_edge(4, 2);

        test_case("Weird 3 #20", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(2, 1);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(4, 3);
        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(6, 5);
        g.add_no_direct_edge(6, 7);
        g.add_no_direct_edge(2, 5);

        test_case("Shape 3 #21", g, 4);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(0, 2);
        g.add_no_direct_edge(0, 3);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(3, 2);

        g.add_no_direct_edge(4, 2);
        g.add_no_direct_edge(5, 2);
        g.add_no_direct_edge(5, 4);
        g.add_no_direct_edge(6, 4);
        g.add_no_direct_edge(7, 4);

        g.add_no_direct_edge(7, 6);
        g.add_no_direct_edge(7, 5);
        g.add_no_direct_edge(8, 5);
        g.add_no_direct_edge(8, 7);

        test_case("Xmas tree #22", g, 5);
    }

    {
        Graph<int> g;

        g.add_vertex(); // 0
        g.add_vertex(); // 1
        g.add_vertex(); // 2

        g.add_vertex(); // 3
        g.add_vertex(); // 4
        g.add_vertex(); // 5
        g.add_vertex(); // 6

        g.add_no_direct_edge(0, 3);
        g.add_no_direct_edge(0, 4);
        g.add_no_direct_edge(0, 5);
        g.add_no_direct_edge(0, 6);

        g.add_no_direct_edge(1, 3);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(1, 5);
        g.add_no_direct_edge(1, 6);

        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(2, 4);
        g.add_no_direct_edge(2, 5);
        g.add_no_direct_edge(2, 6);

        test_case("nn 1 #23", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex(); // 0
        g.add_vertex(); // 1
        g.add_vertex(); // 2

        g.add_vertex(); // 3
        g.add_vertex(); // 4
        g.add_vertex(); // 5
        g.add_vertex(); // 6

        g.add_no_direct_edge(0, 3);
        g.add_no_direct_edge(0, 4);
        g.add_no_direct_edge(0, 5);
        g.add_no_direct_edge(0, 6);

        g.add_no_direct_edge(1, 3);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(1, 5);
        g.add_no_direct_edge(1, 6);

        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(2, 4);
        g.add_no_direct_edge(2, 5);
        g.add_no_direct_edge(2, 6);

        test_case("nn 1 #23", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex(); // 0
        g.add_vertex(); // 1
        g.add_vertex(); // 2

        g.add_vertex(); // 3
        g.add_vertex(); // 4
        g.add_vertex(); // 5
        g.add_vertex(); // 6

        g.add_vertex(); // 7
        g.add_vertex(); // 8
        g.add_vertex(); // 9
        g.add_vertex(); // 10

        g.add_no_direct_edge(0, 3);
        g.add_no_direct_edge(0, 4);
        g.add_no_direct_edge(0, 5);
        g.add_no_direct_edge(0, 6);
        g.add_no_direct_edge(0, 7);
        g.add_no_direct_edge(0, 8);
        g.add_no_direct_edge(0, 9);
        g.add_no_direct_edge(0, 10);

        g.add_no_direct_edge(1, 3);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(1, 5);
        g.add_no_direct_edge(1, 6);
        g.add_no_direct_edge(1, 7);
        g.add_no_direct_edge(1, 8);
        g.add_no_direct_edge(1, 9);
        g.add_no_direct_edge(1, 10);

        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(2, 4);
        g.add_no_direct_edge(2, 5);
        g.add_no_direct_edge(2, 6);
        g.add_no_direct_edge(2, 7);
        g.add_no_direct_edge(2, 8);
        g.add_no_direct_edge(2, 9);
        g.add_no_direct_edge(2, 10);

        test_case("nn 2 #24", g, 3);
    }

    {
        Graph<int> g;

        g.add_vertex(); // 0
        g.add_vertex(); // 1

        g.add_vertex(); // 2
        g.add_vertex(); // 3
        g.add_vertex(); // 4

        g.add_vertex(); // 5
        g.add_vertex(); // 6
        g.add_vertex(); // 7

        g.add_no_direct_edge(0, 2);
        g.add_no_direct_edge(0, 3);
        g.add_no_direct_edge(0, 4);
        g.add_no_direct_edge(0, 5);
        g.add_no_direct_edge(0, 6);
        g.add_no_direct_edge(0, 7);

        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(1, 3);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(1, 5);
        g.add_no_direct_edge(1, 6);
        g.add_no_direct_edge(1, 7);

        g.add_no_direct_edge(0, 1);

        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(4, 3);
        
        g.add_no_direct_edge(5, 6);
        g.add_no_direct_edge(7, 6);

        test_case("nn 3 connected #25", g, 4);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 2);
        g.add_no_direct_edge(0, 3);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(1, 4);
        g.add_no_direct_edge(2, 4);

        g.add_no_direct_edge(3, 2);
        g.add_no_direct_edge(5, 2);
        g.add_no_direct_edge(5, 3);
        g.add_no_direct_edge(5, 4);
        g.add_no_direct_edge(5, 6);

        g.add_no_direct_edge(3, 6);
        g.add_no_direct_edge(8, 4);
        g.add_no_direct_edge(8, 5);
        g.add_no_direct_edge(7, 5);
        g.add_no_direct_edge(7, 6);
        g.add_no_direct_edge(7, 8);

        g.add_no_direct_edge(7, 10);
        g.add_no_direct_edge(7, 9);
        g.add_no_direct_edge(8, 9);
        g.add_no_direct_edge(6, 10);

        test_case("A lot of polygons #26", g, 6);
    }
    
    {
        Graph<int> g;

        g.add_vertex(); // 0
        g.add_vertex(); // 1
        g.add_vertex(); // 2
        g.add_vertex(); // 3

        g.add_vertex(); // 4
        g.add_vertex(); // 5
        g.add_vertex(); // 6
        g.add_vertex(); // 7

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(2, 1);
        g.add_no_direct_edge(2, 3);

        g.add_no_direct_edge(4, 5);
        g.add_no_direct_edge(6, 5);
        g.add_no_direct_edge(6, 7);

        test_case("Two lines #27", g, 4);
    }

    {
        Graph<int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(2, 1);
        g.add_no_direct_edge(2, 5);
        g.add_no_direct_edge(2, 7);
        g.add_no_direct_edge(2, 8);

        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 6);
        g.add_no_direct_edge(4, 3);
        g.add_no_direct_edge(5, 6);
        g.add_no_direct_edge(7, 6);
        
        g.add_no_direct_edge(7, 8);

        test_case("Weird 4 #28", g, 5);
    }

    return 0;
}