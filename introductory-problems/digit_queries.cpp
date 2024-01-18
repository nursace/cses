#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int q;
  ll k;

  // total amount of i-digit number
  ll a[19];

  a[0] = 9;
  for (int i = 1; i < 19; i++) {
    a[i] = a[i - 1] * 10;
  }

  cin >> q;

  while (q--) {
    cin >> k;

    int dignum;
    for (int i = 1; i < 19; i++) {
      if (a[i] <= k) {
        dignum = i;
        break;
      }
    }
  }
}
