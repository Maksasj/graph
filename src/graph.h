#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

namespace graph {
    using namespace std;
    
    template<class I_EdgeType>
    class Graph {
        private:
            struct EdgeInstance {
                bool _enabled = false;
                I_EdgeType _edgeValue;
            };
            vector<vector<EdgeInstance>> _adjacencyMatrix;
            size_t _edgeCount;
            
        public:
            using edgeType = I_EdgeType;

            friend struct Algorithm;

            Graph() : _edgeCount(0) {

            }

            void add_vertex() {
                const size_t currentSize = _adjacencyMatrix.size(); 
                _adjacencyMatrix.push_back(vector<EdgeInstance>(currentSize));

                for(auto& collum : _adjacencyMatrix)
                    collum.push_back(EdgeInstance());
            }

            void erase_vertex(const size_t& vertex) {
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
            }

            size_t count_no_direct_edges(const size_t& vertex) const {
                size_t count = 0;

                for(const auto& edge : _adjacencyMatrix[vertex])
                    if(edge._enabled == true) ++count;

                return count;
            }

            vector<size_t> get_neighbour_vertex(const size_t& vertex) {
                unordered_set<size_t> neighbours;

                for(size_t i = 0; i < _adjacencyMatrix.size(); ++i)
                    if(_adjacencyMatrix[vertex][i]._enabled == true)
                        neighbours.insert(i);

                for(size_t i = 0; i < _adjacencyMatrix.size(); ++i)
                    if(_adjacencyMatrix[i][vertex]._enabled == true)
                        neighbours.insert(i);
                        
                return vector<size_t>(neighbours.begin(), neighbours.end());
            }

            void add_edge(const size_t& first, const size_t& second) {
                if(_adjacencyMatrix[first][second]._enabled == false)
                    ++_edgeCount;

                _adjacencyMatrix[first][second]._enabled = true;
            }

            bool is_edge_exist(const size_t& first, const size_t& second) const {
                return _adjacencyMatrix[first][second]._enabled;
            }

            void add_no_direct_edge(const size_t& first, const size_t& second) {
                add_edge(first, second);
                add_edge(second, first);
            }

            void erase_edge(const size_t& first, const size_t& second) {
                if(_adjacencyMatrix[first][second]._enabled == true)
                    --_edgeCount;
                
                _adjacencyMatrix[first][second]._enabled = false;
            }

            void erase_no_direct_edge(const size_t& first, const size_t& second) {
                erase_edge(first, second);
                erase_edge(second, first);
            }

            size_t vertex_size() const {
                return _adjacencyMatrix.size();
            }

            size_t edge_size() const {
                return _edgeCount;
            }

            void traverse() const {
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
    };

    struct Algorithm {
        template<class G>
        static size_t find_max_deg_vertex(const G& graph) {
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
        static size_t vertex_cover_greedy_algorithm(G graph) {
            size_t s = 0;

            while (graph.edge_size() / 2 > 0) {
                const auto vertex = find_max_deg_vertex(graph);
                graph.erase_vertex(vertex);
                ++s;
            }

            return s;
        }

        template<class G>
        static pair<size_t, vector<int>> vertex_cover_greedy_algorithm_pro(G graph) {
            size_t s = 0;
            vector<int> vertexSubset;

            while (graph.edge_size() / 2 > 0) {
                const auto vertex = find_max_deg_vertex(graph);
                graph.erase_vertex(vertex);
                vertexSubset.push_back(static_cast<int>(vertex));
                ++s;
            }

            sort(vertexSubset.begin(), vertexSubset.end());

            return make_pair(s, vertexSubset);
        }

        template<class G>
        static size_t vertex_cover_brute_force_algorithm(const G& graph) {
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
        static pair<size_t, vector<int>> vertex_cover_brute_force_algorithm_pro(const G& graph) {
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

            return make_pair(s, out);
        }
    };
}

#endif