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
bool BFS(Graph* graph, char option, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool BFS(Graph *graph, char option, int vertex) - invalid graph.";
        return false;
    }

    // get size of graph
    int size = graph->getSize() + 1;
    if (vertex >= size)
    {
        throw "bool BFS(Graph *graph, char option, int vertex) - invalid vertex.";
        return false;
    }

    // open log.txt
    ofstream fout("log.txt", ios::app);

    // create visit list
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++)
        visited[i] = false;

    // create queue to save next visit vertex
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

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

    fout.close();
    delete[] visited;
    return true;
}

// depth first search
bool DFS(Graph* graph, char option, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool DFS(Graph *graph, char option, int vertex) - invalid graph.";
        return false;
    }

    int size = graph->getSize() + 1;
    if (vertex >= size)
    {
        throw "bool DFS(Graph *graph, char option, int vertex) - vertex is over than size.";
        return false;
    }

    // open log.txt
    ofstream fout("log.txt", ios::app);

    // create visit list
    bool* visited = new bool[size];
    for (int i = 1; i < size; i++)
        visited[i] = false;

    // create stack to remember backtracking vertex
    stack<int> s;
    s.push(vertex);

    // counter for printing ->
    int counter = 0;

    while (!s.empty())
    {
        int curr = s.top();
        s.pop();

        if (visited[curr] == false)
        {
            fout << curr;
            visited[curr] = true;
            counter++;
        }
        else
            continue;

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

        for (const auto& edge : edges)
        {
            int neighbor = edge.first;
            if (visited[neighbor] == false)
                s.push(neighbor);
        }

        // print ->
        if (!s.empty() && counter < size - 1)
            fout << " -> ";
    }

    fout << endl;

    fout.close();
    delete[] visited;
    return true;
}

// Kruskal MST generation
bool Kruskal(Graph* graph)
{
    if (graph == nullptr)
    {
        throw "bool Kruskal(Graph *graph) - invalid graph.";
        return false;
    }

    return true;
}

// Dijkstra
bool Dijkstra(Graph* graph, char option, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool Dijkstra(Graph *graph, char option, int vertex) - invalid graph.";
        return false;
    }

    int size = graph->getSize() + 1;
    if (vertex >= size)
    {
        throw "bool DFS(Graph *graph, char option, int vertex) - vertex is over than size.";
        return false;
    }

    // open log.txt
    ofstream fout("log.txt", ios::app);

    // create a priority queue to store vertices with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // create a vector to store distances from the source vertex
    vector<int> distance(size, INT_MAX);
    distance[vertex] = 0;

    // create a vector to store the previous vertex on the shortest path
    vector<int> previous(size, -1);

    // insert source vertex into priority queue
    pq.push({ 0, vertex });

    while (!pq.empty())
    {
        int curr = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        // Skip if this vertex has been processed already
        if (curr_dist > distance[curr])
            continue;

        // Create adjacency list
        map<int, int> edges;

        // Get adjacency edges
        if (option == 'Y')
            graph->getAdjacentEdgesDirect(curr, &edges);
        else if (option == 'N')
            graph->getAdjacentEdges(curr, &edges);
        else
        {
            throw "bool Dijkstra(Graph *graph, char option, int vertex) - invalid option.";
            return false;
        }

        // Relaxation step
        for (const auto& edge : edges)
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distance[curr] + weight < distance[neighbor])
            {
                distance[neighbor] = distance[curr] + weight;
                previous[neighbor] = curr;
                pq.push({ distance[neighbor], neighbor });
            }
        }
    }

    // Output the result
    for (int i = 1; i < size; ++i)
    {
        if (i == vertex)
            fout << "[" << i << "]x" << endl;
        else
        {
            fout << "[" << i << "]";
            // Print the shortest path
            int prev = i;
            while (prev != -1)
            {
                fout << prev;
                if (previous[prev] != -1)
                    fout << " -> ";
                prev = previous[prev];
            }
            fout << " (" << distance[i] << ")" << endl;
        }
    }

    fout.close();
    return true;
}

// BellmanFord
bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex)
{
    if (graph == nullptr)
    {
        throw "bool Bellmanford(Graph *graph, char option, int s_vertex, int e_vertex) - invalid graph.";
        return false;
    }

    return true;
}

// FLOYD
bool FLOYD(Graph* graph, char option)
{
    if (graph == nullptr)
    {
        throw "bool FLOYD(Graph *graph, char option) - invalid graph";
        return false;
    }

    return true;
}

// KWANGWOON
bool KWANGWOON(Graph* graph, int vertex)
{
    if (graph == nullptr)
    {
        throw "bool KWANGWOON(Graph *graph, int vertex) - invalid graph";
        return false;
    }

    int size = graph->getSize() + 1;
    if (vertex > size)
    {
        throw "bool KWANGWOON(Graph* graph, int vertex) - invalid vertex.";
        return false;
    }

    return true;
}