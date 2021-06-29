#include <stdio.h>



int main(){
    int In[10000],Out[500],Ni,No,i,j,C=0;
    scanf("%d",&Ni);
    for (i=0; i<Ni; i++) {
        scanf("%d",&In[i]);
    }
    scanf("%d",&No);
    for (j=0; j<No; j++) {
        scanf("%d",&Out[j]);
    }
    
    for(i=0; i<No; i++){
        j=0;
        In[Ni] = Out[i];
        while(In[j] != Out[i]){
            j++;
        }
        if(j < Ni) C++;
    }
    printf("%d\n",C);
    
}

