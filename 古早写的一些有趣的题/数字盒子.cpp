#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1000003;
int Hash(ll x) {
	return x %= mod;
}
vector<ll>table[mod];
bool check(int op, ll x) {
	int h = Hash(x);
	vector<ll>::iterator ptr = table[h].end();
	for (vector<ll>::iterator it = table[h].begin(); it != table[h].end(); ++it) {
		if (*(it) == x) {
			ptr = it;
			break;
		}
		if (op == 1) {
			if (ptr == table[h].end()) {
				table[h].push_back(x);
				return 1;
			}
			return 0;
		}
		else
			if (ptr != table[h].end()) {
				*ptr = table[h].back();
				table[h].pop_back();
				return 1;
			}
		return 0;
	}
}
int main() {

	int n;
	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		ll x;
		cin >> x;
		int ans = check(op, x);
		if (ans == 1)
			cout << "Succeeded";
		else
			cout << "Failed";
	}
	return 0;
}
