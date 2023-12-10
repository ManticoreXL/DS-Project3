#include "Manager.h"
#include <iomanip>

int main()
{
	// Manager ds;	//Declare DS
	// ds.run("command.txt");	//Run Program
	// return 0;	//Return Program

	try
	{
		ofstream fout("log.txt");
		ListGraph g(false, 5);
		g.insertEdge(1, 2, 3);
		g.insertEdge(2, 3, 3);
		g.insertEdge(3, 4, 3);
		g.insertEdge(4, 1, 3);
		g.printGraph(&fout);
		BFS(&g, 'Y', 1);
		DFS(&g, 'Y', 1);
	}
	catch(const char* err)
	{
		cout << err << endl;
	}


	return 0;
}