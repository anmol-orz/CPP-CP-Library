#include <bits/stdc++.h>

//====================================================================
const int maxn = 1e5 + 3;
int a[maxn + 1];
int tree[4 * maxn];

void build(int node, int tl, int tr) {
  if (tl == tr) {
    tree[node] = a[tl];
  } else {
    int mid = (tl + tr) / 2;
    build(2 * node, tl, mid);
    build(2 * node + 1, mid + 1, tr);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}

int query(int node, int tl, int tr, int l, int r) {
  if (l > r)
    return INT_MAX;
  if (l == tl and r == tr)
    return tree[node];
  int tm = (tl + tr) / 2;
  return min(query(2 * node, tl, tm, l, min(r, tm)),
             query(2 * node + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int node, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    tree[node] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * node, tl, tm, pos, new_val);
    else
      update(2 * node + 1, tm + 1, tr, pos, new_val);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  F(i, 1, n) cin >> a[i];
  build(1, 1, n);
  F(i, 1, 2 * n - 1) cout << tree[i] << ' ';
  cout << endl;
  F(i, 1, q) {
    int a, b;
    char type;
    cin >> type >> a >> b;
    if (type == 'q') {
      cout << query(1, 1, n, a, b) << endl;
    } else {
      cout << "update\n";
      update(1, 1, n, a, b);
    }
  }
}

//====================================================================

int main() {
  solve();
}

