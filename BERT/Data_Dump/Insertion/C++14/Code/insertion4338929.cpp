#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    std::vector<int> a;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    // 初期状態
    for(int ii=0; ii<n; ii++){
        if(ii != 0){
            printf(" ");
        }
        printf("%d", a[ii]);
    }
    printf("\n");

    for(int i=1; i<n; i++){
        int v = a[i];
        int j = 0;
        while(j<n && a[j]<v){
            j++;
        }
        a.erase(a.begin()+i);
        a.insert(a.begin()+j, v);
    
        // 途中経過
        for(int ii=0; ii<n; ii++){
            if(ii != 0){
                printf(" ");
            }
            printf("%d", a[ii]);
        }
        printf("\n");
    }
}
