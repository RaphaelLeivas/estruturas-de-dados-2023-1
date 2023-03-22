# estruturas-de-dados-2023-1
Repositório para códigos da disciplina de Estruturas de Dados, semestre 2023/1 de Engenharia de Sistemas UFMG.

# Configuração de ambiente para C / C++

Siga o link https://stackoverflow.com/a/11366045/16855638

Adicione o MinGW no Path do windows, e reinicie o VS Code para o terminal e a extensão verem o novo path. <br />
Em geral, o endereço do MinGW é 

```
C:\MinGW\bin

```

Para compilar C++, usa `g++`.
Para compilar C, usa `gcc`.

Instale a extensão do VS Code para C / C++. assim temos intellisense e verificação de sintaxe ao desenvolver.


## Formatação automática de codigo

Instale o clang-format via `npm` mesmo e rode no terminal normalmente.

```
npm i -g clang-format

```

```

cd src
clang-format -i *.cpp
cd ../program
clang-format -i *.cpp
cd ../tests
clang-format -i *.cpp
cd ../includes
clang-format -i *.hpp

```

ou

```

.\format.bat

```

## Compilação Manual


```

g++ -std=c++14 -Wall main.cpp -o main.exe
.\main.exe

```

ou (assim pega todos os arquivo dentro de uma pasta src, sem precisar add eles manualmente)

```

cls
g++ -o ./program/main.exe ./program/main.cpp ./src/*.cpp
.\program\main.exe

```

Outra forma de compilar é   

```

g++ -Wall -g -o test.exe test.cpp

``` 
