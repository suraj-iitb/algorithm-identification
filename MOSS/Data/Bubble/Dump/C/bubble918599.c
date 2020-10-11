#include<stdio.h>
main(){
  int i,j,s,p,count = 0,a[100];
  scanf("%d", &s);
    for(i=0;i<s;i++){
      scanf("%d", &a[i]);
    }
    for(i=0;i<s;i++){
      for(j=s-1;j>i;j--){
	if(a[j] < a[j-1]){
          p = a[j];
          a[j] = a[j-1];
          a[j-1] = p;
          count++;
	}
      }
    }         
    for(i=0;i<s;i++){
      printf("%d",a[i]);
      if(i != s-1)
	printf(" ");
    }
    printf("\n%d\n",count);
    return 0;
}
