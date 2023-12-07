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
	delete m_List;
    delete kw_graph;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m)	 //Definition of getAdjacentEdges(No Direction == Undirected)
{
	
}

void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m)	//Definition of getAdjacentEdges(Directed graph)
{
	
}

void ListGraph::insertEdge(int from, int to, int weight) //Definition of insertEdge
{
    // insert (from, to)->weight into map
	m_List[from-1].insert(pair<int, int>(to, weight));
}

bool ListGraph::printGraph(ofstream *fout)	//Definition of print Graph
{
    if(m_List == nullptr)
    {
        throw "bool ListGraph::printGraph(ofstream *fout) - list is empty.";
        return false;
    }

    // print adjacency list's item
	for(int i=0; i < m_Size; i++)
    {
        *fout << i << endl;
        for(auto it = m_List[i].begin(); it != m_List[i].end(); it++) 
            *fout << it->first << " " << it->second << endl; 
    }
}