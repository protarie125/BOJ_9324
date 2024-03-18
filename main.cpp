#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n;
string s;
vl A;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  while (0 < (n--)) {
    cin >> s;

    A = vl(26, 0);

    auto is_fake = bool{false};
    for (auto p = 0; !is_fake && p < s.length(); ++p) {
      const auto& i = s[p] - 'A';

      ++A[i];
      if (3 == A[i]) {
        if (p + 1 == s.length() || s[p] != s[p + 1]) {
          cout << "FAKE\n";
          is_fake = true;
          break;
        }

        A[i] = 0;
        ++p;
      }
    }

    if (!is_fake) {
      cout << "OK\n";
    }
  }

  return 0;
}