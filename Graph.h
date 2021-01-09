#pragma once
#include <string>



class Graph
{
public:
	Graph();
	virtual ~Graph();
	void link(int i, int j, int d);
	void down(int i, int j);
	void dump();
	void setName(int i, std::string name);
	void inacessable();
	bool isInaccessable(int n);
	void deadEnds();
	bool isDE(int n);
	void name(int n);
	void shortestPath(int n1, int n2);
	int minD(int d[], bool arr[]);
	void printPath(int p[], int j);
private:
	int graph[30][30];
	std::string S[30];
	int numNodes;
	int largeNum = 50000;
};

