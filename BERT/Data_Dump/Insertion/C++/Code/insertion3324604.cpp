#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		if(i!=n-1){
		
		cout<<a[i]<<" "; 
	}
		else
		{
		
		cout<<a[i];
		}
	
	}
	cout<<endl;
	
	
	for(int i=1;i<n;i++)
	{
		int j=i;
		while(j>0&&a[j-1]>a[j])
		{
		int k=a[j];
			a[j]=a[j-1];
			a[j-1]=k;
		j--;
		}
		for(int j=0;j<n;j++)
		{
		
			if(j>0)
			{
			cout<<" ";
			
			}
			cout<<a[j];
		
		}
		cout<<endl;
		
	
	}
	
	


}

