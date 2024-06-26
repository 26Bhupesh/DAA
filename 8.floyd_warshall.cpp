//Modified Warshall's algorithm for finding shortest path matrix
#include<iostream>
using namespace std;

#define infinity 9999
#define MAX 100
int n;                //Number of vertices
int adj[MAX][MAX];    //Weighted Adjancy matrix
int D[MAX][MAX];      //Shortest path matrix
int pred[MAX][MAX];   //Predecessor matrix
void create_graph();
void floyd_warshalls();
void findpath(int, int);
void display(int m[MAX][MAX], int);

int main()
{
  int s, d;
  create_graph();     //Called function for taking graph as a input
  floyd_warshalls();  //Called function to perform Floyd-Warshall's algorithm
  
  while(1)
  {
    cout<<"\nEnter source vertex (-1 to exit) : ";
    cin>>s;
    if(s==-1)
    {
      break;
    }
    cout<<"Enter destination vertex : ";
    cin>>d;
    
    if(s<0 || s>n-1 || d<0 || d>n-1)
    {
      cout<<"Enter valid vertices\n\n";
      continue;
    }
    
    cout<<"Shortest path is : ";
    findpath(s, d);
    cout<<"Length of the shortest path is : "<<D[s][d]<<endl;
  }
  
  return 0;
}

//Function taking graph as an input
void create_graph()
{
  int o, d;
  cout<<"Enter number of edges : ";
  cin>>n;
  cout<<"Enter Adjancy matrix :\n";
  for(o=0; o<n; o++)
    for(int d=0; d<n; d++)
      cin>>adj[o][d];
}

//Function implementing Floyd-Warshall's algoritm
void floyd_warshalls()
{
  int i, j, k;
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      if(adj[i][j]==0)
      {
        D[i][j] = infinity;
        pred[i][j] = -1;
      }
      else
      {
        D[i][j] = adj[i][j];
        pred[i][j] = i;
      }
    }
  }
  
  for(k=0; k<n; k++)
  {
    for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
      {
        if(D[i][k] + D[k][j] < D[i][j])
        {
          D[i][j] = D[i][k] + D[k][j];
          pred[i][j] = pred[k][j];
        }
      }
    }
  }
  
  cout<<"\nShortest path matrix is :\n";
  display(D, n);
  cout<<"\nPredecessor matrix is  :\n";
  display(pred, n);
  
  for(i=0; i<n; i++)
  {
    if(D[i][j]<0)
    {
      cout<<"Error : negative cycle\n";
      exit(1);
    }
  }
}

//Function displays the matrix
void display(int m[MAX][MAX], int n)
{
  int i, j;
  for(i=0; i<n; i++)
  {
    for(j=0; j<n; j++)
    {
      cout<<m[i][j]<<" ";
    }
    cout<<"\n";
  }
}

//Function finds path from source to destination
void findpath(int s, int d)
{
  int i, path[MAX], count;
  if(D[s][d]==infinity)
  {
    cout<<"There is no path between "<<s<<" to "<<d<<"\n";
    return;
  }
  
  count = -1;
  do
  {
    path[++count] = d;
    d = pred[s][d];
  }while(d!=s);
  path[++count] = s;
  
  for(i=count; i>0; i--)
  {
    cout<<path[i]<<" -> ";
  }
  cout<<path[i]<<endl;
}

/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 8.floyd_warshall.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter number of edges : 4
Enter Adjancy matrix :
0 2 0 9
3 0 4 7
0 6 0 2
4 0 4 0

Shortest path matrix is :
5 2 6 8 
3 5 4 6 
6 6 6 2 
4 6 4 6 

Predecessor matrix is  :
1 0 1 2 
1 0 1 2 
3 2 3 2 
3 0 3 2 

Enter source vertex (-1 to exit) : 1
Enter destination vertex : 3
Shortest path is : 1 -> 2 -> 3
Length of the shortest path is : 6

Enter source vertex (-1 to exit) : 3
Enter destination vertex : 0
Shortest path is : 3 -> 0
Length of the shortest path is : 4

Enter source vertex (-1 to exit) : -1
*/
