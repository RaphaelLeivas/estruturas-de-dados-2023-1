#include "../include/NumSolver.hpp"

NumSolver::NumSolver() { this->savedExp = NULL; };

NumSolver::~NumSolver() {
    if (this->savedExp != NULL) {
        delete this->savedExp;
    }
}

void NumSolver::printSavedExp() { this->savedExp->print(); }
NumExp* NumSolver::getSavedExp() { return this->savedExp; }
void NumSolver::setSavedExp(NumExp* exp) { this->savedExp = exp; };

std::string NumSolver::parseCommandFromLine(std::string* line) {
    std::string command;

    // encontra a posicao do primeiro espaço
    unsigned int index = line->find(" ");

    if (index != std::string::npos) {
        command = line->substr(0, index);

        // remove o comando da linha
        line->erase(0, index);
    } else {
        // nesse caso, o comando é a linha inteira
        command = *line;
    }

    return command;
}

void NumSolver::save(std::string line) {
    // verifica se precisa ler infixa ou posfixa
    if (line.find(INPUT_INFIX_COMMAND) != std::string::npos) {
        // remove o comando da linha
        int index = line.find(INPUT_INFIX_COMMAND);
        line.erase(index, INPUT_INFIX_COMMAND.length() + 1);

        // gera uma expressao
        NumExp* numExp = new NumExp(line, ExpType::INFIX);

        // se for valida, salva
        if (numExp->isValid()) {
            this->setSavedExp(numExp);
        }
    } else if (line.find(INPUT_POSTFIX_COMMAND) != std::string::npos) {
        // remove o comando da linha
        int index = line.find(INPUT_POSTFIX_COMMAND);
        line.erase(index, INPUT_POSTFIX_COMMAND.length() + 1);

        // gera uma expressao
        NumExp* numExp = new NumExp(line, ExpType::POSTFIX);

        // se for valida, salva
        if (numExp->isValid()) {
            this->setSavedExp(numExp);
        }
    }
}

void NumSolver::convertToInfix() {
    if (this->getSavedExp() == NULL ||
        this->savedExp->getExpType() == ExpType::INFIX) {
        return;
    }

    // converte para infixa
    this->getSavedExp()->toInfix();
}

void NumSolver::convertToPostfix() {
    if (this->getSavedExp() == NULL ||
        this->savedExp->getExpType() == ExpType::POSTFIX) {
        return;
    }

    // converte para posfixa
    this->getSavedExp()->toPostfix();
}

double NumSolver::solve() {
    if (this->getSavedExp() == NULL) {
        throw std::invalid_argument(
            "Unable to solve expression: savedExp is null!");
    }

    // pega o conteudo da expressao salva
    NumExp expressionToCompute = *this->getSavedExp();

    // se for infixa, converte para posfixa antes
    if (expressionToCompute.getExpType() == ExpType::INFIX) {
        expressionToCompute.toPostfix();
    }

    double result = expressionToCompute.computeExpression();

    return result;
}