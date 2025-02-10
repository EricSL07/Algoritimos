//  10)Escreva um conversor de expressões posfix para infix, usando uma versão modificada da calculadora
//  posfix. Exemplo: 6 9 + 3 / 6 4- * → ( ( ( 6 + 9 ) / 3 ) * ( 6- 4 ) )
//  ● Utilize uma pilha de strings (stack<string>) para guardar as expressões na forma infix.
//  ● Utilize os recursos da biblioteca C/C++ para facilitar a construção do programa.
//  ● Paraavaliar a expressão deve-se seguir o processo abaixo:
//  o Quandoumnúmero(operando) é lido, ele é colocado na pilha.
//  o Quando um operador é lido, deve montar a expressão infix com os dois operandos
//  previamente empilhados: retira dois topos da pilha e monta expressão (string) na forma:
//  ( topo operador topo ). Empilha a expressão infix na pilha.
//  ● Aofinal da expressão, a pilha deverá conter um único elemento, com a expressão completa na
//  forma infix.
//  Função: string posfix_to_infix(string expression)

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

std::string posfix_to_infix(std::string expression) {
    std::stack<std::string> stack;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            std::string op2 = stack.top();
            stack.pop();
            std::string op1 = stack.top();
            stack.pop();
            std::string infix = "(" + op1 + " " + token + " " + op2 + ")";
            stack.push(infix);
        } else {
            stack.push(token);
        }
    }
    return stack.top();
}

int main() {
    std::string expression = "6 9 + 3 / 6 4 - *";
    std::string infix = posfix_to_infix(expression);
    std::cout << infix << std::endl;
    return 0;
}
