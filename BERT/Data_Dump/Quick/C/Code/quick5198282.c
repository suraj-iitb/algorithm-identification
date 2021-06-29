#include<stdio.h>
#include<limits.h>
#define MAX 100001
int n;
struct Card{
  char suit;
  int value;
};
void swap(struct Card *x,struct Card *y){
  struct Card temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
int Stable(struct Card A[],struct Card out[]){
  int i;
  for(i=0;i<n;i++){
    if(A[i].suit != out[i].suit)
      return 0;
  }
  return 1;
    
}

int part(struct Card A[],int p,int r){
  int i,j,x;
  x = A[r].value;
  i = p-1;
  for(j=p;j<r;j++){

    if(A[j].value <= x){
      i = i+1;
      swap(&A[i],&A[j]);
    }
  }
  swap(&A[i+1],&A[r]);
 return i+1;

}
void merge(struct Card A[],int left,int mid,int right){
  int i,j,n1,n2,k;
  n1 = mid - left;
  n2 = right - mid;
  struct Card L[n1+1],R[n2+1];
  for(i=0;i<n1;i++){
    L[i] = A[left+i];
}
   for(i=0;i<n2;i++){
    R[i] = A[mid+i];
}
   L[n1].value=R[n2].value = INT_MAX;
   i=j=0;
   for(k=left;k<right;k++){
     if(L[i].value <= R[j].value){
       A[k] = L[i];
       i = i +1;
     }
     else{
       A[k] = R[j];
       j = j + 1;
     }
   }
  
}
void Sort(struct Card A[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left+right)/2;
    Sort(A,left,mid);
    Sort(A,mid,right);
    merge(A,left,mid,right);
}
}
void Quick(struct Card A[],int p,int r){
  int q;
  if(p<r){
    q = part(A, p, r);
    Quick(A, p, q-1);
    Quick(A, q+1, r);
  }
}
void print(struct Card A[],int p,int r){
  struct Card out[MAX];
  int i;
  for(i=0;i < n; i++) out[i] = A[i];
  Quick(out,p,r);
  Sort(A,0,n);
  if (Stable(A,out) == 1) printf("Stable\n");
  else printf("Not stable\n");
    for(i=0;i<=r;i++){
     printf("%c %d\n",out[i].suit,out[i].value);
  }
}
int main(){
  int i;
  struct Card C[MAX];
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&C[i].suit,&C[i].value);
  }

  print(C,0,n-1);
  
  return 0;
}

