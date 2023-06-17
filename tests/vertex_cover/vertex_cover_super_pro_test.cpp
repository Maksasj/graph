#include "test.h"

int main() {
    using namespace graph;

    TEST_CASE {
        Graph<int, int> g;

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 0);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_no_direct_edge(0, 0);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 1);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 1);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_edge(0, 1);
        g.add_edge(0, 2);
        g.add_edge(1, 2);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 2);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 0);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 2);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(0, 2);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 1);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 2);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 3);
        g.add_no_direct_edge(3, 4);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 2);
    }

    TEST_CASE {
        Graph<int, int> g;
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 0);
    }

    TEST_CASE {
        Graph<int, int> g;
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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;
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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;
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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;
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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 4);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 4);
    }

    TEST_CASE {
        Graph<int, int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(1, 2);
        g.add_no_direct_edge(2, 0);
        g.add_no_direct_edge(1, 3);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 2);
    }

    TEST_CASE {
        Graph<int, int> g;

        g.add_vertex();
        g.add_vertex();
        g.add_vertex();
        g.add_vertex();

        g.add_no_direct_edge(0, 1);
        g.add_no_direct_edge(0, 2);
        g.add_no_direct_edge(0, 3);

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 1);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 4);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 5);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 3);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 4);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 6);
    }
    
    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 4);
    }

    TEST_CASE {
        Graph<int, int> g;

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

        auto p = Algorithm::vertex_cover_brute_force_algorithm_super_pro(g);

        ensure(p.first == 5);
    }

    return 0;   
}