/*
  LeetCode Submission ID: 2086706655
  Date: 30/07/2026, 02:38:19
  Runtime: 20 ms
  Memory: 17.3 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/submissions/2086706655/?envType=daily-question&envId=2026-07-29
*/

class Solution {
private:
    long long comb(long long n, long long m, long long k) {
        long long res = 1;
        m = std::min(m, n - m);

        for (long long i = 1; i <= m; i++) {
            res = res * (n - i + 1) / i;
            if (res > k) {
                return k + 1;
            }
        }
        return res;
    }

public:
    std::string smallestPalindrome(std::string s, long long k) {
        int partition = s.length() / 2;
        std::vector<int> bucket(26, 0);

        for (int i = 0; i < partition; i++) {
            bucket[s[i] - 'a'] += 1;
        }

        auto permutations = [&](int rem) {
            long long ways = 1;
            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) {
                    continue;
                }

                ways *= comb(rem, bucket[i], k);
                if (ways > k) {
                    break;
                }
                rem -= bucket[i];
            }
            return ways;
        };

        std::string left = "";
        long long startIndex = 1;

        for (int pos = 0; pos < partition; pos++) {
            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) {
                    continue;
                }

                bucket[i] -= 1;

                long long ways = permutations(partition - pos - 1);
                if (startIndex + ways > k) {
                    left += (char)(i + 'a');
                    break;
                }

                bucket[i] += 1;
                startIndex += ways;
            }
        }

        if (left.length() < partition) {
            return "";
        }

        std::string mid =
            s.length() % 2 != 0 ? std::string(1, s[partition]) : "";
        std::string right = left;
        std::reverse(right.begin(), right.end());

        return left + mid + right;
    }
};