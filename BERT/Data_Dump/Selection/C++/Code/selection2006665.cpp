#include <iostream>

using namespace std;
int i,j,minj,count,box;

void selert_sort(int n,int a[]){
    for(i = 0;i <= n - 1;i++){
        minj = i;
        for(j = i;j <= n - 1;j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        
        if(i != minj){
            box = a[i];
            a[i] = a[minj];
            a[minj] = box;
            count++;
        }
    }
}

int main() {
    int n,a[100];

    cin >> n;

    for(i = 0;i < n;i++){
        cin >> a[i];
    }

    selert_sort(n,a);

    for(i = 0;i < n - 1;i++){
        cout << a[i] << ' ';
    }
    cout << a[i] << endl << count << endl;

    return 0;
}
