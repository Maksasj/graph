#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

namespace graph {
    using namespace std;
    
    template<class I_VertexType, class I_EdgeType>
    class Graph {
        private:
            struct EdgeInstance {
                bool _enabled = false;
                I_EdgeType _edgeValue;
            };
            vector<I_VertexType> _vertices;
            vector<vector<EdgeInstance>> _adjacencyMatrix;
            size_t _edgeCount;
            
        public:
            using edgeType = I_EdgeType;
            using vertexType = I_VertexType;

            friend struct Algorithm;

            Graph();

            void add_vertex();

            void erase_vertex(const size_t& vertex);

            size_t count_no_direct_edges(const size_t& vertex) const;

            vector<size_t> get_neighbour_vertex(const size_t& vertex);

            void add_edge(const size_t& first, const size_t& second);

            bool is_edge_exist(const size_t& first, const size_t& second) const;

            void add_no_direct_edge(const size_t& first, const size_t& second);

            void erase_edge(const size_t& first, const size_t& second);

            void erase_no_direct_edge(const size_t& first, const size_t& second);

            size_t vertex_size() const;

            size_t edge_size() const;

            void traverse() const;
    };

    struct Algorithm {
        template<class G>
        static size_t find_max_deg_vertex(const G& graph);

        template<class G>
        static size_t vertex_cover_greedy_algorithm(G graph);

        template<class G>
        static pair<size_t, vector<int>> vertex_cover_greedy_algorithm_pro(G graph);

        template<class G>
        static size_t vertex_cover_brute_force_algorithm(const G& graph);

        template<class G>
        static pair<size_t, vector<int>> vertex_cover_brute_force_algorithm_pro(const G& graph);

        template<class G>
        static pair<size_t, vector<vector<int>>> vertex_cover_brute_force_algorithm_super_pro(const G& graph);
    };
}

namespace graph {
    using namespace std;

    /* Graph adt */
    template<class I_VertexType, class I_EdgeType>
    Graph<I_VertexType, I_EdgeType>::Graph() : _edgeCount(0) {

    }

    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::add_vertex() {
        const size_t currentSize = _adjacencyMatrix.size(); 
        _adjacencyMatrix.push_back(vector<EdgeInstance>(currentSize));

        for(auto& collum : _adjacencyMatrix)
            collum.push_back(EdgeInstance());

        _vertices.push_back(static_cast<int>(currentSize));
    }

    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::erase_vertex(const size_t& vertex) {
        // Recalculate edge count
        size_t edgesToBeDeleted = 0;

        for(auto& ed : _adjacencyMatrix[vertex])
            if(ed._enabled == true)
                ++edgesToBeDeleted;
        
        for(auto& collum : _adjacencyMatrix)
            if(collum[vertex]._enabled == true)
                ++edgesToBeDeleted;

        // One edge we counted twise
        if(_adjacencyMatrix[vertex][vertex]._enabled == true)
            --edgesToBeDeleted;

        _edgeCount -= edgesToBeDeleted;

        // Delete all vertexes
        _adjacencyMatrix.erase(_adjacencyMatrix.begin() + vertex);

        for(auto i = _adjacencyMatrix.begin(); i != _adjacencyMatrix.end(); ++i) {
            auto& collum = *i;
            collum.erase(collum.begin() + vertex);
        }

        _vertices.erase(_vertices.begin() + vertex);
    }

    template<class I_VertexType, class I_EdgeType>
    size_t Graph<I_VertexType, I_EdgeType>::count_no_direct_edges(const size_t& vertex) const {
        size_t count = 0;

        for(const auto& edge : _adjacencyMatrix[vertex])
            if(edge._enabled == true) ++count;

        return count;
    }

