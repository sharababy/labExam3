#include <iostream>
#include <list>

using namespace std;


// This class represents a directed graph using adjacency list representation
class Graph
{
private:
    int V;    // No. of vertices
     
public:
    int second_shortest[100];
    list<int> *adj;
    int short_length;
    int shortest[100];
    int parent[100];
    int shortest_length;
    
    int sec_count;
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void removeEdge(int v, int w);
    void BFS(int s,int end);  // prints BFS traversal from a given source s
};

int sh_graph;

void backtrack(Graph g, int end,int stop);
void secondShort(Graph g,int k,int end,int stop);
int backtrack2(Graph g, int end,int stop);

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    shortest_length = 100000;
    sec_count = 1;
    //parent = new list<int>;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}

void Graph::removeEdge(int v, int w)
{
    
    adj[v].remove(w); // Add w to v’s list.
    adj[w].remove(v);
}

void Graph::BFS(int s,int end)
{
    int reached =1;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        /*cout << s << " ";*/
        queue.pop_front();
        if (s==end)
        {    
            break;
        }
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i]){
                parent[*i] = s;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void backtrack(Graph g, int end,int stop){



    cout<<endl;
    int k =0;
    int start = end;
    g.shortest[k]= end;
    k++;
    cout<<"Shortest Path: "<<end<<"->";

    while(g.parent[start] != stop){
        g.shortest[k] = g.parent[start];
        k++;
        cout<<" "<<g.parent[start]<<"->";
        start = g.parent[start];        
    }
    g.shortest[k] = g.parent[start];
    cout<<stop<<endl<<endl;

    //cout<<"\n no of edges: "<<k<<endl;

    secondShort(g,k,end,stop);


}




int backtrack2(Graph g, int end,int stop){

    int start = end;
    int k=1;
    cout<<"Path "<<g.sec_count<<" :"<<end<<"->";


    g.second_shortest[0]=end;

    while(g.parent[start] != stop){

        g.second_shortest[k]=(g.parent[start]);
        k++;
        cout<<" "<<g.parent[start]<<"->";
        start = g.parent[start];        
    }
    g.second_shortest[k]=stop;

    cout<<stop<<" | length = "<<k<<endl;

    
    return k;

}

void secondShort(Graph g,int k,int end,int stop){

    int i=0,len;

    while(i<k){

        if (i==0)
        {
            g.removeEdge(g.shortest[i],g.shortest[i+1]);
        }
        else{
            g.addEdge(g.shortest[i-1],g.shortest[i]);
            g.removeEdge(g.shortest[i],g.shortest[i+1]);
        }
        g.BFS(stop,end);
        len = backtrack2(g,end,stop);

         g.sec_count++;

        if(len < g.shortest_length)
        {
            g.shortest_length = len;
            sh_graph = g.sec_count;
        }


       
        i++;
    }    

}

int main()
{

        sh_graph = 1;

       /* int noofvertices,ch=1;
            cout<<"Enter no of vertices"<<endl;
            cin>>noofvertices;
         int x,y;
                Graph g(noofvertices);
      do {
         
         cout<<"Enter vertices to add a edge between them";
              cin>>x>>y;
          g.addEdge(x, y);
          cout << "Enter 1 to continue ";
                cin >> ch;

      } while(ch==1);
      
      do{
        cout << "enter source and destination vertex ";
        cin>>x>>y;
             cout<< "bfs starting (starting from vertex "<<x<<") \n";
        g.BFS(x,y);

        backtrack(g,y,x);

        cout<<"\n\nPath "<<sh_graph<<" is the second shortest"<<endl;

        cout << "\nEnter 1 to repeat ";
                cin >> ch;   
     }while(ch==1);
*/

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(0, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.BFS(1,2);
    backtrack(g,2,1);

    cout<<"\n\nPath "<<sh_graph<<" is the second shortest"<<endl;
    

    return 0;
}


