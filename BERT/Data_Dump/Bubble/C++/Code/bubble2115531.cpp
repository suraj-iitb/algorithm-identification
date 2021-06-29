#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int[],int,int*);
static int n;
int a[100];

int main(){
	cin>>n;
	
	for (int i = 0; i <n; ++i)
	{
		cin>>a[i];
	}
	int sum=0;
	bubbleSort(a,n,&sum);
	for (int i = 0; i < n-1; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[n-1]<<endl;
	cout<<sum<<endl;
		

	
return 0;
}

void bubbleSort(int a[],int n, int* sum){
	int flag=1;
	
	while (flag){
		flag=0;
		for (int j = n-1; j>0; --j)
		{
			if (a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
				flag=1;
				*sum= *sum+1;
				
			}
		}
	}
}
