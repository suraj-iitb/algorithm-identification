#include<stdio.h>
# include<stdlib.h> 

int str[100][100];
int x;
int d[100], f[100], tt;
int pr[100];

void dvis(int);
void search(void);


int main(){
    
    int i, j;
    int u, v, k;
    
    scanf("%d", &x);
    if(x < 1 || x > 100){
        exit(1);
    }
    
    i = 0;
    while(i < x){
        j = 0;
        while(j< x){
            str[i][j] = 0;
        j++;
        }
        i++;
    }
 
    for (i= 0; i < x; i++){
        scanf("%d %d", &u, &k);
        u = u-1;
        for (j= 0; j < k; j++){
            scanf("%d", &v);
            v = v-1;
            str[u][v] = 1;
        }
    }

    search();
    
    return 0;
}


void search(){
    int u;

    for (u = 0; u < x; u++){
        pr[u] = 0;
    }
    tt = 0;

    for(u= 0; u < x; u++){
        if(pr[u] == 0){
            dvis(u);
        }
    }
    for(u = 0; u < x; u++){
        printf("%d %d %d\n", u+1, d[u], f[u]);
    }
}


void dvis(int u){
    int v;
    pr[u] = 1;
    d[u]= ++tt;
    for (v= 0; v < x; v++){
        if (str[u][v] == 0){
            continue;
        }
        if (pr[v] == 0){
            dvis(v);
        }
    }
    pr[u] = 2;
    f[u]= ++tt;
}
