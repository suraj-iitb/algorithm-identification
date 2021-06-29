#include<iostream>
#include<vector> 
using namespace std;

vector<int> array;

int main()
{
	
	int a,b,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		b=a;
		array.push_back(b);	
	}
	int v=0;
	for(int i=1;i<n;i++)
	{
		for(int k=0;k<n;k++)
	    {
		if(k<n-1)
		cout<<array[k]<<" "	;
		else
		cout<<array[k];	
	    }
	    cout<<endl;
	    
		v=array[i];
		int j=i-1;
		
		while(j >= 0 && array[j] > v )
		{
			array[j+1] = array[j];
			j--;	
		}
		
		array[j + 1] = v;

	}
	
	for(int i = 0; i < n; i++)
	    {
		if (i<n-1)
		cout<<array[i]<<" "	;	
		else 
		cout<<array[i];
	    }
	    cout<<endl;
	    
	return 0;
 } 
