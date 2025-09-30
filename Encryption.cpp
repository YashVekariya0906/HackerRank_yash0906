#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    // remove spaces
    string str = "";
    for (char c : s) {
        if (c != ' ') str += c;
    }

    int L = str.size();
    int rows = floor(sqrt(L));
    int cols = ceil(sqrt(L));
    if (rows * cols < L) rows++;

    string result = "";
    for (int c = 0; c < cols; c++) {
        string word = "";
        for (int r = 0; r < rows; r++) {
            int idx = r * cols + c;
            if (idx < L) word += str[idx];
        }
        if (!result.empty()) result += " ";
        result += word;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
