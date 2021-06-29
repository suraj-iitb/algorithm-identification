#include<stdio.h>
#define Max 500000
#define SENTINEL 1000000000
void Merge(int *,int, int,int);
void MergeSort(int *,int,int);

int cnt=0;
int main(){
  int Data[Max],n,i;

  scanf("%d",&n);


 for(i=0;i<n;i++){
   scanf("%d",&Data[i]);
 }
 MergeSort(Data,0,n);

 for(i=0;i<n;i++){
  printf("%d",Data[i]);
  if(i!=n-1){
    printf(" ");
  }
 }
 printf("\n%d\n",cnt);


return 0;
}

void Merge(int *Data,int left,int mid,int right){
 int n1,n2,i,j,k,L[Max/2+2],R[Max/2+2];
 n1=mid-left;
 n2=right-mid;


 for(i=0;i<n1;i++){
   L[i]=Data[left+i];
 }
 for(i=0;i<n2;i++){
   R[i]=Data[mid+i];
 }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;

 for(k=left;k<right;k++){
   cnt++;
   if(L[i]<=R[j]){
     Data[k]=L[i];
     i++;
   }else{
     Data[k]=R[j];
     j++;
   }
 }
 
}

void MergeSort(int *Data,int left,int right){
  int mid;

  if(left+1<right){//leftがrigthtより小さい時入る
   mid = (left + right)/2;
    MergeSort(Data, left, mid);
    MergeSort(Data, mid, right);
    Merge(Data, left, mid, right);
  }
}
