#include "chars.hpp"
#include "sort.hpp"

using namespace std;

vector<pair<char, int>> getChars(const string& file_name) {
    ifstream file(file_name, ios::binary);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    unordered_map<char, int> chars;

    countChars(file, chars);

    vector<pair<char, int>> chars_sorted(chars.begin(), chars.end());
    
    runQuick(chars_sorted);
    return chars_sorted;
}

void countChars(ifstream& file, unordered_map<char, int>& chars) {
    char c;
    short tab = 0;
    while (file.get(c)) {
        if (!(c == ' ')) {
            if (chars.find(' ') != chars.end()) chars[' '] += tab;
            tab = 0;

            chars[c]++;
            continue;
        }

        if (++tab == 4) {
            tab = 0;
            chars['\t']++;
        }
    }
}