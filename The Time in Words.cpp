#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string timeInWords(int h, int m) {
    vector<string> numbers = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen",
        "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
        "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"
    };

    if (m == 0)
        return numbers[h] + " o' clock";
    else if (m == 15)
        return "quarter past " + numbers[h];
    else if (m == 30)
        return "half past " + numbers[h];
    else if (m == 45)
        return "quarter to " + numbers[h + 1];
    else if (m < 30)
        return numbers[m] + (m == 1 ? " minute past " : " minutes past ") + numbers[h];
    else
        return numbers[60 - m] + (60 - m == 1 ? " minute to " : " minutes to ") + numbers[h + 1];
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);
    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);
    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
