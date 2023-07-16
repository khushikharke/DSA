
/*
 * zyrch - Rupanshu Yadav
 */
#ifdef CREED 
#include "creed.h"
#else
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <sstream>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#endif
 
 
using namespace std;
 

// 297586BQ
//=========================CODE STARTS HERE=============================//

const int nax = 2e5 + 15;
vector<pair<int, int>> adjL[nax];
long long cost[27][nax], visited[27][nax];

long long vis[nax], par[nax], dp[nax][18], n, dfsin[nax], dfsout[nax], tim = 0, depth[nax];
 
void dfs(int u) {
	dfsin[u] = ++tim;
	vis[u] = 1;
	for (auto p: adjL[u]) {
		auto v = p.first;
		if (!vis[v]) {
				par[v] = u;
				depth[v] = depth[u] + 1;
				dfs(v);
		}
	}
	dfsout[u] = ++tim;
}
 
void pre() {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
			dp[i][0] = par[i];
    }

    for (int k = 1; k < 18; ++k) {
			for (int i = 0; i < n; ++i) {
				if (dp[i][k - 1] != -1) 
					dp[i][k] = dp[dp[i][k - 1]][k - 1];
			}
		}
}
 
bool isancestor(int a, int b) {
    return dfsin[a] <= dfsin[b] && dfsout[b] <= dfsout[a];
}
 
long long query(int a, int b) {
    long long an = a;
    if (isancestor(a, b)) {
			return a;
    }
    for (int i = 17; ~i; --i) {
			if (dp[an][i] == -1) continue;
			if (!isancestor(dp[an][i], b)) {
				an = dp[an][i];
			}
    }
    if (dp[an][0] == -1) return an;
    return dp[an][0];
}

void dfs2(int u, int target) {
  visited[target][u] = 1;
  for (auto p : adjL[u]) {
    auto v = p.first;
    auto w = p.second;
    if (!visited[target][v]) {
      // additional cost of weight of (edge - target)
      cost[target][v] = cost[target][u] + abs(target - w);
      dfs2(v, target);
    }
  }
}

int main() {

  cin >> n;

  int a, b, w;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b >> w;
    a--, b--;
    adjL[a].push_back({b, w});
    adjL[b].push_back({a, w});
  }

	dfs(0);
	par[0] = -1;
	pre();

  for (int i = 0; i < 27; ++i) {
    dfs2(0, i);
  }

  int q;
  cin >> q;
  while(q--) {

    cin >> a >> b;
    --a, --b;
		int lca = query(a, b);

    long long ans = 1e12L;
    for (int i = 1; i < 27; ++i) {
      ans = min(ans, cost[i][a] + cost[i][b] - cost[i][lca]);
    }
    cout << ans << ' ';
  }
  cout << '\n';

  return 0;
}