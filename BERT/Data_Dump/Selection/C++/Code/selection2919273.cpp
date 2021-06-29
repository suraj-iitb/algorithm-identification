#include <iostream>
using namespace std;

void printList(int num[], int n){
	for (int i = 0; i < n; i++){
		cout << num[i];
		if (i != n-1) cout << ' ';
	}
	cout << endl;
}

void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int selectionSort(int num[], int n){
	int min, j, count = 0;
	for (int i = 0; i < n; i++){
		min = i;
		for (j = i; j < n; j++){
			if (num[min] > num[j])
				min = j;
		}
		if (min != i){
			swap (num[min], num[i]);
			count++;
		}
	}
	return count;
}

int main(){
	int n[100];
	int limit;
	cin >> limit;
	for (int i = 0; i < limit; i++){
		cin >> n[i];
	}
//	printList(n, limit);
	int count;
	count = selectionSort(n, limit);
	printList(n, limit);
	cout << count << endl;
	return 0;
}
