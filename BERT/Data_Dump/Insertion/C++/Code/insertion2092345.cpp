#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    using namespace std;
    
    vector <int> Num;
    int Card, v, j;
    
    cin >> Card;
    int dummy;
    for(int i = 0;i < Card;i++){
        cin >> dummy;
        Num.push_back(dummy);
    }
    
    for(int i = 1;i <= Card - 1;i++){
        for(int h = 0;h < Card - 1;h++){
            cout << Num[h] << ' ';
        }
        cout << Num[Card - 1] << endl;
        v = Num[i];
        j = i - 1;
        while(j >= 0 && Num[j] > v){
            Num[j + 1] = Num[j];
            j--;
        }
        Num[j + 1] = v;
    }
    for(int h = 0;h < Card - 1;h++){
        cout << Num[h] << ' ';
    }
    cout << Num[Card - 1] << endl;
    
    return 0;
}
