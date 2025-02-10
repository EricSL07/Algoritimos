//  6) Escreva uma função que recebe uma expressão pós-fixada (notação Polonesa Inversa) como uma
//  string e devolve um vector<string> contendo cada elemento da expressão. Note que existe um
//  caractere de espaço entre cada elemento da expressão e que os números podem ser compostos por
//  mais de um dígito. Utilize os recursos sugeridos da biblioteca padrão de C++.
//  Função: vector<string> vectorize_expression(string expression);
//  Exemplo: entrada: "24 32 + 2 / 41 5 * +"
//  saída:
//  vector<string> = {24, 32, +, 2, /, 41, 5, *, +}
//  Recursos:
//  ● expressão posfix (Polonesa Inversa): https://en.wikipedia.org/wiki/Reverse_Polish_notation
//  ○ considere operandos naturais e as quatro operações: * / + -

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> vectorize_expression(std::string expression) {
    std::vector<std::string> vec;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        vec.push_back(token);
    }
    return vec;
}

int main() {
    std::string expression = "24 32 + 2 / 41 5 * +";
    std::vector<std::string> vec = vectorize_expression(expression);
    for (std::string& s : vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}