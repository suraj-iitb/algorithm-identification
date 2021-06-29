// Selection Sort
//
// selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
//2   for i が 0 から N - 1 まで
//3     minj = i
//4     for j が i から N - 1 まで
//5       if A[j] < A[minj]
//6         minj = j
//7     A[i] と A[minj] を交換
//
//
// 入力　
//入力の最初の行に、数列の長さを表す整数 N が与えられます。２行目に、N 個の整数が空白区切りで与えられます。
// 出力　
// 出力は 2 行からなります。１行目に整列された数列を 1 行に出力してください。数列の連続する要素は１つの空白で区切って出力してください。2 行目に交換回数を出力してください。
// 

#include <cmath>
#include<iostream>

int main(){
	
	int i, j,minj, n,c=0,a[100],tmp;

	// Input
	std::cin >> n;
	
	for (i = 0; i < n; i++)std::cin >> a[i];
	

	// Search
	
	for (i = 0; i < n ; i++) {
		minj = i;

		for (j = i; j < n ; j++) {
			if (a[minj] > a[j])minj = j;
		}

		if(i!=minj){

		tmp = a[minj];
		a[minj] = a[i];
		a[i] = tmp;
		c++;
		}
	}

	for (i = 0; i < n; i++) {
		std::cout << a[i];
		if (i != n - 1)std::cout << " ";

	}
	std::cout << std::endl;

	std::cout << c << std::endl;
	return 0;
}	
