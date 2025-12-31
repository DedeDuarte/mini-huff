#include <iostream>
#include <vector>
#include <string>

#include "chars.hpp"
#include "sort.hpp"
#include "huff.hpp"

using namespace std;

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    string file = argc == 2 ? argv[1] : "test/text.txt";
    vector<std::pair<char, int>> chars = getChars(file);

    printVector(chars);
    cout << (isOrdered(chars) ? "Ordenado" : "Nao ordenado") << endl;

    cout << "Criando arvore" << endl;

    HuffTree* huff = new HuffTree();
    for (auto c : chars)
        huff->newLetter(c.first);
    
    // CONTINUE Tecnicamente essa arvore está degenerada, mas vai funcionar por enquanto
    // CONTINUE Fazer a conversão para 0's e 1's
    huff->printTree();

    delete huff;

    return 0;
}
