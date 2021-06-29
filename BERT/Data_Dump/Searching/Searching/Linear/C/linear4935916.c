#include<stdio.h>

//番兵=プログラミング用語としては、データの終了を示すために配置される特殊なデータを指す
int linearSearch(int S[],int n,int key)
{
    int i=0;
    while(S[i]!=key){
        i++;
        if(i==n)
        {
            break;
        }
    }
    return i;

}


int main(void)
{
    int n;
    scanf("%d",&n);
    int S[n];
    for(int i=0; i<n; i++){
        scanf("%d",&S[i]);
    }
    int q;
    scanf("%d",&q);
    int T[q];
    int count=0;
    for(int i=0; i<q; i++){
        scanf("%d",&T[i]);
        if(linearSearch(S,n,T[i])<n){
            count++;
        }
    }
    printf("%d\n",count);
    
}

