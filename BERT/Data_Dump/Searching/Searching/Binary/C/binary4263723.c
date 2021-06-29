// Binary Search
#include <stdio.h>
#include <stdlib.h>

int s[100010], t[50010];
int binarySearch(int key, int n){
    int left=0;
    int right=n;
    while(right-left>0){
        int mid=(right+left)/2;
        if(s[mid]==key){return 1;}
        else if(s[mid]>key){right=mid;}
        else{left=mid+1;}
    }
    return 0;
}

int main(void){
    int n, q, flag=0, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){scanf("%d", &s[i]);}
    scanf("%d", &q);
    for(int i=0; i<q; i++){scanf("%d", &t[i]);}
    for(int i=0; i<q; i++){
        flag=binarySearch(t[i], n);
        if(flag){cnt++;}
    }
    printf("%d\n", cnt);
    return 0;
}
