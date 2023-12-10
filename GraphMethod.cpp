#include <iostream>
#include <vector>
#include "GraphMethod.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

using namespace std;

// breadth first search
bool BFS(Graph *graph, char option, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool BFS(Graph *graph, char option, int vertex) - invalid graph.";
        return false;
    }

    // get size of graph
    int size = graph->getSize();
    if (vertex >= size)
    {
        throw "bool BFS(Graph *graph, char option, int vertex) - invalid vertex.";
        return false;
    }

    // open log.txt
    ofstream fout("log.txt", ios::app);

    // create visit list
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

    // create queue to save next visit vertex
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

    // print start vertex
    fout << "startvertex: " << vertex << endl;

    // breadth first search
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        // print visited vertex
        fout << curr;
       
        // create adjacency list
        map<int, int> edges;

        // get adjacency edges
        if (option == 'Y')
            graph->getAdjacentEdgesDirect(curr, &edges);
        else if (option == 'N')
            graph->getAdjacentEdges(curr, &edges);
        else
        {
            throw "bool BFS(Graph *graph, char option, int vertex) - invalid option.";
            delete[] visited;
            return false;
        }

        // insert next visit vertex into queue
        for (const auto& edge : edges)
        {
            int neighbor = edge.first;
            if (visited[neighbor] == false)
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }

        // print ->
        if (!q.empty())
            fout << " -> ";
    }

    fout << endl;

    delete[] visited;
    return true;
}

// depth first search
bool DFS(Graph *graph, char option, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool DFS(Graph *graph, char option, int vertex) - invalid graph.";
        return false;
    }

    int size = graph->getSize();
    if (size <= vertex)
    {
        throw "bool DFS(Graph *graph, char option, int vertex) - vertex is over than size.";
        return false;
    }

    // open log.txt
    ofstream fout("log.txt", ios::app);

    // create visit list
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

    // print start vertex
    fout << "startvertex: " << vertex << endl;

    // call DFS recursive function
    DFSHelper(graph, option, vertex, visited, fout);

    delete[] visited;
    fout << endl;
    return true;
}

// DFS recursive function
bool DFSHelper(Graph *graph, char option, int vertex, bool* visited, ofstream& fout)
{
    visited[vertex - 1] = true;
    fout << vertex;

    // create adjacency list
    map<int, int> edges;

    // get adjacency edges
    if (option == 'Y')
        graph->getAdjacentEdgesDirect(vertex, &edges);
    else if(option == 'N')
        graph->getAdjacentEdges(vertex, &edges);
    else
    {
        throw "bool DFSHelper(Graph *graph, char option, int vertex, bool* visited, ofstream &fout) - invalid option.";
        delete[] visited;
        return false;
    }

    // call recursive DFSHelper edge by edge
    for (const auto& edge : edges)
    {
        int neighbor = edge.first;
        if (visited[neighbor] == false)
        {
            fout << " -> ";
            DFSHelper(graph, option, neighbor, visited, fout);
        }
    }
}

// kruskal MST generation
bool Kruskal(Graph *graph)
{
    if (graph == nullptr)
    {
        throw "bool Kruskal(Graph *graph) - invalid graph.";
        return false;
    }
}

bool Dijkstra(Graph *graph, char option, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool Dijkstra(Graph *graph, char option, int vertex) - invalid graph.";
        return false;
    }
}

bool Bellmanford(Graph *graph, char option, int s_vertex, int e_vertex)
{
    if (graph == nullptr)
    {
        throw "bool Bellmanford(Graph *graph, char option, int s_vertex, int e_vertex) - invalid graph.";
        return false;
    }
}

bool FLOYD(Graph *graph, char option)
{
    if (graph == nullptr)
    {
        throw "bool FLOYD(Graph *graph, char option) - invalid graph";
        return false;
    }
}

bool KWANGWOON(Graph *graph, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool KWANGWOON(Graph *graph, int vertex) - invalid graph";
        return false;
    }
}