#include <stdio.h>

int S[100001];
int n, q;

int search(int key){
    int right = n;
    int left = 0;
    int mid;

    while(left + 1 < right){
        mid = (right + left) / 2;
        if(key < S[mid]) right = mid;
        else left = mid;

    }

    if(key == S[left]) return 1;
    else return 0;

}

int main() {
    int i;
    int t;
    int cnt = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &t);
        if(search(t)) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
