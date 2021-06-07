#include <stdio.h>

void sort(int *a, int n) {
    int i, j, tmp;

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++) {
            if(a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(void){
    int i, j, n, q, head1, head2, prev, cnt;

    int s[10000];
    int t[500];

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &s[i]);
    }

    scanf("%d", &q);

    for(i=0; i<q; i++) {
        scanf("%d", &t[i]);
    }

    sort(s, n);
    sort(t, q);

    head1 = 0;
    head2 = 0;
    prev = -1;
    cnt = 0;

    for(i=head1; i<q; i++) {
        for(j=head2; j<n; j++){
            if(t[i] == s[j] && t[i] != prev) {
                cnt++;
                head1 = i+1;
                head2 = j+1;
                prev = t[i];
            }
        }
    }

    printf("%d\n", cnt);

    return 0;


}
