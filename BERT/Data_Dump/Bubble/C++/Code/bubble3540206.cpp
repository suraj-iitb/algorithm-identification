#include <iostream>

//insertionsort

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
	int flag=1,n,count=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	while(flag){
		flag=0;
		for(int j=n-1;j>0;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				flag=1;
				count++;
			}
		}
	}
	printA(a,n);
	cout << count << "\n";
	return 0;
}