    template<class I_VertexType, class I_EdgeType>
    vector<size_t> Graph<I_VertexType, I_EdgeType>::get_neighbour_vertex(const size_t& vertex) {
        unordered_set<size_t> neighbours;

        for(size_t i = 0; i < _adjacencyMatrix.size(); ++i)
            if(_adjacencyMatrix[vertex][i]._enabled == true)
                neighbours.insert(i);

        for(size_t i = 0; i < _adjacencyMatrix.size(); ++i)
            if(_adjacencyMatrix[i][vertex]._enabled == true)
                neighbours.insert(i);
                
        return vector<size_t>(neighbours.begin(), neighbours.end());
    }
    
    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::add_edge(const size_t& first, const size_t& second) {
        if(_adjacencyMatrix[first][second]._enabled == false)
            ++_edgeCount;

        _adjacencyMatrix[first][second]._enabled = true;
    }

    template<class I_VertexType, class I_EdgeType>
    bool Graph<I_VertexType, I_EdgeType>::is_edge_exist(const size_t& first, const size_t& second) const {
        return _adjacencyMatrix[first][second]._enabled;
    }

    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::add_no_direct_edge(const size_t& first, const size_t& second) {
        add_edge(first, second);
        add_edge(second, first);
    }

    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::erase_edge(const size_t& first, const size_t& second) {
        if(_adjacencyMatrix[first][second]._enabled == true)
            --_edgeCount;
        
        _adjacencyMatrix[first][second]._enabled = false;
    }

    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::erase_no_direct_edge(const size_t& first, const size_t& second) {
        erase_edge(first, second);
        erase_edge(second, first);
    }
    
    template<class I_VertexType, class I_EdgeType>
    size_t Graph<I_VertexType, I_EdgeType>::vertex_size() const {
        return _adjacencyMatrix.size();
    }

    template<class I_VertexType, class I_EdgeType>
    size_t Graph<I_VertexType, I_EdgeType>::edge_size() const {
        return _edgeCount;
    }

    template<class I_VertexType, class I_EdgeType>
    void Graph<I_VertexType, I_EdgeType>::traverse() const {
        const size_t currentSize = _adjacencyMatrix.size(); 

        cout << "   ";
        for(size_t i = 0; i < currentSize; ++i) {
            cout << i << " ";
        }

        cout << "\n";

        for(size_t i = 0; i < currentSize; ++i) {
            cout << i << ": ";
            for(size_t j = 0; j < currentSize; ++j) {
                cout << _adjacencyMatrix[i][j]._enabled << " ";
            }
            cout << "\n";
        }
    }

    /* Algorithms */
    template<class G>
    size_t Algorithm::find_max_deg_vertex(const G& graph) {
        size_t ver = 0;
        size_t deg = 0;
        for(size_t i = 0; i < graph._adjacencyMatrix.size(); ++i) {
            const auto tmpDeg = graph.count_no_direct_edges(i);
            if(tmpDeg > deg) {
                ver = i;
                deg = tmpDeg;
            }
        }

        return ver;
    };

    template<class G>
    size_t Algorithm::vertex_cover_greedy_algorithm(G graph) {
        size_t s = 0;

        while (graph.edge_size() / 2 > 0) {
            const auto vertex = find_max_deg_vertex(graph);
            graph.erase_vertex(vertex);
            ++s;
        }

        return s;
    }

    template<class G>
    pair<size_t, vector<int>> Algorithm::vertex_cover_greedy_algorithm_pro(G graph) {
        size_t s = 0;
        vector<int> vertexSubset;

        while ((graph.edge_size() /2 )> 0) {
            const auto vertex = find_max_deg_vertex(graph);
            vertexSubset.push_back(graph._vertices[vertex]);
            graph.erase_vertex(vertex);
            ++s;
        }

        sort(vertexSubset.begin(), vertexSubset.end(), greater<int>());

        return std::make_pair(s, vertexSubset);
    }

