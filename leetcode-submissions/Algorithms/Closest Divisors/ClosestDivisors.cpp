class Solution {
private:
    vector<int> closestPair(int target) {
        for (int divisor = static_cast<int>(sqrt(target)); divisor >= 1; --divisor) {
            if (target % divisor == 0) {
                return {divisor, target / divisor};
            }
        }

        return {};
    }

public:
    vector<int> closestDivisors(int num) {
        vector<int> first = closestPair(num + 1);
        vector<int> second = closestPair(num + 2);

        int firstDifference = abs(first[0] - first[1]);
        int secondDifference = abs(second[0] - second[1]);

        return firstDifference <= secondDifference ? first : second;
    }
};