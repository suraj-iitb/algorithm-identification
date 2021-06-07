#include <stdio.h>
#include <stdlib.h>
int main(){
  int n,q,*data1,*data2,i,j,count=0,c=0;

  scanf("%d",&n);

  data1=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&data1[i]);
  }

  scanf("%d",&q);

  data2=(int *)malloc(sizeof(int)*q);
  for(i=0;i<q;i++){
    scanf("%d",&data2[i]);
  }
 
  for(i=0;i<q;i++){
    count=0;
    for(j=0;j<n;j++){
      if(data1[j]==data2[i]) count++;

    }
    if(count>0) c++;

  }
  printf("%d\n",c);
  free(data1);
  free(data2);
  return 0;
}
