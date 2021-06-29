#include <iostream>
#include <algorithm>
using namespace std;
int a[100];

int main(){
    int n,minj,count = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < n;i++){
        minj = i;
        for(int j = i;j < n;j++){
            if(a[j] < a[minj])
                minj = j;
        }
        if(i != minj){
            swap(a[i],a[minj]);
            count++;
        }
    }

    for(int i = 0;i < n;i++){
        if(i == 0)
            cout << a[i];
        else
            cout << ' ' << a[i];
    }
    cout << '\n' << count << endl;

    return 0;
}
