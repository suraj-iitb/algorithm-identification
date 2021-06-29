#include<stdio.h>
#include<stdlib.h>

#define S_MAX 1000000000

void merge(int *,int,int, int);
void mergeSort(int *, int, int);

int count=0;

int main(){

  int n,*S;
  int i;

  scanf("%d",&n);
  if(500000<n)exit(1);

  S=(int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
    if(S[i]<0 || S_MAX<S[i])exit(2);
  }

  mergeSort(S,0,n);

  for(i=0; i<n; i++){
    printf("%d",S[i]);
    if(i!=n-1)printf(" ");
  }

  printf("\n%d\n",count);

  free(S);

  return 0;
}

void merge(int *S, int left,int mid,int right){
  int n1,n2;
  int *L,*R;

  int i,j,k;

  n1=mid-left;
  n2=right-mid;

  L=(int *)malloc((n1+1)*sizeof(int));
  R=(int *)malloc((n2+1)*sizeof(int));

  //printf("merge--left%d mid%d right%d\n",left,mid,right);

  for(i=0; i<n1; i++){
    L[i]=S[left+i];
    //printf(" L[%d]%d",i,L[i]);
  }
  //printf("\n");
  for(i=0; i<n2; i++){
    R[i]=S[mid+i];
    //printf(" R[%d]%d",i,R[i]);
  }
  //printf("\n");

  L[n1]=S_MAX+1;
  R[n2]=S_MAX+1;

  i=j=0;

  for(k=left; k<right; k++){
    //printf("mergeS[%d]%d\n",k,S[k]);
    if(L[i]<=R[j]){
      //printf("S[%d]=L[%d]=%d\n",k,i,L[i]);
      S[k]=L[i];
      i++;
    }
    else{
      //printf("S[%d]=R[%d]=%d\n",k,j,R[j]);
      S[k]=R[j];
      j++;
    }
    count++;
  }
  free(L);
  free(R);
}

void mergeSort(int *S,int left,int right){
  int M;
  //printf("Sort--left%d right%d\n",left,right);
  if(left+1<right){
    M=(left+right)/2;
    mergeSort(S,left,M);
    mergeSort(S,M,right);
    merge(S,left,M,right);
  }
  //printf("  EndSort--left%d right%d\n",left,right);
}
