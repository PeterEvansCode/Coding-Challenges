#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

unsigned long int sum(vector<int> arr);
unsigned long int getMin(vector<int> arr);
unsigned long int getMax(vector<int> arr);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    unsigned long int total = sum(arr);
    unsigned long int minSum = total - getMax(arr);
    unsigned long int maxSum = total - getMin(arr);
    
    cout << minSum << " " << maxSum << endl;
}

unsigned long int sum(vector<int> arr){
    unsigned long int total = 0;
    for (int i = 0; i < arr.size(); i++){
        total += arr[i];
    }
    
    return total;
}

unsigned long int getMax(vector<int> arr){
    unsigned long int max = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] > max) max = arr[i];
    }
    
    return max;
}

unsigned long int getMin(vector<int> arr){
    unsigned long int min = numeric_limits<unsigned long int>::max();
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] < min) min = arr[i];
    }
    
    return min;
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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
