#pragma once
#include <windows.h>
#include "D:\Armazenamento\ISEC\2º Ano\2º Semestre\SO2\SOII\servidor\servidor\struct.h"

#ifdef DLL_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

/*
Estrutura para enviar para o Jogador
pos[2] -> tera a posicao em XY
id -> id do inimigo, aliado, tiros, bombas, powerUps
type -> indica se é inimigo, aliado, tiros, bombas ou powerUps
*/
struct dataCli {
	int pos[2];
	int id;
	int type;
};

dataCli data, *pData;

HANDLE buffer,  hEventBuffer;
HANDLE dados,  hEventDados;

DLL_IMP_API BOOL ReadBuffer(Jogador cli);
DLL_IMP_API BOOL WriteBuffer(Jogador c);

DLL_IMP_API BOOL ReadDados(dataCli d);
DLL_IMP_API BOOL WriteDados(dataCli d);