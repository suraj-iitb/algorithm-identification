#include<iostream>
using namespace std;

int main()
{
    int i=0,j=0,a[100],count=0,n,temp=0;
    cin >> n;
    for(i=0;i<n;i++) 
    {
    cin>>a[i];}
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];	
                a[j]=a[j-1];
                a[j-1]=temp;
	            count=count+1;
            }
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
