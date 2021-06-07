#include<stdio.h>
  
int main(){
    int S[10001],T[501],U[10001];
    int i,j,lengh1,lengh2,count=0,count2=0;
     
    scanf("%d",&lengh1);
    for(i=1;i<=lengh1;i++){
        scanf("%d",&S[i]);}
      
    scanf("%d",&lengh2);
    for(i=1;i<=lengh2;i++){
        scanf("%d",&T[i]);
    }
      
    for(i=1;i<=lengh1;i++){
        for(j=1;j<=lengh2;j++){
        	if(S[i]==T[j]){	
        		count++;
        		U[count]=T[j];}
              }}
	
     count2=count;
	
	for(i=1;i<=count2;i++){
		for(j=i+1;j<=count2;j++){
			if(U[j]==U[i]){
				count--;
				break;}
		}}

    printf("%d\n",count);
	   
      
    return 0;
}
