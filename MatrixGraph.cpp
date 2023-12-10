#include "MatrixGraph.h"
#include <iostream>
#include <vector>
#include <string>

// constructor of matrix graph
MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size)
{
    // dynamic allocation of adjacent matrix
    m_Mat = new int *[size];
    for (int i = 0; i < size; i++)
    {
        m_Mat[i] = new int[size];
        for (int j = 0; j < size; j++)
            m_Mat[i][j] = -1; // initialize by 0 (no edge)
    }
}

// constructor of matrix graph
MatrixGraph::~MatrixGraph()
{
    if (m_Mat)
    {
        // delete 2D array
        for (int i = 0; i < m_Size; i++)
            delete[] m_Mat[i];
        delete[] m_Mat;
    }
}

// get undirected adjacent edges at vertex
void MatrixGraph::getAdjacentEdges(int vertex, map<int, int> *m)
{
    if (m_Mat == nullptr)
    {
        throw "void MatrixGraph::getAdjacentEdges(int vertex, map<int, int> *m) - matrix is empty";
        return;
    }

    // insert adjacent edges into map
    for (int i = 0; i < m_Size; i++)
        if (m_Mat[vertex - 1][i] != -1)
            m->insert(pair<int, int>(vertex - 1, m_Mat[vertex - 1][i]));
}

// get directed adjacent edges at vertex
void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m)
{
    if (m_Mat == nullptr)
    {
        throw "void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m) - matrix is empty";
        return;
    }

    // insert adjacent edges into map
    for (int i = 0; i < m_Size; i++)
        if (m_Mat[vertex - 1][i] != -1)
            m->insert(pair<int, int>(vertex - 1, m_Mat[vertex - 1][i]));
}

// insert new edge into m_Mat
void MatrixGraph::insertEdge(int from, int to, int weight)
{
    if (from - 1 > m_Size || to - 1 > m_Size)
    {
        throw "void MatrixGraph::insertEdge(int from, int to, int weight) - out of range";
        return;
    }
    // set (from, to) = weight
    m_Mat[from - 1][to - 1] = weight;
}

// print matrix graph
bool MatrixGraph::printGraph(ofstream *fout)
{
    if (m_Mat == nullptr)
    {
        throw "bool MatrixGraph::printGraph(ofstream *fout) - matrix is empty.";
        return false;
    }

    // display to_vertex of matrix
    *fout << "  ";
    for (int i = 0; i < m_Size; i++)
        *fout << " [" << i + 1 << "] ";
    *fout << endl;

    // display from_vertex and adjaceny matrix
    for (int i = 0; i < m_Size; i++)
    {
        *fout << "[" << i + 1 << "] ";
        for (int j = 0; j < m_Size; j++)
            *fout << m_Mat[i][j] << "  ";
        *fout << endl;
    }

    return true;
}