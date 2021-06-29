#include <iostream>
using namespace std;
int bubbleSort(int *A,int N){
	int flag = 1,count = 0;
	while(flag){
		flag=0;
		for(int j=N-1;j>0;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				flag=1;
				count++;
			}
		}
	}
	return count;
}
int main(){
	int n,i,c,a[100];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	c = bubbleSort(a,n);
	for(i=0;i<n;i++){
		cout << a[i];
		if(i<n-1) cout << " ";
	}
	cout << endl << c << endl;
	return 0;
}
