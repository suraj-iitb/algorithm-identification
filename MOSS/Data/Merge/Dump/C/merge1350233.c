#include<stdio.h>
//#include<stdlib.h>

#define INF (1<<30)

int A[500000];
int count = 0;
int R[500000],L[500000];

//void merge(int A[],int left,int mid,int right);
//void mergeSort(int A[],int left,int right);
//  int *L,*R;

void merge(int A[],int left,int mid,int right){

  int n1,n2;
  int i,j,k;


  n1 = mid - left;
  n2 = right - mid;
  
  
  for(i = 0 ; i < n1 ; i++) 
    L[i] = A[left + i]; 
  for(i = 0 ; i < n2 ; i++)
    R[i] = A[mid + i];

  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;

  for (k = left ; k < right ; k++){
    count++;
    //printf("came123\n");
    if(L[i] < R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
  //  free(L);
  //free(R);

}


void mergeSort(int A[],int left,int right){
  int mid;
  //int i=0;

  if( left+1 < right){
    //fprintf(stderr,"error :%d\n",i);
    //i++;
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    //printf("came1\n");
    mergeSort(A,mid,right);
    //printf("came2\n");
    merge(A,left,mid,right);
    //printf("came3\n");
  }

}



int main(){
  int length,i;
  scanf("%d",&length);
  for(i = 0 ; i < length; i++){
    scanf("%d",&A[i]);
  }

  //  L = malloc(sizeof(int) * length);
  //  R = malloc(sizeof(int) * length);

  mergeSort(A,0,length);
  for(i = 0 ; i < length-1; i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],count);

  return 0;
}
