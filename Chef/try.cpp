#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = (ll) 1e5 + 5;

ll n, m, q;
ll tree[N * 4], dp[N];
vector<ll> g[N], p;
vector< pair<ll, ll> > t[N];

void Update (ll v, ll tl, ll tr, ll pos, ll nv) {
		if (tl == tr) {
				tree[v] = nv;
		} else {
				ll tm = (tl + tr) >> 1;
				if (pos <= tm) {
						Update (v + v, tl, tm, pos, nv);
				} else {
						Update (v + v + 1, tm + 1, tr, pos, nv);
				}
				tree[v] = min (tree[v + v], tree[v + v + 1]);
		}
}

ll Get (ll v, ll tl, ll tr, ll l, ll r) {
		if (l > r || tl > r || tr < l) {
				return (ll) 1e18;
		}
		if (l <= tl && tr <= r) {
				return tree[v];
		} else {
				ll tm = (tl + tr) >> 1;
				return min (Get (v + v, tl, tm, l, r), Get (v + v + 1, tm + 1, tr, l, r));
		}
}

void Dfs (ll v, ll pos = 1) {
		if (v == 1) {
				dp[v] = 0;
		} else {
				dp[v] = (ll) 1e18;
				for (auto i : t[v]) {
						dp[v] = min (dp[v], Get (1, 1, n, pos - i.first, pos - 1) + i.second);
				}
		}
		Update (1, 1, n, pos, dp[v]);
		for (auto to : g[v]) {
				Dfs (to, pos + 1);
		}
}

void Solve () {
		scanf ("%lld%lld", &n, &m);
		for (ll i = 1; i < n; i++) {
				ll a, b;
				scanf ("%lld%lld", &a, &b);
				g[b].emplace_back (a);
		}
		for (ll i = 1; i <= m; i++) {
				ll a, b, c;
				scanf ("%lld%lld%lld", &a, &b, &c);
				t[a].emplace_back (make_pair (b, c));
		}
		Dfs (1);
		scanf ("%lld", &q);
		while (q--) {
				ll a;
				scanf ("%lld", &a);
				printf ("%lld\n", dp[a]);
		}
}

ll tests = 1;

int main () {
//        scanf ("%lld", &tests);

		while (tests--) {
				Solve ();
		}

		return 0;
}
