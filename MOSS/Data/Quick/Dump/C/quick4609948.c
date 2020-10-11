#include<stdio.h>
#define MAX 100000 /* 最大値を定義 */
#define SENTINEL 2000000000
/*カードの構造体の宣言*/
struct Card{
char suit;
int value;
};

struct Card LEFT[MAX/2+2],RIGHT[MAX/2+2];

void merge(struct Card A[], int n, int left,int mid,int right){
int i,j,k;//適当な変数を用意
int n1= mid-left;//真ん中ー左端
int n2=right-mid;//右側ー中央
for(i=0;i<n1;i++) LEFT[i]=A[left+i];//左側の配列
for(i=0;i<n2;i++) RIGHT[i]=A[mid+i];//右側の配列
LEFT[n1].value=RIGHT[n2].value=SENTINEL;
i=j=0;
//左側から右側までの処理をする
for(k=left;k<right;k++){
//左右の数値を比較する
if(LEFT[i].value<=RIGHT[j].value){
A[k]=LEFT[i++];}
else{
A[k]=RIGHT[j++];
}
}
}

void mergesort(struct Card A[],int n,int left,int right){
int mid;//真ん中の部分の処理をする(中央値）
if(left+1<right){
mid =(left+right)/2;
mergesort(A,n,left,mid);
mergesort(A,n,mid,right);//右と左を分けて考える
merge(A,n,left,mid,right);
}
}

//前後2つの部分配列の処理をする
int partition(struct Card A[],int n,int p,int r){
int i,j;//さっきの変数i、jの処理をする
struct Card t,x;//構造体の変数t,xを宣言
x =A[r];
i=p-1;
for(j=p;j<r;j++){
if(A[j].value<= x.value){//xの値とj番目の数値の比較
i++;
//入れ替えにつての処理する
t=A[i];A[i]=A[j];A[j]=t;
}
}
//i+1とr番目の順序を入れ替える
t=A[i+1];A[i+1]=A[r];A[r]=t;
return i+1;
}

void quicksort(struct Card A[],int n,int p,int r){
int m;
if(p<r){
m=partition(A,n,p,r);
quicksort(A,n,p,m-1);
quicksort(A,n,m+1,r);
}
}

//実装させるためのメインメソッド
int main(){
int n,i,v;
struct Card A[MAX],B[MAX];
char S[10];
int stable =1;//安定か否か判定するstable
scanf("%d",&n);
for(i=0;i<n;i++){//n番目の要素までをfor文で回す
scanf("%s %d",S,&v);
A[i].suit=B[i].suit=S[0];
A[i].value=B[i].value=v;
}
mergesort(A,n,0,n);
quicksort(B,n,0,n-1);
for(i=0;i<n;i++){
//マージソートとクイックソートの結果を調べる
if(A[i].suit != B[i].suit)
stable=0;//一致していないときは0とする
}
if(stable==1) printf("Stable\n");
else printf("Not stable\n");
for(i=0;i<n;i++){
printf("%c %d\n",B[i].suit,B[i].value);
}
return 0;
}
