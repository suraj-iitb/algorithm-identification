#include <iostream>

using namespace std;

int main(){
    int n;
    int min, index;
    int count=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int j1=0;j1<n;j1++){
        min = a[j1];
        index = j1;
        for(int j2=j1+1;j2<n;j2++){
            if(min>a[j2]){
                min = a[j2];
                index = j2;
            }
        }
        if(j1!=index){
          swap(a[j1], a[index]);
          count += 1;
        }
    }
    for(int t=0;t<n;t++){
        if(t==n-1){
            cout << a[t];
            break;
        }
        cout << a[t] << " ";
    }
    cout << endl << count << endl;
}
