// 5) Escreva uma função que verifica a parentização de expressões string infix do tipo “[(x + 8) * (9-2)]”.
//  Utilize uma pilha stack<char> para realizar o processo:
//  ● percorrer a expressão de entrada
//  ● aoencontrar um símbolo "abre", ( [ { , empilha
//  ● aoencontrar um símbolo "fecha", ) ] }, retira o símbolo do tipo "abre" do topo e compara ambos
//  o seo"abre" e o "fecha" correspondem, continua
//  o sediferem, então a expressão está incorreta
//  o seapilha estiver vazia, a expressão está incorreta
//  ● aoterminar de percorrer a expressão de entrada, a pilha deve estar vazia
//  o serestou algum símbolo na pilha, então a expressão está incorreta
//  Função: bool check_brackets(string expression)

#include <iostream>
#include <stack>
#include <string>

bool check_brackets(std::string expression) {
    std::stack<char> stack;
    for (char& c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string expression = "[(x + 8) * (9-2)]";
    std::cout << check_brackets(expression) << std::endl;
    return 0;
}