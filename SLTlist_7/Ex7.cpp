// 7) Escreva uma função que calcula e devolve o resultado de expressões posfix usando os recursos da
//  biblioteca padrão de C/C++. Considere que sempre existe um espaço entre os elementos da
//  expressão e que os números são inteiros positivos e podem ser formados por mais de um algarismo.
//  Operações possíveis: +- * /. É necessário usar uma pilha para os operandos (stack<float>).
//  Recursos:
//  ● isdigit(): verifica se caractere é um dígito (número)
//  ○ http://www.cplusplus.com/reference/cctype/isdigit/
//  ● stoi(): converte string C++ para número (http://www.cplusplus.com/reference/string/stoi/)
//  Processo:
//  ● Transforme a expressão string em um vector<string>. Desta forma, cada símbolo (operador ou
//  operando) estará em uma posição do vector.
//  ● Varrer a expressão no vector:
//  ▪ Quandoencontra um número na expressão, empilha (stack<float>).
//  ▪ Quando encontra um operador na expressão, retira dois elementos da pilha, executa a
//  operação e empilha resultado (a ordem dos operandos deve ser considerada na
//  execução da operação);
//  ▪ Quandoterminar de percorrer a expressão, o resultado estará no topo da pilha
//  Função: float calc_posfix(string expression);

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> vectorize_expression(std::string expression) {
    std::vector<std::string> vec;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        vec.push_back(token);
    }
    return vec;
}

float calc_posfix(std::string expression) {
    std::stack<float> stack;
    std::vector<std::string> vec = vectorize_expression(expression);
    for (std::string& token : vec) {
        if (isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else {
            float op2 = stack.top();
            stack.pop();
            float op1 = stack.top();
            stack.pop();
            if (token == "+") {
                stack.push(op1 + op2);
            } else if (token == "-") {
                stack.push(op1 - op2);
            } else if (token == "*") {
                stack.push(op1 * op2);
            } else if (token == "/") {
                stack.push(op1 / op2);
            }
        }
    }
    return stack.top();
}

int main() {
    std::string expression = "24 32 + 2 / 41 5 * +";
    std::cout << calc_posfix(expression) << std::endl;
    return 0;
}