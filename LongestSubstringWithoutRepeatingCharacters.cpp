class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max[s.length()+1] = {0};
        int maxLen = 0;
        int visited[1000] = {0};
        int len = 0;
        
        for(int i = 0; i < s.length(); i ++){
            visited[s[i]] = 1;
            for(int j = i+1; j < s.length(); j ++){
                if(visited[s[j]]){
                    break;
                }
                visited[s[j]] = 1;
                len++;
            }
            max[i] = len + 1;
            len = 0;
            
            for(int i = 0; i < 1000; i ++){
                visited[i] = 0;
            }
        }
        
        for(int k = 0; k < s.length(); k++){
            if (max[k] > maxLen){
                maxLen = max[k];
            }
            cout << max[k] << "\n";
        }
        return maxLen;
    }
};