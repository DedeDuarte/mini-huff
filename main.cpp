#include <iostream>
#include <vector>
#include <string>

#include "chars.hpp"
#include "sort.hpp"

using namespace std;

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    vector<std::pair<char, int>> chars = getChars("test/cr7.txt");

    printVector(chars);
    cout << (isOrdered(chars) ? "Ordenado" : "Nao ordenado") << endl;

    return 0;
}
