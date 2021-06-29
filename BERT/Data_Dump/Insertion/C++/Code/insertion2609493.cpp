#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; ++i)
        cin>>arr[i];

    //algorithm
    for(int i = 0; i < n; ++i){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = key;
        }

        // each step sort print
        for(int x = 0; x < n; ++x){
            if(x) cout << " ";
            cout << arr[x];
        }
        cout << endl;
    }
    //fclose(inp);
    return 0;
}
