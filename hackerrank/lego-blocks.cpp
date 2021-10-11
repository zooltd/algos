#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */
const static int mod = 7 + pow(10, 9);

long long power(long long base, int e) {
  if (e == 0)
    return 1;
  if (e == 1)
    return base;
  long long res = 1;
  for (int i = 0; i < e; ++i) {
    res = (res * base) % mod;
  }
  return res;
}

int legoBlocks(int n, int m) {
  vector<long long> a(1001, 0);
  a[0] = a[1] = 1;
  a[2] = a[1] + a[0];
  a[3] = a[2] + a[1] + a[0];
  for (int i = 4; i < m + 1; ++i) {
    a[i] = (a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4]) % mod;
  }

  vector<long long> total(m + 1, 0);
  for (int i = 0; i < m + 1; ++i) {
    total[i] = power(a[i], n);
  }

  vector<long long> solid(m + 1, 0);
  solid[0] = solid[1] = 1;
  for (int i = 2; i < m + 1; ++i) {
    long long sum = 0;
    for (int j = 1; j < i; ++j) {
      sum += solid[j] * total[i - j];
      sum %= mod;
    }
    solid[i] = (total[i] - sum) % mod;
  }
  while (solid[m] < 0) {
    solid[m] += mod;
  }
  return solid[m] % mod;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int result = legoBlocks(n, m);

    fout << result << "\n";
  }

  fout.close();

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

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
