#include"List.h"           //This code only applies to undirected graph
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct GraphAdjList {
	vector<LinkedList> nodes;   
	int nodes_num;
	int edges_num;
};

void GetNodes(GraphAdjList& graph)
{
	cin >> graph.nodes_num;    //input the number of nodes
	for (int i = 0; i != graph.nodes_num; ++i) {
		LinkedList l;
		l.Insert(i, l.Header());
		graph.nodes.push_back(l); //nodes are numbered from 0 to graph.nodes_num-1
	}
}

void GetEdges(GraphAdjList& graph)
{
	int a, b;
	cin >> graph.edges_num;     //input the number of edges
	for (int i = 0; i != graph.edges_num; ++i) {
		cin >> a >> b;    //(a,b)——there's an edge between node a and b
		graph.nodes[a].Insert(b, graph.nodes[a].First());
		graph.nodes[b].Insert(a, graph.nodes[b].First());
	}
}

void PrintGraph(const GraphAdjList& graph)
{
	for (const auto& i : graph.nodes) {
		cout << i << endl;
	}
}

int main()
{
	GraphAdjList graph;
	GetNodes(graph);
	GetEdges(graph);
	PrintGraph(graph);
	return 0;
}

//input:
//4
//5
//0 1
//0 2
//0 3
//1 2
//2 3

//output:
//0 3 2 1
//count = 4
//1 2 0
//count = 3
//2 3 1 0
//count = 4
//3 2 0
//count = 3

