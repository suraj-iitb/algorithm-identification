#include <iostream>
using namespace std;

int bubblesort(int a[], int n) {
        int sw = 0;
        int flag =  1;          //????????£??\????´?????????¨??????
        while(flag) {
                flag = 0;
                for(int j = n - 1; j > 0; j--) {
                        if(a[j] < a[j - 1]) {
                                swap(a[j], a[j - 1]);
                                flag = 1;
                                sw++;
                        }
                }
        }
        return sw;
}

int main() {
        int N;
        cin >> N;
        int input[N];
        for(int i = 0; i < N; i++) {
                cin >> input[i];
        }

        int sw = bubblesort(input, N);
        for(int i = 0; i < N; i++) {
                if(i) cout << " ";
                cout << input[i];
        }
        cout << endl;
        cout << sw << endl;

        return 0;
}
