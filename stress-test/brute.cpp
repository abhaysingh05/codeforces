#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Helper function to generate all subsequences with unique elements
void generateUniqueSubsequences(const vector<int>& a, int index, vector<int>& current, set<int>& used, vector<vector<int>>& allSubsequences) {
    if (index == a.size()) {
        if (!current.empty()) {
            allSubsequences.push_back(current);
        }
        return;
    }

    // Option 1: Include the current element if it has not been used
    if (used.find(a[index]) == used.end()) {
        current.push_back(a[index]);
        used.insert(a[index]);
        generateUniqueSubsequences(a, index + 1, current, used, allSubsequences);
        current.pop_back();
        used.erase(a[index]);
    }

    // Option 2: Exclude the current element
    generateUniqueSubsequences(a, index + 1, current, used, allSubsequences);
}

// Comparator function to compare two subsequences after applying the -1 multiplication on odd positions
bool compareSubsequences(const vector<int>& a, const vector<int>& b) {
    int len = min(a.size(), b.size());
    for (int i = 0; i < len; ++i) {
        int valA = (i % 2 == 0) ? -a[i] : a[i];
        int valB = (i % 2 == 0) ? -b[i] : b[i];
        if (valA != valB) return valA < valB;
    }
    return a.size() < b.size();  // If they are equal up to len, the shorter one is considered smaller
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> allSubsequences;
        vector<int> current;
        set<int> used;

        // Generate all subsequences with unique elements
        generateUniqueSubsequences(a, 0, current, used, allSubsequences);

        // Find the maximum length of subsequences
        int maxLength = 0;
        for (const auto& subseq : allSubsequences) {
            if (subseq.size() > maxLength) {
                maxLength = subseq.size();
            }
        }

        // Collect all subsequences of maximum length
        vector<vector<int>> maxLenSubsequences;
        for (const auto& subseq : allSubsequences) {
            if (subseq.size() == maxLength) {
                maxLenSubsequences.push_back(subseq);
            }
        }

        // Find the lexicographically smallest sequence after applying the transformation
        vector<int> result = maxLenSubsequences[0];
        for (const auto& subseq : maxLenSubsequences) {
            if (compareSubsequences(subseq, result)) {
                result = subseq;
            }
        }

        // Output the result
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
