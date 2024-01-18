#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

#define ll long long

using namespace std;

int cnt = 0;

char m[8][8], used[8][8];
char used_row[8], d1[16], d2[16];

void solve(int cur_col) {
  if (cur_col == 8) {
    cnt++;
    return;
  }

  for (int row = 0; row < 8; row++) {
    if (m[row][cur_col] == '.' && !used_row[row] && !d1[row + cur_col] && !d2[row - cur_col + 7]
        && !used[row][cur_col]) {

      used[row][cur_col] = used_row[row] = d1[row + cur_col] = d2[row - cur_col + 7] = true;
      solve(cur_col + 1);
      used[row][cur_col] = used_row[row] = d1[row + cur_col] = d2[row - cur_col + 7] = false;
    }
  }
}

int main() {

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> m[i][j];
    }
  }

  solve(0);
  cout << cnt;
}
