#include <iostream>
using namespace std;
#define LOOP(i,v,n) for(int i=v;i<n;i++)

void CountingSort(int a[],int b[],int k,int n){
	int c[k+1]={};
	LOOP(i,0,n)c[a[i]]+=1;
	LOOP(i,1,k+1)c[i]=c[i-1]+c[i];
	LOOP(i,0,n){
		b[c[a[i]]-1] = a[i];
		c[a[i]] = c[a[i]]-1;
		}
	}

int main(){
	int n;
	cin >> n;
	int a[n]={},b[n]={};
	int max=0;
	LOOP(i,0,n){
		cin>>a[i];
		max = (a[i]>max)?a[i]:max;
		}
	CountingSort(a,b,max,n);
	LOOP(i,0,n)cout<<b[i]<<((i==n-1)?"\n":" ");
	}

