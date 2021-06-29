#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; ++i)
        cin>>arr[i];
    int swap_count = 0;
    // algorithm
    for(int i = 0; i < n; ++i){
        int mini = i;
        for(int j = i; j < n; ++j){
            if(arr[j]<arr[mini]){
               mini = j;
            }
        }
        if(mini != i){
            swap(arr[i], arr[mini]);
            swap_count++;
        }
    }

    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    cout << swap_count << endl;
    //fclose(inp);
    return 0;
}
