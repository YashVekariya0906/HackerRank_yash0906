#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    // Extract AM/PM
    string meridian = s.substr(8, 2);
    // Extract hour part
    int hour = stoi(s.substr(0, 2));
    
    if (meridian == "AM") {
        if (hour == 12) {
            hour = 0; // midnight case
        }
    } else { // PM
        if (hour != 12) {
            hour += 12;
        }
    }
    
    // Format hour to 2 digits
    stringstream ss;
    ss << setw(2) << setfill('0') << hour;
    
    // Build final time in 24-hour format
    return ss.str() + s.substr(2, 6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
