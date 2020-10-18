#include<bits/stdc++.h>
using namespace std;
vector<int>getanswer(int n, vector<int>a, vector<int>ds) {
	vector<int>id, sum,ans;
	int cnt=0;
	for (int i = 0; i < n; ++i) {
		id.push_back(i + 1);
		sum.push_back(a[i] + ds[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > 0;--j) {
			if (sum[j] > sum[j - 1] || sum[j] == sum[j - 1] && a[j] > a[j - 1]) {
				swap(id[j], id[j - 1]);
				swap(sum[j], sum[j - 1]);
				swap(a[i], a[i - 1]);
				swap(ds[i], ds[i - 1]);
				cnt++;
			}
		}
	}
	for(int j=0;j<n;++j){
			ans.push_back(id[j]);
			ans.push_back(sum[j]);
			ans.push_back(a[j]);
			ans.push_back(ds[j]);
		}
	
	ans.push_back(cnt);
	return ans;
	}
	

}
int main() {
	int n;
	cin >> n;
	vector<int>a, ds;
	int y = n;
	int temp;
	while (y--) {
		cin >> temp;
		a.push_back(temp);
		cin >> temp;
		ds.push_back(temp);
	}
	vector<int>ans;
	ans = getanswer(n, a, ds);
	for (int i = 0; i < 4 * n; i += 4) {
		cout << ans[i] << ans[i + 1] << ans[i + 2] << ans[i + 3] << endl;
	}
	cout<<ans[4*n];
	return 0;
}

