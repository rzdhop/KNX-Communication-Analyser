# KNX-Comunicação-Analyser

> Por KNXWorkegtggggggfreeeeeeeeeeegggrs Inc.* II

[![Língua](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)

## Sobre

**KNX-Communication-Analyser é um analisador de estrutura de rede do tipo Wireshark- para objectos KNX**, como persianas, iluminação, aquecimento, ar condicionado, e até dispositivos de comunicação de portas ligados através da rede KNX. O programa é escrito em C++.

## Características

* Ver em tempo real a transição de quadros KNX em bruto na rede.
* Ver a tradução da acção. Por exemplo "Caixa n°1 transmite a ordem de acender a luz n°04".
* Modo Log: exportar num ficheiro .md ou .txt as molduras e a sua tradução transmitida durante a execução do programa.
* Modo de registo minimizado: o programa corre em segundo plano e escreve num ficheiro as molduras transmitidas durante a execução do programa.
* (em projecto) Imprimir fotogramas KNX seleccionados directamente a partir da aplicação.

## Comece

Para executar este programa, necessitará de um cartão PCB (a ligação do nosso está abaixo) no qual irá colocar um cabo do seu autocarro KNX, e ligá-lo ao seu computador.  
  
Após descarregar e instalar o pacote [aqui no fosshub](https://www.fosshub.com/ "KNX-Communication-Analyser download"), e o KNX-Communication-Analyser lançado, reconhecerá se necessitará de instalar um (ou mais) controladores no seu PC.
O software detectará os quadros KNX e começará a ler após premir o botão ▶️ ou premir Ctrl+B.

## Como utilizar o KNX-Communication-Analyser ?

|Atalisador de Teclado|Informação|
|-----|----|
|▶️ ou Ctrl+B|Start capturando pacotes|
|⏺️ ou Ctrl+R|Recordar os pacotes em um ficheiro .md ou um .txt com a sua descrição|
|↘️ ou Ctrl+M|Minimizar o programa (ainda em execução em segundo plano)| |
|⏸️ ou Ctrl+Pausa|Pausa a captura|
|⏏️ ou Ctrl+Del|Restart current capture (erase all current data)|
|🔚 ou Ctrl+S|Save e saia|

[//]: <> (Screenshot nedded. Por favor, remover esta linha APENAS quando a captura de ecrã for adicionada).

## Compatibilidade

Este programa ainda se encontra em desenvolvimento. A versão actual é a alfa 0.0.1
Este programa foi concebido para ser utilizado em Windows.

## Feedbacks

Se encontrar algum bug, não hesite em criar um novo [número](https://github.com/rzdhop/KNX-Communication-Analyser/issues "issue's section"). Obrigado!

## Contribuintes

Este programa espectacular foi escrito por [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "VictorFS78 GitHub profile") e [Soajoh](https://github.com/Soajoh "Soajoh GitHub profile").

## Licença

Licença do MIT.
