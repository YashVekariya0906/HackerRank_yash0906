#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'circularArrayRotation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER k
 *  3. INTEGER_ARRAY queries
 */

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int n = a.size();
    k = k % n; // Handle large k

    // Rotate array by k steps
    vector<int> rotated(n);
    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = a[i];
    }

    // Answer queries
    vector<int> result;
    for (int q : queries) {
        result.push_back(rotated[q]);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int k = stoi(first_multiple_input[1]);
    int q = stoi(first_multiple_input[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = stoi(a_temp[i]);
    }

    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);
        queries[i] = stoi(ltrim(rtrim(queries_item_temp)));
    }

    vector<int> result = circularArrayRotation(a, k, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i] << "\n";
    }

    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); }));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0, end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
