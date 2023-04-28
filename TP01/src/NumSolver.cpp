#include "../include/NumSolver.hpp"

NumSolver::NumSolver() { this->savedExp = NULL; };

NumSolver::~NumSolver() {
    delete this->savedExp;
}

void NumSolver::print() { this->savedExp->print(); }

NumExp* NumSolver::getSavedExp() { return this->savedExp; }
void NumSolver::setSavedExp(NumExp* exp) { this->savedExp = exp; };

void NumSolver::save(std::string line) {
    if (line.find(INPUT_INFIX_LABEL) != std::string::npos) {
        // remove o label da linha
        int index = line.find(INPUT_INFIX_LABEL);
        line.erase(index, INPUT_INFIX_LABEL.length());

        // gera uma expressao
        NumExp* numExp = new NumExp(line, ExpType::INFIX);

        // se for valida, salva
        if (numExp->isValid()) {
            this->setSavedExp(numExp);
        }

        delete numExp;
    } else if (line.find(INPUT_POSTFIX_LABEL) != std::string::npos) {
        // remove o label da linha
        int index = line.find(INPUT_POSTFIX_LABEL);
        line.erase(index, INPUT_POSTFIX_LABEL.length());

        // gera uma expressao
        NumExp* numExp = new NumExp(line, ExpType::POSTFIX);

        // se for valida, salva
        if (numExp->isValid()) {
            this->setSavedExp(numExp);
        }
        
        delete numExp;
    }
}

void NumSolver::convertToInfix() {
    if (this->getSavedExp() == NULL || this->savedExp->getExpType() == ExpType::INFIX) {
        return;
    }

    // converte para infixa
    this->getSavedExp()->toInfix();
}

void NumSolver::convertToPostfix() {
    if (this->getSavedExp() == NULL || this->savedExp->getExpType() == ExpType::POSTFIX) {
        return;
    }

    // converte para posfixa
    this->getSavedExp()->toPostfix();
}

double NumSolver::solve() {
    if (this->getSavedExp() == NULL) {
        throw std::invalid_argument("Unbale to solve expression: savedExp is null!");;
    }

    // pega a expressao salva
    NumExp* expressionToCompute = this->getSavedExp();

    // se for infixa, converte para posfixa antes
    if (expressionToCompute->getExpType() == ExpType::INFIX) {
        expressionToCompute->toPostfix();
    }

    double result = expressionToCompute->computeExpression();

    delete expressionToCompute;
    return result;
}