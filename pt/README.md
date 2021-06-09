# KNX-Comunicação-Analyser

> Por KNX Workers Inc (este é um projecto estudantil)

[![Língua](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B#Standardization)
![APM](https://img.shields.io/apm/l/vim-mode)

## Sobre

**KNX-Communication-Analyser é um analisador de estrutura de rede do tipo Wireshark- para objectos KNX**, tais como persianas, iluminação, aquecimento, ar condicionado, e até dispositivos ligados à comunicação de portas utilizando a rede KNX. O programa está escrito em C++.

## Características

* Ver em tempo real as estruturas KNX em bruto em transição na rede.
* Modo de registo: exportar para um ficheiro .txt os quadros transmitidos durante a execução do programa.

## Arranque

Para executar este programa, necessitará de um PCB (a ligação ao nosso está abaixo) no qual irá colocar um cabo do seu autocarro KNX, e ligá-lo ao seu computador.  
  
Depois de descarregar e instalar o pacote disponível no Git Releases do projecto (<https://github.com/rzdhop/KNX-Communication-Analyser> "KNX-Communication-Analyser download"), e de executar o KNX-Communication-Analyser, reconhecerá se necessita de instalar um (ou mais) controladores no seu PC.
O software detectará os quadros KNX e começará a ler depois de premir o botão ▶️.

## Como utilizar a versão gráfica do analisador de telegramas KNX?

|▶️|Start packet capture|
|➕|Restore current capture (limpar todos os dados actuais)|
|🔚|Save and Exit|.

Encontre mais informações sobre como funcionam os dois programas nesta documentação

## Compatibilidade

A versão actual é a alfa 0.0.1.
Este programa foi concebido para ser utilizado no Windows 10. As ferramentas Qt e Visual Studio podem ser necessárias, mas serão instaladas automaticamente se necessário.

## Feedbacks

Se encontrar um bug, sinta-se à vontade para criar um novo [número] (<https://github.com/rzdhop/KNX-Communication-Analyser/issues> "secção do número"). Obrigado!

## Contribuintes

Este programa fantástico foi escrito por [IchInose_0x3b](https://github.com/rzdhop "IchInose_0x3b GitHub profile"), [VictorFS78](https://github.com/VictorFS78 "VictorFS78 GitHub profile") e [Soajoh](https://github.com/Soajoh "Soajoh GitHub profile").

## Licença

Licença do MIT.

# Usando o software

## Com o software gráfico

O primeiro método é utilizar o software gráfico, o mais fácil de utilizar, do qual uma versão executável está disponível no GitHub, na secção de Lançamentos.

Iniciar o software. É provável que tenha de o abrir com direitos de administrador a fim de poder detectar os diferentes portos COM.
![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/KNXCA_desktop.jpg)

Uma vez iniciado o software, prima ▶️ para começar a ler as molduras.

![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/Inkedscreen_qt_withoutdetails_LI.jpg)

À medida que as molduras são exibidas, é possível ver o detalhe clicando no ícone ➕.

![KNX-CA Windows Logo](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/Inkedscreen_qt_LI.jpg)

## Com o software de linha de comando

A versão de linha de comando é mais complicada de utilizar, mas mais completa.

Executado sem quaisquer argumentos, não devolverá nada. Aqui está a lista dos diferentes argumentos disponíveis.

|-h|-ajuda| Mostra a ajuda rápida e um link para a documentação online.
|-Automaticamente detecta a porta COM e ouve as molduras KNX.
|- Pede ao utilizador para especificar a porta COM que pretende utilizar para o analisador de frames.
|-Possibilita ao utilizador ter a informação de uma moldura hexadecimal já na posse do utilizador.

Uma das características mais interessantes é a decopagem de uma moldura existente, como se viu anteriormente. Execute-o assim: .\\ nome do programa> -f````

Um GIF mostra-lhe a execução desta opção abaixo.

![Utilisation avec une trame déjà existante](https://raw.githubusercontent.com/rzdhop/KNX-Communication-Analyser/gh-pages/assets/knx-manualframe.gif)

## Ficheiro de registo

Após cada execução do software, é gerado um ficheiro de registo na pasta que contém o software.
Tenham cuidado. Este ficheiro não é purgado em cada execução para evitar a perda de dados importantes. Deve, portanto, apagá-lo ou apagar o seu conteúdo se quiser ter um novo ficheiro.
