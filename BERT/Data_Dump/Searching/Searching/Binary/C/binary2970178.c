#include <stdio.h>

int main () {
    int ns,nt;
    scanf("%d ",&ns);
    int s[ns];
    int pre;
    for (pre=0;pre<ns;pre++) {
        scanf (" %d",&s[pre]);
    }
    scanf("%d ",&nt);
    int t[nt];
    for (pre=0;pre<nt;pre++) {
        scanf (" %d",&t[pre]);
    }

    int result=0;
    for (pre=0;pre<nt;pre++) {
    int r=ns,l=0,m=0;
        while (l < r) {
            m =(r+l)/2;
            if (t[pre] == s[m]) {
                result++;
                break;
            }else if (s[m] < t[pre]) {
                l = m+1;
            }else if (s[m] > t[pre]) {
                r = m;
            }
        }
    }
    printf("%d\n",result);

    return 0;
}
