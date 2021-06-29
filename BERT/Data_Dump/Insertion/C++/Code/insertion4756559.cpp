#include <iostream>
using namespace std;
const int max_number=1000;

int inputnumbers(int *n,int *a){
	cin >> *n;
	for(int i=0;i<*n;i++)
		cin >> *(a+i);
	return *n;
}

int printnumbers(int n,int *a){
	for(int i=0;i<n-1;i++)
		cout <<*(a+i)<<' ';
	cout<<*(a+n-1)<<endl;
	return n;
}

void swap(int i,int j,int *a){
	int temp;
	temp=*(a+i);
	*(a+i)=*(a+j);
	*(a+j)=temp;
}

void insertionsort(int n,int *a){
	int i,j;

	for(i=1;i<n;i++){
		for(j=i-1;j>=0 && *(a+j)>*(a+j+1);j--){
			swap(j,j+1,a);
		}
		printnumbers(n,a);
	}
}

int main() {
	int n,a[max_number];

	inputnumbers(&n,a);
	printnumbers(n,a);
	insertionsort(n,a);
	//printnumbers(n,a);

	return 0;
}

