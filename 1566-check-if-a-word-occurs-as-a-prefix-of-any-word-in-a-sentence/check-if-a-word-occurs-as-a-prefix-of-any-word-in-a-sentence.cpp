class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int sc = 1;
        char prev = ' ';
        for(int i=0; i<sentence.length(); i++)
        {
            if(sentence[i] == ' ')
            {
                sc++;
            }
            int j = 0;
            while(sentence[i] == searchWord[j] && prev == ' ')
            {
                i++; j++;
                if(j == searchWord.length())
                    return sc;
                if(sentence[i] == ' ')
                {
                    sc++;
                }
            }
            prev = sentence[i];
        }

        return -1;
    }
};