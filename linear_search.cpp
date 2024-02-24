#include<iostream>
using namespace std;

class linear
{
    int arr[5];
  public:
    void array()
    {
      //Input array
      cout<<"Enter element in array:\n";
      for(int i=0; i<5; i++)
        cin>>arr[i]; 
    }
    
    void search(int n)
    {
      int i;
      
      //Searching the element in array
      for(i=0; i<5; i++)
      {
        if(arr[i] == n)
        {
          cout<<"Value found at index "<<i;
          break;
        }
      }
      
      if(i==5)
      {
        cout<<"Element not found in list";
      }
    }
};

int main()
{
  linear x;
  int n;
  x.array();
  cout<<"Enter element to be searched : ";
  cin>>n;
  x.search(n);
  return 0;
}
