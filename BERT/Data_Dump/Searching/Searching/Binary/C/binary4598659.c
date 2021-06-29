/*
 * FileName:     binary_search_fix
 * CreatedDate:  2020-06-20 12:15:48 +0900
 * LastModified: 2020-06-20 20:35:13 +0900
 */

#include <stdio.h>
#include <stdlib.h>
int count=0;
int bi_search( int t, int *s, int left, int right){
    while(left+1<right){
        int mid = (left+right)/2;
        if(s[mid]<=t)left=mid;
        else right=mid;
    }
    return s[left]==t;
}

int main(void){
    int n;scanf("%d",&n);
    int *s = malloc(n*sizeof(int));
    for(int i=0;i<n;i++)scanf("%d",s+i);
    int q;scanf("%d",&q);

    for(int i=0;i<q;i++){
        int t;scanf("%d",&t);
        count+=bi_search(t,s,0,n);
    }
    printf("%d\n",count);
    free(s);
    return 0;
}

