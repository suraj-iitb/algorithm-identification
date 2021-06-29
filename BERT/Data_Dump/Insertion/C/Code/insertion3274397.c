#include<stdio.h>
#define N 100
int main(){
    int A[N];
    int i,j,n,m,w,v,a;
    scanf("%d",&w);
    for(n=0;n<w;n++){
        if(scanf("%d",&a)==EOF){
            break;
        }
        A[n]=a;
    }
    for(i=1;i<w;i++){
        v=A[i];
        j=i-1;
	for(m=0;m<w-1;m++){
            printf("%d ",A[m]);
        }
	printf("%d\n",A[m]);
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }
    for(m=0;m<w-1;m++){
            printf("%d ",A[m]);
        }
    printf("%d\n",A[m]);
    return 0;
}
