#include <stdio.h>

int bubbleSort(int s[],int N){
    int flag=1;
    int count=0;
    int tmp;
    int i;
    
    while(flag){
        flag=0;
        for(i=N-1;i>=1;i--){
            if(s[i]<s[i-1]){
                tmp=s[i];
                s[i]=s[i-1];
                s[i-1]=tmp;
                count++;
                flag=1;
            }
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
    count=bubbleSort(s,N);
    
    printf("%d",s[0]);
    for(i=1;i<N;i++)printf(" %d",s[i]);
    printf("\n%d\n",count);
    
    return 0;
}
