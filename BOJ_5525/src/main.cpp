#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    int M;
    cin >> M;

    string S;
    cin >> S;

    auto f = S.find("IOI");
    if (S.npos != f) {
        M -= f;
        S = S.substr(S.find("IOI"));

        vector<int> ps{};
        f = S.find("I");
        int p{ 0 };
        int i{ 0 };
        while (S.npos != f) {
            if ("OI" == S.substr(f + i + 1, 2)) {
                p += 1;
                i += 2;
            }
            else {
                ps.push_back(p);
                p = 0;

                S = S.substr(f + i + 1);
                i = 0;

                f = S.find("I");
            }
        }

        int result{ 0 };
        for (const auto& p : ps)
        {
            if (N <= p) {
                result += (p - N + 1);
            }
        }

        cout << result;
    }
    else {
        cout << 0;
    }

    return 0;
}