#include<stdio.h>

int search(int a[], int n, int key){
        int i=0;
        while(1){
                if(a[i]==key){
                        break;
                }
                i++;
        }
        return i==n?-1:i;
}

int main(){
        int i, n, q, count=0;
        scanf("%d", &n);
        int s[n+1];
        for(i=0;i<n; i++){
                scanf("%d", &s[i]);
        }
        scanf("%d", &q);
        for(i=0; i<q; i++){
                scanf("%d", &s[n]);
                if(search(s, n, s[n])!=-1)
                        count++;
        }
        printf("%d\n", count);
        return 0;
}

