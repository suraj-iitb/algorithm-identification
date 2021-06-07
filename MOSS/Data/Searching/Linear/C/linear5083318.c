#include<stdio.h>


int main(){
    int a,b,i,j,cnt=0;
    int s[15000],k[600];
    
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&b);
    for(j=0;j<b;j++){
        scanf("%d",&k[j]);
    }
        for(j=0;j<b;j++){
	  for(i=0;i<a;i++){
	  if(s[i]==k[j]){
	    cnt++;
	    break;
	  }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

