#include<iostream>
using namespace std;

void divide(int a[], int l, int u);
void copy(int a[], int temp[], int l, int u);
void merge(int a[], int temp[], int l1, int u1, int l2, int u2);

int main()
{
  int a[] = {5,2,6,3,8,4,7,10,13,1};
  int low=0, up=9;
  divide(a,low,up);
  cout<<"Array a:\n";
  for(int i=0; i<=up; i++)
    cout<<a[i]<<"\n";
  return 0;
}

void divide(int arr[], int l, int u)
{
  int mid, temp[10];
  
  if(l<u)
  {
    mid = (l+u)/2;
    divide(arr,l,mid);
    divide(arr,mid+1,u);
    merge(arr,temp,l,mid,mid+1,u);
    copy(arr,temp,l,u);
  }
}

void merge(int arr[], int temp[], int l1, int u1, int l2, int u2)
{
  int i=l1;
  int j=l2;
  int k=l1; 
  
  while((i<=u1) && (j<=u2))
  {
    if(arr[i]<arr[j])
      temp[k++] = arr[i++];
    else if(arr[i]>arr[j])
      temp[k++] = arr[j++];
  }
  
  while(i<=u1)
    temp[k++] = arr[i++];
  
  while(j<=u2)
    temp[k++] = arr[j++];
}

void copy(int arr[], int temp[], int l, int u)
{
  for(int i=0; i<=u; i++)
    arr[i] = temp[i];
}
