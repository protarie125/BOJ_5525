#include <iostream>
#include <string>
#include <vector>

using namespace std;

using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	string s; cin >> s;

	auto pc = vi(m / 2, 0);
	auto nl = int{ 0 };
	for (auto i = 0; i < m - 2; ++i) {
		if ('O' == s[i]) {
			if (0 < nl) {
				pc[nl - 1] += 1;
			}

			nl = 0;
			continue;
		}

		if ("OI" == s.substr(i + 1, 2)) {
			++nl;
			i += 1;
		}
		else {
			if (0 < nl) {
				pc[nl - 1] += 1;
			}
			nl = 0;
		}
	}

	if (0 < nl) {
		pc[nl - 1] += 1;
	}

	auto ans = int{ 0 };
	for (auto i = n - 1; i < m / 2; ++i) {
		ans += pc[i] * (i - (n - 1) + 1);
	}
	cout << ans;

	return 0;
}