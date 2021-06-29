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
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<i; j++) {
            if (a[j]>a[j+1]) {
                int t;
                t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
                sum++;
            }
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
