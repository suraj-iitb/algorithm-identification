#include<stdio.h>
#define datamax 500001
#define banpei 1000000001
int left[datamax/2 +1];
int right[datamax/2 + 1];
int cnt;
void merge(int *,int,int,int,int);
void mergeSort(int *,int,int,int);
  int main(){
  int a[datamax],n,i;
  cnt = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  mergeSort(a,n,0,n);
  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",cnt);

  return 0;
}

void merge(int a[],int n, int leftnum ,int mid,int rightnum){
  int n1,n2,i=0,j=0,k;
   n1 = mid - leftnum;
   n2 = rightnum - mid;
  for(i=0;i<n1;i++)left[i] = a[leftnum + i];
  for(i=0;i<n2;i++)right[i] = a[mid + i];
  left[n1] = right[n2] = banpei;
  i=0;
  for(k=leftnum;k<rightnum;k++){
    cnt++;
    if(left[i] <= right[j]){
      a[k] = left[i++]; 
    }else{
      a[k] = right[j++];
    }
  }
}

void mergeSort(int a[],int n,int leftnum,int rightnum){
  int mid;
  if(leftnum +1 != rightnum){
    mid = (leftnum + rightnum) / 2;
    mergeSort(a,n,leftnum,mid);
    mergeSort(a,n,mid,rightnum);
    merge(a,n,leftnum,mid,rightnum);
  }
}


