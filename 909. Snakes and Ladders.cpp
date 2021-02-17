class Solution {
public:
    pair<int,int> nextMove (int i, int j, vector<vector<int>>& b, map<int, pair<int,int>> &boardMap) {
         if (b[i][j]==-1)
            return {i, j};
        else 
            return boardMap[b[i][j]];
    }
    vector<pair<int,int>> findPossibleMoves (int x, int y, vector<vector<int>>& b, map< pair<int,int>, bool> &vis, map<int, pair<int,int>> &boardMap, int n) {
        int cntMoves = 0;
        vector<pair<int,int>> moves;
        if ((n-x)&1) {
            int i = x;
            for (int j=y+1;j<n && cntMoves<6; j++, cntMoves++)
                moves.push_back(nextMove(i, j, b, boardMap));
            i = x-1;
            if (i>=0 && cntMoves<6) {
                for (int j=n-1;j>=0 && cntMoves<6;j--, cntMoves++)
                    moves.push_back(nextMove(i, j, b, boardMap));
            }
        }
        else {
            int i = x;
            for (int j=y-1;j>=0 && cntMoves<6;j--, cntMoves++)
                moves.push_back(nextMove(i, j, b, boardMap));
            i = x-1;
            if (i>=0 && cntMoves<6) {
                for (int j=0;j<n && cntMoves<6;j++, cntMoves++) 
                    moves.push_back(nextMove(i, j, b, boardMap));
            }
        }
        return moves;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int cnt=1;
        map<int, pair<int,int>> boardMap;
        for (int i=n-1;i>=0;i--) {
            if ((n-i)&1) {
                for(int j=0;j<n;j++, cnt++) {
                    boardMap[cnt] = {i,j};
                }
            } else {
                for (int j=n-1;j>=0;j--,cnt++) {
                    boardMap[cnt] = {i,j};
                }
            }
        }
        
        pair <int,int> st = {n-1, 0};
        auto it = boardMap.find(n*n);
        pair <int,int> en = it->second;
        queue< pair<pair<int,int>, int> > q;
        q.push({st, 0});
        map< pair<int,int>, bool> vis;
        
        vis[st] = 1;
        
        
        while (!q.empty()) {
            pair<pair<int,int>, int> front = q.front();
            q.pop();
            
            int x = front.first.first;
            int y = front.first.second;
            int level = front.second;
            
            // cout<<"( "<<x<<", "<<y<<") => "<< level<<"\n";
            if (en.first == x && en.second == y) {
                return level;
            }
            
            vector<pair<int,int>> possibleNextMoves = 
                findPossibleMoves(x, y, board, vis, boardMap, n);
            
            for (auto it: possibleNextMoves) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, level+1});
                }
            }
        }
        return -1;
    }
};
