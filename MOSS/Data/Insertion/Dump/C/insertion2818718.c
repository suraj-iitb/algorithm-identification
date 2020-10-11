#include <stdio.h>

void insertionSort(int s[],int N){
    int i,j;
    int v;
    for(i=1;i<N;i++){
        for(j=i-1;j>=0;j--){
            if(s[j]>s[j+1]){
                v=s[j];
                s[j]=s[j+1];
                s[j+1]=v;
            }else break;
        }
        
        for(j=0;j<N;j++){
            if(j==0)printf("%d",s[j]);
            else printf(" %d",s[j]);
        }
        printf("\n");
    }
    
}
int main(void){
    int i;
    
    int N;
    scanf("%d",&N);
    
    int s[N];
    for(i=0;i<N;i++)scanf("%d",&s[i]);
    printf("%d",s[0]);
    for(i=1;i<N;i++)printf(" %d",s[i]);
    printf("\n");
    
    insertionSort(s,N);
}
