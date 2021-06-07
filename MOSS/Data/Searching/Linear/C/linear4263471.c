// Linear Search
#include <stdio.h>

int s[10010], t[510];
int linearSearch(int key, int n){
    for(int i=0; i<n; i++){
        if(s[i]==key){return 1;}
    }
    return -1;
}
int main(void){
    int n, q, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){scanf("%d", &s[i]);}
    scanf("%d", &q);
    for(int i=0; i<q; i++){scanf("%d", &t[i]);}
    for(int i=0; i<q; i++){
        if(linearSearch(t[i], n)==1){cnt++;}
    }
    printf("%d\n", cnt);
    return 0;
}
