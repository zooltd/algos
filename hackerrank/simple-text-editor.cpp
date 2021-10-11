#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  string s;
  stack<string> re;
  string w;
  int k;
  int num;
  cin >> num;
  for (; num > 0; num--) {
    int type;
    cin >> type;
    switch (type) {
    case 1:
      cin >> w;
      re.push(s);
      s += w;
      break;
    case 2:
      cin >> k;
      re.push(s);
      s = s.substr(0, s.size() - k);
      break;
    case 3:
      cin >> k;
      cout << s[k - 1] << endl;
      break;
    case 4:
      s = re.top();
      re.pop();
      break;
    default:
      continue;
    }
  }
  return 0;
}
