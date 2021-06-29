#include <iostream>
#define MAX_NUM 10000
using namespace std;

int inputnumber(int *n){
	cin >> *n;
	return 0;
}

int inputsequence(int n, int *s){
	for(int i=0;i<n;i++)
		cin >> *(s+i);
	return 0;
}

void swap(int i, int j ,int *a){
	int value=*(a+i);
	*(a+i)=*(a+j);
	*(a+j)=value;
}

int selectionsort(int n,int *seq){
	int i,j,count=0;
	int seln;

	for(i=0;i<n;i++){
		seln=i;
		for(j=i+1;j<n;j++){
			if(*(seq+j)<*(seq+seln)){
				seln=j;
			}
		}
		if(i != seln){
			swap(i,seln,seq);
			count++;
		}
	}
	return count;
}

int printsequence(int n, int *seq){
	for(int i=0;i<n-1;i++)
		cout << *(seq+i) << ' ';
	cout << *(seq+n-1) << endl;
	return 0;
}

int main() {
	int n, a[MAX_NUM];
	int count;

	inputnumber(&n);
	inputsequence(n,a);
	count=selectionsort(n,a);
	printsequence(n,a);

	cout << count << endl;
	return 0;
}

