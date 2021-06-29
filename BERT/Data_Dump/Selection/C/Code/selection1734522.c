#include <stdio.h>
#define N 100

int main(){

  int a[N],i,j,count=0,min,nagasa,tmp,tmp2,k;

  scanf("%d",&nagasa);
  for(i=0;i<nagasa;i++) scanf("%d",&a[i]);

  for(j=0;j<nagasa-1;j++){
    /*    printf("j=%d\n",j);*/
  min=a[j];
  /*  printf("min=%d\n",min);*/
  for(i=j;i<nagasa;i++){

    if(min>a[i]){
      /*      printf("mae min=%d\n",min);*/
      min=a[i];
      tmp2=i;
      /*      printf("atomin=%d %d\n",min,tmp2);*/
    }

  }

    if(min!=a[j]){

      tmp=a[j];
      a[j]=min;
      a[tmp2]=tmp;
      count++;
      /*      printf("henka %d %d %d\n",a[j],a[tmp2],count);
      for(k=0;k<nagasa;k++) printf("%d ",a[k]);
	printf("\n");
      */
}

  }

  for(i=0;i<nagasa-1;i++) printf("%d ",a[i]);
  printf("%d",a[i]);
  printf("\n%d\n",count);

  return 0;
  
}
