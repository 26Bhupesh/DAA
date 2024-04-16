#include<iostream>
using namespace std;

void divide(int a[], int l, int u);
void copy(int a[], int temp[], int l, int u);
void merge(int a[], int temp[], int l1, int u1, int l2, int u2);

int main()
{
  
  int n;
  cout<<"Enter size of an array: ";     //Taking size of an array as input
  cin>>n;
  
  int a[n], low=0, up=n-1;
  
  cout<<"Enter elements in array:\n";   //Taking array elements as input
  for(int i=0; i<n; i++)
    cin>>a[i];
  
  divide(a,low,up);     //Calling a divide function
  
  cout<<"Sorted array:\n";       //Showing a sorted array as output
  for(int i=0; i<=up; i++)
    cout<<a[i]<<"\n";
  
  return 0;
}

//Divide function which divides array in two
void divide(int arr[], int l, int u)
{
  
  int mid, temp[10];
  
  if(l<u)
  {
    mid = (l+u)/2;        //finding mid of array
    divide(arr,l,mid);      //Recursively calling divide function
    divide(arr,mid+1,u);    //Recursively calling divide function
    merge(arr,temp,l,mid,mid+1,u);    //Merging divided arrays
    copy(arr,temp,l,u);     //Copying sorted array in array 'a'
  }
}

//Function merges two arrays by sorting elements of both arrays
void merge(int arr[], int temp[], int l1, int u1, int l2, int u2)
{
  
  int i=l1;
  int j=l2;
  int k=l1; 
  
  while((i<=u1) && (j<=u2))   //Adding elements of both arrays in temporary array
  
  {
    if(arr[i]<arr[j])
      temp[k++] = arr[i++];
    else if(arr[i]>arr[j])
      temp[k++] = arr[j++];
  }
  
  while(i<=u1)      //Adding remaining elements first array in temporary array
    temp[k++] = arr[i++];
  
  while(j<=u2)      //Adding remaining elements second array in temporary array
    temp[k++] = arr[j++];
}

//Function copies sorted temporary array in main array
void copy(int arr[], int temp[], int l, int u)
{
  for(int i=0; i<=u; i++)
    arr[i] = temp[i];
}

/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 2.recmerge.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter size of an array: 5
Enter elements in array:
7
3
4
6
1
Sorted array:
1
3
4
6
7
*/
