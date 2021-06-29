#include<stdio.h>
#include<stdlib.h>
void mergeSort(int *,int,int);
int count=0;
int main(){
  int i,A[500000],L,R;
  scanf("%d",&R);
  for(i=0;i<R;i++)scanf("%d",&A[i]);
  mergeSort(A,0,R);
  for(i=0;i<R;i++){
    if(i<R-1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",count);
  return 0;
}

void mergeSort(int *array,int L,int R){
  int i,l,r,Lnum,Rnum;
  int *array2;
  
  if(L+1 < R){
    mergeSort(array,L,(L+R)/2);
    mergeSort(array,(L+R)/2,R);
  
    array2=malloc(sizeof(int)*(R-L));
    l=L;
    r=(L+R)/2;
    for(i=0;i<R-L;i++){
      count++;
      if(l==((L+R)/2)){
	array2[i] = array[r];
	r++;
	
      }
      else if(r==R){
	array2[i] = array[l];
	l++;
	
      }
      else if(array[l]<=array[r]){
	array2[i] = array[l];
	l++;
	
      }
      else {
	array2[i] = array[r];
	r++;

      }
    }
    for(i=L;i<R;i++){
      array[i]=array2[i-L];
    }
    free(array2);
  }
}
