#include <cstdio>
#define MAX 100
int N;
int a[MAX];

void insert(int *a,int n){
    int v,j;
    for(int i=1;i<=N-1;i++){
       v=a[i];
       j=i-1;
       while(j>=0 && a[j]>v){
           a[j+1]=a[j];
           j--;
       } 
       a[j+1]=v;
       for(int k=0;k<N;k++){
           printf("%d",a[k]);
           if(k!=N-1){
            printf(" ");
           }else{
               printf("\n");
           }
       }
    }

}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        printf("%d",a[i]);
        if(i!=N-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    insert(a,N);
}
