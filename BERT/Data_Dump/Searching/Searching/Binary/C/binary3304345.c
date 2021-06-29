#include <stdio.h>

int s[100000];
int t[50000];
int n = 0;
int search(int);

int main(){
    int i, q, count = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &s[i]);
    scanf("%d", &q);
    for(i=0;i<q;i++)
        scanf("%d", &t[i]);
    for(i=0;i<q;i++)
        if(search(t[i]))
            count++;
    printf("%d\n", count);
    return 0;
}

int search(int key){
    int l=0;
    int r=n;
    int m;
    while(l<r){
        m = (l+r)/2;
        if(s[m]==key)
            return 1;
        else if(key > s[m])
            l = m+1;
        else
            r=m;
    }
    return 0;
}

