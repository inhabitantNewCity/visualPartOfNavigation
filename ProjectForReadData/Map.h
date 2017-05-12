#pragma once
using namespace System::Windows::Media;
using namespace System;
using namespace System::Windows::Shapes;
using namespace System::Collections::Generic;

#define ESP 10

ref class Map {
	
private:
	PathGeometry^ intervals;
	List<Line^>^ lines;
	Map^ optWay;
	Line^ currentInterval;
public:
	
	Map(List<Line^>^ intervals) {
		this->lines = intervals;
		this->intervals = gcnew PathGeometry();
		for (int i = 0; i < intervals->Count; i++) {
			Windows::Point point1(intervals[i]->X1, intervals[i]->Y1);
			Windows::Point point2(intervals[i]->X2, intervals[i]->Y2);
			this->intervals->AddGeometry(gcnew LineGeometry(point1, point2));
		}
		currentInterval = intervals[0];
	}

	bool intervalContains(Line^ line) { 
		Windows::Point point1(line->X1, line->Y1);
		Windows::Point point2(line->X2, line->Y2);
		return intervals->FillContains(gcnew LineGeometry( point1, point2));
	}
	
	List<Line^>^ getRelatedEges(Line^ line){
		List<Line^>^ result = gcnew List<Line^>();
		for (int i = 0; i < lines->Count; i++) {
			if (line == lines[i]) {
				continue;
			}
			else if (line->X1 == lines[i]->X1 && line->Y1 == lines[i]->Y1) {
				result->Add(lines[i]);
			}
			else if (line->X2 == lines[i]->X2 && line->Y2 == lines[i]->Y2) {
				result->Add(lines[i]);
			}
		}
		return result;
	}

	bool isFillIntervalsByIndex(Line^ line, Windows::Point point) {
		Windows::Point point1(line->X1, line->Y1);
		Windows::Point point2(line->X2, line->Y2);
		LineGeometry^ lineCheck = gcnew LineGeometry(point1, point2);
		return lineCheck->FillContains(point);
	}

	bool iFillNextIntervalsByInterval(Line^ line, Windows::Point) {
		return false;
	}

	Line^ getCurrentInterval(Line^ prev, Windows::Point point) {
		Windows::Point point1(prev->X1, prev->Y1);
		Windows::Point point2(prev->X2, prev->Y2);
		LineGeometry^ line = gcnew LineGeometry(point1, point2);
		int index = lines->IndexOf(prev);
		return line->FillContains(point, ESP, ToleranceType::Absolute) ? prev : lines[index + 1 < lines->Count? index + 1: index];
	}


	void setOptimWay(Map^ way) {
		this->optWay = way;
	}

	Map^ getOptimWay() {
		return optWay;
	}

};


ref class Way : public Map {
private:
	bool isOptim;
public: 
	Way(List<Line^>^ intervals) :Map(intervals) {
		isOptim = false;
	}

	void setOptimFlag(bool flag) {
		isOptim = flag;
	}
	bool isOptimWay() {
		return isOptim;
	}
};
// TODO: implementaion algorithm here

ref class MapChecker {

private:
	Map^ map;
	Way^ way;
	List<Line^>^ intervals;
	Line^ prev_interval;
	int count_diveded;
	List<System::Collections::Generic::Stack<Windows::Point>^>^ stacks;
	Windows::Point divided_point;
	Windows::Point prev_point;
	

	Windows::Point projVectorToVector(Windows::Vector vector1, Windows::Vector vector2, Windows::Point startPoint) {
		vector2.Normalize();
		return startPoint + vector2 * Windows::Vector::Multiply(vector1,vector2) ;
	}

	Windows::Point calculate_point(float x, float y, Line^ interval) {
		Windows::Point pointCheck(x, y);
		Windows::Vector vector1(x, y);
		Windows::Vector vector2(interval->X2 - interval->X1, interval->Y1 - interval->Y2);
		Windows::Point startPoint(interval->X1, interval->Y1);

		Windows::Point point1(interval->X1, interval->Y1);
		Windows::Point point2(interval->X2, interval->Y2);
		LineGeometry^ lineCheck = gcnew LineGeometry(point1, point2);

		return lineCheck->FillContains(pointCheck, ESP, ToleranceType::Absolute) ? projVectorToVector(vector1, vector2, startPoint) : pointCheck;
	}
	
	void divide_calculation(Line^ prev, int count) {
		List<Line^>^ relatedLines = map->getRelatedEges(prev_interval);
		
		for (int i = 0; i < relatedLines->Count; i++) {

			intervals->Add(relatedLines[i]); // добавляем разделённый интервал
			stacks->Add(gcnew System::Collections::Generic::Stack<Windows::Point>()); // добавление нового стека для хранения точек
			if (count_diveded == 0) {
				divided_point.X = relatedLines[i]->X2; // сохранение точки разветления только один раз
				divided_point.Y = relatedLines[i]->Y2;
			}
		}
	}
	
	bool check_interval_select_way(Line^ interval) {
		return way->intervalContains(interval);
	}
	
	Windows::Point update_way(Windows::Point point) {
		Windows::Point result = divided_point;

		for (int i = 0; i < stacks->Count; i++) { // итеративно опусташаем все ранее созданные стэки и вычисляем коректную точку		
			while (stacks[i]->Count != 0) {
				Windows::Point point = stacks[i]->Pop();
				result.X += point.X;
				result.Y += point.Y;
			}
		}
		return result;
	}

public:
	MapChecker(List<Line^>^ map, List<Line^>^ way) {
		this->map = gcnew Map(map);
		this->way = gcnew Way(way);

		intervals = gcnew List<Line^>();
		prev_interval = way[0];
		count_diveded = 0;
	}
	
	Windows::Point checkOnMap(float x, float y) {
		Windows::Point rowPoint(x, y);
		Line^ current_interval = way->getCurrentInterval(prev_interval, rowPoint);

		Windows::Point current_point = calculate_point(x, y, current_interval);

		if (map->getRelatedEges(current_interval)->Count > 1) { // разветвление алгоритма при разветлении пути
			divide_calculation(prev_interval, count_diveded);
			count_diveded++;
		}

		if (intervals->Count > 1)
		{
			for (int i = 0; i < intervals->Count; i++) {
				if (!map->isFillIntervalsByIndex(intervals[i], current_point)
					&& (!map->iFillNextIntervalsByInterval(intervals[i], current_point)))
					intervals->RemoveAt(i); // удаление интервала из в случае не попадания точки в расматриваемый интервал 
				stacks[i]->Push(current_point); //(current_point);
			}
		}

		if (intervals->Count == 1) {
			if (!check_interval_select_way(intervals[0]))
				current_point = update_way(divided_point);// вычисляем текущий путь если оставшийся интервал не попадает в выбранный путь
			count_diveded = 0;
		}

		prev_point = current_point;
		prev_interval = current_interval;

		return current_point;
	}
};