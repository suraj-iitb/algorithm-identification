#include <stdio.h>

int main()
{

  int n,i,max,c[10005];
  scanf("%d",&n);

  int a[n],b[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(i>0){
      if(max<a[i]){
	max=a[i];
      }
    }
    else
      max=a[i];
 
  }
  
  for(i=0;i<=max;i++)
    {
      c[i]=0;
    }

  for(i=0;i<n;i++){
    c[a[i]]++;
  }

  for(i=1;i<=max;i++){
    c[i]=c[i]+c[i-1];
  }

  for(i=0;i<n;i++){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
 for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",b[i]);
    else
      printf("%d ",b[i]);
  }
 return 0;
}

