//  4) Escreva uma função que recebe a referência de duas forward_list<int> e concatena seus conteúdos
//  emumvector<int>, a ser devolvido pelo função.
//  Função: vector<int> list_concat(forward_list& list1, forward_list& list2);
//  Exemplo de uso:
//  forward_list<int> f1 = {1,2,3,4};
//  forward_list<int> f2 = {5,6};
//  vector<int> vec = list_concat(f1, f2);
//  // vec = {1,2,3,4,5,6}

#include <iostream>
#include <vector>
#include <forward_list>

std::vector<int> list_concat(std::forward_list<int>& list1, std::forward_list<int>& list2){
    std::vector<int> vec;
    for (int& item : list1) {
        vec.push_back(item);
    }
    for (int& item : list2) {
        vec.push_back(item);
    }
    return vec;
}
int main() {
    std::forward_list<int> list1 = {1, 2, 3, 4};
    std::forward_list<int> list2 = {5, 6};

    std::vector<int> vec = list_concat(list1, list2);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}