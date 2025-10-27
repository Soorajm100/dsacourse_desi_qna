#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


vector<int> calculateKadanePrefixMaxSum(const vector<int>& nums) {
    int n = nums.size() - 1; // because 1-indexed
    vector<int> prefixMax(n + 1, 0);
    int currentMax = nums[1];
    prefixMax[1] = nums[1];

    for (int i = 2; i <= n; i++) {
        currentMax = max({0, nums[i], currentMax + nums[i]});
        prefixMax[i] = currentMax;
    }
    return prefixMax;
}

vector<int> calculateKadaneSuffixMax(const vector<int>& nums) {
    int n = nums.size() - 1;
    vector<int> suffixMax(n + 2, 0);
    int currentMax = nums[n];
    suffixMax[n] = nums[n];

    for (int i = n - 1; i >= 1; i--) {
        currentMax = max({0, nums[i], currentMax + nums[i]});
        suffixMax[i] = currentMax;
    }
    return suffixMax;
}

int calculateMaxSum(vector<int>& a) {
    int n = a.size() - 1;

    // Step 1: get prefix and suffix Kadane results
    vector<int> prefixMax = calculateKadanePrefixMaxSum(a);
    vector<int> suffixMax = calculateKadaneSuffixMax(a);

    // Step 2: compute running maximums
    vector<int> maxPrefixSum(n + 2, 0);
    vector<int> maxSuffixSum(n + 2, 0);

    maxPrefixSum[1] = prefixMax[1];
    for (int i = 2; i <= n; i++) {
        maxPrefixSum[i] = max(maxPrefixSum[i - 1], prefixMax[i]);
    }

    maxSuffixSum[n] = suffixMax[n];
    for (int i = n - 1; i >= 1; i--) {
        maxSuffixSum[i] = max(maxSuffixSum[i + 1], suffixMax[i]);
    }

    // Step 3: find maximum non-overlapping sum
    int G = 0;
    for (int parititon = 1; parititon < n; parititon++) {
        G = max(G, maxPrefixSum[parititon] + maxSuffixSum[parititon + 1]);
    }

    return G;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << "The maximum sum of two non-overlapping subarrays: "
         << calculateMaxSum(a) << endl;
    return 0;
}
