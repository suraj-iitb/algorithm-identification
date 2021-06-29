#include<stdio.h>
typedef struct{
    char s;
    int t;
  }f;
int part(f a[],int p,int r){
  int x=a[r].t;
  int i=p-1;
  int j;
  f b;
  for(j=p;j<r;j++){
    if(a[j].t<=x){
      i++;
      b=a[i];
      a[i]=a[j];
      a[j]=b;
    }
  }
  b=a[i+1];
  a[i+1]=a[r];
  a[r]=b;
  return i+1;
}
void quick(f a[],int p,int r){
  int q;
  if(p<r){
    q=part(a,p,r);
    quick(a,p,q-1);
    quick(a,q+1,r);
  }
}
void merge(f s[], int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  f L[n1], R[n2];
  int i,j,k;
  for(i=0;i<n1;i++)L[i] = s[left + i];
  for(i=0;i<n2;i++)R[i] = s[mid + i];
  L[n1].t = 999999999;
  R[n2].t = 999999999;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if( L[i].t <= R[j].t){
      s[k] = L[i];
      i = i + 1;
    }
    else {
      s[k] = R[j];
      j = j + 1;
    }

  }
}
void mergeSort(f s[],int left,int right){
  int mid;
  if( left+1 < right){
    mid = (left + right)/2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);
    merge(s, left, mid, right);
  }
}
int main(){
  int n,i,c=0;
  f a[100000],b[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%d",&a[i].s,&a[i].t);
    b[i]=a[i];
  }
  quick(a,0,n-1);
  mergeSort(b,0,n);
  for(i=0;i<n;i++)if(a[i].s!=b[i].s)c=1;
  if(c==1)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<n;i++)printf("%c %d\n",a[i].s,a[i].t);
  return 0;
}
