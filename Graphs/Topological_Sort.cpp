#include<bits/stdc++.h>

using namespace std;
class graph{
	int V;
	list<int> *adj;
	void toposort(int V, bool visited[], stack<int> &stack);
public:
	graph(int V);

	void addEdge(int v, int w);

	void toposort_print();
};

graph::graph(int V){
	//cout<<"call 1\n";
	this -> V = V;
	adj = new list<int>[V];
}

void graph::addEdge(int v, int w){
	//cout<<"call 2\n";
	adj[v].push_back(w);
}

void graph::toposort(int V, bool visited[], stack<int> &stack){
	//cout<<"call 3\n";
	visited[V] = true;

	list<int>::iterator it;
	for (it = adj[V].begin(); it != adj[V].end(); it++) if (!visited[*it]) toposort(*it, visited, stack);
	stack.push(V);
}
//here now we need to print the result

void graph::toposort_print(){
	//cout<<"call 4\n";
	stack<int> stack;

	//bool visited[V] = false;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
        visited[i] = false;
	for (int i=0;i<V;i++) {
		//cout<<"call 4 / 1 \n";
		if (!visited[i]){
			//cout<<"call 4 / 2 \n";
			toposort(i, visited, stack);
		}
	}
	while (stack.empty() == false) {
		cout<<stack.top()<<" "<<endl; stack.pop();
	}
}

int main()
{
		cout<<"Execution Started\n";
	  graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.toposort_print();
	return 0;
}
