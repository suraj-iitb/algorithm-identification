#include <stdio.h>
 
struct Card{
  char mark;
  int num;
};
 
 
int Partition(struct Card A[], int left, int pivot, int right){
  int i, j;
  struct Card x, temp;
  x = A[right];
  i = pivot-1;
  for(j=pivot; j<right; j++){
    if(A[j].num<=x.num){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[right];
  A[right] = temp;
  return i+1;
}
 
 
void quickSort(struct Card A[], int n, int p, int r){
  int q;
  if(p<r){
    q=Partition(A, n, p, r);
    quickSort(A, n, p, q-1);
    quickSort(A, n, q+1, r);
  }
}
 
void Merge(struct Card A[], int n, int left, int mid, int right){
  int i, j, k, n1, n2;
  struct Card L[100001/2+2], R[100001/2+2];
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++)
    L[i] = A[left+i];
  for(i=0;i<n2;i++)
    R[i] = A[mid+i];
  L[n1].num=2000000000;
  R[n2].num=2000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i++;;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
}
 
void MergeSort(struct Card A[], int n, int left, int right){
  int mid;
  if (left+1<right){
    mid = (left + right)/2;
    MergeSort(A, n, left, mid);
    MergeSort(A, n, mid, right);
    Merge(A, n, left, mid, right);
  }
}
    
 
 
int main(){
  int n, i, j, v, stable=0;
  char s[10];
  struct Card A[100001], B[100001]; 
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%s %d", s, &v);
    A[i].mark=s[0];
    B[i].mark=A[i].mark;
    A[i].num=v;
    B[i].num=A[i].num;
  }
 
  quickSort(A, n, 0, n-1);
  MergeSort(B, n, 0, n);
   
  for(i=0; i<n; i++){
    if(A[i].mark==B[i].mark)stable++;
  }
 
  if(stable==n)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].mark, A[i].num);
  }  
  return 0;
}
