#include <iostream>

#include "Graph.h"

using namespace std;

void nameNode(Graph*);
void linkNodes(Graph*);
void removeEdge(Graph*);
void shortestPath(Graph*);
void printName(Graph*);

int main()
{
	cout << "****" << "Note: do not use node number 0." << endl << endl;
	Graph g;
	int request = 1;
	while (request > 0 && request <= 8)
	{
		cout << "What do you wish to do: " << endl;
		cout << "1) Name a node." << endl;
		cout << "2) Print inaccessable nodes." << endl;
		cout << "3) Link 2 nodes." << endl;
		cout << "4) Remove an edge." << endl;
		cout << "5) Print all dead ends." << endl;
		cout << "6) Print all edges." << endl;
		cout << "7) Shortest path between 2 edges." << endl;
		cout << "8) Print names of nodes." << endl;
		cout << "9) Exit." << endl;
		cin >> request;


		switch (request)
		{
		case 1:
			nameNode(&g);
			break;
		case 2:
			g.inacessable();
			break;
		case 3:
			linkNodes(&g);
			break;
		case 4:
			removeEdge(&g);
			break;
		case 5:
			g.deadEnds();
			break;
		case 6:
			g.dump();
			break;
		case 7:
			shortestPath(&g);
			break;
		case 8:
			printName(&g);
			break;
		}
	}
}


void nameNode(Graph* gr)
{
	int node; string name;
	cout << "Which node is to be named? (int value)" << endl;
	cin >> node;
	cout << "What will be the name of the node?" << endl;
	cin.ignore();
	getline(cin, name);

	gr->setName(node, name);
}

void linkNodes(Graph* gr)
{
	int n1; int n2; int wt;
	cout << "What is the first node?  (from)" << endl;
	cin >> n1;
	cout << "What is the second node? (to)" << endl;
	cin >> n2;
	cout << "What is the weight between them?" << endl;
	cin >> wt;

	gr->link(n1, n2, wt);
}

void removeEdge(Graph* gr)
{
	int n1; int n2;
	cout << "What is the first node?  (from)" << endl;
	cin >> n1;
	cout << "What is the second node? (to)" << endl;
	cin >> n2;

	gr->down(n1, n2);
}

void shortestPath(Graph* gr)
{
	int n1; int n2;
	cout << "What is the first node?  (from)" << endl;
	cin >> n1;
	cout << "What is the second node? (to)" << endl;
	cin >> n2;

	gr->shortestPath(n1, n2);
}

void printName(Graph* gr)
{
	int n;
	cout << "Which node would you like to get the name of?" << endl;
	cin >> n;

	gr->name(n);
}