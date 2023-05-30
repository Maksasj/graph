#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <unordered_set>

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
                if(edgesToBeDeleted != 0)
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

                _adjacencyMatrix[first][second] = EdgeInstance{true};
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
                
                _adjacencyMatrix[first][second] = EdgeInstance{false};
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

    };
}

#endif