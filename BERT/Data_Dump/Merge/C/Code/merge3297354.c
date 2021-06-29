#include <stdio.h>
#include <stdlib.h>

int marge(int*,int,int,int);
int mergeSort(int*,int,int);

int main(){
  int n,*s,i,cnt;

  scanf("%d",&n);
  s= (int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&s[i]);

  cnt=margeSort(s,0,n);

  for(i=0;i<n;i++){
    printf("%d",s[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",cnt);

  free(s);
  return 0;
}

int margeSort(int A[],int left,int right){
  int mid,i;
  int cnt=0;/* すべての比較回数をまとめておく */
  if(left+1<right){
    mid =(left+right)/2;
    cnt+=margeSort(A,left,mid);
    cnt+=margeSort(A,mid,right);
    cnt+=merge(A,left,mid,right);
  }
  
  return cnt;
}

int merge(int A[],int left,int mid,int right){
  int n1,n2,*L,*R,i,j,k,cnt=0;

  n1=mid-left;
  n2=right-mid;


  L=(int *)malloc((n1+1)*sizeof(int));
  R=(int*)malloc((n2+1)*sizeof(int));

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++)  R[i]=A[mid+i];
   

  L[n1]=1000000001;/* この数より上回らないため */
  R[n2]=1000000001;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    cnt++;
  }
  free(L);
  free(R);

  return cnt;
}

