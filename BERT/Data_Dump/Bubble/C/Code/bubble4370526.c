#include<stdio.h>
#include<stdlib.h>
int Bubblesort(int *p, int N){
    int flag,j,tmp,count=0,i=1;
    flag=1;//逆の隣接要素が存在する
    while(flag==1){
        flag=0;
    for(j=N-1;j>=i;j--){
        if(*(p+j)<*(p+j-1)){
            tmp=*(p+j);
            *(p+j)=*(p+j-1);
            *(p+j-1)=tmp;
            count++;
            flag=1;
        }
    }
    i++;
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
    count=Bubblesort(p,N);
    for(i=0;i<N-1;i++){
        printf("%d ",*(p+i));
    }
    printf("%d\n",*(p+i));
    printf("%d\n",count);
    free(p);
    return 0;
}
