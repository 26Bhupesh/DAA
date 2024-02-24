#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int arr3[], int n1, int n2);

int main()
{
  int a1[] = {1,3,5}, a2[] = {2,4,6,8}, a3[7], n1=3, n2=4;
  
  merge(a1, a2, a3, n1, n2);
    
  cout<<"a3[]\n";
  for(int i=0; i<7; i++)
    cout<<a3[i]<<endl;
  return 0;
}

void merge(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
  int i=0, j=0, k=0;
  
  while((i <= n1-1) && (j <= n2-1))
  {
    if(arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }
  while(i <= n1-1)
    arr3[k++] = arr1[i++];
  while(j <= n2-1)
    arr3[k++] = arr2[j++];
}
