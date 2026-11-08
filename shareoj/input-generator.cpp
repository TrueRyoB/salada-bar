#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

struct Test {
    int N, K;
    string A, B;
};

// 提示された解法から、通常の境界値を計算する。
// 返り値が -1 の場合は、単純な境界ペアとして使わない。
ll get_border(int N, const string& A, const string& B) {
    int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] == '0' && B[i] == '0') cnt00++;
        if (A[i] == '0' && B[i] == '1') cnt01++;
        if (A[i] == '1' && B[i] == '0') cnt10++;
        if (A[i] == '1' && B[i] == '1') cnt11++;
    }

    int rem = N - cnt00 - cnt11;

    // 常に Yes になるため、境界が存在しない
    if (rem == 0) return -1;

    // 特殊ケース: Yes iff K > 1
    if (rem == N && N == 1) return 2;

    // 特殊ケース: Yes iff K <= 2
    // 通常の「K以下がYes、K+1がNo」という形ではない
    if (rem == N && cnt01 == rem && rem == 2) {
        return -1;
    }

    ll sum = 0;

    if (rem == N) {
        if (cnt01 == rem) {
            cnt00++;
            cnt11++;
            cnt01 -= 2;
            sum += 2;
        } else {
            cnt11++;
            cnt10--;
            sum++;
        }
    }

    sum += 2LL * cnt01 + 3LL * cnt10;
    if (cnt01 + cnt10 > 0) sum += cnt00;

    // Yes iff K >= sum + 1
    return sum + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int BASE_CASES = 3000;
    // constexpr int MAX_N = 100;
    constexpr int MAX_N = 10;
    constexpr int MAX_T = 10000;
    constexpr int MAX_SUM_N = 1000000;
    constexpr int MAX_K = 1000000000;

    vector<Test> tests;
    tests.reserve(BASE_CASES * 3);

    int sumN = 0;

    while ((int)tests.size() < BASE_CASES * 3) {
        int N = rnd(1, MAX_N);

        // 3ケース分のNの合計を制約内に収める
        if (sumN + 3 * N > MAX_SUM_N) continue;

        string A(N, '0'), B(N, '0');
        for (int i = 0; i < N; ++i) {
            A[i] = char('0' + rnd(0, 1));
            B[i] = char('0' + rnd(0, 1));
        }

        ll K = get_border(N, A, B);

        // 境界がない、またはKの制約を満たさない場合は破棄
        if (K < 1 || K + 1 > MAX_K) continue;

        // 3つ目は K-1 または K+2
        int extra = rnd(0, 1) ? -1 : 2;
        ll K3 = K + extra;

        // K-1が制約外ならK+2に切り替える
        if (K3 < 1 || K3 > MAX_K) K3 = K + 2;

        if (K3 < 1 || K3 > MAX_K) continue;

        tests.push_back({N, (int)K, A, B});       // Yes
        tests.push_back({N, (int)(K + 1), A, B}); // No
        tests.push_back({N, (int)K3, A, B});      // ランダムな追加ケース

        sumN += 3 * N;
    }

    cout << tests.size() << '\n';

    for (const auto& t : tests) {
        cout << t.N << ' ' << t.K << '\n';
        cout << t.A << '\n';
        cout << t.B << '\n';
    }

    return 0;
}
