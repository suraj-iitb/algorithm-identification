#include<iostream>
using namespace std;

int main()
{
    int i=0,j=0,a[100],count=0,n,min=0,temp=0;
    cin >> n;
    for(i=0;i<n;i++) 
    {
    cin>>a[i];}
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=a[i];	
            a[i]=a[min];
            a[min]=temp;
	        count=count+1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(i!=0)
        {cout<<" ";}
        else
        {cout<<"";}    
        cout<<a[i];
    }
    cout <<endl<<count<<endl;
    return 0;
}
