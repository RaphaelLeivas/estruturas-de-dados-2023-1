#include "../include/NumExp.hpp"

NumExp::NumExp(std::string exp) {
    this->exp = exp;
    this->size = exp.length();
}

NumExp::~NumExp() {}

void NumExp::print() { std::cout << this->exp << std::endl; }

float NumExp::computeExpression() {
    Stack* stack = new Stack(this->size);

    std::istringstream iss(this->exp);
    std::string item;
    char delimiter = ' ';

    while (std::getline(iss, item, delimiter)) {
        // remove caracteres especiais da string
        item = std::regex_replace(item, std::regex("\r"), "");
        item = std::regex_replace(item, std::regex("\n"), "");

        if (this->isOperator(item)) {
            // se é operador, puxa os dois ultimos da stack
            float num2 = stack->pop();
            float num1 = stack->pop();

            // calcula a operação
            char op = item[0];
            float operationResult = this->computeOperation(op, num1, num2);

            // salva na stack o resultado da operação
            stack->push(operationResult);
        } else {
            // se não é operador, é um número e puxa ele para a stack
            stack->push(std::stof(item));
        }
    }

    // a ultima coisa que sobrou na stack é o resultado da expressão
    float expressionResult = stack->pop();
    delete stack;

    return expressionResult;
}

bool NumExp::isOperator(std::string op) {
    if (op == "+" || op == "-" || op == "x" || op == "/") {
        return true;
    } else {
        return false;
    }
}

float NumExp::computeOperation(char op, float num1, float num2) {
    switch (op) {
        case '+': {
            return num1 + num2;
            break;
        }
        case '-': {
            return num1 - num2;
            break;
        }
        case 'x': {
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