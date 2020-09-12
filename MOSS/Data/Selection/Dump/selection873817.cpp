//セレクションソートはMAXを求める感じのソート、バブルソートの一種ともいえるか…
#include<iostream>
#include<algorithm>
using namespace std;

int n,A[100];

int Selectionsort(int *p,int size){
	int count = 0;
	for(int i = 0;i < size-1;i++){
		//int minest = A[i];		//配列データ捨てたくないので、これはだめ
		int minest = i;
		for(int j = i+1;j < size;j++){
			if(A[minest] > A[j])
				minest = j;
		}
		if(A[minest] < A[i]){
			swap(A[minest],A[i]);
			count++;
		}
	}
	return count;
}
int main(){
	int count;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> A[i];
	count = Selectionsort(A,n);
	for(int i = 0;i < n-1;i++)
		cout << A[i] << " ";
	cout << A[n-1] << endl;
	cout << count << endl;
	return 0;
}
	
