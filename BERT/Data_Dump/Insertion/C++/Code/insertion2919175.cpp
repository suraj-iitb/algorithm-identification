#include <iostream>
using namespace std;

void printList(int num[], int n){
	for (int i = 0; i < n; i++){
		cout << num[i];
		if (i != n-1) cout << ' ';
	}
	cout << endl;
}

void insertSort(int num[], int n){
	int tmp;
	int j;
	for (int i = 1; i < n; i++){
		tmp = num[i];
		j = i - 1;
		while (j >= 0 && num[j] > tmp){
			num[j+1] = num[j];
			j--;
		}
		num[j+1] = tmp;
		printList(num, n);
	}
}

int main(){
	int n[100];
	int limit;
	cin >> limit;
	for (int i = 0; i < limit; i++){
		cin >> n[i];
	}
	printList(n, limit);
	insertSort(n, limit);
//	printList(n, limit);
	return 0;
}
