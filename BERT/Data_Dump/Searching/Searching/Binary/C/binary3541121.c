#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bi_search(int a[], int start, int end, int q){
    if(end-start==1){
        if(a[start]==q) return start;
        else if(a[end]==q) return end;
        else return -1;
    }
    int mid = (start+end)/2;
    if(a[mid]==q) 
        return mid;
    else if(a[mid]>q) 
        return bi_search(a, start, mid, q);
    else 
        return bi_search(a, mid, end, q); 
}

int main(){
    int a[100005];
    int q[50005];
    int data_num;
    scanf("%d", &data_num);
    for(int i=0; i<data_num; i++){
        scanf("%d", &a[i]);
    }
    int query_num;
    scanf("%d", &query_num);
    for(int i=0; i<query_num; i++){
        scanf("%d", &q[i]);
    }
    
    /*int q;
    scanf("%d", &q);
    printf("%d\n",bi_search(a,0,data_num-1,q));*/
    
    int find = 0;
    for(int i=0; i<query_num; i++){
        if(bi_search(a, 0, data_num-1, q[i])!=-1)
            find++;
    }
    printf("%d\n", find);
}

