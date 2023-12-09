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

// get undirected graph list
void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m) // Definition of getAdjacentEdges(No Direction == Undirected)
{
    if (m_List == nullptr)
    {
        throw "void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m) - list is empty.";
        return;
    }

    if (m_Type == true) // case: directed -> undirected
    {
        // copy and make opposite direction edge
        for (int i = 0; i < m_Size; i++)
        {
            for (auto it = m_List[i].begin(); it != m_List[i].end(); it++)
            {
                // insert original edge into m
                m[i].insert(pair<int, int>(it->first, it->second));

                // insert opposite direction edge into m
                if (m_List[it->first].find(i) != m_List[it->first].end())
                    m[it->first].insert(pair<int, int>(i, it->second));
            }
        }
    }
    else // case 2: undirected -> undirected
    {
        // just copy it
        for (int i = 0; i < m_Size; i++)
        {
            for (auto it = m_List[i].begin(); it != m_List[i].end(); it++)
                m[i].insert(pair<int, int>(it->first, it->second));
        }
    }
}

// get directed graph list
void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m) // Definition of getAdjacentEdges(Directed graph)
{
    if (m_List == nullptr)
    {
        throw "void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m) - list is empty.";
        return;
    }

    if (m_Type == true) // case: directed -> directed
    {
        for (int i = 0; i < m_Size; i++)
        {
            // just copy it
            for (auto it = m_List[i].begin(); it != m_List[i].end(); it++)
                m[i].insert(pair<int, int>(it->first, it->second));
        }
    }
    else // case 2: undirected -> directed
    {
        for (int i = 0; i < m_Size; i++)
        {
            // just copy it // remain maintain section
            for (auto it = m_List[i].begin(); it != m_List[i].end(); it++)
                m[i].insert(pair<int, int>(it->first, it->second));
        }
    }
}

void ListGraph::insertEdge(int from, int to, int weight) // Definition of insertEdge
{
    if (m_List == nullptr)
    {
        throw "void ListGraph::insertEdge(int from, int to, int weight) - list is empty.";
        return;
    }

    // insert (from, to)->weight into map
    m_List[from - 1].insert(pair<int, int>(to, weight));
}

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
        *fout << i << "-> " << endl;

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