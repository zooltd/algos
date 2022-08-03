/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution { 
private:
    struct Node {
        int id;
        Node *son[26];
        Node() {
            id = -1;
            for (int i = 0; i < 26; i++) son[i] = nullptr;
        }
    }* root;
    int m;
    int n;
    unordered_set<int> ids;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        root = new Node();
        for (int i = 0; i < words.size(); i++) insert(words[i], i);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = board[i][j] - 'a';
                if (root->son[u])
                    dfs(board, i, j, root->son[u]);
            }
        }
        vector<string> res;
        for (auto id: ids) res.push_back(words[id]);
        return res;
    }

private:
    void dfs(vector<vector<char>>& board, int x, int y, Node* p) {
        if (p->id != -1) ids.insert(p->id);
        char t = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= m || b < 0 || b >= n || board[a][b] == '.') continue;
            int u = board[a][b] - 'a';
            if (p->son[u]) dfs(board, a, b, p->son[u]);
        }
        board[x][y] = t;
    }

private:
    void insert(const string& word, int id) {
        auto p = root;
        for (const char c : word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = id;
    }
};
// @lc code=end

