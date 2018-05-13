#include <windows.h>
#include "dll.h"

//Exportar a função para ser utilizada fora da DLL
BOOL ReadBuffer(Jogador cli) {
	WaitForSingleObject(mBuffer, INFINITE);
	CopyMemory(cli, cliente, sizeof(Cliente));
	ReleaseSemaphore(mBuffer);
}
BOOL WriteBuffer(Jogador c) {

	WaitForSingleObject(mBuffer, INFINITE);
	CopyMemory(cliente, c, sizeof(Cliente));
	ReleaseSemaphore(mBuffer);
	return true;
}
BOOL ReadDados(dataCli d) {			
	WaitForSingleObject(mDados, INFINITE); 
	CopyMemory(d, info, sizeof(Dados)); 
	ReleaseSemaphore(mDados);
	return true;
}
BOOL WriteDados(dataCli d) {
	WaitForSingleObject(mDados, INFINITE);
	CopyMemory(info, d, sizeof(Dados));
	ReleaseSemaphore(mDados);
	return true;
}

BOOL WINAPI DllMain(HANDLE hInstance, DWORD razao, LPVOID tipo_declaracao) {
	switch (razao) {
	case DLL_PROCESS_ATTACH:
		if (tipo_declaracao == NULL)
			MessageBox(NULL, TEXT("O processou carregou a biblioteca explicitamente"), TEXT("DLLmain"), MB_OK);
		else
			MessageBox(NULL, TEXT("O processou carregou a biblioteca implicitamente"), TEXT("DLLmain"), MB_OK);
		break;
	case DLL_PROCESS_DETACH:
		if (tipo_declaracao == NULL)
			MessageBox(NULL, TEXT("O processou desmapeou a biblioteca explicitamente"), TEXT("DLLmain"), MB_OK);
		else
			MessageBox(NULL, TEXT("O processou desmapeou a biblioteca implicitamente"), TEXT("DLLmain"), MB_OK);
		break;
	}
	return 1;
}
