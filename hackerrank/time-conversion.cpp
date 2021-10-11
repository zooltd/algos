#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
  int pos = s.find(":");
  int t = stoi(s.substr(0, pos));
  bool isAM = s[8] == 'A';
  if (isAM)
    t %= 12;
  else
    t = t % 12 + 12;
  if (t >= 10) {
    return to_string(t) + s.substr(pos, 6);
  } else {
    return to_string(0) + to_string(t) + s.substr(pos, 6);
  }
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
