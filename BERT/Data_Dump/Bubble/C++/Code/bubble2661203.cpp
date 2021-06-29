#include <iostream>
#include <vector>

using namespace std;

struct result {
    int exchange;
    vector<int> a;
};

struct result bubble_sort(vector<int> v) {
    int tmp, fin = 0;
    bool change = true;
    struct result res;
    
    res.exchange = 0;

    while(change) {
        change = false;
        
        for(int i = 0;i < v.size() - 1 - fin;i++) {
            if(v[i] > v[i + 1]) {
                res.exchange++;
                
                tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                
                change = true;
            }
        }
        
        fin++;
    }
    
    res.a = v;
    
    return res;
}

void print_attr(vector<int> v) {
    for(int i = 0;i < v.size();i++) {
        cout << v[i];
        
        if(i < v.size() - 1) 
            cout << " ";
    }
    
    cout << endl;
}

int main() {
    int n;
    vector<int> v;
    struct result res;
    
    cin >> n;
    
    v.resize(n);
    
    for(int i = 0;i < n;i++) {
        cin >> v[i];
    }
    
    res = bubble_sort(v);
    
    print_attr(res.a);
    cout << res.exchange << endl;
    
    return 0;
}
