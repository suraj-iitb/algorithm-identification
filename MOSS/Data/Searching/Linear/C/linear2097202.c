#include<stdio.h>

int search (long s[], long t[], int s_number, int t_number)
{
    int i, j;
    int answer = 0;

    for (i = 0; i < t_number; i++) {
      for (j = 0; j < s_number; j++) {
        if (t[i] == s[j]) {
          answer++;
          break;
        }
      }
    }
    return answer;
}

int main()
{

    unsigned long s[10000], t[500];
    int n, q, ncount, qcount;

    scanf("%d", &n);
    for (ncount = 0; ncount < n; ncount++)
      scanf("%d", &s[ncount]);

    scanf("%d", &q);
    for (qcount = 0; qcount < q; qcount++)
      scanf("%d", &t[qcount]);


    printf("%d\n", search(s, t, n, q));

    return 0;
}
