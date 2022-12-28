Projeto **Jogo da Vida**
Laboratório de Programação - LP/2022
Introdução
Em 1970, o cientista John Conway inventou um jogo que simula o processo de 
nascimento, sobrevivência, e morte. O jogo da vida é um autômato celular e foi criado de modo 
a reproduzir, através de regras simples, as alterações e mudanças em grupos de seres vivos, tendo 
aplicações em diversas áreas da ciência (ver: http://pt.wikipedia.org/wiki/Jogo_da_vida ).
A ideia base é que um ser vivo necessita de outros seres vivos para sobreviver e procriar, mas 
um excesso de densidade populacional provoca a morte do ser vivo devido à escassez de comida. 
Os indivíduos vivem num mundo matricial e a geração seguinte é gerada a partir da geração 
anterior de acordo com as seguintes regras:
• Reprodução: Um ser vivo nasce numa célula vazia se essa célula vazia tiver exatamente 
3 seres vivos vizinhos. 
• Sobrevivência: Um ser vivo que tenha 2 ou 3 vizinhos sobrevive para a geração seguinte. 
• Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre porque fica sem 
comida. 
• Morte por solidão: Um ser vivo com 0 ou 1 vizinhos morre de solidão.
A cada geração, as regras devem ser aplicadas para todos os seres vivos ao mesmo tempo 
(isto é no mesmo passo) para obtermos o próximo passo ou geração. 
Objetivo do projeto
O objetivo do projeto é criar um programa em C para simular o jogo da vida. Os 
indivíduos vivem numa matriz e o programa deve gerar a geração seguinte a partir das regras 
previamente apresentadas. Cada posição da matriz é uma célula que pode ter um “O” (para 
representar um ser vivo) ou um espaço em branco ou um ponto para indicar “vazio” ou “morto”. 
Cada célula tem um máximo de 8 células vizinhas. Considerar que o mundo é plano e possui 
limites (pois fica complicado definir que a última célula é vizinha da primeira simulando assim 
um mundo esférico).
Pontifícia Universidade Católica de São Paulo
Faculdade de Ciência Exatas e Tecnologia
2
Pequeno exemplo (10 x10). Se a geração inicial for a seguinte:
O programa deverá implementar as funções e estruturas de dados necessárias para a 
execução da simulação e para a interface com o usuário. Vamos usar um padrão de projeto de 
sistemas interativos para construir o programa (padrão MVC). Além disso, o programa deverá 
permitir o armazenamento em arquivo das configurações iniciais de uma 1ª geração para uma 
possível futura nova execução. 
Detalhamento dos Requisitos Funcionais do Jogo
Os seguintes requisitos deverão ser implementados durante o desenvolvimento do projeto:
Etapa 1:
◆ REQ01: O sistema deve permitir ao usuário a definição do tamanho do mundo (mínimo 
10 e máximo 60) procurando sempre caber numa tela texto sem retorno de nova linha.
◆ REQ02: O sistema deve permitir ao usuário definir os seres vivos da primeira geração da 
simulação
Pontifícia Universidade Católica de São Paulo
Faculdade de Ciência Exatas e Tecnologia
3
◆ REQ03: O sistema deverá permitir ao usuário limpar todas as células do mundo (mapa)
Etapa 2:
◆ REQ04: O sistema deverá permitir ao usuário iniciar a simulação
◆ REQ05: O sistema deverá permitir ao usuário definir a velocidade da simulação das 
gerações (a cada 1, 2 ou mais segundos). Isso no caso do usuário determinar a quantidade 
de gerações que serão simuladas (requisito 6)
◆ REQ06: O sistema deverá permitir ao usuário simular uma determinada quantidade de 
gerações a serem processadas
Etapa 3:
◆ REQ07: O sistema deverá permitir ao usuário simular passo-a-passo, visualizando as 
gerações que se sucedem
Etapa 4:
◆ REQ08: O sistema deverá permitir ao usuário selecionar alguns padrões de gerações 
iniciais de seres vivos. (preparação para os Requisitos 09 e 10)
Etapa 5:
◆ REQ09: O sistema deverá permitir ao usuário salvar as gerações iniciais em arquivo
◆ REQ10: O sistema deverá permitir ao usuário carregar uma geração previamente 
armazenada em arquivo para um novo processamento.
Estrutura de Dados do Jogos
O mapa (ou mundo) que representa a estrutura matricial dos indivíduos deverá ser implementado
usando tipo agregado de homogêneo (matriz) e cada célula deverá ser devidamente representada
com as informações necessárias para o contexto do problema. Sugere-se criar duas matrizes 
bidimensionais: uma original e outra auxiliar para representar todas as células.
Interface com o Usuário
A interface com o usuário deverá ser no modo texto (terminal).
Simuladores OnLine do Jogo da Vida
• https://bitstorm.org/gameoflife/
Pontifícia Universidade Católica de São Paulo
Faculdade de Ciência Exatas e Tecnologia
4
Questões de Ordem.
• O programa deverá ser desenvolvido na linguagem C (padrão ANSI) 
• O código desenvolvido deverá estar bem estruturado e com o uso correto de funções 
• A interface do jogo deve ser no modo texto (terminal)
• Os grupos deverão ser os mesmos do projeto anterior. Será descontado 0,5 ponto por dia 
atraso na formação dos grupos.
• Durante as aulas de LP as equipes deverão trabalhar no projeto e tirar dúvidas sobre os 
conceitos de LP e construtores da linguagem C necessários para o desenvolvimento do 
projeto
• As etapas funcionando deverão ser apresentadas para o professore na data planejada
• Cada etapa definida acima deverá ser entregue no prazo e valerá nota para o grupo.
• Não serão aceitos trabalhos entregues fora do prazo ou através de e-mail
• O projeto deverá ser desenvolvido em equipe de no mínimo 3 e no máximo 4 alunos
• Todos os alunos do grupo deverão estar presentes no dia da apresentação
• Trabalhos copiados ou com indícios de cópia receberão nota zero!
• Código totalmente ou parcialmente copiado da Internet serão zerado