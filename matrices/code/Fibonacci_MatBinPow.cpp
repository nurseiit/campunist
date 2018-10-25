#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()

typedef long long ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

const ll MOD = (int)1e9 + 7;

vvi Base(int n){
  vvi res (n, vi(n));
  for (int i = 0; i < n; i++)
    res[i][i] = 1;
  return res;
}

vvi Mul(vvi a, vvi b){
  int n = sz(a);
  int m = sz(a[0]);
  int k = sz(b[0]);
  vvi res(n, vi (k));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++)
      for(int p = 0; p < m; p++) {
        res[i][j] += a[i][p] * b[p][j] % MOD;
        res[i][j] %= MOD;
      }
  return res;
}

vvi BinPow(vvi a, int n){
  vvi res = Base(sz(a));
  while(n){
    if(n & 1)
      res = Mul(res, a);
    a = Mul(a, a);
    n >>= 1;
  }
  return res;
}

int main () {
  int n;
  cin >> n;
  vvi dp (2, vi(2, 1));
  dp[0][0] = 0;
  dp = BinPow(dp, n);
  cout << dp[1][1] << "\n";
  return 0;
}
