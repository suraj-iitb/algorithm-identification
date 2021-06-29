#include<iostream>
#include<vector>

using namespace std;
int main()
{
	int n,a;
	vector<int> array;
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
		cin>>a;
		array.push_back(a);
		
	}
	
	int count=0,temp;
	for(int i=0;i<n;++i)
	{
		int min=i; 
		for(int j=i+1;j<n;++j)//用min指向最小值位置 
		{
		  if(array[j]<array[min])	
		  {
		  	min=j;
		  }
		}
		
		if(min!=i)
		{
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;	
		count++;	
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
