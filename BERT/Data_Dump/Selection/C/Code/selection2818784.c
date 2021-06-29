#include <stdio.h>

int selectionSort(int s[],int N){
    int i,j;
    int minj;
    int tmp;
    int count=0;
    for(i=0;i<N-1;i++){
        minj=i;
        for(j=i+1;j<N;j++){
            if(s[j]<s[minj])minj=j;
        }
        if(minj!=i){
            tmp=s[i];
            s[i]=s[minj];
            s[minj]=tmp;
            count++;
        }
    }

    return count;
}
int main(void){
    int i;
    
    int N;
    scanf("%d",&N);
    int s[N];
    for(i=0;i<N;i++)scanf("%d",&s[i]);
    
    int count;
    count=selectionSort(s,N);
    
    printf("%d",s[0]);
    for(i=1;i<N;i++)printf(" %d",s[i]);
    printf("\n%d\n",count);
    
    return 0;
}
