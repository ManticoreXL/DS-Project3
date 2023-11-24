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
            m_Mat[i][j] = 0; // initialize by 0
    }
}

// constructor of matrix graph
MatrixGraph::~MatrixGraph()
{
    // delete 2D array
    for (int i = 0; i < m_Size; i++)
        delete[] m_Mat[i];
    delete[] m_Mat;
}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int> *m)
{
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m)
{
}

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

bool MatrixGraph::printGraph(ofstream *fout)
{
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
}