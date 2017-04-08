#include<iostream>
#include<list>
#include<set>
#include<vector>
using namespace std;

vector<int> vertex_cover;
vector<int> vertex_list[10];
vector <int>::iterator i;
int in = 0;//Global variable for maintaining array of list
// This class represents a undirected graph using adjacency list
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;  // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printVertexCover();  // prints vertex cover
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
		vertex_list[in].push_back(v);
		vertex_list[in].push_back(w);
		in++;
}

// The function to print vertex cover
void Graph::printVertexCover()
{
    // Initialize all vertices as not visited.
    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;

    list<int>::iterator i;

    // Consider all edges one by one
    for (int u=0; u<V; u++)
    {
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if (visited[u] == false)
        {
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for (i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                     // Add the vertices (u, v) to the result set.
                     // We make the vertex u and v visited so that
                     // all edges from/to them would be ignored
                     visited[v] = true;
                     visited[u]  = true;
                     break;
                }
            }
        }
    }
    // Print the vertex cover
    for (int j=0; j<V; j++)
        if (visited[j])
          vertex_cover.push_back(j);
}

int main()
{
    // Create a graph given in the above diagram
     	int noofvertices,ch=1;
	  	cout<<"Enter no of vertices"<<endl;
   		cin>>noofvertices;
			Graph g(noofvertices);
  do {
     int x,y;
   	 cout<<"Enter vertices to add a edge between them";
		  cin>>x>>y;
      g.addEdge(x, y);
      cout << "Enter 1 to continue ";
			cin >> ch;

  } while(ch==1/* condition */);



    g.printVertexCover();
		cout << "Vertex cover is:" << endl;
		for(i = vertex_cover.begin(); i != vertex_cover.end(); i++) {
			cout << *i << " ";
		}

		bool vis[in];
		memset(vis, false, sizeof(vis));
		cout << "\nEdge list is:" << endl;
		for(int j = 0; j < in; j++) {
			for(int k = 0; k < 2; k++) {
				cout << vertex_list[j][k] << " ";
			}
			cout << endl;
		}
       int m=0,n=0,c=1,k;
     if(m<in)
		 {for(int j=0;j<in;j++)
		 {
        if(vis[j]!=true)
				{

					for( k=0;k<2;++k)
					{
            if(vertex_list[j][k]==vertex_cover[m])
						{
							vis[j]=true;
                  m++;
               break;
						}

					}
					if(k==2)
					{
						m++;
					}
				}






		 }
}
		 for(k=0;k<in;++k)
		 {
      if(vis[k]==true)
			 c++;

		 }
		 if(c==in)
		 cout<<"yes";




    return 0;
}
