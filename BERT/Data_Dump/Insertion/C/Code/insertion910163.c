#include <stdio.h>
main(){
  int h,i, j, k,l;
  int c[100];
  scanf("%d", &h);
  for(i=0; i<h; i++){
    scanf("%d", &c[i]);
  }
  for(l=0;l<h;l++){
    printf("%d", c[l]);
    if(l != h-1) printf(" ");
  }
   printf("\n");

  for(i=1; i<h; i++){
     k = c[i];
     j = i - 1;
     while(j >= 0 && c[j] > k){
      c[j+1] = c[j];
      j = j - 1;
    }
     c[j+1] = k;
     for(l=0;l<h;l++){
       printf("%d", c[l]);
       if(l != h-1) printf(" ");
      }
     printf("\n");
  }
 return 0;
}
