#include "../include/NumExp.hpp"

NumExp::NumExp(std::string exp, ExpType expType) {
    this->exp = exp;
    this->expType = expType;
    this->size = exp.length();
}

NumExp::~NumExp() {}

void NumExp::print() { std::cout << this->exp << std::endl; }

void NumExp::setExpType(ExpType expType) { this->expType = expType; }
void NumExp::setExp(std::string exp) { this->exp = exp; }

// converte o salvo em this->exp para infixa
void NumExp::convertToInfix() {
    if (this->expType == ExpType::INFIX) {
        return;
    }

    std::string currentExp = this->exp;
    std::string convertedExp = this->getInfix(currentExp);
    this->setExp(convertedExp);
    this->setExpType(ExpType::INFIX);
}

// converte o salvo em this->exp para posfixa
void NumExp::convertToPostfix() {
    if (this->expType == ExpType::POSTFIX) {
        return;
    }

    std::string currentExp = this->exp;
    std::string convertedExp = this->getPostfix(currentExp);
    this->setExp(convertedExp);
    this->setExpType(ExpType::POSTFIX);
}

double NumExp::computeExpression() {
    std::string expressionToCompute;

    if (this->expType == ExpType::INFIX) {
        expressionToCompute = this->getPostfix(this->exp);
    } else {
        expressionToCompute = this->exp;
    }

    // calcula a expressao via algoritmo de posfixa, que é mais simples
    Stack<double>* stack = new Stack<double>(this->size);

    std::istringstream iss(expressionToCompute);
    std::string item;
    char delimiter = ' ';

    while (std::getline(iss, item, delimiter)) {
        // protecao espaços duplos
        if (item == "" || item == " ") {
            continue;
        }

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

// converte a string argumento para posfixa, e retorna essa nova string
std::string NumExp::getPostfix(std::string expression) {
    Stack<std::string>* stack = new Stack<std::string>(this->size);

    std::istringstream iss(expression);
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
    return result;
}

// converte a string argumento para infixa, e retorna essa nova string
std::string NumExp::getInfix(std::string expression) {
    Stack<std::string>* stack = new Stack<std::string>(this->size);

    std::istringstream iss(expression);
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
    return result;
}

bool NumExp::isValid() {
    // a expressao so é valida se ela conseguir calcular um numero

    // seria melhor ver um algortimo que verifique a string em vez de calcular,
    // pois assim vou estar calculando a string inteira a toa, sem salvar e sem
    // o usuario pedir

    // faz calculando direto mesmo, para nao gastar muito tempo

    // na consigo diferenciar infixa invalida de posfixa valida
    // ex: 3 4 + é valida posfixa, mas invalida infixa: melhorar no futuro

    bool isValid = true;

    try {
       this->computeExpression();
    }
    catch(...) {
        isValid = false;
    }
    
    return isValid;
}

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