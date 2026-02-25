class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();
        unordered_map <string, int> freq;

        // Add the banned words with sentinel value to the map.
        for(string &s : banned)
            freq[s] = -1;
        
        string word = "";
        string maxWord = "";
        int maxFreq = 0;

        for(int i = 0; i < n; i++)
        {
            if(!isalpha(paragraph[i])) // current charater is not a letter.
            {
                if(freq[word] != -1 && !word.empty()) // word is not banned or empty.
                {
                    freq[word]++; // increment freq.
                    if(freq[word] > maxFreq) // update maxWord of freq is largest.
                    {
                        maxFreq = freq[word];
                        maxWord = word;
                    }
                }
                word = ""; // clear the word.
            }
            else // if current charater is a letter the add to word.
                word += tolower(paragraph[i]);
        }

        // Last word handling.
        if(freq[word] != -1 && !word.empty())
        {
            freq[word]++;
            if(freq[word] > maxFreq)
            {
                maxFreq = freq[word];
                maxWord = word;
            }
        }

        return maxWord;
    }
};