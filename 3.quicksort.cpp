#include<iostream>
using namespace std;

const int MAX = 10;
void quicksort(int a[], int l, int u);
int partition(int a[], int l, int u);

int main()
{
  int a[MAX];
  
  cout<<"Enter elements in an array:\n";    //Taking input of elements in an array
  for(int i=0; i<MAX; i++)
    cin>>a[i];
  
  quicksort(a,0,MAX-1);     //Calling quicksort function to sort array
  
  cout<<"Sorted array: ";   //Showing sorted array in output
  for(int i=0; i<MAX; i++)
    cout<<a[i]<<" ";
  
  return 0;
}

//Function sorts elements of array by dividing recursively
void quicksort(int arr[], int l, int up)
{
  int pvtloc;
  if(l>=up)
    return;
  pvtloc = partition(arr,l,up);   //Calling partition function to find correct location of pivot
  quicksort(arr,l,pvtloc-1);      //Calling quicksort function for left half of an array
  quicksort(arr,pvtloc+1,up);     //Calling quicksort function for right half of an array
}

//Function gives correct location of an pivot
int partition(int arr[], int l, int up)
{
  int t, pvt;
  int i = l+1;
  int j = up;
  pvt = arr[l];
  while(i<=j)
  {
    while(arr[i]<pvt)
      i++;
    while(arr[j]>pvt)
      j--;
    if(i<j)
    {
      t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
      i++;
      j--;
    }
    else
    {
      i++;
    }
  }
  arr[l] = arr[j];
  arr[j] = pvt;     //Placing pivot at its current location
  return j;
}

/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 3.quicksort.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter elements in an array:
6
3
4
2
8
9
3
5
7
10
Sorted array: 2 3 3 4 5 6 7 8 9 10
*/
