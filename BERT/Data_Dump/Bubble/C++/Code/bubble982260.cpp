#include<iostream>

using namespace std;

int bubbleSort(int a[],int n)
{
     int c,d,t,cont=0;
     for(c=0;c<(n-1);c++)
     {
          for(d=0;d<(n-c-1);d++)
          {
               if(a[d]>a[d+1])
               {
                 t=a[d];
                 a[d]=a[d+1];
                 a[d+1]=t;
                 cont++;
               }
          }
     }
     return cont;
}

int main()
{
    int x;
    cin>>x;
    int a[x];
    for(int i=0;i<x;i++)
    {
       cin>>a[i];
    }

    int m=bubbleSort(a,x);

    for(int i=0;i<x;i++)
    {
       cout<<a[i];
       if(i<x-1){cout<<" ";}
    }

    cout<<endl<<m<<endl;

return 0;
}
