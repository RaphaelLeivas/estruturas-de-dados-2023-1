#include "../include/NumExp.hpp"

NumExp::NumExp(std::string exp) {
    this->exp = exp;
    this->size = exp.length();
}

NumExp::~NumExp() {}

void NumExp::print() { std::cout << this->exp << std::endl; }

double NumExp::computeExpression() {
    Stack<double>* stack = new Stack<double>(this->size);

    std::istringstream iss(this->exp);
    std::string item;
    char delimiter = ' ';

    while (std::getline(iss, item, delimiter)) {
        // protecao espaços duplos
        if (item == "" || item == " ") {
            continue;
        }

        // remove caracteres especiais da string
        // item = std::regex_replace(item, std::regex("\r"), "");
        // item = std::regex_replace(item, std::regex("\n"), "");

        if (this->isOperator(item)) {
            // se é operador, puxa os dois ultimos da stack
            double num2 = stack->pop();
            double num1 = stack->pop();

            // calcula a operação
            char op = item[0];
            double operationResult = this->computeOperation(op, num1, num2);

            // salva na stack o resultado da operação
            stack->push(operationResult);
        } else {
            // se não é operador, é um número e puxa ele para a stack
            // std::cout << item << std::endl;
            stack->push(std::stof(item));
        }
    }

    // a ultima coisa que sobrou na stack é o resultado da expressão
    double expressionResult = stack->pop();
    delete stack;

    return expressionResult;
}

// converte o salvo em exp para pos-fixa
// assumindo que o que esta salvo em exp é infixa
void NumExp::toPostfix() {
    Stack<std::string>* stack = new Stack<std::string>(this->size);

    std::istringstream iss(this->exp);
    std::string item;
    std::string result;
    char delimiter = ' ';

    while (std::getline(iss, item, delimiter)) {
        // protecao espaços duplos
        if (item == "" || item == " ") {
            continue;
        }

        if (item == ")") {
            std::string op;

            while (!stack->isEmpty()) {
                // vai puxando operadores da stack e joga para o resultado
                // ate chegar em um abre parenteses
                op = stack->pop();

                if (op == "(") {
                    break;
                }

                result.append(op + " ");
            }
        } else if (item == "(") {
            // se é abre parenteses joga ele para a stack
            stack->push(item);
        } else if (this->isOperator(item)) {
            if (stack->isEmpty()) {
                stack->push(item);
                continue;
            }

            // se é operador, olha quem esta no topo
            std::string topOperator = stack->pop();

            // se o topo da stack tem abre parenteses, puxa o operador para a
            // stack
            if (topOperator == "(") {
                stack->push(topOperator);
                stack->push(item);
                continue;
            }

            // se tem precedencia maior que o topo
            if ((item == "*" || item == "/") &&
                (topOperator == "+" || topOperator == "-")) {
                // salva na stack com precedencia sobre o topo
                stack->push(topOperator);
                stack->push(item);
            } else {  // se tem precendencia menor ou igual ao operador do topo
                // joga direto para a string o operador do topo
                stack->push(item);
                result.append(topOperator + " ");
            }
        } else {
            // se não é operador, nem parenteses, é um número e
            // joga ele para a string resultado
            result.append(item + " ");
        }
    }

    // vai tirando o que sobrou na stack e jogando na string resultado
    while (!stack->isEmpty()) {
        std::string op = stack->pop();
        result.append(op + " ");
    }

    delete stack;
    this->exp = result;

    return;
}

// converte o salvo em exp para iofixa
// assumindo que o que esta salvo em exp é posfixa valida
void NumExp::toInfix() {
    Stack<std::string>* stack = new Stack<std::string>(this->size);

    std::istringstream iss(this->exp);
    std::string item;
    char delimiter = ' ';

    while (std::getline(iss, item, delimiter)) {
        // protecao espaços duplos
        if (item == "" || item == " ") {
            continue;
        }

        if (this->isOperator(item)) {
            // puxa os dois ultimos numeros da stack
            std::string num1 = stack->pop();
            std::string num2 = stack->pop();

            // monta expressao infixa com parenteses
            std::string expression =
                "( " + num2 + " " + item + " " + num1 + " )";

            // salva a expressao na stack
            stack->push(expression);
        } else {
            // é um numero: joga para a stack
            stack->push(item);
        }
    }

    // ao final, o que restou na stack é a string resultado inteira
    std::string result = stack->pop();

    delete stack;
    this->exp = result;

    return;
}

// bool NumExp::isValid() {
    
// }

bool NumExp::isOperator(std::string op) {
    if (op == "+" || op == "-" || op == "*" || op == "/") {
        return true;
    } else {
        return false;
    }
}

double NumExp::computeOperation(char op, double num1, double num2) {
    switch (op) {
        case '+': {
            return num1 + num2;
            break;
        }
        case '-': {
            return num1 - num2;
            break;
        }
        case '*': {
            return num1 * num2;
            break;
        }
        case '/': {
            return num1 / num2;
            break;
        }
        default: {
            throw std::invalid_argument(
                "Invalid operator sent to computeOperation");
        }
    }
}