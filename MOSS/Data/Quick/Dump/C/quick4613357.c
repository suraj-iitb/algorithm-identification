#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

struct Card{//構造を決める
	char suit;
	int value;
};

struct Card L[MAX / 2 + 2],R[MAX / 2 + 2];

//安定したソートなのか確認するためのマージソート実装部分
void merge(struct Card A[] , int left , int mid , int right){
	int a,b,c;
	int n1 = mid - left;
	int n2 = right - mid;
	for(a = 0;a < n1;a++) L[a] = A[left + a];
	for(a = 0;a < n2;a++) R[a] = A[mid + a];
	L[n1].value = R[n2].value = SENTINEL;
	a = b = 0;
	for(c = left;c < right;c++){
		if(L[a].value <= R[b].value){
			A[c] = L[a++];
		}else{
			A[c] = R[b++];
		}
	}
}

void mergeSort(struct Card A[],int left,int right){
	int mid;
	if(left + 1 < right){
		mid = (left + right) / 2;
		mergeSort(A,left,mid);//マージソートもクイックソートも二回呼び出している
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}//ここまでが確認用のマージソート実装部分

int partition(struct Card A[],int p,int r){//クイックソートのメインの作業を行う
	int a,b;
	struct Card t,x;
	x = A[r];
	a = p-1;
	for(b=p;b<r;b++){
		if(A[b].value <= x.value){
			a++;
			t=A[a];A[a]=A[b];A[b]=t;//入れ替えを行なっている。
		}
	}
	t=A[a+1];A[a+1]=A[r];A[r]=t;
	return a+1;
}

void quickSort(struct Card A[],int p,int r){//分割したものをそれぞれクイックソートとして呼び出す
	int q;
	if(p<r){
		q = partition(A,p,r);
		quickSort(A,p,q-1);//分割しているため二回呼び出す
		quickSort(A,q+1,r);
	}
}

int main(){
	int n,i,v;
	struct Card A[MAX],B[MAX];
	char S[10];
	int stable = 1;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%s %d",S,&v);
		A[i].suit=B[i].suit=S[0];//トランプの文字が与えられるので頭文字だけ抽出
		A[i].value=B[i].value=v;//数値を入力
	}
	
	mergeSort(A,0,n);//マージソートには最初と最後を与える
	quickSort(B,0,n-1);//クイックソートには最後の判定用の値を除いたものを与える
	
	for(i=0;i<n;i++){//一文字ずつトランプの文字の方を比較
		if(A[i].suit != B[i].suit) stable = 0;
	}
	
	if(stable == 1) printf("Stable\n");//マージソートとクイックソートの結果が一致しているか確認
	else printf("Not stable\n");
	for(i=0;i<n;i++){
		printf("%c %d\n",B[i].suit,B[i].value);
	}
	return 0;
}
//何個のデータがあるかを示す変数nはソート事態では使用しなかったため消した
