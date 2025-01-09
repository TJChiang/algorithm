#include <iostream>
#include <vector>

using namespace std;

class BruteForce {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string& word : words) {
            if (word.find(pref) == 0) count++;
        }

        return count;
    }
private:
    bool hasPrefix(string& word, string pref) {
        int it;
        for (it = 0; it < word.size() && it < pref.size(); it++) {
            if (word[it] != pref[it]) return false;
        }

        // word 長度比 pref 短，則為 false
        // 長度與 pref 相等，表示迴圈有跑完，且有找到
        return it == pref.size();
    }
};

class BruteForceWithMethod {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string& word : words) {
            if (word.find(pref) == 0) count++;
        }

        return count;
    }
};

class TrieSolution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;

        for (string& word : words) {
            trie.add(word);
        }

        return trie.countPrefix(pref);
    }
private:
    class Trie {
        struct Node {
            vector<Node*> links;
            int count;

            Node() : links(26, nullptr), count(0) {}
        };

        Node* root;
    public:
        Trie() { root = new Node(); }

        void add(string& word) {
            Node* curr = root;
            for (char c : word) {
                if (curr->links[c - 'a'] == nullptr) curr->links[c - 'a'] = new Node();

                curr = curr->links[c - 'a'];
                curr->count++;
            }
        }

        int countPrefix(string& pref) {
            Node* curr = root;
            for (char c : pref) {
                if (curr->links[c - 'a'] == nullptr) return 0;
                curr = curr->links[c - 'a'];
            }
            return curr->count;
        }
    };
};

int main(int argc, char* argv[])
{
    // case 1 => 2
    vector<string> words = {"pay","attention","practice","attend"};
    string prefix = "at";
    // case 2 => 0
//    vector<string> words = {"leetcode","win","loops","success"};
//    string prefix = "code";
    BruteForceWithMethod sol;
    cout << "Result: " << sol.prefixCount(words, prefix) << endl;

    return 0;
}
