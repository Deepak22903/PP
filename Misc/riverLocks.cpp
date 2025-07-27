
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<ll> v(n + 1), pref(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    pref[i] = pref[i - 1] + v[i];
  }

  // Compute minimal time needed even with all n pipes
  ll minTimeNeeded = 0;
  for (int i = 1; i <= n; i++) {
    ll need = (pref[i] + i - 1) / i;
    minTimeNeeded = max(minTimeNeeded, need);
  }

  int q;
  cin >> q;
  while (q--) {
    ll t;
    cin >> t;
    if (minTimeNeeded > t) {
      cout << -1 << "\n";
    } else {
      // binary search smallest k so that k * t >= total volume
      ll total = pref[n];
      int lo = 1, hi = n, ans = n;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ((ll)mid * t >= total) {
          ans = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
