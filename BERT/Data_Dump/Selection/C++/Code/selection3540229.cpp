#include <iostream>

//selectionSort

using namespace std;

void printA(int x[], int n){
	for(int i=0;i<n;i++){
		cout << x[i];
		if(i==n-1)cout<<"\n";
		else cout << " ";
	}
}

void swap(int *x, int *y){
	int *tmp;
	*tmp=*y;
	*y=*x;
	*x=*y;
}

int main(){
	int n,min,count=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		swap(a[i],a[min]);
		if(i!=min)count++;
	}
	
	printA(a,n);
	cout << count << "\n";
	return 0;
}
