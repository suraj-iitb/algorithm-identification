    #include <bits/stdc++.h>
    #define INF 1e9
    #define all(v) v.begin(), v.end()
    #define rep(i, n) for(int i = 0; i < n; i++)
    #define pb push_back
    #define eb emplace_back
    #define mp make_pair
    #define max(v) *max_element(v.begin(), v.end())
    #define min(v) *min_element(v.begin(), v.end())
    using namespace std;
     
    int main(void){
        cin.tie(0);
        ios::sync_with_stdio(false);

        int n;
        cin>>n;
        int a[n];
        rep(i, n){
            cin>>a[i];
        }
        int v, i, j, k;
        for(i = 0; i < n; i++){
            v = a[i];
            j = i-1;
            while(j >= 0 && a[j] > v){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = v;
            rep(k, n){
                if(k==n-1){
                    cout<<a[k];
                }
                else{
                    cout<<a[k]<<" ";
                }
            }
            cout<<endl;
        }


        return 0;
    }
