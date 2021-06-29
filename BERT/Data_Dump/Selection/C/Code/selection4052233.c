#include <stdio.h>
#define MAX 100
int main(){
  int num[MAX],a,i,j,k=0,m,n=0,p,minj;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<a-1;i++){
      m=num[i];
      minj=i;
        for(j=i;j<a;j++){
	  if(num[minj]>num[j]){
	    minj=j;
	  }
        }
	if(num[i]>num[minj]){
        num[i]=num[minj];
        num[minj]=m;
	n++;
	}
    }
     for(i=0;i<a;i++){
       printf("%d",num[i]);
       if(i !=a-1){
           printf(" ");
       }
     }
        printf("\n%d\n",n);
    return 0;
}

