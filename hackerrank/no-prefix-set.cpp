#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

class Trie {
public:
  Trie() : children(26), isEnd(false) {}

  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (children[i] != nullptr)
        delete children[i];
    }
  }

  /* @return: has Prefix or Extension */
  bool insert(string word) {
    bool hasPre = false, hasExt = true;
    Trie *curr = this;
    int idx;
    for (const char ch : word) {
      idx = ch - 'a';
      if (curr->children[idx] == nullptr) {
        hasExt = false;
        curr->children[idx] = new Trie();
      }
      /* prefix exists */
      if (curr->children[idx]->isEnd)
        hasPre = true;
      curr = curr->children[idx];
    }
    curr->isEnd = true;
    return hasPre || hasExt;
  }

private:
  vector<Trie *> children;
  bool isEnd;
};

void noPrefix(vector<string> words) {
  Trie trie;
  for (const string &s : words) {
    if (trie.insert(s)) {
      cout << "BAD SET" << endl;
      cout << s << endl;
      return;
    }
  }
  cout << "GOOD SET" << endl;
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<string> words(n);

  for (int i = 0; i < n; i++) {
    string words_item;
    getline(cin, words_item);

    words[i] = words_item;
  }

  noPrefix(words);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
