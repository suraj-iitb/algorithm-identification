#include<stdio.h>
#define MAX 100000

typedef struct{
  char mark;
  int  num;
}Card;

Card A[MAX];

void change(Card *x,Card *y) {
  Card z=*x;
  *x=*y;
  *y=z;
}

int partition( int p, int r){
  int j;
  int  x = A[r].num;
  int i = p-1;
  
  for (j = p;j<r;j++){
    if (A[j].num <= x){
      i = i+1;
      change(&A[i],&A[j]);
    }
  }
  change(&A[i+1],&A[r]);
  return i+1;
}

void quickSort(int p,int r){
  int q;
  
  if (p <r){
    q = partition(p, r);
    quickSort(p, q-1);
    quickSort(q+1, r);
  }
}
//-----------------------------------------------------------merge
void merge(Card *A,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  int count;
  
  Card L[n1];
  Card R[n2];
  
  for (i = 0;i< n1;i++)L[i] = A[left + i];
  for (i = 0;i< n2;i++)R[i] = A[mid + i];
  
  L[n1].num = 1000000001;
  R[n2].num = 1000000001;

  i = 0;
  j = 0;

  for (k = left;k<right;k++){
    count++;
    if (L[i].num <= R[j].num){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }  
}

void mergeSort(Card *A,int left,int right){//Aの左と右を入力で　昇順 安定
  int mid;
  
  if (left+1 < right){    
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
//-----------------------merge
int main(){//構造体に対するソート
  int i;
  int n;
  int flag=1;
  Card B[100000];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){//入力
    scanf(" %c%d",&A[i].mark,&A[i].num);
    B[i]=A[i];
  }
  
  quickSort(0,n-1);//ソート//A[]を使う　配列スタートからエンドまで指定
  mergeSort(B,0,n);//Bを使う 0~n

  
  for(i=0;i<n;i++){ //JUDGE　　違ってたらflagで0
    if(A[i].mark!=B[i].mark)flag=0;	 
  }
 
  if(flag)printf("Stable\n");
  else printf("Not stable\n");
  
  for(i=0;i<n;i++){//OUTPUT
    printf("%c %d\n",A[i].mark,A[i].num);
  }
 
  return 0;
}

