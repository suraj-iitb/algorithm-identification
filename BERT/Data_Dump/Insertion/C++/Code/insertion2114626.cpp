#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <typeinfo>
#include <queue>
#include <math.h>
using namespace std;

static int n;
int a[101];
void insertionSort(int[],int);

int main(){
	
	cin>>n;
	for (int i = 1; i < n+1; ++i)
	{
		cin>>a[i];
	}
	insertionSort(a,n);


return 0;
}

void insertionSort(int a[], int n){
	for (int i = 1; i < n+1; ++i)
	{
		int v=a[i];
		int j=i-1;
		while(j>0 && a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		
		for (int y = 1; y < n; ++y)
		{
			cout<<a[y]<<" ";
		}
		cout<<a[n]<<endl;

	}


}
