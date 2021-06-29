#include <stdio.h>
int hi[1000000];
int NT (int n, int key);
int main()
{
  int i,n,q,key,count=0;
  scanf ("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&hi[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if ( NT(n,key)==1 )
      count++;
  }
  printf ("%d\n",count);

  return 0;
}

int NT (int n, int key ){
  int l=0,m,r=n;
  while(l<r){
    m= (l+r)/2;
    if (hi[m]==key)
      return 1;
    else if(hi[m]<key)
      l=m+1;
    else if(key<hi[m])
      r=m;
  }
  return 0;
}

