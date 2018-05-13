#include <windows.h>
#include "dll.h"

//Exportar a função para ser utilizada fora da DLL
int UmaString(void) {
	TCHAR str[TAM];
	_tprintf(TEXT("Dentro da Dll\nIntroduza uma frase:"));
	_fgetts(str, TAM, stdin);
	if (_tcslen(str) > 1) //Introduzir mais caracteres do que apenas <enter>
		return 1;
	else
		return 0;
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
