#include <iostream>
#include <math.h>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int n, count, min;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++) 
	{
		int input;
		cin>>input;
		array[i] = input;
	}
	for(int i=0;i<n;i++)
	{
		min = i;
		for(int j=i;j<n;j++)
		{
			if(array[j]<array[min])
			{
				min = j;
			}			
		}
		if(array[i]!=array[min])
		{
			swap(array[i], array[min]);
			count++;			
		}
	}
	for(int i=0; i<n; i++)
	{
		if(i!=0) cout<<" ";
		cout<<array[i];
	}
	
	cout<<endl<<count<<endl;
	return 0;
}
