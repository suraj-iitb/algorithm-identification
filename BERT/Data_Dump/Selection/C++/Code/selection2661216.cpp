#include <iostream>
#include <vector>

using namespace std;

typedef struct result {
    int exchange;
    vector<int> a;
} result;

result selection_sort(vector<int> v) {
    int tmp, min_i;
    result res;
    
    res.exchange = 0;
    
    for(int i = 0;i < v.size();i++) {
        min_i = i;
        
        for(int j = i;j < v.size();j++) {
            if(v[j] < v[min_i]) {
                min_i = j;
            }
        }
        
        if(i != min_i) {
            res.exchange++;
            
            tmp = v[i];
            v[i] = v[min_i];
            v[min_i] = tmp;
        }
    }
    
    res.a = v;
    
    return res;
}

void print_attr(result res) {
    for(int i = 0;i < res.a.size();i++) {
        cout << res.a[i];
        
        if(i < res.a.size() - 1) {
            cout << " ";
        }
    }
    
    
    cout << endl << res.exchange << endl;
}

int main() {
    int n;
    vector<int> v;
    result res;
    
    cin >> n;
    
    v.resize(n);
    
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }
    
    res = selection_sort(v);
    
    print_attr(res);
    
    return 0;
}
