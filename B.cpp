#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if a substring can be repeated to form the original string with at most one difference
bool canFormString(const string& s, const string& sub) {
    int n = s.size(), m = sub.size();
    int diffCount = 0; // Count the number of differences
    for (int i = 0; i < n; i++) {
        if (diffCount > 1) {
            return false; // More than one difference found, not valid
        }
        if (s[i] != sub[i % m]) { // Check for difference
            diffCount++;
        }
    }
    return diffCount <= 1; // Valid if at most one difference found
}

// Function to find the shortest repeating substring
string findShortestRepeatingSubstring(const string& s) {
    int n = s.size();
    // Iterate through all possible substring lengths (from longest to shortest)
    for (int len = n; len >= 1; len--) {
        // Check all possible substrings of length 'len'
        for (int i = 0; i <= n - len; i++) {
            string sub = s.substr(i, len); // Extract substring
            if (canFormString(s, sub)) {
                return sub; // Shortest valid substring found, return it
            }
        }
    }
    return ""; // No valid substring found
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        string result = findShortestRepeatingSubstring(s);
        if (result.empty()) {
            cout << "NO" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}