#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int A[N];
	int temp;
	for(int i=0; i<N ;i++)
	{
		cin>>A[i];
	} 
	for(int i=0;i<N;i++)
	{
		temp = A[i];
		int j = i - 1;
		while(j>=0 && A[j]>temp)
		{
			A[j+1] = A[j];
			j--;	
		} 
		A[j+1] = temp;
		for(int h=0;h<N;h++)
		{
			if(h<N-1) 
				cout<<A[h]<<" ";
			else
				cout<<A[h];
		}
		cout<<endl;

	} 
	
 } 
