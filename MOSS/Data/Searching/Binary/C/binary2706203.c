#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int descending_compare(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}

int ascending_compare(const void *a, const void *b){
    if (*(int*)a < *(int*)b){
        return -1;
    }else if (*(int*)a == *(int*)b){
        return 0;
    }else{
        return 1;
    }
}


int lower_bound(int *a, int n, int key){
    int left, mid, right;
    left = 0, right = n;
    mid = (left + right)/2;
    while ((left+1 != mid || mid+1 != right) && mid != left){
        if (key > a[mid]){
            left = mid;
        }else{
            right = mid+1;
        }
        mid = (left + right)/2;
    }
    if (a[left] >= key)return left;
    if (a[mid] >= key)return mid;
    if (a[right] >= key)return right;
    return n;
}

//greatest common divisor
unsigned long gcd(unsigned long x, unsigned long y){
    if (y == 0){ 
        return x;
    }else if (x > y){
        return gcd(y, x % y);
    }else{
        return gcd(x, y % x);
    }
}

unsigned long lcm(unsigned long x, unsigned long y){
    unsigned long g = gcd(x, y);
    return x*y/g;

}



long long factorial(int x){
    long long rtn = 1;
    int i;
    for (i = x; i > 1; i--){
        rtn = (rtn*i);
    }
    return rtn;
}
int s[100005];
int t;
int n;
int q;

int my_bsearch(int key){
    int left, right, mid;
    left = 0;
    right = n;
    while (left < right){
        mid = (left+right)/2;
        if (s[mid] == key){
            return mid;
        }else if(s[mid] < key){
            left = mid + 1;
        }else if(s[mid] > key){
            right = mid;
        }
    }
    return -1;
}

int main(void){
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    qsort(s, n, sizeof(int), ascending_compare);
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        scanf("%d", &t);
        if (my_bsearch(t) != -1){
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
    
    

}
