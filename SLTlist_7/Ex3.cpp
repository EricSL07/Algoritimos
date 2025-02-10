//  3) Escreva uma função que recebe o endereço de um array de inteiros e devolve uma stack<int>,
//  contendo os elementos do array na mesma ordem.
//  Função: stack<int> vet_to_stack(int v*, int n);
//  Referência de stack: http://www.cplusplus.com/reference/stack/stack

#include <iostream>
#include <stack>

std::stack<int> vet_to_stack(int v[], int n) {
    std::stack<int> stack;
    for (int i = 0; i < n; i++) {
        stack.push(v[i]);
    }
    return stack;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    std::stack<int> stack = vet_to_stack(v, 5);
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
    return 0;
}