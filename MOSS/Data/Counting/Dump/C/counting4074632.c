#include<stdio.h>
#define MAX 2000000
 
int arr[MAX];
int n;
 
void count(int a[], int k)
{
  int ca[k],i,j;
  i = k;
  for(; i>=0 ; i--) ca[i] = 0;
  for(j=1; j<=n; j++) ca[a[j]]++;
  for(i=1; i<k; i++) ca[i] += ca[i-1];
  for(j=n; j>=1; j--){
    arr[ca[a[j]]] = a[j];
    ca[a[j]]--;
  }
}


int main(int argc,char *argv[])
{
  int k=0,i;
  int a[MAX];
  scanf("%d",&n);
  for(i=1; i<=n; i++)
    {
    scanf("%d",&a[i]);
  }
  k=a[1];
  for(i=2; i<=n; i++){
    if(k < a[i]) k = a[i];
  }
  
  count(a, k+1);
  for(i=1; i<n; i++) {
    printf("%d ",arr[i]);
  }

  
  printf("%d\n",arr[i]);
  return 0;
}
