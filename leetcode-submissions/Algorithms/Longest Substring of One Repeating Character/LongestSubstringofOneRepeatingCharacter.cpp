/*
  LeetCode Submission ID: 2108191019
  Date: 16/08/2026, 00:56:13
  Runtime: 128 ms
  Memory: 92.9 MB
  Difficulty: Easy
  Problem Link: https://leetcode.com/problems/longest-substring-of-one-repeating-character/submissions/2108191019/?envType=daily-question&envId=2026-08-13
*/

class Solution {
private:
    class SegmentTree {
    private:
        int n;
        vector<int> pre;
        vector<int> suf;
        vector<int> best;
        string s;

        void pushUp(int node, int l, int r) {
            int left = node << 1;
            int right = node << 1 | 1;
            int mid = (l + r) >> 1;

            int lenL = mid - l + 1;
            int lenR = r - mid;

            pre[node] = pre[left];
            suf[node] = suf[right];
            best[node] = max(best[left], best[right]);

            if (s[mid] == s[mid + 1]) {
                if (pre[left] == lenL) {
                    pre[node] = lenL + pre[right];
                }
                if (suf[right] == lenR) {
                    suf[node] = lenR + suf[left];
                }
                best[node] = max(best[node], suf[left] + pre[right]);
            }
        }

        void build(int node, int l, int r) {
            if (l == r) {
                pre[node] = 1;
                suf[node] = 1;
                best[node] = 1;
                return;
            }

            int mid = (l + r) >> 1;
            build(node << 1, l, mid);
            build(node << 1 | 1, mid + 1, r);

            pushUp(node, l, r);
        }

        void update(int node, int l, int r, int i) {
            if (l == r) {
                return;
            }

            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(node << 1, l, mid, i);
            } else {
                update(node << 1 | 1, mid + 1, r, i);
            }

            pushUp(node, l, r);
        }

    public:
        vector<int> getBest() const { return best; }
        int getRootBest() const { return best[1]; }
        SegmentTree(const string& str) : n(str.length()), s(str) {
            pre.assign(n << 2, 0);
            suf.assign(n << 2, 0);
            best.assign(n << 2, 0);
            build(1, 0, n - 1);
        }
        void update(int i) { update(1, 0, n - 1, i); }
        void updateChar(char c, int i) { s[i] = c; }
    };

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int k = queryIndices.size();
        SegmentTree tree(s);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            int index = queryIndices[i];
            tree.updateChar(queryCharacters[i], index);
            tree.update(index);
            ans[i] = tree.getRootBest();
        }
        return ans;
    }
};