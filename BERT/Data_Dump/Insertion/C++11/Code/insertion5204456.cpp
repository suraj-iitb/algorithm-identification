#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e3+10;

int n;
int a[N];

void trace(int a[], int n){
    for(int i=0;i<n;i++){
        if(i!=n-1)printf("%d ",a[i]);
        else if(i==n-1)printf("%d",a[i]);
    }
}

void insertion_sort(int a[], int l ,int r){
    for(int i=l;i<r;i++){
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        trace(a,n);
        puts("");
    }
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    insertion_sort(a,0,n);

    return 0;
}
