#include <iostream>
using namespace std;
int main(){
    int a,b[10000];
    cin >> a;
    for(int i = 0;i < a;i++)cin >> b[i];
    for(int i = 0;i < a;i++){
        int v,j;
        v = b[i];
        j = i - 1;
        while(j >= 0 && b[j] > v){
            b[j + 1] = b[j];
            b[j] = v;
            j--;
        }
    	for (int k = 0; k < a; k++) {
			if (k < a - 1)cout << b[k] << " ";
			else cout << b[k] << endl;
		}
    }
    return 0;
}