    template<class G>
    size_t Algorithm::vertex_cover_brute_force_algorithm(const G& graph) {
        const size_t graphSize = graph.vertex_size();
        const size_t subsetsCount = 1 << graphSize;

        size_t s = UINT64_MAX;
        
        // Binary string counting, iterating over all subsets of graph vertice set
        for (size_t mask = 0; mask < subsetsCount; ++mask) {
            vector<size_t> vertexSubset;

            for (size_t i = 0; i < graphSize; ++i)
                if (mask & (1 << i))
                    vertexSubset.push_back(i);

            sort(vertexSubset.begin(), vertexSubset.end(), std::less<size_t>());

            G subGraph = graph;

            for(auto it = vertexSubset.begin(); it != vertexSubset.end(); ++it) {
                const auto& vertex = *it;
                subGraph.erase_vertex(vertex);

                for(auto ot = it; ot != vertexSubset.end(); ++ot)
                    --(*ot);
            }

            const size_t subsetSize = vertexSubset.size();

            if(subGraph.edge_size() == 0 && s > subsetSize)
                s = subsetSize;
        }

        return s;
    }

    template<class G>
    pair<size_t, vector<int>> Algorithm::vertex_cover_brute_force_algorithm_pro(const G& graph) {
        const size_t graphSize = graph.vertex_size();
        const size_t subsetsCount = 1 << graphSize;

        size_t s = UINT64_MAX;
        vector<int> out;
        
        // Binary string counting, iterating over all subsets of graph vertice set
        for (size_t mask = 0; mask < subsetsCount; ++mask) {
            vector<size_t> vertexSubset;

            for (size_t i = 0; i < graphSize; ++i)
                if (mask & (1 << i))
                    vertexSubset.push_back(i);

            sort(vertexSubset.begin(), vertexSubset.end(), std::less<size_t>());
            vector<size_t> oldVertexSubset = vertexSubset;

            G subGraph = graph;

            for(auto it = vertexSubset.begin(); it != vertexSubset.end(); ++it) {
                const auto& vertex = *it;
                subGraph.erase_vertex(vertex);

                for(auto ot = it; ot != vertexSubset.end(); ++ot)
                    --(*ot);
            }

            const size_t subsetSize = vertexSubset.size();

            if(subGraph.edge_size() == 0 && s > subsetSize) {
                s = subsetSize;

                out.clear();

                for(const auto& v : oldVertexSubset) {
                    out.push_back(static_cast<int>(v));
                }
            }
        }

        sort(out.begin(), out.end(), greater<int>());

        return std::make_pair(s, out);
    }

    template<class G>
    pair<size_t, vector<vector<int>>> Algorithm::vertex_cover_brute_force_algorithm_super_pro(const G& graph) {
        const size_t graphSize = graph.vertex_size();
        const size_t subsetsCount = 1 << graphSize;

        size_t s = UINT64_MAX;
        vector<vector<int>> coverSets;
        
        // Binary string counting, iterating over all subsets of graph vertice set
        for (size_t mask = 0; mask < subsetsCount; ++mask) {
            vector<size_t> vertexSubset;

            for (size_t i = 0; i < graphSize; ++i)
                if (mask & (1 << i))
                    vertexSubset.push_back(i);

            sort(vertexSubset.begin(), vertexSubset.end(), std::less<size_t>());
            vector<size_t> oldVertexSubset = vertexSubset;

            G subGraph = graph;

            for(auto it = vertexSubset.begin(); it != vertexSubset.end(); ++it) {
                const auto& vertex = *it;
                subGraph.erase_vertex(vertex);

                for(auto ot = it; ot != vertexSubset.end(); ++ot)
                    --(*ot);
            }

            const size_t subsetSize = vertexSubset.size();

            if(subGraph.edge_size() == 0) {
                if(subsetSize < s) {
                    s = subsetSize;
                //     coverSets.clear();
                }

                // if(subsetSize == s) {
                    vector<int> out;
                    for(const auto& v : oldVertexSubset) {
                        out.push_back(static_cast<int>(v));
                    }

                    sort(out.begin(), out.end(), greater<int>());

                    coverSets.push_back(out);
                // }
            }
        }

        sort(coverSets.begin(), coverSets.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a.size() == b.size()) {
                const size_t size = a.size();

                for(size_t i = 0; i < size; ++i) {
                    if(a[i] != b[i]) {
                        return a[i] < b[i];
                    }
                }

                return false;
            } else {
                return a.size() > b.size();
            }

            return false;
        });

        return std::make_pair(s, coverSets);
    }
}

#endif