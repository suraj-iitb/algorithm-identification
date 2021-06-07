#include<stdio.h>
#define N 100000
#define Q 50000
int cnt = 0, a[N];
int max,min,mid;
void bi(int key){
    
    while(min <= max){
            mid = (min + max) / 2;
            if(a[mid] == key) {
                cnt++; 
                break;
            }else if(a[mid] < key) min = mid + 1;
            else if(a[mid] > key) max = mid - 1; 
    }

}
int main(){
    
    int n,q,i,j,k,u = 0,flg = 0;
    int b[Q],c[Q];
    
    scanf("%d",&n);
    for( i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&q);
    for( i = 0; i < q; i++){
        scanf("%d",&b[i]);
    }
    for( i = 0; i < q; i++){
        max = n - 1;
        min = 0;
        bi(b[i]);      
    }
    printf("%d\n",cnt);
    
    return 0;
}
