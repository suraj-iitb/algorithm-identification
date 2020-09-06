//バブルソートにもいろいろなやり方があるが、その中でもっともバブルな感じにする。
#include<iostream>
#include<algorithm>
using namespace std;

int n,A[100];

int Bubblesort(int *p,int size){
	int count = 0;
	for(int i = 0;i < size-1;i++){
		for(int j = size-1;j >= i+1;j--){
			if(A[j] < A[j-1]){
				swap(A[j],A[j-1]);
				count++;
			}
		}
	}
	return count;
}
int main(){
	int count;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> A[i];
	count = Bubblesort(A,n);
	for(int i = 0;i < n-1;i++)
		cout << A[i] << " ";
	cout << A[n-1] << endl;
	cout << count << endl;
	return 0;
}
	
