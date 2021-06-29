#include <iostream>
#define MAX_NUM 10000

using namespace std;

int inputnumber(int *n){
	cin >> *n;
	return 0;
}

int inputnumbers(int n,int *x){
	for(int i=0;i<n;i++){
		cin >> *(x+i);
	}
	return 0;
}


int printdata(int n, int *x){
	for(int i=0;i<n-1;i++)
		cout << *(x+i) << ' ';
	cout << *(x+n-1) << endl;
	return 0;
}

int insertion(int n,int val,int *x){
	int j=n-1;
	while(j>=0 && *(x+j)>val){
		//cout << *(x+j+1) << ' ' << *(x+j) << " val=" << val << endl;
		*(x+j+1)=*(x+j);
		j--;
	}
	*(x+j+1)=val;
	return 0;
}

int insertionSort(int n, int *x){
	for(int i=1;i<n;i++){
		insertion(i,*(x+i),x);
		printdata(n,x);
	}

	return 0;
}


int main() {
	int n, x[MAX_NUM];

	inputnumber(&n);
	inputnumbers(n, x);
	printdata(n,x);
	insertionSort(n, x);


	return 0;
}

