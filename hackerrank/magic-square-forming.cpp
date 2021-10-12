#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();
  /* flip horizontally */
  for (int i = 0; i < n / 2; ++i) {
    for (int j = 0; j < n; ++j) {
      swap(matrix[i][j], matrix[n - i - 1][j]);
    }
  }
  /* flip diagonally */
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}

int calDiff(const vector<vector<int>> &oldMatrix,
            const vector<vector<int>> &newMatrix) {
  int diff = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      diff += abs(newMatrix[i][j] - oldMatrix[i][j]);
    }
  }
  return diff;
}

/**
 * a) the "middle" of any 3x3 magic square must be 5
 * b) the "magic sum" must be 15.
 * c) 4 "pairs" can go on opposite sides of 5: (1, 9), (2, 8), (3, 7), (4, 6)
 * d) only two of these pairs fit in the "corners": (2, 8), (4, 6)
 * start with one "seed": {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}
 * From that you can take the mirror images (horizontally and vertically)
 * and the rotation of each.
 */
int formingMagicSquare(vector<vector<int>> s) {
  vector<vector<int>> m1 = {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}};
  vector<vector<int>> m2 = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};

  int minDiff = numeric_limits<int>::max();
  for (int i = 0; i < 4; i++) {
    rotate(m1);
    minDiff = min(minDiff, calDiff(s, m1));
  }
  for (int i = 0; i < 4; i++) {
    rotate(m2);
    minDiff = min(minDiff, calDiff(s, m2));
  }
  return minDiff;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> s(3);

  for (int i = 0; i < 3; i++) {
    s[i].resize(3);

    string s_row_temp_temp;
    getline(cin, s_row_temp_temp);

    vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

    for (int j = 0; j < 3; j++) {
      int s_row_item = stoi(s_row_temp[j]);

      s[i][j] = s_row_item;
    }
  }

  int result = formingMagicSquare(s);

  fout << result << "\n";

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
