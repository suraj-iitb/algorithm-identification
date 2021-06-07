#include <stdio.h>

int table[105][105];
int time_table[105][2];

int depth_search(int tm, int id, int col) {
	int i;
	int j;
	
	time_table[id][0] = tm;
	table[id][0] = 0;

	for(i=1;i<=col;i++) {
		if(table[id][i] == 1 && table[i][0] == 1) {
			for(j=0;j<=col;j++) table[j][i] = 0;
			tm = depth_search(tm+1, i, col);
		}
	}
	return time_table[id][1] = tm+1;
}

int main(void) {
    int i, j, n, q;
    int id, t;
    char buff[1024];
    int ret;
   
    scanf("%d\n", &n);
    for(i=0;i<=n;i++) {
    	table[i][0] = 1;
        for(j=1;j<=n;j++) {
            table[i][j] = 0;
        }
    }
   
    for(i=0;i<n;i++) {
        scanf("%d %d", &id, &q);
        for(j=0;j<q;j++) {
            scanf("%d", &t);
            table[id][t] = 1;
        }
        gets(buff);
    }
    ret = 0;
    for(i=1;i<=n;i++) {
    	if(table[i][0] == 1) {
			ret = depth_search(ret+1, i, n);
    	}
    }
	
	for(i=1;i<=n;i++) {
		printf("%d %d %d\n", i, time_table[i][0], time_table[i][1]);
	}

    return 0;
}
