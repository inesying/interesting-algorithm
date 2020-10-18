#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
vector<int>seq;
void mergesort(int l, int r) {
	l = 0; r = n;
	int cnt=0;
	int mid = (l + r) >> 1;
	if (l == r) {
		return;
	}
		mergesort(l, mid);
		mergesort(mid + 1, r);

	int p = l; q = mid + 1;
	vector<int>tempseq;
	tempseq.clear();
	for (int i = l; i <= r; ++i) {
		if (q > r || p < (mid + 1) && seq[p] <= seq[q]) {
			tempseq.push_back(seq[p++]);
		}
		else {
			tempseq.push_back(seq[q++]);
			cnt += mid + 1 - p;
		}
	}
	for (int i = l; i < r, ++i) {
		seq[i] = tempseq[i];
	}



}
ll geranswer(int n, vector<int>seq) {
	mergesort(0, n - 1);
	return cnt;

}
int main() {
	int n;
	cin >> n;
	vector<int>seq;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		seq.push_back(temp);
	}
	ll cnt= getanswer(n, seq);
	cout << cnt << endl;
	return 0;


}