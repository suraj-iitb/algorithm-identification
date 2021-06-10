#include<cstdio>
#define INF (2100000000)
#define NMAX 100
int path[NMAX][NMAX];
int n;

bool floyd(){
    for(char k=0;k<n;k++){
        for(char i=0;i<n;i++){
            if(path[i][k]==INF)
                continue;
            for(char j=0;j<n;j++){
                if(path[k][j]==INF)
                    continue;
                int temp = path[i][k]+path[k][j];
                path[i][j] = (path[i][j] < temp)? path[i][j]:temp;
                if(i==j&&temp<0)
                    return false;
            }
        }
    }
}

int main(){
    int i, j;
    int weight;
    short edge;
    scanf("%d%d", &n, &edge);
    for(i=0;i<n;i++)//initial
        for(j=0;j<n;j++)
            path[i][j] = (i==j) ? 0 : INF;
    while(edge--){
        scanf("%d%d%d", &i, &j, &weight);
        path[i][j] = weight;
    }
    if(floyd()){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j) printf(" ");
                if(path[i][j]==INF) printf("INF");
                else printf("%d", path[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("NEGATIVE CYCLE\n");
    }
    return 0;
}

