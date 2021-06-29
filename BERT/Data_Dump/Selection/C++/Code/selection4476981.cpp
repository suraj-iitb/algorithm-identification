#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    
    int minj;
    int cnt=0;
    for(int i=0; i<n; i++){
        minj = i;
        for(int j=i+1; j<n; j++){
            if(v[minj] > v[j]){
                minj = j;   
            }
        }
        if(i!=minj){
            int tmp = v[i];
            v[i] = v[minj];
            v[minj] = tmp;
            cnt++;
        }
    }
    /*
    for(int i=0; i<n; i++){
        if(i!=n-1)
            printf("%d ",v[i]);
        else
            printf("%d\n",v[i]);
    }
    printf("%d\n",cnt);
    */
    for(int i=0; i<n; i++)
        cout << v[i] << ( (i!=n-1) ? " " : "\n");
    cout << cnt << endl;
    return 0;
}
