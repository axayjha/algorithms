#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> lps(string pattern) {
    int n = pattern.length();
    vector <int> result = vector<int>(n, 0);
    int i = 1, j = 0;
    while (i < n) {
        if (pattern[i] == pattern[j]) {
            j++;
            result[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = result[j-1];
            } else {
                result[i] = 0;
                i++;
            }
        }
    }
    return result;
}

int kmp(string str, string pattern) {
    int count = 0;
    int n = str.length(), m = pattern.length();
    int i = 0, j = 0;
    vector<int> pi = lps(pattern);
    while (i < n) {
        if (str[i] == pattern[j]) {
            j++;
            i++;
        } 
        if (j == m) {
            count++;
            j = pi[j-1];
        } 
        else if (i < n && str[i] != pattern[j]) {
            if (j != 0) {
                j = pi[j-1];
            } else {
                j = 0;
                i++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector <int> pi = lps("abaaba");
    for (int i : pi) {
        cout << i << " ";
    }
    cout << endl;
    cout << kmp("akshayabababa", "aba") << endl;

    return 0;
}
