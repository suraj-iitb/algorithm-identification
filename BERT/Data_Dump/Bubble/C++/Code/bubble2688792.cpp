#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,a,b;
	vector<int> array;
	
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
		cin>>a;
		array.push_back(a);	
	}
	
	int flag=1,count=0;
	
	while(flag)
	{
	flag = 0;
	int k = 0;	
	for( ; k < n-1 ; ++k )
	{
		if( array[k] > array[k+1] )
		{
			int temp=0;
			temp = array[k];
			array[k] = array[k+1];
			array[k+1] = temp;
			count++; 
			flag=1;
		}
	}
		
	}
	
	for(int i=0;i<n;++i)
	{
		if(i<n-1)
		cout<<array[i]<<" ";
		else
		cout<<array[i]<<endl;

	 } 
	 cout<<count<<endl; 
	return 0;
}
