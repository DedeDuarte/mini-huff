#ifndef CHARS_H
#define CHARS_H

#include <unordered_map>
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief Conta e ordena quais e a qauntidade de cada caracter presente em @c file_name
 * 
 * @param file_name Nome do arquivo a ser lido
 * 
 * @return Vetor no formato '<Char> <Quantidade>' (<pair<char, int>>)
 */
std::vector<std::pair<char, int>> getChars(const std::string& file_name);

/**
 * @brief Conta a quantidade de caracteres em um @c file . Nao ordenado
 * 
 * @param file @c ifstream(ios::binary) do arquivo desejado
 * @param chars Mapa onde estara a contagem os caracteres
 */
void countChars(std::ifstream& file, std::unordered_map<char, int>& chars);

#endif