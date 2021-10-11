#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  stack<int> s1;
  stack<int> s2;
  int queries, type, num;
  cin >> queries;
  for (int i = 0; i < queries; ++i) {
    cin >> type;
    switch (type) {
    case 1:
      cin >> num;
      s1.push(num);
      break;

    case 2:
      if (s2.empty()) {
        while (!s1.empty()) {
          s2.push(s1.top());
          s1.pop();
        }
      }
      s2.pop();
      break;

    case 3:
      if (s2.empty()) {
        while (!s1.empty()) {
          s2.push(s1.top());
          s1.pop();
        }
      }
      cout << s2.top() << endl;
      break;

    default:
      continue;
    }
  }
  return 0;
}
