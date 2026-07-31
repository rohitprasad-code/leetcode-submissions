/*
  LeetCode Submission ID: 1152220274
  Date: 31/07/2026, 11:42:09
  Runtime: 123 ms
  Memory: 27 MB
  Difficulty: Medium
  Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/submissions/1152220274/?envType=daily-question&envId=2026-07-31
*/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        int kPresses = 0, kPosition = 1, kNumber = 2;
        vector<char> sortedChars;

        for (char ch : word)
            freq[ch]++;

        for (const auto& pair : freq) 
            sortedChars.push_back(pair.first);
        
        sort(sortedChars.begin(), sortedChars.end(), [&](char a, char b) { return freq[a] > freq[b]; });

        for (char ch : sortedChars) {
            kPresses += freq[ch] * kPosition;
            if (kNumber<9) {
                kNumber++;
            } else {
                kNumber = 2;
                kPosition++;
            }
        }
        return kPresses;
    }
};