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
    NumExp* numExp = NULL;

    // verifica se precisa ler infixa ou posfixa
    if (line.find(INPUT_INFIX_COMMAND) != std::string::npos) {
        // remove o comando da linha
        int index = line.find(INPUT_INFIX_COMMAND);
        line.erase(index, INPUT_INFIX_COMMAND.length() + 1);

        // gera uma expressao
        numExp = new NumExp(line, ExpType::INFIX);
    } else if (line.find(INPUT_POSTFIX_COMMAND) != std::string::npos) {
        // remove o comando da linha
        int index = line.find(INPUT_POSTFIX_COMMAND);
        line.erase(index, INPUT_POSTFIX_COMMAND.length() + 1);

        // gera uma expressao
        numExp = new NumExp(line, ExpType::POSTFIX);
    }

    if (numExp == NULL) {
        std::cout << "ERRO: TIPOEXP INVALIDO OU NAO INFORMADO" << std::endl;
        return;
    }

    // se for valida, salva
    if (numExp->isValid()) {
        this->setSavedExp(numExp);
        std::cout << "EXPRESSAO OK: " << this->getSavedExp()->getExp()
                  << std::endl;
    } else {
        std::cout << "ERRO: " << line << " NAO VALIDA" << std::endl;
    }
}

void NumSolver::convertToInfix() {
    if (this->getSavedExp() == NULL) {
        std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
        return;
    }

    if (this->savedExp->getExpType() != ExpType::INFIX) {
        // converte para infixa somente se nao estiver em infixa inicialmente
        this->getSavedExp()->toInfix();
    }

    std::cout << "INFIXA: " << this->getSavedExp()->getExp() << std::endl;
}

void NumSolver::convertToPostfix() {
    if (this->getSavedExp() == NULL) {
        std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
        return;
    }

    if (this->savedExp->getExpType() != ExpType::POSTFIX) {
        // converte para posfixa somente se nao estiver em posfixa inicialmente
        this->getSavedExp()->toPostfix();
    }

    std::cout << "POSFIXA: " << this->getSavedExp()->getExp() << std::endl;
}

void NumSolver::solve() {
    if (this->getSavedExp() == NULL) {
        std::cout << "ERRO: EXP NAO EXISTE" << std::endl;
        return;
    }

    // pega o conteudo da expressao salva
    NumExp expressionToCompute = *this->getSavedExp();

    // se for infixa, converte para posfixa antes
    if (expressionToCompute.getExpType() == ExpType::INFIX) {
        expressionToCompute.toPostfix();
    }

    double result = expressionToCompute.computeExpression();

    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << "VAL: " << result << std::endl;
}