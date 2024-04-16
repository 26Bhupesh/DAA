//Bellman-Ford algorithm for finding shortest path from source vertex to any vertex in graph

#include<iostream>
using namespace std;

#define MAX 100
#define infinity 9999
#define NIL -1
#define TRUE 1
#define FALSE 0

int n, r, f;    //n = Number of vertices, r = rear, f = front
int q[MAX];     //queue
int predecessor[MAX];
int pathlength[MAX];
int is_in_q[MAX];     //For tracking that vertex is in queue or not
int adj[MAX][MAX];    //Graph

void graph();
int bellmanford(int);
void initialize_q();
void insert_q(int);
int is_queue_empty();
int delete_q();
void findpath(int, int);

int main()
{
  int flag, s, v;
  
  graph();    //Calling function for taking input of graph
  
  cout<<"Enter source vertex : ";   //Taking source vertex as an input
  cin>>s;
  
  flag = bellmanford(s);    //Calling bellmanford function and assigning return value to flag
  
  if(flag == -1)    //Checks for negative cycle in loop
  {
    cout<<"Error : negative cycle in Graph\n";
    exit(1);
  }
  
  while(1)
  {
    cout<<"Enter the destination vertex (-1 to quit): ";
    cin>>v;
    
    if(v==-1)
      break;
    
    if(v<0 || v>n)
      cout<<"Invalid vertex!\n";
    else if(v==s)
      cout<<"Source vertex and destination vertex are same\n";
    else if(pathlength[v] == infinity)
      cout<<"There is not path from "<<s<<" to "<<v<<endl;
    else
      findpath(s, v);
  }
  
  return 0;
}

//Function taking graph input
void graph()
{
  int max_e, o, d, w;
  cout<<"Enter number of vertices: ";
  cin>>n;
  max_e = n*(n-1);    //Calculating maximum number of edges
  
  for(int i=0; i<=max_e; i++)
  {
    cout<<"Enter edge "<<i+1<<" (-1 -1 to quit) : ";
    cin>>o>>d;
    
    if((o==-1) && (d==-1))
      break;
    
    cout<<"Enter weight for this edge : ";
    cin>>w;
    
    if(o>=n || d>=n || o<0 || d<0)
    {
      cout<<"Invalid edge!\n";
      i--;
    }
    else
      adj[o][d] = w;
  }
}

//Function implementing bellman-ford algorithm
int bellmanford(int s)
{
  int k=0, c, i;
  for(i=0; i<n; i++)    //Initializing pathlength of all vertices to infinity and predecessor to NIL
  {
    predecessor[i] = NIL;
    pathlength[i] = infinity;
    is_in_q[i] = FALSE;
  }
  
  initialize_q();    //Initializing queue
  
  pathlength[s] = 0;    //Initializing pathlength of source vertex to zero
  insert_q(s);          //Inserting source vertex to queue
  is_in_q[s] = TRUE;
  
  while(is_queue_empty())   //loop until queue is not empty
  {
    c = delete_q();   //Deleting element from front of the queue and made it current
    is_in_q[c] = FALSE;
    if(s==c)
      k++;
    if(k>n)
      return -1;
    
    //Examining pathlength of adjacent elements to the current vertex
    for(int i=0; i<n; i++)    //i = vertex
    {
      if(adj[c][i] != 0)
      {
        if(pathlength[i] > pathlength[c] + adj[c][i])
        {
          pathlength[i] = pathlength[c] + adj[c][i];
          predecessor[i] = c;
          if(!is_in_q[i])
          {
            insert_q(i);
            is_in_q[i] = TRUE;
          }
        }
      }
    }
  }
  
  return 1;
}

//Function initializes all queue elements to zero and rear & front to -1
void initialize_q()
{
  for(int i=0; i<MAX; i++)
    q[i] = 0;
  
  r = -1;
  f = -1;
}

void insert_q(int item)
{
  if(r == MAX-1)
  {
    cout<<"Queue Overflow\n";
    exit(1);
  }
  else
  {
    if(f == -1)
      f = 0;
    r++;
    q[r] = item;
  }
}

//Function checking that queue is empty or not
int is_queue_empty()
{
  if(f == -1 || f>r)
    return 0;
  else
    return 1;
}

//Function deletes queue and returns the deleted element
int delete_q()
{
  int x;
  if(!(is_queue_empty()))
  {
    cout<<"Queue underflown!";
    exit(1);
  }
  x = q[f];
  f++;
  return x;
}

//Function for finding pathlength from source to destination vertex
void findpath(int s, int v)
{
  int i, u;
  int path[MAX];    //Stores the shortest path
  int shortdist = 0;    //Length of shortest path
  int count = 0;    //Number of vertices in the shortest path
  
  while(v!=s)
  {
    count++;
    path[count] = v;
    u = predecessor[v];
    shortdist += adj[u][v];
    v = u;
  }
  
  count++;
  path[count] = s;
  cout<<"Shortest path is : ";
  for(i = count; i>1; i--)
    cout<<path[i]<<" -> ";
  cout<<path[i]<<endl;
  cout<<"Shortest distance is : "<<shortdist<<endl;
}

/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 7.bellman_ford.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter number of vertices: 5
Enter edge 1 (-1 -1 to quit) : 0 4
Enter weight for this edge : 7
Enter edge 2 (-1 -1 to quit) : 1 0
Enter weight for this edge : 6
Enter edge 3 (-1 -1 to quit) : 1 2
Enter weight for this edge : 5
Enter edge 4 (-1 -1 to quit) : 2 4
Enter weight for this edge : -3
Enter edge 5 (-1 -1 to quit) : 2 3
Enter weight for this edge : -4
Enter edge 6 (-1 -1 to quit) : -1 -1
Enter source vertex : 1
Enter the destination vertex (-1 to quit): 3
Shortest path is : 1 -> 2 -> 3
Shortest distance is : 1
Enter the destination vertex (-1 to quit): 4
Shortest path is : 1 -> 2 -> 4
Shortest distance is : 2
Enter the destination vertex (-1 to quit): 0
Shortest path is : 1 -> 0
Shortest distance is : 6
Enter the destination vertex (-1 to quit): 1
Source vertex and destination vertex are same
Enter the destination vertex (-1 to quit): -1
*/
