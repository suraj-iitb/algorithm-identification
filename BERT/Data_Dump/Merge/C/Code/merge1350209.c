#include <stdio.h>

int S[500000];
int S2[500000];
int cou = 0;

void merge(int[],int,int);


int main(){

  int i,j,n; 


  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&S2[i]);
  }
  
  merge(S2,0,n-1);
  
  for(i = 0; i < n; i++){
    printf("%d",S2[i]);
    if(i != n - 1)printf(" ");
  }
  printf("\n");
  printf("%d\n",cou);
  return 0;
}


void merge(int x[], int left,int right){
  
  int mid,i,j,k;
  
  if(left >= right)
    return;

  mid = (left + right)/2;
   merge(x, left,mid);
   merge(x, mid+1, right);

  for(i= left; i<= mid; i++){
    S[i] = x[i];
  }
 

  for(i= mid + 1, j = right; i <= right; i++,j--){
    S[i] = x[j];
  }

  i = left;
  j = right;

  for(k = left; k <= right; k++){
    cou++;
    if (S[i] <= S[j]){
    x[k] = S[i++];
    }
    else x[k] = S[j--];
  }

} 
