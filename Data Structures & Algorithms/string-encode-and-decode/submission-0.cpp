#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            // Format for each string: [length] + "#" + [string]
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.length()) {
            // Step 1: Find the next delimiter '#' starting from index i
            int j = s.find('#', i);
            
            // Step 2: Extract the length of the upcoming string
            int length = stoi(s.substr(i, j - i));
            
            // Step 3: Extract the actual string using the parsed length
            string str = s.substr(j + 1, length);
            decoded.push_back(str);
            
            // Step 4: Move the pointer 'i' to the start of the next encoded string
            i = j + 1 + length;
        }
        
        return decoded;
    }
};