#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){
	int n, count;
	cin>>n;
//	vector<int> array;
	int array[100];
	for(int i=0;i<n;i++) 
	{
		int input;
		cin>>input;
//		array.push_back(input);
		array[i] = input;
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				swap(array[j], array[j+1]);
				count++;
			}			
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
