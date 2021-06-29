#include <iostream>
using namespace std;

void show_array(int n, int num[]) {
    for (int i=0; i<n-1; i++) {
        cout << num[i] << " ";
    }
    cout << num[n-1] << endl;
}

void inset_sor(int n, int num[]) {
    int key;
    show_array(n, num);
    for (int i=1; i<n; i++) {
        key = num[i];
        int j = i-1;
        
        while (j >= 0 && num[j] > key) {
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = key;
        show_array(n, num);
    }
}

int main() {
    int n;
    cin >> n;
    
    int  num[100];
    
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    
    inset_sor(n, num);
    
	return 0;
}
