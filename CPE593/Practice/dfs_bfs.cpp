#include<iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph {
private:
    int V;    // No. of vertices
    list<int> *adj;   
public:
    Graph(int V) : V(V), adj(new list<int>[V]) {};  // Constructor
    void addEdge(int v, int w) {
		adj[v].push_back(w); // Add w to v’s list.
	}
	
	
    void BFS(int s) {
		bool *visited = new bool[V];
		for(int i = 0; i < V; i++)
			visited[i] = false;
		list<int> queue;
		visited[s] = true;
		queue.push_back(s);
		while(!queue.empty()){
			s = queue.front();
			queue.pop_front();
			cout << s << " ";

			for (auto i = adj[s].begin(); i != adj[s].end(); ++i){
				if (!visited[*i]){
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
	}
	
    void DFS_It(int s) {
		bool *visited = new bool[V];
		for(int i = 0; i < V; i++)
			visited[i] = false;
		list<int> stack;
		visited[s] = true;
		stack.push_front(s);
		while (!stack.empty()) {
			s = stack.front();
			stack.pop_front();
			cout << s << ' ';
			for (auto i = adj[s].begin(); i != adj[s].end(); ++i){
				if (!visited[*i]){
					stack.push_front(*i);
					visited[*i] = true;
				}
			}
		}
	}
	
	bool* DFS_Util(int s) {
		bool *visited = new bool[V];
		for(int i = 0; i < V; i++)
			visited[i] = false;
		list<int> stack;
		visited[s] = true;
		stack.push_front(s);
		while (!stack.empty()) {
			s = stack.front();
			stack.pop_front();
			for (auto i = adj[s].begin(); i != adj[s].end(); ++i){
				if (!visited[*i]){
					stack.push_front(*i);
					visited[*i] = true;
				}
			}
		}
		return visited;
	}
	
	
    void DFS(int s) {
		bool *visited = new bool[V];
		for(int i = 0; i < V; i++)
			visited[i] = false;
		DFS2(s, visited);
	}
	void DFS2(int s, bool* visited){
		visited[s] = true;
		cout << s << ' ';
		list<int>::iterator i;
		for (i = adj[s].begin(); i != adj[s].end(); ++i){
			if (!visited[*i])
				this->DFS2(*i, visited);
		}
	}
	
	bool isConnected(){
		bool *visited = this->DFS_Util(0);
		for (int i = 0; i < V; i++)
			if(!visited[i])
				return false;
		return true;
	}
};

int main() {
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.BFS(0);
	cout << '\n';	
	g.DFS(0);
	cout << '\n';
	g.DFS_It(0);
	cout << '\n';
	cout << g.isConnected();
}

 
