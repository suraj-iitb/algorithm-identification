#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int array[N];
    for(int i=0;i<N;i++)
        scanf("%d",&array[i]);
    
    int change=0;
    int flg=1;
    int cp;

    while(flg){
        flg=0;
        for(int i=0;i<N-1;i++){
            if(array[i]>array[i+1]){
                cp=array[i];
                array[i]=array[i+1];
                array[i+1]=cp;
                change++;
                flg=1;
            }
        }
    }

    for(int i=0;i<N;i++){
        if(i==0)
            printf("%d",array[i]);
        else
            printf(" %d",array[i]);
    }
    printf("\n");
    printf("%d\n",change);
}
