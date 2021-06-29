#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e3+10;

int n;
int a[N];

int bubble_sort(int a[],int l,int r){
    bool flag=1;
    int res=0;
    for(int i=0;flag;i++){
        flag=0;
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]) {
                swap(a[j], a[j - 1]);
                flag = 1;
                res++;
            }
        }
    }
    return res;
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    int t = bubble_sort(a,0,n);

    for(int i=0;i<n;i++){
        if(i!=n-1)printf("%d ",a[i]);
        else printf("%d\n",a[i]);
    }
    printf("%d\n",t);

    return 0;
}
