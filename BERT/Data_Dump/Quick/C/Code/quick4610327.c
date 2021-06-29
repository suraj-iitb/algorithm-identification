#include<stdio.h>
#define MAX 100000 //カード枚数の上限
#define SENTINEL 2000000000 //カードに書かれている数の上限

/*構造体Cardの宣言
suit : カードの絵柄(S,H,C,Dのいずれか)
value : カードの数字()*/
struct Card{
	char suit;
	int value;
};

/* 構造体Cardを要素数MAX/2+2個作成したものを左Lと右Rの２つ用意する*/
struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

/*リストの統合を行う関数(ALDS1_5_B)
left : 部分配列の先頭の要素のインデックス
right : 部分配列の末尾+1の要素のインデックス
mid : left+right/2
*/
void merge(struct Card A[], int n, int left, int mid, int right){
	int i, j, k;
	int n1 = mid - left;
	int n2 = right - mid;
	for( i = 0; i < n1; i++ ) L[i] = A[left + i];
	for( i = 0; i < n2; i++ ) R[i] = A[mid + i];
	L[n1].value = R[n2].value = SENTINEL;
	i = j = 0;
	for(k = left; k < right; k++){
		if(L[i].value <= R[j].value){
			A[k] = L[i++];
		}else{
			A[k] = R[j++];
		}
	}
}

/*リストの分割を行う関数(ALDS1_5_B)
リストを２分割していき最終的にリストの要素が１つになったら, mergeによって順に統合を行っていく*/
void mergeSort(struct Card A[], int n, int left, int right){
	int mid;
	if(left + 1 < right){
		mid = (left + right) / 2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

/*パーティション関数(ALDS1_6_B)
配列Aのr番目(最後)の要素xを配列の基準とし, xより大きい要素はpからi番目までの範囲,xより小さい要素はi+1からj番目までの範囲に移動させる*/
int partition(struct Card A[], int n, int p, int r){
	int i,j;
	struct Card t, x;
	x = A[r];
	i = p - 1;
	for(j = p; j < r; j++){
		if(A[j].value <= x.value){
			i++;
			t = A[i]; A[i] = A[j]; A[j] = t;
		}
	}
	t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;
	return i + 1;
}

/*クイックソート関数
パーティション関数を使う範囲を狭めていき精度を高くしてリストをソートする*/
void quickSort(struct Card A[], int n, int p, int r){
	int q;
	if(p < r){
		q  = partition(A, n, p, r);
		quickSort(A, n, p, q - 1);
		quickSort(A, n, q + 1, r);
	}
}

int main(){
	int n, i, v;
	struct Card A[MAX], B[MAX];
	char S[10];
	int stable = 1;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%s %d", S, &v);
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = v;
	}
	
	mergeSort(A, n, 0, n);
	quickSort(B, n, 0, n - 1);
	
	for(i = 0; i < n; i++){
		if(A[i].suit != B[i].suit) stable = 0;
	}
	
	if(stable == 1)printf("Stable\n");
	else printf("Not stable\n");
	for(i =  0; i < n; i++){
		printf("%c %d\n", B[i].suit, B[i].value);
	}
	
	return 0;
}
