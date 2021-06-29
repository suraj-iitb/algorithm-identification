#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b;
    int i=0, j,k;
    int *s;
    scanf("%d",&a);
    s = (int *)malloc(a * sizeof(int));
    while(i < a){
      scanf("%d",&s[i]);
      i++;
    }
     printf("%d",s[0]);
     for(k = 1;k < a;k++){
	  printf(" %d",s[k]);
        }
        printf("\n");
    for(i = 1;i < a;i++){
        b = s[i];
        j = i - 1;
        while(j >= 0 && s[j] > b){
        s[j+1] = s[j];
        j--;
        s[j+1]=b;
        }
	 printf("%d",s[0]);
     for(k = 1;k < a;k++){
	  printf(" %d",s[k]);
        }
        printf("\n");
    }
    free(s);
    return 0;
}


