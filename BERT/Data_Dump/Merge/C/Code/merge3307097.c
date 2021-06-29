#include<stdio.h>
int c=0, n,i,j,l,m,r,q,a[1000000],temp[1000000];
void input(){
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
}
void pri(){
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[n-1],c);
}
void M(int x[],int left,int right){
  int mid,i,j,k;
  if(left>=right)return;
  mid=(left+right)/2;
  M(x, left, mid);
  M(x, mid + 1, right);
  for (i = left; i <= mid; i++) temp[i] = x[i];
  for (i = mid + 1, j = right; i <= right; i++, j--) temp[i] = x[j];
  i = left;
  j = right;
  for (k = left; k <= right; k++){
    if (temp[i] <= temp[j]){
        x[k] = temp[i++];
        c++;
    }else{
        x[k] = temp[j--];
        c++;
    }
  }
}
int main(){
  input();
  M(a,0,n-1);
  pri();
}
