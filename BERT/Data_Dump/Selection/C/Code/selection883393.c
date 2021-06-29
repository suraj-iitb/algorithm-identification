#include<stdio.h>
int main(void)
{
  int n,i,count=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  int j,mini,p;
  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if (a[j]<a[mini]){
	mini=j;
      }
    }
    if(mini != i){
      p=a[i];
      a[i]=a[mini];
      a[mini]=p;
      count++;
      int t;
      /*for(t=0;t<n;t++){
	printf("%d",a[t]);
	if(t<n-1) printf(" ");
	if (t==n-1) printf("\n");
	}*/
    }
  }
  
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
    if (i==n-1) printf("\n");
  }
  printf("%d\n",count);
  return 0;
}
