// 8) Escreva uma função que verifica a corretude de uma expressão posfix. Para tanto, modifique a lógica
//  da função do exercício anterior para que o processo ocorra da seguinte forma:
//  ● Quandoencontra um número na expressão, empilha
//  ● Quandoencontra um operador na expressão, deve haver ao menos dois números na pilha
//  o retira apenas um número da pilha e prossegue na varredura da expressão
//  ● Quantoterminar de percorrer a expressão, deverá haver exatamente um número na pilha
//  Função: bool check_posfix(string expression)

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

bool check_posfix(std::string expression) {
    std::stack<float> stack;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                return false;
            }
            stack.pop();
        } else {
            stack.push(std::stof(token));
        }
    }
    return stack.size() == 1;
}

int main() {
    std::string expression = "24 32 + 2 / 41 5 * +";
    std::cout << check_posfix(expression) << std::endl;
    return 0;
}

