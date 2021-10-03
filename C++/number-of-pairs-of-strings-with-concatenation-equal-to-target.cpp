// Time:  O(n * l), n is the size of nums, l is the average length of the digit string in nums
// Space: O(n)

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<int, int> prefix, suffix;
        int result = 0;
        for (const auto& num : nums) {
            if (size(num) > size(target)) {
                continue;
            }
            if (!target.compare(0, size(num), num)) {  // in c++ 20, we can directly use starts_with, see https://en.cppreference.com/w/cpp/string/basic_string/starts_with
                result += suffix[size(target) - size(num)];
            }
            if (!target.compare(size(target) - size(num), size(num), num)) {
                result += prefix[size(target) - size(num)];
            }
            if (!target.compare(0, size(num), num)) {  // in c++ 20, we can directly use ends_with, see https://en.cppreference.com/w/cpp/string/basic_string/ends_with
                ++prefix[size(num)];
            }
            if (!target.compare(size(target) - size(num), size(num), num)) {
                ++suffix[size(num)];
            }
        }
        return result;
    }
};