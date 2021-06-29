#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;
int a[200];
int main(){
    int n, count=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min]) {
                min = j;
            }
        }
        if(min!=i){
            count++;
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0) cout << " ";
        cout << a[i];
    }
    cout << "\n" << count << endl;
    return 0;
}
