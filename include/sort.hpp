#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

/**
 * @brief Algorítimo de QuickSort implementado por mim :)
 */
class QuickSort {
public:
    /**
     * @brief Chamada do QuickSort
     * @details Para nao ser nescessario passar valores extras
     * 
     * @param nums Vetor a ser ordenado
     */
    void quick(std::vector<std::pair<char, int>>& nums);

private:
    /**
     * @brief Chamada recursiva da funcao QuickSort
     * @details Valores extras sao recebidos automaticamente
     * 
     * @param nums Vetor a ser ordenado
     * @param start Inicio (inclusivo) do bloco atual
     * @param end Fim (exclusivo) do bloco atual
     */
    void quick_rec(std::vector<std::pair<char, int>>& nums, int start, int end);
};

/**
 * @brief Facilita a chamada do QuickSort
 * @details Gosto de deixar funcoes de chamadas e sua recurcao juntas em uma classe, logo para facilitar, essa funcao chama a classe e a funcao principal
 * 
 * @param nums Vetor a ser ordenado
 */
void runQuick(std::vector<std::pair<char, int>>& nums);

/**
 * @brief Verifica se o vetor esta ordenado
 * 
 * @param nums Vetor ordenado ou nao
 * 
 * @retval @c true  -> Ordenado
 * @retval @c false -> Nao ordenado
 */
bool isOrdered(const std::vector<std::pair<char, int>>& nums);

/**
 * @brief Printa o vetor no formato: '<Char>: <Quantidade>\n'
 * 
 * @param nums Vetor no formato <pair<char, int>>
 */
void printVector(const std::vector<std::pair<char, int>>& nums);

/**
 * @brief Testa o tempo de execucao da ordenacao, e printa resultados!
 * 
 * @param alg Algoritimo de ordenação (nome da funcao)
 * @param nums Vetor a ser ordenado
 */
void testTime(void (*alg)(std::vector<std::pair<char, int>>&), std::vector<std::pair<char, int>>& nums, std::string name);

#endif