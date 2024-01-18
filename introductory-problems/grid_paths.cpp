#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

#define ll long long

using namespace std;

int cnt = 0;
int paths = 0;

bool used[7][7];
string path;

int recs = 0;

void dfs(int r, int c) {

  recs++;

  if (r == 6 && c == 0) {
    if (cnt == 48) {
      paths++;
    }
    return;
  }

  if (used[r][c])
    return;

  bool can_turn_right_left =
      (c > 0 && !used[r][c - 1] && c < 6 && !used[r][c + 1]);
  bool on_top_down_edge =
      (r == 0 && used[r + 1][c] || r == 6 && used[r - 1][c]);

  bool can_turn_up_down =
      (r > 0 && !used[r - 1][c] && r < 6 && !used[r + 1][c]);
  bool on_left_right_edge =
      (c == 0 && used[r][c + 1] || c == 6 && used[r][c - 1]);

  bool can_not_up_down = (r > 0 && used[r - 1][c] && r < 6 && used[r + 1][c]);
  bool can_not_right_left =
      (c > 0 && used[r][c - 1] && c < 6 && used[r][c + 1]);

  if (can_turn_right_left && on_top_down_edge ||
      can_turn_up_down && on_left_right_edge ||
      can_turn_right_left && can_not_up_down ||
      can_turn_up_down && can_not_right_left)
    return;

  used[r][c] = true;

  if (path[cnt] != '?') {
    switch (path[cnt]) {
    case 'D':
      if (r < 6 && !used[r + 1][c]) {
        cnt++;
        dfs(r + 1, c);
        cnt--;
      }
      break;

    case 'U':
      if (r > 0 && !used[r - 1][c]) {
        cnt++;
        dfs(r - 1, c);
        cnt--;
      }
      break;
    case 'R':
      if (c < 6 && !used[r][c + 1]) {
        cnt++;
        dfs(r, c + 1);
        cnt--;
      }
      break;

    case 'L':
      if (c > 0 && !used[r][c - 1]) {
        cnt++;
        dfs(r, c - 1);
        cnt--;
      }
      break;
    }

  } else {
    if (r < 6 && !used[r + 1][c]) {
      cnt++;
      dfs(r + 1, c);
      cnt--;
    }

    if (r > 0 && !used[r - 1][c]) {
      cnt++;
      dfs(r - 1, c);
      cnt--;
    }

    if (c < 6 && !used[r][c + 1]) {
      cnt++;
      dfs(r, c + 1);
      cnt--;
    }

    if (c > 0 && !used[r][c - 1]) {
      cnt++;
      dfs(r, c - 1);
      cnt--;
    }
  }

  used[r][c] = false;
}

int main() {

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  cin >> path;

  dfs(0, 0);

  cout << paths << endl;

  // cout << "Recursive calls: " << recs << endl;
}
