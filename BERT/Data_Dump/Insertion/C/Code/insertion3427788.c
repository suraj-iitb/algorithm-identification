#include<stdio.h>
#define N 100

void print(int *,int);
int main(){
    int i,j,v[N],n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&v[i]);
    }
    print(v,n);
    for(i=1;i<n;i++){
        m = v[i];
        j=i-1;
        while(j>=0&&v[j]>m){
            v[j+1] = v[j];
            j--;
            
        }
        v[j+1]=m;
        print(v,n);
        
    }
 return 0;   
}


void print(int v[],int n){
    
int i;
for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",v[i]);
    else printf("%d",v[i]);
}
printf("\n");
}

