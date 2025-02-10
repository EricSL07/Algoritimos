//  Instruções Gerais
//  ● Implemente os exercícios em C++ (extensão cpp e compilador g++).
//  ● Aofinal, envie o arquivo main.cpp pelo Moodle.
//  ● Asbibliotecas necessárias são: <iostream>, <vector>, <forward_list>, <stack> e <queue>.
//  1) Escreva uma função que recebe o endereço de um array de inteiros e devolve um vector<int>,
//  contendo os elementos do array na mesma ordem.
//  Função: vector<int> vet_to_vector(int v*, int n);
//  Referência de vector: http://www.cplusplus.com/reference/vector/vector/

#include <iostream>
#include <vector>

std::vector<int> vet_to_vector(int v[], int n) {
    std::vector<int> vec;
    for (int i = 0; i < n; i++) {
        vec.push_back(v[i]);
    }
    return vec;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    std::vector<int> vec = vet_to_vector(v, 5);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}