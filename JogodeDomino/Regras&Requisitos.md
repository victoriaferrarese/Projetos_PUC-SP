## Projeto Jogo de Dominó
### Introdução
O jogo de dominó é organizado por peças (ou pedras) formadas por números indicados por meio de pontos. Como cada peça é composta por dois números, formando assim um retângulo por  meio  de  dois  quadrados  congruentes.  O  conjunto  de  dominó é  formado  por  28  peças retangulares. Nessas peças aparecem todas as combinações possíveis de números que vão de 0 a 6, e esses números inclusive podem se repetir, portanto, cada número aparecerá oito vezes. As peças são chamadas segundo seus números da ponta, por exemplo: se em uma peça tiver o número 3 em uma ponta e o número 4, chamamos de “três-quatro”.
### Origem do jogo
As primeiras aparições desse jogo aconteceram na China e sua criação veio de Hung Ming, um santo soldado chinês. Seu nome é proveniente da expressão latina“domino gratias” que quer dizer “Graças ao Senhor”, a frase dita pelo vencedor no final do jogo.
### Regras do Jogo
As regras do jogo são bem simples: cada jogador pega sete peças e pode comprar sempre que precisar de uma peça para poder jogar e quantas vezes for necessário. Dá-se início ao jogo o jogador que tirar a pedra “seis-seis”. Caso ninguém tenha o tirado, inicia-se o jogador que tiver a peça com os números repetidos mais altos, ou seja, “cinco-cinco”, “quatro-quatro”, e assim sucessivamente.<br> 
O jogo acontece no sentido anti-horário e os jogadores devem colocar peças que tenham os mesmos números das peças que se encontram nas 2 pontas da mesa. O jogador que começa a partida leva vantagem. Este é um conceito importante para a estratégia do dominó, pois o jogador que começa, normalmente, é o que leva a vantagem durante a partida.<br>
Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincidam com os pontos da extremidade onde está  sendo  colocada. As  dobradas  são  colocadas  de  maneira  transversal  para  facilitar  sua localização. Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador.<br>
Se um jogador não puder jogar, deverá “comprar” do monte tantas peças quanto forem necessárias. Se não houver peças no monte, passará o turno ao seguinte jogador. A partida continua com os jogadores colocando suas peças sobre a mesa até que se apresente alguma das seguintes *situações*:
* Quando um jogador coloca sua última pedra na mesa, essa ação é chamada de bater. Quando joga-se sozinho, o jogador que ganhou a partida soma os pontos de todos os seus adversários. Jogando em dupla, somam-se os pontos de todos os jogadores incluindo os do seu companheiro.
* Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o número das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida está fechada. Os jogadores contarão os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se os pontos da maneira habitual.<br>
Pode acontecer de você ter os mesmos pontos que o jogador ou a dupla que tem avantagem, nesse caso, ganha este jogador.Via de regra: Ao terminar, vence o jogador que tiver a menor quantidade de peças (ou se houver empate, a menor contagem total de pontos)
### Objetivo do Projeto
O objetivo do projeto é desenvolver um programa em **C** que permite ao usuário jogar o “jogo de dominó” com regras simples (sem ser o jogo fechado). O jogo poderá ser jogado entre dois oponentes reais (pessoas) ou entre um jogador real e o computador (vamos simular um comportamento inteligente do computador por meio de regras implementadas em código). O programa deverá implementar as funções e estruturas de dados para a execução do jogo com as regas simples e com a interface com o usuário necessária para a interação dos jogadores. Vamos usar um padrão de projeto de sistemas interativos para construir o programa, a **arquitetura MVC**. 
### Detalhamento dos Requisitos Funcionais do Jogo e Etapas do Projeto
Os seguintes requisitos deverão ser implementados durante o desenvolvimento do projeto:

**Etapa 1: Tipo agregado (homogêneo e heterogêneo) e I/O (vídeo e teclado) em C**
* REQ01: O sistema deverá montar as peças do dominó com a numeração correta do jogo.
* REQ02: O sistema deve permitir ao usuário embaralhar as peças do domino.
* REQ03: O sistema deverá permitir ao usuário organizar as peças (sequencia correta) para jogar novamente.
* REQ04: O sistema deverá permitir ao usuário mostrar todas as peças do dominó na tela (modo texto ou gráfico).

**Etapa 2: Padrão MVC (Model-View-Controller)**
* REQ05: O sistema deverá ter diferentes formas de apresentação do jogo (múltiplas interfaces).
* REQ06: O sistema deverá ser fácil de manter e as alterações realizadas não devem impactar nos demais módulos do sistema.

**Etapa 3: Funções e Procedimentos (Lógica do Jogo e Interação com o Usuário)**
* REQ07: O sistema deve permitir ao usuário determinar o número jogadores. No mínimo 1e máximo 2 jogadores. 
* REQ08: O sistema deve criar uma mesa após a distribuição das peças entre os jogadores.
* REQ09: O sistema deverá permitir ao usuário distribuir as peças do dominóentre os jogadores.
* REQ10: O sistema deverá permitir ao usuário correto iniciar o jogo.
* REQ11: O sistema deve permitir ao usuário pegar (“comprar”) uma peça.
* REQ12: O sistema deve verificar se a jogada do jogador é válida (se a peça a ser colocada tem a mesma pontuação das peças das extremidades da mesa).

**Etapa 4: Funções e Procedimentos (Lógica do Jogo e Interação com o Usuário)**
* REQ13: O sistema deverá permitir ao usuário ver as suas peças na tela durante o jogo.
* REQ14: O sistema deverá permitir ao usuário esconder as peças dos demais jogadores.
* REQ15: O sistema deverá permitir ao usuário finalizar o jogo de dominó.
* REQ16: O sistema deverá permitir ao usuário comprar peças durante o jogo.
* REQ17: O sistema deverá permitir ao usuário visualizar as regras do jogo.

**Etapa 5: Arquivos em C**
* REQ18: O sistema deverá permitir ao usuário salvar o jogo em um arquivo a qualquer momento, para poder continuar jogando numa outra ocasião. 
* REQ19: O sistema deverá permitir ao usuário carregar um jogo que foi salvo em arquivo para prosseguir jogando.

**Etapa 6: Computador Jogador**
* REQ20: No caso de apenas um jogador contra o computador, o sistema deverá simular o comportamento inteligente como umjogador real por meio da implementação das regras do jogo no código em C. 

### Estrutura de Dados do Jogos
O dominó deverá ser implementado usando tipo agregado de homogêneo (*vetor*) e cada peça deverá ser devidamente representada com as informações necessárias para o contexto do problema. Deve-se criar um tipo agregado heterogêneo para representar cada peça do jogos e no vetor dominó  será  armazenado  as  informações  de  uma  peça.
### Interface com o Usuário (GUI)
A interface com o usuário deverá ser no modo texto (terminal). Toda a interação com o usuário deverá ser controlada por um menu principal com as opções principais e submenus com as demais opções necessárias para o funcionamento do jogo. A figura abaixo ilustra as opções do jogo que devem ser apresentadas para o usuário. Lembre-se: a operação do jogo deve ser a mais amigável possível.

