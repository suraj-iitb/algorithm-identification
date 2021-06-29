#include<stdio.h>
#define MAXLEN 100000
     
int main(){
    int n, q, i, c, l, h, m;
    int S[MAXLEN+1], T[MAXLEN+1];
       
    scanf("%d", &n); 
    
    for(i=0; i<n; i++){
        scanf("%d", &S[i]); 
    }
   
    scanf("%d", &q); 
    
    for(i=0; i<q; i++){
        scanf("%d", &T[i]); 
    }
    
    c=0;
    
    for(i=0; i<q; i++){
		l=0;
		h=n;
		
		while(l<=h){
			m=(l+h)/2; 
			
            if(T[i]==S[m]){
                c++;
                break;
            } 
            
            else if(T[i]<S[m]){
            	h=m-1;
            } 
            
            else{
            	l=m+1;        	
            }
        }
    }
 
    if(c){
        printf("%d\n", c);
    } 
    
    else{
        printf("0\n");
    }
   
    return 0;
}

