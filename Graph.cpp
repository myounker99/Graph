#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = -1;
		}
		S[i] = "unkown";
	}

	cout << "How many nodes will there be?" << endl;
	cin >> numNodes;

	for (int i = 1; i <= numNodes; i++)
	{
		for (int j = 1; j <= numNodes; j++)
		{
			if (graph[i][j] == -1)
				graph[i][j] = largeNum;
		}
	}

}


Graph::~Graph()
{
}

void Graph::link(int i, int j, int d)
{
	graph[i][j] = d;
}

void Graph::down(int i, int j)
{
	graph[i][j] = largeNum;
}

void Graph::dump()
{
	cout << "==========" << endl;
	for (int i = 1; i <= numNodes; i++)
	{
		for (int j = 1; j <= numNodes; j++)
		{
			if (graph[i][j] != 0 && graph[i][j] != largeNum)
			{
				cout << S[i] << " (node " << i << ") connects to " << S[j] << " (node " << j << ") with weight " << graph[i][j] << endl;
				cout << "==========" << endl;
			}
		}
	}
}

void Graph::setName(int i, string name)
{
	S[i] = name;
}

void Graph::inacessable()
{
	cout << endl << "Inaccessable nodes: " << endl;
	for (int i = 1; i <= numNodes; i++)
	{
		if (isInaccessable(i))
			cout << "node " << i << ": " << S[i] << endl;
	}
	cout << endl;
}

bool Graph::isInaccessable(int n)
{
	for (int i = 1; i <= numNodes; i++)
	{
		if (graph[i][n] != 0 && graph[i][n] != largeNum)
			return false;
	}
	return true;
}

void Graph::deadEnds()
{
	cout << endl << "Dead end nodes: " << endl;
	for (int i = 1; i <= numNodes; i++)
	{
		if (isDE(i))
			cout << "node " << i << ": " << S[i] << endl;
	}
	cout << endl;
}

bool Graph::isDE(int n)
{
	for (int j = 1; j <= numNodes; j++)
	{
		if (graph[n][j] != 0 && graph[n][j] != largeNum)
			return false;
	}
	return true;
}

void Graph::name(int n)
{
	cout << "Name of node " << n << ": " << S[n] << endl;
}

void Graph::shortestPath(int n1, int n2)
{
	int dist[30];
	bool included[30];
	int pth[30];

	for (int i = 0; i < 30; i++)
	{
		pth[i] = -1;
		dist[i] = largeNum;
		included[i] = false;
	}

	dist[n1] = 0;

	for (int i = 1; i <= numNodes; i++)
	{
		int m = minD(dist, included);

		included[i] = true;

		for (int i = 1; i <= numNodes; i++)
		{
			if (!included[i] && graph[m][i] && dist[m] + graph[m][i] < dist[i])
			{
				pth[i] = m;
				dist[i] = dist[m] + graph[m][i];
			}
		}
	}

	bool foundPath = false;
	for(int i = 0; i < 30; i++)
	{
		if (pth[i] != -1)
		{
			foundPath = true;
		}
	}

	if (!foundPath)
	{
		cout << "No path found" << endl << endl;
		return;
	}

	cout << endl << endl;
	cout << n1 << "     ::     ";
	printPath(pth, n2);

	cout << endl << endl;
}

void Graph::printPath(int p[], int j)
{
	if (p[j] == -1)
		return;

	printPath(p, p[j]);

	cout << j << "     ::     ";
}

int Graph::minD(int d[], bool arr[])
{
	int min = largeNum;
	int indx;

	for (int i = 1; i <= numNodes; i++)
	{
		if (arr[i] == false && d[i] <= min)
		{
			min = d[i];
			indx = i;
		}
	}
		

	return indx;
}
  