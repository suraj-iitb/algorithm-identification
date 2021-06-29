#include <stdio.h>

#define M 500000
#define S 1000000000
void Merge(int[],int,int,int);
void Mergesort(int[],int,int);
int SS[M];
int count = 0;

main(){

  int n;
  int i;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&SS[i]);
  }

  Mergesort(SS,0,n);

  for(i = 0 ;i <= n - 2 ; i++ ){
    printf("%d ",SS[i]);
  }

  printf("%d\n",SS[n - 1]);
  printf("%d\n",count);

  return 0;

}



void Mergesort(int SS[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    Mergesort(SS, left, mid);
    Mergesort(SS, mid, right);
    Merge(SS, left, mid, right);
  }
}


void Merge(int SS[],int left,int mid,int right){
  int n1,n2,i = 0,j = 0,k = 0;
  int L[M],R[M];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1 ; i++){
    L[i] = SS[left + i];
  }

  for(j = 0 ; j < n2 ;j++ ){
   R[j] = SS[mid + j];
  }



//L[n1] = S;                                                                            
  //R[n2] = S;                                                                            




  i = 0;
  j = 0;
  L[n1] = S;
  R[n2] = S;


  for(k = left ; k < right; k++){
    if(L[i] <= R[j]){
      SS[k] = L[i];
      count++;
      i++;
    }
    else{
      SS[k] = R[j];
      count++;
      j++;
    }
  }
}
