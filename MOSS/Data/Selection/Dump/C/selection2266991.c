#include <stdio.h>
#define N 100

int main(){
int i,j,A[N],minj,count=0,key,num;

scanf("%d",&num);

for(i=0;i<num;i++){
scanf("%d",&A[i]);
}

for(i=0;i<num;i++){
    minj=i;
    for(j=i;j<num;j++){
        if(A[j]<A[minj]){
            minj=j;  
        } 
    }
        if(i!=minj){
        key=A[i];
        A[i]=A[minj];
        A[minj]=key;
        count++;
        }
    
}

for(i=0;i<num-1;i++){
printf("%d ",A[i]);
}

printf("%d\n%d\n",A[num-1],count);

return 0;
}
