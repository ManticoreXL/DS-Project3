#include "ListGraph.h"
#include <iostream>
#include <utility>

// constructor of ListGraph
ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
}

ListGraph::~ListGraph()
{
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
        }
    }
}

void ListGraph::insertEdge(int from, int to, int weight) // Definition of insertEdge
{
}

bool ListGraph::printGraph(ofstream *fout) // Definition of print Graph
{
}