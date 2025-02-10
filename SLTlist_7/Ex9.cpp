//  9) Escreva uma calculadora de expressões infix parentizada: ( ( ( 6 + 9 ) / 3 ) * ( 6- 4) )
//  ● Considere que sempre existe um espaço entre os elementos da expressão e que ela está
//  completamente parentizada para informar a ordem de precedência das operações.
//  ● Sãonecessárias duas pilhas: operadores (stack <char>) e operandos (stack <float>)).
//  ● Utilize novamente os recursos da biblioteca C/C++ para facilitar a construção do programa.
//  ● Paraavaliar a expressão deve-se seguir o processo abaixo:
//  o Quandoumoperando (número) é lido, ele é colocado na pilha de operandos.
//  o Quantoumparêntese esquerdo é lido "(", ele é colocado na pilha de operadores.
//  o Quando um dos quatro operadores é lido, ele é colocado na pilha de operadores caso
//  tenha maior precedência sobre o operador que está no topo da pilha ou topo seja “(“.
//  ▪ Caso contrário, deve calcular a expressão empilhada: retirar dois números da
//  pilha de operandos e o operador da outra pilha. Calcular a expressão e colocar o
//  resultado na pilha de operandos.
//  o Quando umparêntese direito é lido ")", deve calcular a expressão empilhada seguindo o
//  processo mencionado acima, colocando o resultado na pilha de operandos. Este
//  processo é repetido até que o topo da pilha de operadores contenha um parêntese
//  esquerdo "(", que deverá ser removido.
//  Função: float calc_infix(string expression);

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

float calc_infix(std::string expression) {
    std::stack<char> operators;
    std::stack<float> operands;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            operators.push(token[0]);
        } else if (token == "(") {
            operators.push(token[0]);
        } else if (token == ")") {
            while (operators.top() != '(') {
                float op2 = operands.top();
                operands.pop();
                float op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                if (op == '+') {
                    operands.push(op1 + op2);
                } else if (op == '-') {
                    operands.push(op1 - op2);
                } else if (op == '*') {
                    operands.push(op1 * op2);
                } else if (op == '/') {
                    operands.push(op1 / op2);
                }
            }
            operators.pop();
        } else {
            operands.push(std::stof(token));
        }
    }
    while (!operators.empty()) {
        float op2 = operands.top();
        operands.pop();
        float op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        if (op == '+') {
            operands.push(op1 + op2);
        } else if (op == '-') {
            operands.push(op1 - op2);
        } else if (op == '*') {
            operands.push(op1 * op2);
        } else if (op == '/') {
            operands.push(op1 / op2);
        }
    }
    return operands.top();
}

int main() {
    std::string expression = "( ( ( 6 + 9 ) / 3 ) * ( 6 - 4 ) )";
    std::cout << calc_infix(expression) << std::endl;
    return 0;
}

