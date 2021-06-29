#include<stdio.h>
#define AAA 500000
#define BBB 1000000000

int count;
int L[AAA/2+2];
int R[AAA/2+2];

void mergeSort(int [],int ,int ,int );
void merge(int [],int ,int ,int ,int);


int main()
{
  int ori[AAA],n,i;
  
   scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ori[i]);
  }

  mergeSort(ori,n,0,n);

  for(i=0;i<n-1;i++){
    printf("%d",ori[i]);
    printf("%c",' ');
  }

  printf("%d\n",ori[n-1]);
  printf("%d\n",count);

  return 0;
}

void mergeSort(int ori[],int n, int left, int right)
{
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(ori,n,left,mid);
    mergeSort(ori,n,mid,right);
    merge(ori,n,left,mid,right);
  }
}

void merge(int ori[],int n,int left,int mid,int right)
{
  int i=mid-left;
  int j=right-mid;
  int k,l=0,m=0,o;

  for(k=0;k<i;k++) L[k]=ori[left+k];
  for(k=0;k<j;k++) R[k]=ori[mid+k];

  L[i]=R[j]=BBB;

  for(o=left;o<right;o++){
    count++;
    if(L[l]<=R[m]){
      ori[o]=L[l];
      l++;
    }
    else {
      ori[o]=R[m];
      m++;
    }
  }
}
  
