#include<stdio.h>
#include<string.h>

int a[10001];

void trace(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i > 0)printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int main(void){

	int n, i, j;
	int flag;//フラグは配列のソートがすでに終わっているかを調べる
	int tmp;
	int count = 0;

	//データの入力//
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		flag = 1;
		while (flag == 1) {
			flag = 0;
			for (j = n - 1; j >= i + 1; j--) {//0番目からi番目まではソート済みであることに注意//
				if (a[j] < a[j - 1]) {
					tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
					count++;
					flag = 1;//もし一回も入れ替えなかったのならフラグが立たないため、iの値が一つ増える//
				}
			}
		}
	}

	

	trace(a, n);
	printf("%d\n", count);


	return 0;
}
