#include<stdio.h>
   
int main(){
    int S[100001],T[50001],U[100001];
    int i,j,lengh1,lengh2,count=0,count2=0;
      
    scanf("%d",&lengh1);
    for(i=1;i<=lengh1-count2;i++){
        scanf("%d",&S[i]);
    	if(i>1 && S[i]==S[i-1]){
    		i--;
    		count2++;
    
    }}
       
    scanf("%d",&lengh2);
    for(i=1;i<=lengh2;i++){
        scanf("%d",&T[i]);
    }
       
    for(i=1;i<=lengh1-count2;i++){
        for(j=1;j<=lengh2;j++){
        	if(S[i]==T[j]){
        		count++;
    break;}          
              }}
     
 
    printf("%d\n",count);
        
       
    return 0;
}
