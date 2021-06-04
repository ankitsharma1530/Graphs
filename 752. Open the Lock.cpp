class Solution {
public:
    // The main differnce between this question and word ladder is 
    // In word ladder we had to move only forward, means for 'a' there will be
    // a,b,c,d,e........v,w,x,y,z
    // but for this question we have to check for forward and backward condn
    // like for a number n = 7 , we had to check for n-1 and n+1 both
    // look into LEETCODEnotes for logic diagram
    
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>s(deadends.begin(),deadends.end());
        unordered_set<string>vis;
        if(s.find("0000")!=s.end()){
            return -1;
        }
        vis.insert("0000");
        queue<string>q;
        q.push("0000");
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == target){
                    return time;
                }
                
                // same as we check in word ladder for every index of string
                // here we also check for all indexes
                for(int i=0;i<4;i++){
                    
                    // we use down and up to iterate in both directions 
                    string down = curr;
                    string up = curr;
                    char up_char = up[i];
                    char down_char = down[i];
                    
                    // edge cases because 9 can not be added to 10
                    // and 0 can not be subtracted to -1
                    //  Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
                    //The wheels can rotate freely and wrap around: for example we can turn '9' to be '0',                     // or '0' to be '9'.
                    up[i] = (up_char=='9')?'0':up_char+1;
                    down[i] = (down_char=='0')?'9':down_char-1;
                    
                    if(vis.find(up)==vis.end() and s.find(up)==s.end()){
                        q.push(up);
                        vis.insert(up);
                    }
                    if(vis.find(down)==vis.end() and s.find(down)==s.end()){
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            time++;
        }
        return -1;
    }
    
};
