//  2) Escreva uma função que recebe o endereço de um array de inteiros e devolve uma forward_list<int>,
//  contendo os elementos do array na mesma ordem.
//  Função: forward_list<int> vet_to_flist(int* v, int n);
//  Referência de forward_list: https://cplusplus.com/reference/forward_list/forward_list/

#include <iostream>
#include <forward_list>

std::forward_list<int> vet_to_flist(int* v, int n) {
    std::forward_list<int> flist;
    for (int i = n - 1; i >= 0; i--) {
        flist.push_front(v[i]);
    }
    return flist;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    std::forward_list<int> flist = vet_to_flist(v, 5);
    for (int i : flist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}

