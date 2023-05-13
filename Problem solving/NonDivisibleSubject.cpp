#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    int a[k];
    vector<int> vec;
    //create a vector with only remainders
    for (int x: s){
        vec.push_back(x%k);
    }
    //create a vector with all the possible remainders
    for (int x;x<k;x++){
        a[x] = 0;
    }
    //counting number of available numbers giving the same remainder
    for(int x:vec){
        a[x]=a[x]+1;
    }
    //check k even or odd
    bool even = true;
    if(k%2==1){
        even = false;
    }
    int length=0;
    
    //when k even
    if(even){
        //only 1 added from the number in middle
        if(a[k/2]>0){
            length++;
        }

        //starting from middle checking numbers in left and right and adding the highest
        for(int x=1;x<k/2;x++){
            int left = a[k/2-x];
            int right = a[k/2+x];
            if(left>right){
                length += left;
            }
            else{
                length += right;
            }
        }
    }

    //when k odd
    else{
        //starting from middle and extending to both sides and adding the highest
        for(int x=0;x<k/2;x++){
            int left = a[k/2-x];
            int right = a[k/2+1+x];
            if(left>right){
                length += left;
            }
            else{
                length += right;
            }
        }
    }

    //considering numbers divisable by k
    if(a[0]>0){
        length++;
    }

    //returning value
    return length;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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
