#include <stdio.h>

int u[101] = {0};
int d[101] = {0};
int f[101] = {0};
int next[101][101] = {0};

int cost = 1;

int top = 0;
int s[101];
 
void push(int x) {
  top++;
  s[top] = x;
}
 
int pop() {
  top--;
  return s[top + 1];
}

int next_look(int r) {
  int i = 0;
  int rr;
  for (i = 0; i < 101; i++) {
    if ((next[r][i] != 0) && (d[next[r][i]] == 0)) {
      return next[r][i];
    }
  }
  pop();
  f[r] = cost++;
  return 0;
}

void depth_first_search(int v) {
  int rr = v;
  int ll;
  push(rr);
  d[rr] = cost++;
    while (top >= 1) {
      ll = next_look(rr);
      if (ll == 0) {
	rr = s[top];
      }
      else {
	d[ll] = cost++;
	push(ll);
	rr = ll;
      }
    }
}

int main(void) {
  int n;
  int k;
  //int rr;
  //int ll;
  
  scanf("%d", &n);
  
  for (int i = 1; i <= n; i++) {
    scanf("%d", &u[i]);
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &next[u[i]][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (f[i] == 0)
      depth_first_search(i);
  }

  for (int i = 1;i <= n; i++) { 
    printf("%d %d %d\n", u[i], d[i], f[i]);
  }

  return 0;
}
