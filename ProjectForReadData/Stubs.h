#include "way_load.h"
#pragma once

using namespace System::Collections::Generic;
using namespace System::Windows::Shapes;
using namespace System::Windows::Forms;

int simpleGenerate(List<Line^>^ map, List<Line^>^ way, PictureBox^ image) {
	
	Line^ line1 = gcnew Line();
	line1->X1 = 10;
	line1->Y1 = 10;
	line1->X2 = 10 + image->Width / 2;
	line1->Y2 = 10;
	map->Add(line1);
	way->Add(line1);

	Line^ line2 = gcnew Line();
	line2->X1 = line1->X2;
	line2->Y1 = line1->Y2;
	line2->X2 = line1->X2 + image->Width / 4;
	line2->Y2 = line1->Y2;
	map->Add(line2);

	Line^ line3 = gcnew Line();
	line3->X1 = line2->X2;
	line3->Y1 = line2->Y2;
	line3->X2 = line2->X2;
	line3->Y2 = line2->Y2 + image->Width / 4;
	map->Add(line3);

	Line^ line4 = gcnew Line();
	line4->X1 = line3->X2;
	line4->Y1 = line3->Y2;
	line4->X2 = line3->X2;
	line4->Y2 = line3->Y2 + image->Width / 2;
	map->Add(line4);

	Line^ line5 = gcnew Line();
	line5->X1 = line1->X2;
	line5->Y1 = line1->Y2;
	line5->X2 = line1->X2;
	line5->Y2 = line1->Y2 + image->Width / 4;
	map->Add(line5);
	way->Add(line5);

	Line^ line6 = gcnew Line();
	line6->X1 = line5->X2;
	line6->Y1 = line5->Y2;
	line6->X2 = line5->X2 + image->Width / 4;
	line6->Y2 = line5->Y2;
	map->Add(line6);
	way->Add(line6);
	way->Add(line4);

	return 0;
}

int databaseGenerate(List<Line^>^ map, List<Line^>^ way, PictureBox^ image) {
	
	char* basename = new char[11];
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

	int *countMap, *countWay;
	Coord* mapCor = GetMap(countMap, basename);
	Coord* wayCor = GetWay(mapCor[0], mapCor[*countMap - 1], countWay, basename);


	for (int i = 0; i < *countMap - 1; i++) {
		Line^ line = gcnew Line();
		line->X1 = mapCor[i].x_;
		line->Y1 = mapCor[i].y_;
		line->X2 = mapCor[i + 1].x_;
		line->Y2 = mapCor[i + 1].y_;
		map->Add(line);
	}

	for (int i = 0; i < *countWay - 1; i++) {
		Line^ line = gcnew Line();
		line->X1 = wayCor[i].x_;
		line->Y1 = wayCor[i].y_;
		line->X2 = wayCor[i + 1].x_;
		line->Y2 = wayCor[i + 1].y_;
		way->Add(line);
	}

	return 0;

}