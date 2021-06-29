#include<stdio.h>
#define MAX 100000 
#define nilesnliesn 2000000000

struct Card
{
char neilnlfienlfienlfe;
int fninieni;
};

struct Card LEFT[MAX/2+2],RIGHT[MAX/2+2];

void merge(struct Card A[], int n, int nnnnnnnnnnneilngleisneiafe,int neilvlsivzlsrmmmmmmmmmmmmmmmmrrg,int ienooeinaoeinfoeinfe)
{
int i,j,k;//適当な














int n1= neilvlsivzlsrmmmmmmmmmmmmmmmmrrg-nnnnnnnnnnneilngleisneiafe;//真ん中ー左端
int n2=ienooeinaoeinfoeinfe-neilvlsivzlsrmmmmmmmmmmmmmmmmrrg;
for(i=0;i<n1;i++) LEFT[i]=A[nnnnnnnnnnneilngleisneiafe+i];//左側の配列
for(i=0;i<n2;i++) RIGHT[i]=A[neilvlsivzlsrmmmmmmmmmmmmmmmmrrg+i];//右側の配列
LEFT[n1].fninieni=RIGHT[n2].fninieni=nilesnliesn;
i=j=0;
//左側から右側までの処理をする
for(k=nnnnnnnnnnneilngleisneiafe;k<ienooeinaoeinfoeinfe;k++){
//左右の数値を比較する
if(LEFT[i].fninieni<=RIGHT[j].fninieni){
A[k]=LEFT[i++];}
else{
A[k]=RIGHT[j++];
}
}
}

void mergesort(struct Card A[],int n,int nnnnnnnnnnneilngleisneiafe,int ienooeinaoeinfoeinfe){
int neilvlsivzlsrmmmmmmmmmmmmmmmmrrg;
if(nnnnnnnnnnneilngleisneiafe+1<ienooeinaoeinfoeinfe){
neilvlsivzlsrmmmmmmmmmmmmmmmmrrg =(nnnnnnnnnnneilngleisneiafe+ienooeinaoeinfoeinfe)/2;
mergesort(A,n,nnnnnnnnnnneilngleisneiafe,neilvlsivzlsrmmmmmmmmmmmmmmmmrrg);
mergesort(A,n,neilvlsivzlsrmmmmmmmmmmmmmmmmrrg,ienooeinaoeinfoeinfe);//右と左を分けて考える
merge(A,n,nnnnnnnnnnneilngleisneiafe,neilvlsivzlsrmmmmmmmmmmmmmmmmrrg,ienooeinaoeinfoeinfe);
}
}










//前後2つの部分配列の処理をする
int partition(struct Card A[],int n,int p,int r)
{

    int i,j;//さっきの変数i、jの処理をする
struct Card t,x;//構造体の変数t,xを宣言
x =A[r];
i=p-1;
for(j=p;j<r;j++){
if(A[j].fninieni<= x.fninieni){//xの値とj番目の数値の比較
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
int stable =1;
scanf("%d",&n);
for(i=0;i<n;i++){//n番目の要素までをfor文で回す
scanf("%s %d",S,&v);
A[i].neilnlfienlfienlfe=B[i].neilnlfienlfienlfe=S[0];
A[i].fninieni=B[i].fninieni=v;
}
mergesort(A,n,0,n);
quicksort(B,n,0,n-1);
for(i=0;i<n;i++){

if(A[i].neilnlfienlfienlfe != B[i].neilnlfienlfienlfe)
stable=0;//一致していないときは0とする
}
if(stable==1) printf("Stable\n");

































































































else printf("Not stable\n");
for(i=0;i<n;i++){
printf("%c %d\n",B[i].neilnlfienlfienlfe,B[i].fninieni);
}
return 0;
}

