class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> availableW(wordList.begin(), wordList.end());
        q.push(beginWord);

        int counter = 1;
        while(!q.empty()) {
            int qSize = q.size();

            for(int i = 0; i < qSize; i++) {
                string currWord = q.front();
                q.pop();

                if (currWord == endWord) {
                    return counter;
                }

                for (int j = 0; j < currWord.size(); j++) {
                    char realChar = currWord[j];

                    for (char newChar = 'a'; newChar <= 'z'; newChar++) {
                        currWord[j] = newChar;

                        if (availableW.count(currWord)) {
                            q.push(currWord);
                            availableW.erase(currWord);
                        }
                    }

                    currWord[j] = realChar;
                }
            }
            counter++;
        }

        return 0;
    }
};


/*
//a...z
//"cat", *at, c*t, ca* c = 1 in each wildcard index we vary the cahr with a to z.
"bat","bag","sag","dag","dot"

//bat-> *at, b*t, ba* c = 2
"bag","sag","dag","dot"

bag -> *ag, b*g, *ag c = 3
"sag","dag","dot"
sag == endword :: return counter

*/