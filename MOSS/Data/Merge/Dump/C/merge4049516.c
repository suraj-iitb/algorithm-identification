#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

typedef int32_t i32;
typedef int64_t i64;
typedef double f64;

void *const null=(void *)0;
i64 const llinf=4611686018427387903LL;
i64 const mod=1000000009LL;
f64 const pi=3.141592653589793;
f64 const rad=57.295779513082323;

#define CODE_

#ifndef CODE_
#include "f:/kyopro/code.c"
#define CODE_
#endif

i64 c;

typedef i64 data_merge_sort;

static inline i32 merge_sort_cmp(data_merge_sort *const x,data_merge_sort *const y){
    if(*x<=*y) return 1;
    return 0;
}

static void merge_sort_rec(data_merge_sort *const a,i64 const n,data_merge_sort *const d){
    if(n<2LL) return;
    c+=n;
    i64 const m=n/2LL;
    merge_sort_rec(a,m,d);
    merge_sort_rec(&a[m],n-m,&d[m]);
    i64 l=0LL,r=m,k=0LL;
    if(merge_sort_cmp(&a[m-1LL],&a[n-1LL])){
        while(l<m){
            if(merge_sort_cmp(&a[l],&a[r])) d[k++]=a[l++];
            else d[k++]=a[r++];
        }
        while(r<n) d[k++]=a[r++];
    }
    else{
        while(r<n){
            if(merge_sort_cmp(&a[l],&a[r])) d[k++]=a[l++];
            else d[k++]=a[r++];
        }
        while(l<m) d[k++]=a[l++];
    }
    for(i64 i=0LL;i<n;++i) a[i]=d[i];
    return;
}

static inline void merge_sort(data_merge_sort *const a,i64 const n){
    data_merge_sort *d=(data_merge_sort *)calloc(n,sizeof(data_merge_sort));
    merge_sort_rec(a,n,d);
    free((void *)d);
}

i32 cmp(const void *x,const void *y){
    if(*(i64 *)x<*(i64 *)y) return 1;
    if(*(i64 *)x>*(i64 *)y) return -1;
    else return 0;
}

i32 main(void){
    i64 n;
    scanf("%lli",&n);
    i64 *a=(i64 *)calloc(n,sizeof(i64));
    for(i64 i=0LL;i<n;++i) scanf("%lli",&a[i]);
    merge_sort(a,n);
    --n;
    for(i64 i=0LL;i<n;++i) printf("%lli ",a[i]);
    printf("%lli\n",a[n]);
    printf("%lli\n",c);
    // qsort(a,n,sizeof(i64),cmp);
    return 0;
}

