class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> s(wordList.begin(), wordList.end()); // put all the words into unordered_set for fast search and erase.

        if(s.find(endWord) == s.end())
            return 0;

        queue <string> q;
        q.push(beginWord); // since we need to count the total words in the path pass 1.
        int words = 1;
        while(!q.empty())
        {
            int qs = q.size();
            while(qs--)
            {
                string str = q.front();
                q.pop();
                for(int i = 0; i < str.size(); i++) // Selects index in the current string.
                {
                    char tmp = str[i]; // temporary string which represents the word we need to search for next step.
                    for(char c = 'a'; c <= 'z'; c++) // 
                    {
                        str[i] = c; // Replace the character at jth index.
                        auto it = s.find(str);
                        if(it != s.end()) // if modified word that has one character difference to str is found the push to queue.
                        {
                            if(*it == endWord)
                                return words+1;
                            q.push(*it);
                            s.erase(it); // erase from the set since word can be used only once.
                        }
                    }
                    str[i] = tmp;
                }
            }
            words++;
        }
        return 0;
    }
};