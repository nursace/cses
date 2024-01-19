#include <algorithm>
#include <cmath>
#include <iostream>

#define ll long long

using namespace std;

// total amount of i-digit number
ll a[19];

ll get_st_idx(ll n, int dignum) {

  ll nstdx = 0;
  for (int i = 1; i < dignum; i++) {
    nstdx += a[i] * i;
  }
// starting index of {digit}-number
  nstdx += 1;

  // minimal value of {digit}-number
  ll mn = pow(10L, dignum - 1);
  nstdx += (n - mn) * dignum;

  return nstdx;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ll q;
  ll k;

  a[1] = 9;
  for (int i = 2; i < 19; i++) {
    a[i] = a[i - 1] * 10;
  }

  cin >> q;

  while (q--) {
    cin >> k;

    long long index = 0;
    int dignum;
    for (int i = 1; i < 19; i++) {
      // index range of i-th digit number
      index += a[i] * i;

      if (k <= index) {
        dignum = i;
        break;
      }
    }

    // min and max of n-dignum number
    ll lo = pow(10LL, dignum - 1);
    ll hi = pow(10LL, dignum) - 1;

    // a number where k points
    ll ans = 0, anstdx = 0;

    while (lo <= hi) {
      // not index, but real number
      // we are searching for number knowing the amount of digits in that number
      ll mid = (lo + hi) / 2;

      // now we need to find starting index of this number
      // and compare with k
      ll stdx = get_st_idx(mid, dignum);
      // cout << "stdx: " << stdx << endl;

      if (stdx <= k) {
        if (mid > ans) {
          ans = mid;
          anstdx = stdx;
        }
        lo = mid + 1;
      } else if (stdx > k) {
        hi = mid - 1;
      }
    }
    // cout << "ans: " << ans << " ";

    cout << to_string(ans)[k - anstdx] << endl;
  }
}
