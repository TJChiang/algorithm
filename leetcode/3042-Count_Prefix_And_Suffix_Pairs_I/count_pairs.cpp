#include <iostream>
#include <vector>

using namespace std;

class BruteForce {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string& str1 = words[i];
                string& str2 = words[j];

                // 前面的字串長度大於後面的字串長度，則一定不是 prefix or suffix
                if (str1.size() > str2.size()) continue;

                if (str2.find(str1) == 0 && str2.rfind(str1) == str2.size() - str1.size()) count++;
            }
        }

        return count;
    }
};

class Node {
public:
    // 設定長度為 26 的節點陣列，分別對應 26 個字母，儲存該字母的節點
    Node* links[26] = {};
    bool contains(char c) { return links[c - 'a'] != nullptr; }

    void put(char c, Node* node) { links[c - 'a'] = node; }

    Node* next(char c) { return links[c - 'a']; }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }

    void insert(string& word) {
        Node* node = root;
        for (char c : word) {
            // 沒有字符的話，就設定新的 node
            if (!node->contains(c)) node->put(c, new Node());

            // 指向下一個 node ，基本上 node 不會重複，所以每個 node 都是新建的
            node = node->next(c);
        }
    }

    bool startsWith(string& prefix) {
        Node* node = root;
        for (char c : prefix) {
            if (!node->contains(c)) return false;

            node = node->next(c);
        }

        return true;
    }
};

class DualTrie {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            // 設定字串的前綴節點樹與後綴節點樹
            Trie prefixTrie, suffixTrie;

            // 前綴節點樹初始化
            prefixTrie.insert(words[i]);

            // 字串反轉即可變成後綴節點樹
            string reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());
            suffixTrie.insert(reverseWord);

            for (int j = 0; j < i; j++) {
                if (words[j].size() > words[i].size()) continue;

                string prefixWord = words[j]; // 前綴即為字串
                string reversePrefixWord = prefixWord;
                reverse(reversePrefixWord.begin(), reversePrefixWord.end()); // 後綴即為反轉字串

                // 前綴節點樹比對前綴字串，後綴節點樹比對後綴字串
                if (prefixTrie.startsWith(prefixWord) && suffixTrie.startsWith(reversePrefixWord)) count++;
            }
        }

        return count;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<string>> testCase = {
        {"a","aba","ababa","aa"}, // 4
        {"pa","papa","ma","mama"}, // 2
        {"abab","ab"} // 0
    };
    BruteForce sol;
    for (auto t : testCase) {
        cout << "result: " << sol.countPrefixSuffixPairs(t) << endl;
    }

    return 0;
}
