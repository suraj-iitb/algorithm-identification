#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 100000
#define SENTINEL 200000000

struct Card{ 
	char suit;
	int value;
};


struct Card L[MAX/2+2],R[MAX/2+2];

void merge(struct Card A[],int n,int left,int mid,int right){
	int n1=mid-left;//左側の配列を用意
	int n2 = right - mid;//右側の配列を用意
	for(int i = 0;i<n1;i++){
		L[i] = A[left + i];//左側の数列を入力
	}

	for(int i = 0;i<n2;i++){
		R[i] = A[mid+ i];//右側の数列を入力
	}

	L[n1].value = R[n2].value = SENTINEL;
	int i=0,j=0;

	for(int k = left;k < right;k++){//比較
		if(L[i].value<=R[j].value){
			A[k] = L[i++];
		}else{
			A[k] = R[j++];
		}
	}
}

void mergeSort(struct Card A[],int n,int left,int right){
	if(left+1<right){//左のほうが右より小さいなら
		int mid = (left+right)/2;//真ん中を計算
		mergeSort(A,n,left,mid);//右を真ん中とする
		mergeSort(A,n,mid,right);//真ん中を左とする
		merge(A,n,left,mid,right);//統合
	}
}

int partition(struct Card A[],int n,int p,int r){
	int i;
	struct Card x;
	x = A[r];//r以下、r以上で分けるための変数
	i = p-1;//先頭を作成
	for(int j = p;j<r;j++){
		if(A[j].value <= x.value){
			i++;
			swap(A[i],A[j]);//j番目が基準xより小さいか大きいかでわける
		}
	}
	swap(A[i+1],A[r]);//xを正しい位置に挿入
	return i+1;
}

void quickSort(struct Card A[],int n,int p,int r){
	int q;
	if(p<r){
		q = partition(A,n,p,r);
		quickSort(A,n,p,q-1);
		quickSort(A,n,q+1,r);
	}
}

int main(){
	int v,n;
	cin >> n;
	struct Card A[MAX],B[MAX];
	char S[10];
	int stable = 1;

	for(int i = 0;i < n;i++){
		cin >> S >> v;
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = v;
	}

	mergeSort(A,n,0,n);
	quickSort(B,n,0,n - 1);

	for(int i = 0;i < n;i++){
		if(A[i].suit !=B[i].suit)stable = 0;
	}

	if(stable == 1)cout<<"Stable"<<endl;
	else cout<<"Not stable"<<endl;

	for(int i = 0;i < n;i++){
		cout << B[i].suit <<" "<< B[i].value << endl;
	}
	return 0;
}
