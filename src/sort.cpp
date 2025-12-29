#include "sort.hpp"

using namespace std;

void QuickSort::quick(vector<pair<char, int>>& nums) {
    quick_rec(nums, 0, nums.size());
}

void QuickSort::quick_rec(vector<pair<char, int>>& nums, int start, int end) {
    if (end - start <= 1) return;

    int pv = nums[end-1].second;    // Pivô
    int sw = start-1;               // Swap

    for (int i = start; i < end; i++)
        if (nums[i].second >= pv && ++sw < i) swap(nums[i], nums[sw]);

    quick_rec(nums, start, sw);
    quick_rec(nums, sw+1, end);
}

void runQuick(vector<pair<char, int>>& nums) {
    QuickSort q;

    q.quick(nums);
}

bool isOrdered(const vector<pair<char, int>>& nums) {
    int nums_size = nums.size();
    for (int i = 0; i < nums_size-1; i++)
        if (nums[i].second < nums[i+1].second) return false;
    return true;
}

void printVector(const vector<pair<char, int>>& nums) {
    for (auto num : nums) {
        string s = string(1, num.first);
        s.push_back(' ');

        if (s == "  ")  s = "sp";
        if (s == "\n ") s = "\\n";
        if (s == "\t ") s = "\\t";

        cout << s << " (" << num.second << ')' << '\n';
    }
    cout << endl;
}

void testTime(void (*alg)(vector<pair<char, int>>&), vector<pair<char, int>>& nums, string name) {
    cout << name << " started " << (isOrdered(nums) ? "" : "not ") << "sotred." << endl;
    auto start = chrono::high_resolution_clock::now();
    alg(nums);
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << name << " ended " << (isOrdered(nums) ? "" : "not ") <<  "sorted.\n"
         << duration.count() << "ms execution\n" << endl;
}