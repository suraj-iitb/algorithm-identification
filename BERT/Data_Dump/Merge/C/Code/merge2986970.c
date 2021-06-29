#include <stdio.h>
#include <stdlib.h>

#define infty 999999999
#define ele 10000000

void merge(int left, int mid, int right);
void mergeSort(int left, int right);

int S[ele];
int count = 0;

int main(){
  int n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(0,n);

  for(i=0;i<n;i++){
     if(i!=n-1)
    printf("%d ",S[i]);
     else
       printf("%d\n",S[i]);
  }
   printf("%d\n",count);
  return 0;
}
void merge(int left, int mid, int right){
  int n1,n2,k,i,j;
  int *L,*R;
   n1 = mid - left;
   n2 = right - mid;
L = (int *)malloc((n1+1) * sizeof(int));
R = (int *)malloc((n2+1) * sizeof(int));
 
    for(i=0;i<= n1-1;i++){
      L[i] = S[left + i];
      }

  for( i = 0;i<= n2-1;i++){
    R[i] = S[mid + i];
  }

  L[n1] = infty;
  R[n2] = infty;

  i = 0;
  j = 0;

  for(k = left; k<= right-1;k++){

    if( L[i] <= R[j]){
      count++;
	S[k] = L[i];
	i = i + 1;
	}

	else {
	  count++;
        S[k] = R[j];
	j = j + 1;
	}
}
  free(L);
  free(R);
}

void mergeSort(int left, int right){
  int mid;
  if(left+1 < right){
  mid = (left + right)/2;
  mergeSort(left, mid);
  mergeSort(mid, right);
  merge(left, mid, right);
  }
}

