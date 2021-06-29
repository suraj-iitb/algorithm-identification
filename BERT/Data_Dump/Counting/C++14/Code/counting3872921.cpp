#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define sortr(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 2000001
#define vmax 10000
constexpr int inf = 100000000;

int main(){
    unsigned short *a,*b;
    int c[vmax+1];
    int n;
    cin>>n;
    a=(unsigned short *)malloc(sizeof(short)*n+1);
    b=(unsigned short *)malloc(sizeof(short)*n+1);
    for(int i=0;i<=vmax;i++)c[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<=vmax;i++){
        c[i]=c[i]+c[i-1];
    }
    for(int i=1;i<=n;i++){
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }
    for(int i=1;i<=n;i++){
        if(i>1){
            cout<<" ";
        }
        cout<<b[i];
    }
    cout<<endl;
}










