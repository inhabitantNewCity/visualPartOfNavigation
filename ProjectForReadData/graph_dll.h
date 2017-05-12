#ifndef graph_dll_h
#define graph_dll_h

#define BASEEXPORTFUNC __cdecl
#define DLLEXPORT extern "C" __declspec(dllexport)
//---------------------------------------------------------------------------

#include "Coord.h"
#include <Windows.h>

#define BERR_OK             0  // ���������� ����������
#define BERR_NOINF          2  // ��� ���������� �� �������
//---------------------------------------------------------------------------
typedef struct
{
 unsigned Load_Graph : 1; 
 unsigned Close_Graph : 1;
 unsigned FindPath_Make : 1;
 unsigned GetResultPath : 1;
 unsigned ClearCurrentPath : 1;
} FUN;

//------- ������������ �������� GDBMS00.DLL � ������������ ������� �������
HINSTANCE BaseFun(
 int *err,         // ��� ����������:
                   // BERR_OK - ������ ���� ������� ���������
                   // BERR_NOINF - ���� �� ���� ������� �� �������
 FUN *Fun		   // ������� ������ ������ �������. ���� ��� = 1,
                   //  ������� �������, ���� = 0, �� �� �������
                   // ���� Fun==NULL, �� ������� ������ �� �����������
);

typedef bool (BASEEXPORTFUNC *Load_Graph)(const char *name); //wchar_t
typedef void (BASEEXPORTFUNC *Close_Graph)();
typedef int (BASEEXPORTFUNC *FindPath_Make)(const Coord &start, const Coord &end);
typedef void (BASEEXPORTFUNC *GetResultPath)(Coord *path);
typedef void (BASEEXPORTFUNC *ClearCurrentPath)();

extern Load_Graph _Load_Graph;
extern Close_Graph _Close_Graph;
extern FindPath_Make _FindPath_Make;
extern GetResultPath _GetResultPath;
extern ClearCurrentPath _ClearCurrentPath;

#endif