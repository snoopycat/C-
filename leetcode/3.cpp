class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        
        int dp[s.length()];
        int record[1000];
        int last_start = 0, res(1);
        memset(&dp,0,s.length());
        memset(&record,-1,1000);
        record[s[0]] = 0;
        dp[0] = 1;
        
        for(int i = 1; i < s.length(); i++){
            if(record[s[i]] == -1){
                dp[i] = dp[i-1] + 1;
                record[s[i]] = i;
            }
            else{
                if(last_start <= record[s[i]]){
                    dp[i] = i - record[s[i]];
                    last_start = record[s[i]] + 1;
                    record[s[i]] = i;
                }
                else{
                    dp[i] = dp[i-1] + 1;
                    record[s[i]] = i;
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
