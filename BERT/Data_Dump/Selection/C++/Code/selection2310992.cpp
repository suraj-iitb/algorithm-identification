#include<iostream>

using namespace std;

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        {
            cout<<a[i];
            if(i!=n-1)
                cout<<" ";
        }
    cout<<endl;
}

int main()
{
   int n,i,j,v=0;
   int a[100];
   int minx,flag;

   cin>>n;
   for(i=0;i<n;i++)cin>>a[i];

   for(i=0;i<n;i++)
   {
       minx=i;
       flag=0;
       for(j=i+1;j<n;j++)
       {
           if(a[j]<a[minx])
            {
                minx=j;
                flag=1;
            }
       }
       if(flag==1)
       {
           swap(a[i],a[minx]);
           v++;
       }


   }
   print(a,n);
   cout<<v<<endl;
    return 0;

}
