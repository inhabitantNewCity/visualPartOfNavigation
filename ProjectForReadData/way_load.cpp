#include "stdafx.h"
#include "way_load.h"
#include "graph_dll.h"
#include "gdbms01.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#pragma comment (lib, "baseloadvc.lib")

//name_base="CORP1FLOOR2";
//#define BASE_NAME CORP1FLOOR2


using namespace std;
bool graph;
FILE *f;
Coord* GetWay(Coord coordStart, Coord coordEnd, int *n, char* namebase)
{
	int error_1;
	HINSTANCE hdll00;
	char* graphname;
	int len=strlen(namebase);
	//cout<<"len "<<len<<endl;
	graphname = new char[len+2];       
				 for(int j=0;j<len;j++)
				 {
				  graphname[j]=namebase[j]; 
				  graphname[len]='.';
				  graphname[len+1]='g';
				  graphname[len+2]=0;				
				 }  
	//cout<<"graphname "<<graphname<<endl;
	hdll00=BaseFun(&error_1,NULL);
	if (hdll00 == NULL)
	{
		//printf("Library not found");	
		return 0;
	}
	else 
		//printf("Library Graph_DLL_Project.dll  - OK\n");

//проверка на наличие такого графа!!
		f = fopen(graphname,"rb");
		if(!f)
		{
			cout<<"not_graph_file"<<endl;				
			return 0;	
		}
		else
		{
		_Load_Graph(graphname);	
		//  Close_Graph();	  
		int pointsCount=0;  
		Coord *path;
		pointsCount =_FindPath_Make(coordStart, coordEnd);
		*n = pointsCount;
		if (pointsCount==-1)
		 {  
			printf("pCount==-1\n");
		 }
		path=new Coord[pointsCount]; 
		_GetResultPath(path); 
		return path;
		// delete [] path;	
		}
}

Coord* GetMap(int *n, char* namebase) {
	
	/*char* basename = new char[11];
	basename[0] = 'C';
	basename[1] = 'O';
	basename[2] = 'R';
	basename[3] = 'P';
	basename[4] = '1';
	basename[5] = 'F';
	basename[6] = 'L';
	basename[7] = 'O';
	basename[8] = 'O';
	basename[9] = 'R';
	basename[10] = '2';

	int* countVertex;
	Coord coordStart, coordEnd;
	Coord* wayCoord = GetWay(coordStart, coordEnd, countVertex, basename);

	for (int i = 0; i < *countVertex - 1; i++) {
		Line^ line = gcnew Line();
		line->X1 = wayCoord[i].x_;
		line->Y1 = wayCoord[i].y_;
		line->X2 = wayCoord[i+1].x_;
		line->Y2 = wayCoord[i+1].y_;
		way->Add(line);
	}*/

	int err1;
	HINSTANCE hdll01;
	hdll01 = Base01LoadFun1(&err1, NULL);
	if (hdll01 == NULL)
	{
		printf("Library not found");
		return NULL;
	}

	int error_1;
	HINSTANCE hdll00;
	char* graphname;
	int len = strlen(namebase);
	//cout<<"len "<<len<<endl;
	graphname = new char[len + 2];
	for (int j = 0; j<len; j++)
	{
		graphname[j] = namebase[j];
		graphname[len] = '.';
		graphname[len + 1] = 'g';
		graphname[len + 2] = 0;
	}
	//cout<<"graphname "<<graphname<<endl;
	hdll00 = BaseFun(&error_1, NULL);
	if (hdll00 == NULL)
	{
		//printf("Library not found");	
		return 0;
	}
	else
		//printf("Library Graph_DLL_Project.dll  - OK\n");

		//проверка на наличие такого графа!!
		f = fopen(graphname, "rb");
	if (!f)
	{
		cout << "not_graph_file" << endl;
		return 0;
	}
	else
	{
		_Load_Graph(graphname);
		//  Close_Graph();	  
		int pointsCount = 0;
		Coord *path;
		//pointsCount = _FindPath_Make(coordStart, coordEnd);
		*n = pointsCount;
		if (pointsCount == -1)
		{
			printf("pCount==-1\n");
		}
		path = new Coord[pointsCount];
		_GetResultPath(path);
		return path;
		// delete [] path;	
	}
}