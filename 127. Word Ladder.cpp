class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        int depth = 0;
        bool flag = false;
        for(int i=0;i<wordList.size();i++)
        {
            s.insert(wordList[i]);
            if(endWord.compare(wordList[i])==0)
            {
                flag = true;
            }
        }
        if(!flag)
        {
            return 0;
        }
        //bfs
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            depth++;
            int size = q.size();
            while(size--)
            {
                string temp = q.front();
                q.pop();
                for(int i=0;i<temp.length();i++)
                {
                    string curr = temp;
                    for(char j='a';j<='z';j++)
                    {
                        curr[i] = j;
                        // check for the same element
                        if(curr.compare(temp)==0)
                        {
                            continue;
                        }
                        if(curr.compare(endWord)==0)
                        {
                            return depth+1;
                        }
                        if(s.find(curr)!=s.end())
                        {
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};
