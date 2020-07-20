#include <iostream>
#define MAX_NUM 1000
using namespace std;

int inputnumber(int *n){
	cin >> *n;
	return 0;
}

int inputnumbers(int n, int *a){
	for(int i=0;i<n;i++){
		cin >> *(a+i);
	}
	return 0;
}

void swap(int i,int j,int *a){
	int value=*(a+i);
	*(a+i)=*(a+j);
	*(a+j)=value;
}

int bubblesort(int n, int *a){
	int i,j,count=0;
	for(i=0;i<n;i++){
		for(j=n-1;j>0;j--){
			if(*(a+j)<*(a+j-1)){
				swap(j,j-1,a);
				count++;
			}
		}
	}
	return count;
}

int printnumbers(int n,int *a){
	for(int i=0;i<n-1;i++)
		cout << *(a+i) << ' ';
	cout << *(a+n-1) << endl;
	return 0;
}


int main() {
	int n,a[MAX_NUM];
	int count;

	inputnumber(&n);
	inputnumbers(n,a);
	count=bubblesort(n,a);
	printnumbers(n,a);
	cout << count << endl;
	return 0;
}
