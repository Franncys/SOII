#pragma once
/*
pos[2] -> pzosi��o do objeto em XY
type -> representa o tipo de objeto
apanhado -> indica se j� foi apanhado;
E tipo 1 = escudo(temp)
G tipo 2 = Gelo(temp)
B tipo 3 = Bateria(velocido dos tiros dos defensores)(temp)
M tipo 4 = Mais, aumenta velocidade das naves inimigas(temp)
V tipo 5 = Vida extra(perm)
A tipo 6 = Alcool, inverte sentido das teclas(temp)
*/
struct powerUps {
	int pos[2];
	int type;
	int apanhado;
	int tempo;
};


/*
pos -> Posi��o do Jogador no jogo
pontuacao -> Pontua��o do jogador durante o jogo
vidas -> vidas do jogador durante o jogo
pid -> player id
pUps -> objetos que o jogador tem durante o jogo
accao -> caso alguma coisa aconteca do lado do cliente � enviado um codigo na estrutura
*/
struct Jogador {
	int pos[2];
	int pontuacao;
	int vidas;
	powerUps pUps[5][1];
	int pid;
	int accao;
};

/*
pos[2] -> tera a posicao em XY do inimigo
vivo-> indica o estado do inimio se est� vivo ou nao.
tipo-> Tipo da nave invasora
hp-> n�mero de pontos de resist�ncias
*/
struct enemies {
	int pos[2];
	int vivo;
	int tipo;
	int hp;
};

/*
Tipos para as bombas e tiros em que s�o guardadas as posi��es dos mesmo
*/
int bombas[2], tiros[2];

/*mapa opcional*/

//A��es Jogador
#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define BOMBA 3

//Nomes Semaforos
#define readMsgSem "rdMsg"
#define readStrSem "rdStr"
#define writeMsgSem "wrMsg"
#define writeStrSem "wrStr"
