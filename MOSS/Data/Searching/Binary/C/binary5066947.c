#include <stdio.h>
#define N 100000
#define Q 50000

int n;

int binarysearch(int *,int);

int main(){
    int q;
    int s[N],t[Q];
    int i,cnt=0;

    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&s[i]);
    }

    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&t[i]);
    }

    for(i=0;i<q;i++){
        if( binarysearch(s,t[i]) ) {
            cnt++;
        }
    }

    printf("%d\n",cnt);

    return 0;
}

int binarysearch(int *s,int key){
    int left = 0;
    int right = n;
    int mid;

    while(left < right){
        mid = ( left + right )/2;

        if(s[mid] == key){
            return 1;
        }
        else if(s[mid] < key){
            left = 1 + mid;
        }
        else {
            right = mid;
        }
    }
    return 0;
}
