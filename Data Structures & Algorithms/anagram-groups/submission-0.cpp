class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagram;
        unordered_map <string,vector<string>> anamap;
        for (const string &s :strs){
            string key=s;
            sort(key.begin(),key.end());
            anamap[key].push_back(s);
        }
        for(auto& pair:anamap){
            anagram.push_back(pair.second);
        }
        return anagram;
      
        
    }
};
