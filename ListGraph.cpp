#include "ListGraph.h"
#include <iostream>
#include <utility>

// constructor of ListGraph
ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
    // create new m_List and kw_graph
    m_List = new map<int, int>[size];
    kw_graph = new vector<int>;
}

// destructor of ListGraph
ListGraph::~ListGraph()
{
    // delete memory of m_List and kw_graph
    if (m_List)
        delete[] m_List;
    if (kw_graph)
        delete[] kw_graph;
}

// get undirected adjacent edges at vertex
void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m) // Definition of getAdjacentEdges(No Direction == Undirected)
{
    if (m_List == nullptr || vertex < 0 || vertex >= m_Size)
    {
        throw "void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m) - invalid parameter.";
        return;
    }

    *m = m_List[vertex - 1];
}

// get directed adjacent edges at vertex
void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m) // Definition of getAdjacentEdges(Directed graph)
{
    if (m_List == nullptr || vertex < 0 || vertex >= m_Size)
    {
        throw "void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m) - invalid parameter.";
        return;
    }

    *m = m_List[vertex - 1];
}

// insert new edge into m_List
void ListGraph::insertEdge(int from, int to, int weight) // Definition of insertEdge
{
    if (m_List == nullptr || from < 0 || from >= m_Size || to < 0 || to >= m_Size)
    {
        throw "void ListGraph::insertEdge(int from, int to, int weight) - invalid parameter.";
        return;
    }

    // insert (from, to)->weight into map
    m_List[from - 1].insert(pair<int, int>(to, weight));
}

// print list graph
bool ListGraph::printGraph(ofstream *fout) // Definition of print Graph
{
    if (m_List == nullptr)
    {
        throw "bool ListGraph::printGraph(ofstream *fout) - list is empty.";
        return false;
    }

    for (int i = 0; i < m_Size; i++)
    {
        // print from vertex
        *fout << i+1 << "-> ";

        // print adjacency list's item
        for (auto it = m_List[i].begin(); it != m_List[i].end(); it++)
        {
            *fout << "(" << it->first << ", " << it->second << ")";
            if (++it != m_List[i].end()) // check for ->
                *fout << " -> ";

            it--; // move back
            *fout << endl;
        }
    }
}