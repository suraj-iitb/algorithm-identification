#include <stdio.h>

#define N 100

int main(){

  int hairetu[N],i,j,nagasa,tmp,count=0;

  scanf("%d",&nagasa);

  for(i=0;i<nagasa;i++) scanf("%d",&hairetu[i]);

  for(j=nagasa-1;j>0;j--){

    for(i=nagasa-1;i>0;i--){

      if(hairetu[i]<hairetu[i-1]){

	tmp=hairetu[i];
	hairetu[i]=hairetu[i-1];
	hairetu[i-1]=tmp;

	count++;

}

    }

}

  for(i=0;i<nagasa-1;i++) printf("%d ",hairetu[i]);
  printf("%d",hairetu[i]);
  printf("\n%d\n",count);

  return 0;

}
