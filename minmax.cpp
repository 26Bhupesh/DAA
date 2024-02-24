#include<iostream>
using namespace std;

class min_max
{
    int a[5];
  public:
    void array()
    {
      //Input array
      cout<<"Enter element in array:\n";
      for(int i=0; i<5; i++)
        cin>>a[i]; 
    }
    
    void check()
    {
      int min = a[0], max = a[0];
      
      for(int i=1; i<5; i++)
      {
        if(a[i]<min)
          min = a[i];
        
        if(a[i]>max)
          max = a[i];
      }
      cout<<"Min = "<<min<<" Max = "<<max<<endl;
    }
};

int main()
{
  min_max m;
  m.array();
  m.check();
  return 0;
}
