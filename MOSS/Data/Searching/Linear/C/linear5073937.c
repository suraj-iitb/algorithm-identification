#include <stdio.h>

int main() {

  int ns,nt,i,j,count=0,tar;
  scanf("%d",&ns);
  int sar[ns];

  for(i=0;i<ns;i++){
    scanf("%d",&sar[i]);
  }

  scanf("%d",&nt);

  for(i=0;i<nt;i++) {
    scanf("%d",&tar);
    for(j=0;j<ns;j++) {
      if(sar[j]==tar) {
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}
