#include<iostream>
using namespace std;

//Function performing knapsack problem
void knapsack(int n, float w[], float p[], float c)
{
  float x[20], tp=0;
  int i, j, u;
  u = c;
  for(i=0; i<n; i++)    //Initialize the solution vector x to all zeros
    x[i] = 0.0;
    
  for(i=0; i<n; i++)    //Greedily fill the knapsack
  {
    if(w[i] > u)
      break;
    else
    {
      x[i] = 1.0;
      tp = tp + p[i];
      u = u - w[i];
    }
  }
  
  //Fill the knapsack partially with the next object if there is remaining capacity
  if(i < n)
    x[i] = u/w[i];
  
  tp = tp + (x[i] * p[i]);    //Calculating total profit
  
  cout<<"\nThe result vector is:- ";    //Showing result of knapsack problem as output
  for(i=0; i<n; i++)
    cout<<x[i]<<"\t";
  cout<<"\nMaximum profit is:- "<<tp<<endl;   //Showing maximum profit as output
}

int main()
{
  float w[20], p[20], c;
  int num, i, j;
  float r[20], temp;
  cout<<"\nEnter the no. of objects:- ";    //Taking number of objects as input
  cin>>num;
  cout<<"\nEnter the wts and profits of each object:-\n";   //Taking weight & profit of each object as input
  for(i=0; i<num; i++)
  {
    cin>>w[i]>>p[i];
  }
  
  cout<<"\nEnter the capacity of knapsack:- ";    //Taking capacity of knapsack as input
  cin>>c;
  
  //Calculating profit to weight ratio for each object
  for(i=0; i<num; i++)
  {
    r[i] = p[i]/w[i];
  }
  
  // Sort the objects based on their profit-to-weight ratio in non-increasing order
  for(i=0; i<num; i++)
  {
    for(j=i+1; j<num; j++)
    {
      if(r[i] < r[j])
      {
        temp = r[j];
        r[j] = r[i];
        r[i] = temp;
        
        temp = w[j];
        w[j] = w[i];
        w[i] = temp;
        
        temp = p[j];
        p[j] = p[i];
        p[i] = temp;
      }
    }
  }
  
  knapsack(num, w, p, c);   //Calling knapsack function to perform operations of knapsack problem
  
  return 0;
}

/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 5.knapsack.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out

Enter the no. of objects:- 3

Enter the wts and profits of each object:-
18 30
15 21
10 18

Enter the capacity of knapsack:- 20

The result vector is:- 1	0.555556	0	
Maximum profit is:- 34.6667
*/
