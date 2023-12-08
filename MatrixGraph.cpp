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

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int> *m)
{
    if (m_Mat == nullptr)
    {
        throw "void MatrixGraph::getAdjacentEdges(int vertex, map<int, int> *m) - matrix is empty";
        return;
    }

    if (m_Type == true) // case 1: directed -> undirected
    {
        // copy only under diagonal
        for (int i = 0; i < m_Size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // no edge but opposite direction edge is existing
                if (m_Mat[i][j] == 0 || m_Mat[j][i] != 0)
                    m[i].insert(pair<int, int>(j, m_Mat[j][i]));
                else // insert edge
                    m[i].insert(pair<int, int>(j, m_Mat[i][j]));
            }
        }
    }
    else // case 2: undirected -> undirected
    {
        // just copy it
        for (int i = 0; i < m_Size; i++)
            for (int j = 0; j < m_Size; j++)
                m[i].insert(pair<int, int>(j, m_Mat[i][j]));
    }
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m)
{
    if (m_Mat == nullptr)
    {
        throw "void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int> *m) - matrix is empty";
        return;
    }

    if (m_Type == true) // case 1: directed -> directed
    {
        // just copy it
        for (int i = 0; i < m_Size; i++)
            for (int j = 0; j < m_Size; j++)
                m[i].insert(pair<int, int>(j, m_Mat[i][j]));
    }
    else // case 2: undirected -> directed
    {
        // copy under the diagonal
        for (int i = 0; i < m_Size; i++)
            for (int j = 0; j < i; j++)
                m[i].insert(pair<int, int>(j, m_Mat[i][j]));
    }
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