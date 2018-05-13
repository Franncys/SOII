#include <windows.h>
#include "dll.h"

HANDLE writeStr, writeMsg;

//Exportar a função para ser utilizada fora da DLL
BOOL ReadBuffer(Jogador cli) {
	writeMsg = OpenSemaphore(SYNCHRONIZE, TRUE, TEXT("Buffer"));
	WaitForSingleObject(writeMsg, INFINITE);
	CopyMemory(cli, data , sizeof(Jogador));
	CloseHandle(writeMsg);
}
BOOL WriteBuffer(Jogador cli) {
	writeMsg = OpenSemaphore(SYNCHRONIZE, TRUE, TEXT("Buffer"));
	WaitForSingleObject(writeMsg, INFINITE);
	CopyMemory(data, cli, sizeof(Jogador));
	CloseHandle(writeMsg);
	return true;
}
BOOL ReadDados(dataCli d) {			
	writeStr = OpenSemaphore(SYNCHRONIZE, TRUE, TEXT("Data"));
	WaitForSingleObject(writeStr, INFINITE);
	CopyMemory(d, pData, sizeof(dataCli));
	CloseHandle(writeStr);
	return true;
}
BOOL WriteDados(dataCli d) {
	writeStr = OpenSemaphore(SYNCHRONIZE, TRUE, TEXT("Data"));
	WaitForSingleObject(writeStr, INFINITE);
	CopyMemory(pData, d, sizeof(dataCli));
	CloseHandle(writeStr);
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
