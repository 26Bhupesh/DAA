//Dijkstra's algorithm for finding shortest path from source vertex to other vertices in graph

#include <iostream>
using namespace std;

#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

int adj[MAX][MAX];
int pathLength[MAX];
int predecessor[MAX];
int status[MAX];

int n;

void findPath(int s, int v);
void Dijkstra(int s);
int min_temp();
void createGraph();

int main()
{
    createGraph();                      //call to function taking input graph

    int s, v;
    cout << "Enter source vertex: ";    //knowing source vertex
    cin >> s;
    Dijkstra(s);                        //call to dijkstra function for finding shortest path to each vertex

    while (1)
    {
        cout << "Enter destination vertex (-1 to quit): ";    //taking destination vertex to find shortest path between source and destination
        cin >> v;

        if (v == -1)
            break;

        if (v < 0 || n <= v)
            cout << "This vertex does not exist\n";
        else if (v == s)
            cout << "Source and destination vertices are the same\n";
        else if (pathLength[v] == infinity)
            cout << "There is no path from source to destination vertex\n";
        else
            findPath(s, v);             //calling findpath function to find shortest path from source to destination vertex
    }

    return 0;
}

//Function implements Dijkstra's Algorithm
void Dijkstra(int s)
{
    int i, current;

    for (i = 0; i < n; i++)
    {       //initializing all pathlength of all vertices to infinity, predecessor to NIL, and status as TEMPORARY
        predecessor[i] = NIL;
        pathLength[i] = infinity;
        status[i] = TEMP;
    }

    pathLength[s] = 0;              //Making pathlength of source vertex zero

    while (1)
    {
        current = min_temp();       //finding temporary vertex with minimum pathlength by calling a function and making current
        if (current == NIL)         //to terminate loop when there is no temporary variable
            return;

        status[current] = PERM;     //Making current vertex permanent
        for (int i = 0; i < n; i++)
        {
            if (status[i] == TEMP && adj[current][i] != 0)                    //Checking if vertex is temporary and adjacent or not
            {   
                if (pathLength[current] + adj[current][i] < pathLength[i])    //Checking if redefining is needed
                {
                  pathLength[i] = pathLength[current] + adj[current][i];
                  predecessor[i] = current;
                }
            }
        }
    }
}

//Function finds index of temporary vertex with minimum value of pathlength
int min_temp()
{
    int min = infinity, index = NIL;

    for (int i = 0; i < n; i++) {   //finding index of temporary vertex having minimum pathlength
        if (status[i] == TEMP && pathLength[i] < min) {
            min = pathLength[i];
            index = i;
        }
    }

    return index;
}

//Function finds path from source vertex to destination vertex
void findPath(int s, int v)
{
    int path[MAX], count = 0;
    
    cout << "Path Length: " << pathLength[v] << endl;

    while (v != s) {        //Creating path matrix
        path[count++] = v;
        v = predecessor[v];
    }
    path[count++] = s;
    
    //Printing path matrix
    cout << "Shortest Path: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0)
            cout << " -> ";
    }
    cout<<endl;
}

//Function creates graph by taking input
void createGraph()
{
    int m_e, o, d, wt;

    cout << "Enter the number of vertices: ";   //input number of vertices
    cin >> n;

    m_e = n*(n-1);                              //calculating maximum number of edges
    
    for (int i = 0; i < m_e; i++)               //taking graph as a input
    {
        cout<<"Enter edge "<<i+1<<"(-1 -1 to quit) : ";   //Taking edge as input
        cin>>o>>d;
        
        if((o==-1) && (d==-1))
          break;
        
        cout<<"Enter weight for this edge : ";    //Taking input weight of edge
        cin>>wt;
        
        adj[o][d] = wt;   //Assigning weight of edge
    }
}

/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 6.dj.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter the number of vertices: 5
Enter edge 1(-1 -1 to quit) : 0 1
Enter weight for this edge : 8
Enter edge 2(-1 -1 to quit) : 0 2
Enter weight for this edge : 9
Enter edge 3(-1 -1 to quit) : 2 3
Enter weight for this edge : 3
Enter edge 4(-1 -1 to quit) : 3 1
Enter weight for this edge : 7
Enter edge 5(-1 -1 to quit) : 1 4
Enter weight for this edge : 5
Enter edge 6(-1 -1 to quit) : 4 3
Enter weight for this edge : 6
Enter edge 7(-1 -1 to quit) : -1 -1
Enter source vertex: 0
Enter destination vertex (-1 to quit): 4
Path Length: 13
Shortest Path: 0 -> 1 -> 4
Enter destination vertex (-1 to quit): 3
Path Length: 12
Shortest Path: 0 -> 2 -> 3
Enter destination vertex (-1 to quit): 0
Source and destination vertices are the same
Enter destination vertex (-1 to quit): -1
*/
