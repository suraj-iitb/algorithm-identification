#include <bits/stdc++.h>

void show_list(std::vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        printf("%d", list.at(i));
        if (i != list.size() - 1) {
            printf(" ");
        }
    }
    printf("\n");
} 

int main(void) {
    using namespace std;

    int n;
    cin >> n;
    vector<int> a;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    show_list(a);

    for (int i = 1; i < n; i++) {
        int v = a.at(i);
        int j = i - 1;
        while (j >= 0 && a.at(j) > v) {
            a.at(j + 1) = a.at(j);
            j--; 
        }
        a.at(j + 1) = v;
        show_list(a);
    }
    return 0;
}
