#include <stdio.h>
int main(void){
int i,i_2,j,v,N;
int a[100]={};
scanf("%d",&N);
for(i=0;i<N;i++){
    scanf("%d",&a[i]);
}
for(i=1;i<N;i++){
    for(i_2=0;i_2<N;i_2++){
        printf("%d%s",a[i_2],i_2<N-1?" ":"\n");
    }
v=a[i];
    for(j=i-1;j>=0&&a[j]>v;j--){
        a[j+1]=a[j];
    }
    a[j+1]=v;
}
    for(i_2=0;i_2<N;i_2++){
        printf("%d%s",a[i_2],i_2<N-1?" ":"\n");
    }
    return 0;
}
