#include<stdio.h>
void Merge(int s[],int l,int r);
int temp[1000000];
int c=0;
int main(){
  int n,i,j,l,m,r,q;
  int a[1000000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  Merge(a,0,n-1);
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",c);
  return 0;
}
void Merge(int x[],int left,int right){
  int mid,i,j,k;
  if(left>=right){
    return;
  }
  mid=(left+right)/2;
  Merge(x, left, mid);
  Merge(x, mid + 1, right);
  for (i = left; i <= mid; i++){
    temp[i] = x[i];
  }

  for (i = mid + 1, j = right; i <= right; i++, j--){
    temp[i] = x[j];
  }

  i = left;
  j = right;

  for (k = left; k <= right; k++){
    if (temp[i] <= temp[j]){
        x[k] = temp[i++];
        c++;
      }
    else{
        x[k] = temp[j--];
        c++;
      }
    }
}

