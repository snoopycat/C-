class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return vector<vector<string>> ();
        int len = strs.size();
        sort(strs.begin(),strs.end());
        vector<vector<string>> res;
        map<string,vector<string>> rec;
        for(int i = 0; i < len; i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            rec[str].push_back(strs[i]);
        }
        for (map<string, vector<string> >::iterator iter = rec.begin(); iter != rec.end(); iter++)
            res.push_back(iter->second);
        return res;
    }
};
