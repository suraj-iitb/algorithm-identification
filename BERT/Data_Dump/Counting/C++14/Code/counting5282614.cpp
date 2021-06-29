/*HELLO, WORLD*/
#include <bits/stdc++.h>
#define     ll          long long
#define     ull          unsigned long long
#define     pb          push_back
#define     tc()        ll test_case; cin>>test_case; while(test_case--)
#define     ed          '\n'
#define     UTSHO      ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define     OJ \
freopen("in.txt", "r", stdin); \
freopen("out.txt", "w", stdout);
using namespace std;

int main() {
    UTSHO;
    // OJ;
    int n; cin>>n;
    int arr[n+2];
    int maX=-1;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>maX) maX = arr[i];
    }
    int srt[maX+2]={};
    for(int i=0; i<n; i++){
        srt[arr[i]]++;
    }
    for(int i=0; i<=maX; i++){
        if(srt[i]>0){
            cout<<i;
            srt[i]--;
            while(srt[i]--!=0)cout<< " "<<i;
            if(i!=maX) cout<<" ";
        }
    }
    cout<<ed;
    return 0;
}

