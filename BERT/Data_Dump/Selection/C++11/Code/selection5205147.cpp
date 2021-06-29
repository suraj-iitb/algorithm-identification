#include <cstdio>
#include <algorithm>
using namespace std;

const int N=1e3+10;

int n;
int a[N];

int selection_sort(int a[],int l,int r){
    int res=0;

    for (int i=0;i<n;i++){
        int k=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[k])k=j;
        }
        swap(a[i],a[k]);
        if(i!=k)res++;
    }

    return res;
}

int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    int t=selection_sort(a,0,n);

    for(int i=0;i<n;i++){
        if(i!=n-1)printf("%d ",a[i]);
        else printf("%d\n",a[i]);
    }
    printf("%d\n",t);

    return 0;
}
