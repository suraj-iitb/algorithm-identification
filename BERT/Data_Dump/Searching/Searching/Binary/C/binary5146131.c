#include <stdio.h>


int main(){
  int i,n,a[100001],b[50001],j,h;
  int c=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&h);

  for(i=0;i<h;i++){
    scanf("%d",&b[i]);
  }

    for(i=0;i<h;i++){
      int l=0,r=n;
    while(r-l>1){
      int m=(l+r)/2;
      if(a[m] > b[i])r=m;
      else l=m;
    }
    if(a[l]==b[i] || a[r]==b[i]) c++;
    }


  printf("%d\n",c);
  return 0;

}
