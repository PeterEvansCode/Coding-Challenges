#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hour = stoi(s.substr(0, 2));
    char meridiem = s[8];

    // Convert hour based on AM/PM
    if (meridiem == 'P' && hour != 12) hour += 12;
    else if (meridiem == 'A' && hour == 12) hour = 0;

    // Create formatted time in 24-hour format
    ostringstream oss;
    oss << setw(2) << setfill('0') << hour << s.substr(2,6);
    
    return oss.str();
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
