#include<stdio.h>

#define MAX_N 10000
#define MAX_Q 500

int main(){

    int i, j, key, sum, s_n, t_n, s[MAX_N], t[MAX_Q];

    scanf("%d",&s_n);
    for(i=0; i<s_n;i++){
        scanf("%d", &s[i]);
    }

    scanf("%d",&t_n);
    for(i=0; i<t_n;i++){
        scanf("%d", &t[i]);
    }

    sum = 0;
    for(i=0;i<t_n;i++){
        key = t[i];
        for(j=0;j<s_n;j++){
            if(s[j] == key){
                sum++;
                break;
            }
        }
    }

    printf("%d\n", sum);
   
    return 0;
}
