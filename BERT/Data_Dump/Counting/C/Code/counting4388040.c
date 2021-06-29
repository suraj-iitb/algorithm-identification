#include<stdio.h>
#include<stdlib.h>//counting sort
void Countingsort(int *a, int *b,int *c,int n, int max){
    int i;
    for(i=0;i<n;i++){
        *(c+*(a+i))+=1;
    }
    for(i=1;i<=max;i++){
        *(c+i)=*(c+i)+*(c+i-1);
    }
    for(i=n-1;i>=0;i--){
        *(b+*(c+*(a+i)))=*(a+i);
        *(c+*(a+i))-=1;
    }
}
int main(void){
    int m,n,i,*a,*b,*c,max=0;
    scanf("%d",&n);
    m=n;
    a=malloc(sizeof(int)*n);
    b=malloc(sizeof(int)*2000000);
    for(i=0;i<n;i++){
        scanf("%d",(a+i));
        if(max<*(a+i)) max=*(a+i);
    }
    c=malloc(sizeof(int)*(max+1));
    Countingsort(a,b,c,n,max);
    for(i=1;i<n;i++){
        printf("%d ",*(b+i));
    }
    printf("%d\n",*(b+i));
    free(a);
    free(b);
    free(c);
    return 0;
}
