#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
typedef long long int ll;
using namespace std;
const int INF = 5*1e9;
const int MAX = 1e2+10;
int a[MAX];

int main(){
    //freopen("/Users/mac/Desktop/C++?¨????/test/test.txt", "r", stdin);
    int n;
    int sum=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        int mini=i;
        for (int j=i; j<n; j++) {
            if (a[j]<a[mini]) {
                mini=j;
            }
        }
        int t;
        t=a[i];
        a[i]=a[mini];
        a[mini]=t;
        if (i!=mini) {
            sum++;
        }
    }
    for (int i=0; i<n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d",a[i]);
    }
    printf("\n%d\n",sum);
    return 0;
}
