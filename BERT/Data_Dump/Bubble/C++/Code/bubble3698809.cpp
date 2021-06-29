#include<bits/stdc++.h>
using namespace std;
static const int N = 105; 
int cont;
int n;
void BubbleSort(int *a){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--)
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				cont++;
			}
	}
}
int main(){
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	BubbleSort(a); 
	for(int i=0;i<n;i++){
		if(i!=n-1)
			cout<<a[i]<<" ";
		else
			cout<<a[i]<<endl;
	}
	cout<<cont<<endl;
	return 0;
}
