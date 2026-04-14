class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index = 0, i = 0;
        int ans = 0;
        int n = s.size();

        int arr[256] = {0};

        while(i < n) {
            if(arr[s[i]] == 0) {
                arr[s[i]]++;
                i++;
            }

            else {
                arr[s[index]]--;
                index++;
            }

            if(i - index > ans) {
                ans = i - index;
            }
        }

        return ans;
    }
};