#include <algorithm>
#include <iostream>

#define ll long long
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  ll row, col, mx, mxd;
  cin >> t;
  while (t--) {
    cin >> row >> col;
    mx = max(row, col);
    mxd = mx * mx - (mx - 1);

    if (row == col) {
      cout << mxd << endl;
    } else if (row > col) {
      if (row % 2 == 1) {
        cout << mxd - row + col << endl;
      } else {
        cout << mxd + (row - col) << endl;
      }
    } else {
      if (col % 2 == 1) {
        cout << mxd + (col - row) << endl;
      } else {
        cout << mxd - col + row << endl;
      }
    }
  }
}
