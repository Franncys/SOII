#pragma once
#include <windows.h>
#include "D:\Armazenamento\ISEC\2� Ano\2� Semestre\SO2\SOII\servidor\servidor\struct.h"

#ifdef DLL_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

DLL_IMP_API BOOL ReadBuffer(pCliente cli);
DLL_IMP_API BOOL WriteBuffer(pCliente c);

DLL_IMP_API BOOL ReadDados(pDados d);
DLL_IMP_API BOOL WriteDados(pDados d);