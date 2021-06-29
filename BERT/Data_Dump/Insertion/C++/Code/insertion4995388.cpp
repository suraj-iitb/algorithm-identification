#include <iostream>
#include<cstdlib>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;


int main() 
{     
	int n;
    cin>>n;
	int A[101];
	int u=0;
	for(;u<n;u++)
	{   
	   cin>>A[u];
	}
	for(int i=0;i<u;i++)
	{
        if(i>0)cout<<" ";
        cout<<A[i];
	        
    }
	    cout<<endl;
	for(int i=1;i<u;i++)
	{
	    int key=A[i];
	    int j=i-1;
	    while(j>=0&&A[j]>key)
	    {
	        A[j+1]=A[j];
	        j--;
	    }
	    A[j+1]=key;
	    for(int k=0;k<u;k++)
	    {
	        if(k>0)cout<<" ";
	        cout<<A[k];
	        
	    }
	    cout<<endl;
	    
	}
	
	
	return 0;
}

