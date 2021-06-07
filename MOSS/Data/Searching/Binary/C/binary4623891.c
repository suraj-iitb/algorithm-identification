#include<stdio.h>
long long int n, q, s[100001], i, count, key;

int binary_search(long long int i, long long int j){
    long long int x = i + (j-i)/2;
    if(s[x] == key){count++;return 1;}
    else if(i == j || i>j) return 0;
    else if(key > s[x]){
        return binary_search(x+1, j);
    }else if(key<s[x]){
        return binary_search(i, x-1);
    }
}
int main(){
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld", &s[i]);
    }
    scanf("%lld", &q);
    count = 0;
    for(i=0;i<q;i++){
        scanf("%lld", &key);
        binary_search(0, n-1);
    }
    printf("%lld\n", count);
    return 0;
}

