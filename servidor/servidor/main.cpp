#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include "client.h"
#include "enemy.h"
#include "struct.h"

#define NInimigosTipoA 10
#define NInimigosTipoB 2
#define NMaxPlayers 20
#define NMaxEnemies 20
#define NMaxPowerUps 20

HANDLE readMsg;
HANDLE writeMsg;
HANDLE readStr;
HANDLE writeStr;

int _tmain(int argc, TCHAR * argv[]) {
	DWORD *threadId; //Id da thread a ser criada
	HANDLE *hT; //HANDLE/ponteiro para a thread a ser criada
	int type;

	//Alocar memoria para as 2 threads 
	//2 Tipos de Inimigos
	hT = (HANDLE *)malloc(sizeof(HANDLE) * 2);
	threadId = (DWORD*)malloc(sizeof(DWORD) * 2);

	enemies inimigos[NMaxEnemies];
	//Jogador jogadores[NMaxPlayers];
	//powerUps powerups[NMaxPowerUps];

	//Contadores Jogadores, Inimigos, PowerUps
	int nPlayers = 0;
	int nEnemies = 0;
	int nPowerups = 0;

	//Criar Semaforos arranjar alternativa para os de ler ou talvez eliminar apenas fazendo testes
	//Faz sentido tanto o gateway como o servidor ler ao mesmo tempo escrever � que nao
	readMsg = CreateSemaphore(NULL, 0, 1, readMsgSem);
	readStr = CreateSemaphore(NULL, 0, 1, readStrSem);
	writeMsg = CreateSemaphore(NULL, 0, 1, writeMsgSem);
	writeStr = CreateSemaphore(NULL, 0, 1, writeStrSem);

	//Verificar se os semaforos foram criados com sucesso
	if (readMsg == NULL || readStr == NULL || writeMsg == NULL || writeStr == NULL) {
		_tprintf(TEXT("[ERRO] Occurreu um erro ao criar os Semaforos(%d)\b"), GetLastError());
		return 1;
	}

	//Criar Inimigos
	//createEnemies(3, 1, &nPlayers, inimigos);
	//createEnemies(3, 2, &nPlayers, inimigos);

	//Tipo1
	for (int i = 0; i < 3; i++) {
		inimigos[nEnemies].hp = 2;
		inimigos[nEnemies].pos[0] = 0;
		inimigos[nEnemies].pos[1] = nEnemies;
		inimigos[nEnemies].vivo = 1;
		inimigos[nEnemies].tipo = 0;
		nEnemies++;
	}

	//Tipo2
	for (int i = 0; i < 3; i++) {
		inimigos[nEnemies].hp = 2;
		inimigos[nEnemies].pos[0] = 0;
		inimigos[nEnemies].pos[1] = nEnemies;
		inimigos[nEnemies].vivo = 1;
		inimigos[nEnemies].tipo = 1;
		nEnemies++;
	}
	
	//Criar Threads para os diferentes tipos;
	for (int i = 0; i < 2; i++)
	{
		type = i;
		hT[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadStartEnemy, (LPVOID)&type, 0, &threadId[i]);

		if (hT != NULL) {
			_tprintf(TEXT("Lancei uma thread com id %d\n"), threadId[i]);
			Sleep(3000);
		}
		else
			_tprintf(TEXT("Erro ao criar Thread\n"));
	}



	free(hT);
	free(threadId);

	return 0;
}