#include<stdio.h>
#define MAX 500000
int count=0;

void merge(int *A,int left,int mid,int right){//leftからrightまでのAを昇順に入れ直す
  int n1 = mid - left;//左大きさ
  int n2 = right - mid;//右大きさ
  int i,j,k;

  int L[n1+1];//左の配列
  int R[n2+1];//右の配列
  //初期化
  for (i = 0;i< n1;i++)L[i] = A[left + i];
  for (i = 0;i< n2;i++)R[i] = A[mid + i];
  
  L[n1] = 1000000001;//番兵
  R[n2] = 1000000001;

  i = 0;
  j = 0;

  for (k = left;k<right;k++){//LとRの要素をうまいこと、昇順にAに入れ直す
      count++;
      
      if (L[i] <= R[j]){
	  A[k] = L[i];
	  i++;
	}
      else{
	  A[k] = R[j];
	  j++;
	}
    }  
}


void mergeSort(int *A,int left,int right){//グループに半分ずつ分けて,mergeにわたす
  int mid;
  if (left+1 < right){    
      mid = (left + right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
}

int main()
{
  int i;
  int  n;
  int B;
  int A[MAX];
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  mergeSort(A,0,n);//初めは配列、左、右の番号
 
  for(i=0;i<n;i++){
      if(i)printf(" ");
      printf("%d",A[i]);
    }

  printf("\n%d\n",count);
  return 0;
}

