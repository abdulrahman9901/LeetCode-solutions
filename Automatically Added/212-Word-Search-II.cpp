class Solution {
    vector<vector<char>> board;
    vector<string> words;
    vector<string> res;
    int m, n;
    vector<vector<bool>> visited;
    vector<int> dir = {-1, 0, 1, 0, -1}; // Direction array for navigating the board

    struct Node {
        char val;
        bool eos;
        array<Node*, 26> childs;
        
        Node(char val) : val(val), eos(false), childs{} {}
    };

    class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node('/');
        }

        void addWord(const string& word) {
            Node* curr = root;
            for (char c : word) {
                if (curr->childs[c - 'a'] == nullptr) {
                    curr->childs[c - 'a'] = new Node(c);
                }
                curr = curr->childs[c - 'a'];
            }
            curr->eos = true;
        }
    };

    void dfs(int r, int c, Node* node, string word) {
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || node->childs[board[r][c] - 'a'] == nullptr)
            return;

        visited[r][c] = true;
        node = node->childs[board[r][c] - 'a'];
        word += board[r][c];

        if (node->eos) {
            res.push_back(word);
            node->eos = false; // To avoid duplicate entries
        }

        for (int i = 0; i < 4; ++i) {
            int newY = r + dir[i], newX = c + dir[i + 1];
            dfs(newY, newX, node, word);
        }

        visited[r][c] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie();
        for (const string& word : words) {
            t->addWord(word);
        }

        this->board = board;
        this->words = words;
        this->m = board.size();
        this->n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, t->root, \\);
            }
        }

        delete t; // Properly delete the allocated Trie to avoid memory leaks
        return res;
    }
};
