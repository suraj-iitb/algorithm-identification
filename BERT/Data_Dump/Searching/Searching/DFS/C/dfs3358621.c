#include<stdio.h>
#define N 100
#define White 0
#define Gray 1
#define Black 2

int n,A[N][N];
int color[N],b[N],c[N],d;

void Visit(int u){
    int e;
    color[u]=Gray;
    b[u]=++d;
    for(e=0;e<n;e++){
        if(A[u][e]==0)continue;
        if(color[e]==White){
            Visit(e);
        }
    }
    color[u]=Black;
    c[u]=++d;
}

void depth(){
    int u;
    for(u=0;u<n;u++)color[u]=White;
    d=0;

    for(u=0;u<n;u++){
        if(color[u]==White)Visit(u);
}
for(u=0;u<n;u++){
printf("%d %d %d\n",u+1,b[u],c[u]);

}
}


int main(){
int u,v,w,i,j;

scanf("%d",&n);
for(i=0;i<n;i++){
    for(j=0;j<w;j++)A[i][j]=0;
}

for(i=0;i<n;i++){
 scanf("%d %d",&u,&w);
 u--; 
 for(j=0;j<w;j++){
     scanf("%d",&v);
     v--;
     A[u][v]=1;
 }  
}
depth();

return 0;


}
