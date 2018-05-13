#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include "enemy.h"

//função para iniciar as duas threads dos 2 tipos de inimigos
DWORD WINAPI ThreadStartEnemy(LPVOID param)
{
	int *type = (int*)param;

	printf("Tipo: %d\n", *type);
	//Tratar Inimigos
	

	//WriteDados Função da DLL

	return 0;
}

/*void createEnemies(int n, int type, int *nEnemies, enemies inimigos[]) {
	for (int i = 0; i < n; i++) {
		*nEnemies++;
		inimigos[*nEnemies].hp = 2;
		inimigos[*nEnemies].pos[0] = 0;
		inimigos[*nEnemies].pos[1] = *nEnemies;
		inimigos[*nEnemies].vivo = 1;
	}
}*/