#include<stdio.h>
#include<stdlib.h>
int Selectionsort(int *p,int N){
    int i,min,j,tmp,count=0;
    for(i=0;i<=N-1;i++){
    min=i;
    for(j=i;j<=N-1;j++){
        if(*(p+j)<*(p+min)){
            min=j;
        }
    }
            if(min!=i){
            tmp=*(p+i);
            *(p+i)=*(p+min);
            *(p+min)=tmp;
            count++;
            }
    
    }
    return count;

}
int main(void){
int N,*p,n,i=0,count;
    scanf("%d",&N);
    p=malloc(sizeof(int)*N);
    while(scanf("%d",(p+i))==1){
        i++;
        if(i==N) break;
    }
    count=Selectionsort(p,N);
    for(i=0;i<N-1;i++){
        printf("%d ",*(p+i));
    }
    printf("%d\n",*(p+i));
    printf("%d\n",count);
    free(p);
    return 0;
}
