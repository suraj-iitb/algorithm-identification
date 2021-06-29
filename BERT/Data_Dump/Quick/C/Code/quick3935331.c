#include<stdio.h>
#include<stdlib.h>

#define SENTINEL 2000000000

long int cnt=0;

typedef struct box{
	char a;
	int b;
} card;

void merge(card *A,int left,int mid,int right)//分割した配列を小さい順に結合
{
  int n1 = mid - left;
  int n2 = right - mid;
  card L[n1+1],R[n2+1];
  int k,i,j;
  for (i=0;i<n1;i++) {
  	L[i].a = A[left + i].a;
  	L[i].b = A[left + i].b;
  }
  for (i=0;i<n2;i++) {
  	R[i].a = A[mid + i].a;
  	R[i].b = A[mid + i].b;
  }
  L[n1].b = SENTINEL;//EOF
  R[n2].b = SENTINEL;//EOF
  i = 0;
  j = 0;
    
  for(k=left;k<right;k++){//iが左の要素番号,jが右の要素番号
    if(L[i].b<=R[j].b){//左が小さい場合
      A[k].a = L[i].a;
      A[k].b = L[i].b;
      i=i+1;
    }else{ //右が小さい場合
      A[k].a = R[j].a;
       A[k].b = R[j].b;
      if(L[i].b!=SENTINEL) cnt+=(n1-i);//SENTINELと比較する場合を除いて左側の未ソート部分の要素数をcntに加算
      j = j + 1;
    }
  }
}

void mergeSort(card *A,int left,int right)
{
  int mid,i;
  if(left+1<right){//二分探索のように左端が右端を超えたら終了
    mid = (left + right)/2;
    mergeSort(A, left, mid);//左半分で再帰
    mergeSort(A, mid, right);//右半分で再帰
    merge(A, left, mid, right);//結合
  }
}


int partition(card *A,int p,int r)
{
	int x = A[r].b;//基準値をxに格納
	int box,j,i = p-1;
	
	int k;
	
	char s;
	for( j = p ; j < r ; j++){//jがこれから探索する要素番号を示す
		if( A[j].b <= x){//xより小さければ
			i = i+1;//iをインクリメントする
			box=A[i].b;//xより大きくかつ最後に追加した要素と入れ替える
			s=A[i].a;
			A[i].b=A[j].b;
			A[i].a=A[j].a;
			A[j].b=box;
			A[j].a=s;
		}
	}
	box=A[i+1].b;//基準値をiの位置に格納する
	s=A[i+1].a;
	A[i+1].b=A[r].b;
	A[i+1].a=A[r].a;
	A[r].b=box;
	A[r].a=s;
	//for(k=p;k<r;k++) printf("%c %d\n",A[k].a,A[k].b);
	return i+1;
}


void quicksort(card *A,int p ,int r)
{
	int q;
	if(p<r){
		q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main(void)
{
	int i,n;
	card *A;
	card *B;
	int left,right;
	int check=0;
	scanf("%d",&n);
	A = (card*)malloc(sizeof(card)*n+1);
	B = (card*)malloc(sizeof(card)*n+1);
	for(i=0;i<n;i++) {
		scanf("%s",&A[i].a);
		scanf("%d",&A[i].b);
		B[i].a=A[i].a;
		B[i].b=A[i].b;
	}
	
	quicksort(A,0,n-1);
	 left=0;
    right=n;
	mergeSort(B,left,right);
	for(i=0;i<n;i++) if(A[i].a!=B[i].a) check=1;
	if(check==0)printf("Stable\n");
	else printf("Not stable\n");
	for(i=0;i<n;i++) printf("%c %d\n",A[i].a,A[i].b);
	free(A);
	free(B);
	return 0;
}
