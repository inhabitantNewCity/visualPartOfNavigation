#pragma once

//#include "TComNOGps.h"
//#include "ThreePhaseAlgorithm.h"
#include "com_port.h"
#include "math.h"
#include "filtering.h"
#include "Stubs.h"
#include "Map.h"
#include "way_load.h"

#define PI 3.141592653589793238462643383279502884
#define EPS 2
//#include "Vector.h"

using namespace std;
namespace ProjectForReadData {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Data;
	using namespace System::IO;
	using namespace System::Xaml;

	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			pointsX = gcnew List<float>();
			pointsY = gcnew List<float>();

			firstPhaseOfStepDetected = true;
			secondPhaseOfStepDetected = false;
			thridPhaseOfStepDetected = false;

			current_time = 0;
			// const
			CONST_G = 9.8f;

			CONST_ACCELERATION_MIN = 0.8f * CONST_G;
			CONST_H_MIN = 0.6 * CONST_G;

			CONST_ACCELERATION_MAX = 2.3 * CONST_G;
			CONST_H_MAX = 2.0 * CONST_G;

			//set max and min value of accelerations
			double angleBettwenLegOnSecondPhaseAndNormal = PI / 6;
			double angleBettwenLegOnThridPhaseAndNormal = PI / 3;
			this->deltaTime = 100;
			UIOffset = 10;

			SumRecivedAcceleration = 0;
			countStep = 0;

			// set max min for first phase
			accMinVerticalForFirstPart = -2.0f;
			accMaxVerticalForFirstPart = 2.0f;
			accMaxHorizontalForFirstPart = 1.0f;
			accMinHorizontalForFirstPart - 7.0f;

			// set max, min for second phase		
			accMinVerticalForSecondPart = -4.0f;//(CONST_ACCELERATION_MIN)* cos(angleBettwenLegOnSecondPhaseAndNormal) - ((CONST_ACCELERATION_MIN - CONST_G) * sin(angleBettwenLegOnSecondPhaseAndNormal)) - 6.5f;
			accMaxVerticalForSecondPart = -0.234567f;//(CONST_ACCELERATION_MAX)* cos(angleBettwenLegOnSecondPhaseAndNormal) - ((CONST_ACCELERATION_MAX - CONST_G) * sin(angleBettwenLegOnSecondPhaseAndNormal)) - 6.5f;
			accMinHorizontalForSecondPart = -8.0f;// ((CONST_H_MIN)* sin(angleBettwenLegOnSecondPhaseAndNormal)) + ((CONST_H_MIN - CONST_G) * cos(angleBettwenLegOnSecondPhaseAndNormal));
			accMaxHorizontalForSecondPart = 8.0f; ((CONST_H_MAX)* sin(angleBettwenLegOnSecondPhaseAndNormal)) + ((CONST_H_MAX - CONST_G) * cos(angleBettwenLegOnSecondPhaseAndNormal));

			//set max, min for thrid phase
			accMaxVerticalForThridPart = 4.0f;// (CONST_ACCELERATION_MAX - CONST_G) * sin(angleBettwenLegOnThridPhaseAndNormal) + CONST_ACCELERATION_MAX * cos(angleBettwenLegOnThridPhaseAndNormal) - 2.0f;
			accMinVerticalForThridPart = 0.645678f; //(CONST_ACCELERATION_MIN - CONST_G) * sin(angleBettwenLegOnThridPhaseAndNormal) + CONST_ACCELERATION_MIN * cos(angleBettwenLegOnThridPhaseAndNormal) - 2.0f;
			accMaxHorizontalForThridPart = -10.0f;// ((CONST_H_MAX - CONST_G) * cos(angleBettwenLegOnThridPhaseAndNormal)) - ((CONST_H_MAX)* sin(angleBettwenLegOnThridPhaseAndNormal)) + 7.0f;
			accMinHorizontalForThridPart = 10.0f;// ((CONST_H_MIN - CONST_G) * cos(angleBettwenLegOnThridPhaseAndNormal)) - ((CONST_H_MIN)* sin(angleBettwenLegOnThridPhaseAndNormal)) + 7.0f;

			double firstAccelerationY = 0;

			x_patern = gcnew List<float>();
			y_patern = gcnew List<float>();

			x_current = gcnew List<float>();
			y_current = gcnew List<float>();

			way = gcnew List<Line^>();
			map = gcnew List<Line^>();
			points = gcnew List<Windows::Point>();

			pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black, 2);
			penMap = gcnew System::Drawing::Pen(System::Drawing::Color::Yellow, 1);
			penWay = gcnew System::Drawing::Pen(System::Drawing::Color::Blue, 2);
			penPoints = gcnew System::Drawing::Pen(System::Drawing::Color::OrangeRed);


			current_x_single = 0;
			current_y_single = 0;

			numberStep = 0;
			numberReadInBetweenPhase = 0;

			stateX = kalman_init(0.0625, 1.0, 0.22069559, 0.22069557);
			stateY = kalman_init(0.0625, 1.0, 0.22069559, 0.22069557);

			SECOND_PHASE_TIME = 10;
			countTimeAfterScondPhase = 0;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^ labelCountStep;
	private: System::Windows::Forms::Label^ labelCountStepNumber;



	private: float accX, accY, accZ;
	private: float angleX, angleY, angleZ;
	//private: ThreePhaseAlgorithm^ algorithm;
	private: float startX;
	private: float startY;
	private: float finishX;
	private: float finishY;
	private: float lastAngle;
	private: List<float>^ pointsX;
			 List<float>^ pointsY;



    float current_time;
	bool firstPhaseOfStepDetected;
	bool secondPhaseOfStepDetected;
	bool thridPhaseOfStepDetected;
	
	float accMaxVerticalForFirstPart;
	float accMinVerticalForFirstPart;
	float accMaxHorizontalForFirstPart;
	float accMinHorizontalForFirstPart;

	float accMaxVerticalForSecondPart;
	float accMinVerticalForSecondPart;
	float accMaxHorizontalForSecondPart;
	float accMinHorizontalForSecondPart;

	float accMaxVerticalForThridPart;
	float accMinVerticalForThridPart;
	float accMaxHorizontalForThridPart;
	float accMinHorizontalForThridPart;

	kalman_state* stateX;
	kalman_state* stateY;

	float CONST_G;

	float CONST_ACCELERATION_MIN;
	float CONST_H_MIN;

	float CONST_ACCELERATION_MAX;
	float CONST_H_MAX;

	int deltaTime;
	int SECOND_PHASE_TIME;
	int countTimeAfterScondPhase;

	float SumRecivedAcceleration;
	int countStep;
	int prev_countStep;
	StreamWriter^ sw;
	int UIOffset;
	int numberStep;
	int numberReadInBetweenPhase;

	List<float>^ x_patern;
    List<float>^ y_patern;

	List<float>^ x_current;
	List<float>^ y_current;

	List<Line^>^ map;
	List<Line^>^ way;
	List<Windows::Point>^ points;
	MapChecker^ checker;

	System::Drawing::Pen^ pen;
	System::Drawing::Pen^ penMap;
	System::Drawing::Pen^ penWay;
	System::Drawing::Pen^ penPoints;
	
	float current_x_single;
	float current_y_single;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::Button^  buttonSuspend;
	private: System::Windows::Forms::Button^  buttonContinue;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonClear;
private: System::Windows::Forms::Button^  buttonDraw;
		 bool allAccDetected;
	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelCountStep = (gcnew System::Windows::Forms::Label());
			this->labelCountStepNumber = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->buttonSuspend = (gcnew System::Windows::Forms::Button());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonDraw = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(581, 260);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(495, 364);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// labelCountStep
			// 
			this->labelCountStep->Location = System::Drawing::Point(756, 183);
			this->labelCountStep->Name = L"labelCountStep";
			this->labelCountStep->Size = System::Drawing::Size(115, 20);
			this->labelCountStep->TabIndex = 1;
			this->labelCountStep->Text = L"Count recognized step = ";
			this->labelCountStep->Click += gcnew System::EventHandler(this, &Form1::labelCountStep_Click);
			// 
			// labelCountStepNumber
			// 
			this->labelCountStepNumber->Location = System::Drawing::Point(895, 183);
			this->labelCountStepNumber->Name = L"labelCountStepNumber";
			this->labelCountStepNumber->Size = System::Drawing::Size(25, 15);
			this->labelCountStepNumber->TabIndex = 0;
			this->labelCountStepNumber->Text = L"0";
			// 
			// chart1
			// 
			chartArea1->AxisX->MajorGrid->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisX->ScaleView->SizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisY->MajorGrid->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->CursorX->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->CursorX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(1), true));
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend1";
			legend1->Title = L"Vertical";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(26, 24);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Grayscale;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Yellow;
			series1->EmptyPointStyle->IsVisibleInLegend = false;
			series1->IsVisibleInLegend = false;
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Vertical";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(538, 295);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chartVert";
			this->chart1->Click += gcnew System::EventHandler(this, &Form1::chart1_Click);
			// 
			// chart2
			// 
			chartArea2->AxisX->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisX->ScaleView->SizeType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisY->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(26, 338);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Yellow;
			series2->IsVisibleInLegend = false;
			series2->Legend = L"Legend1";
			series2->Name = L"Horizontal";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(538, 284);
			this->chart2->TabIndex = 3;
			this->chart2->Text = L"chartVert";
			// 
			// buttonSuspend
			// 
			this->buttonSuspend->Location = System::Drawing::Point(699, 65);
			this->buttonSuspend->Name = L"buttonSuspend";
			this->buttonSuspend->Size = System::Drawing::Size(75, 23);
			this->buttonSuspend->TabIndex = 4;
			this->buttonSuspend->Text = L"Suspend";
			this->buttonSuspend->UseVisualStyleBackColor = true;
			this->buttonSuspend->Click += gcnew System::EventHandler(this, &Form1::buttonSuspend_Click);
			// 
			// buttonContinue
			// 
			this->buttonContinue->Location = System::Drawing::Point(699, 117);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(75, 23);
			this->buttonContinue->TabIndex = 5;
			this->buttonContinue->Text = L"Continue";
			this->buttonContinue->UseVisualStyleBackColor = true;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &Form1::buttonContinue_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Vertical";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 338);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Horizontal";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(896, 65);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 8;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// buttonDraw
			// 
			this->buttonDraw->Location = System::Drawing::Point(896, 116);
			this->buttonDraw->Name = L"buttonDraw";
			this->buttonDraw->Size = System::Drawing::Size(75, 23);
			this->buttonDraw->TabIndex = 9;
			this->buttonDraw->Text = L"Draw Path";
			this->buttonDraw->UseVisualStyleBackColor = true;
			this->buttonDraw->Click += gcnew System::EventHandler(this, &Form1::buttonDraw_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1088, 646);
			this->Controls->Add(this->buttonDraw);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonContinue);
			this->Controls->Add(this->buttonSuspend);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->labelCountStep);
			this->Controls->Add(this->labelCountStepNumber);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


bool firstPhaseOfStepIsDetected(float accX, float accY, float accZ)
	{
		//accX += 9.8f;
		//accX = -1*accX;
		accMinHorizontalForFirstPart = -1.0f;
		if( ((accX > accMinVerticalForFirstPart) && (accX < accMaxVerticalForFirstPart)) && ((accY > accMinHorizontalForFirstPart) && (accY < accMaxHorizontalForFirstPart)))
			return true;
		return false;
	};
	bool secondPhaseOfStepIsDetected(float accX ,float accY, float accZ)
	{
		bool result = false;
		if( ((accY > accMinVerticalForSecondPart) && (accY < accMaxVerticalForSecondPart)) 
			&& ((accX > accMinHorizontalForSecondPart) && (accX < accMaxHorizontalForSecondPart)))
			result = true;
		sw->WriteLine("SECOND PHAGE RESULT: " + result + 
			" [ " + accMinVerticalForSecondPart + " < " + accY + " < " + accMaxVerticalForSecondPart + " ] " +
			" [ " + accMinHorizontalForSecondPart + " < " + accX + " < " + accMaxHorizontalForSecondPart + " ] "
			);
		return result;
	};
	bool thridPhaseOfStepIsDetected(float accX , float accY,float accZ)
	{
		bool result = false;
		if( ((accY > accMinVerticalForThridPart) && (accY < accMaxVerticalForThridPart))
			&& ((accX > accMaxHorizontalForThridPart) && (accX < accMinHorizontalForThridPart)))
			result = true;
		sw->WriteLine("THRID PHAGE RESULT: " + result + 
			" [ " + accMinVerticalForThridPart + " < " + accY + " < " + accMaxVerticalForThridPart + " ] " +
			" [ " + accMinHorizontalForThridPart + " < " + accX + " < " + accMaxHorizontalForThridPart + " ] "
			);
		return result;
	};
	float calculateLengthOfStep(float acc)
	{
		SumRecivedAcceleration += acc;
		float result = (CONST_G/countStep) * pow((double)SumRecivedAcceleration, 1.0 / 3.0);
		sw->WriteLine ("LENGTH OF STEP: result = " + result + " module acc = " + acc +
			" sum = " + SumRecivedAcceleration + "count step = " + countStep);
		return result;
	}
	float module(float accX, float accY, float accZ)
	{
		float summ = accX * accX + accY * accY;
		return sqrt(summ);
	}
	float execute(float accX, float accY, float accZ)
	{
		//if(firstPhaseOfStepIsDetected(accX, accY, accZ))
			//firstPhaseOfStepDetected = true;
		if(secondPhaseOfStepIsDetected(accX, accY, accZ)){
			secondPhaseOfStepDetected = true;
			thridPhaseOfStepDetected = false;

			DataPoint^ cur_ver_point = gcnew DataPoint(current_time, accY);
			DataPoint^ cur_hor_point = gcnew DataPoint(current_time, accY);

			

			cur_ver_point->Color = System::Drawing::Color::Red;
			cur_ver_point->MarkerColor = System::Drawing::Color::Red;
			cur_ver_point->MarkerSize = 1000;

			cur_hor_point->Color = System::Drawing::Color::Black;
			cur_hor_point->MarkerColor = System::Drawing::Color::Black;
			cur_hor_point->MarkerSize = 1000;

			chart1->Series["Vertical"]->Points->Add(cur_ver_point);
			chart2->Series["Horizontal"]->Points->Add(cur_hor_point);
		}
		if (thridPhaseOfStepIsDetected(accX, accY, accZ) && secondPhaseOfStepDetected) {
			thridPhaseOfStepDetected = true;
			DataPoint^ cur_ver_point = gcnew DataPoint(current_time, accY);
			DataPoint^ cur_hor_point = gcnew DataPoint(current_time, accY);

			cur_ver_point->Color = System::Drawing::Color::Black;
			cur_ver_point->MarkerColor = System::Drawing::Color::Black;
			cur_ver_point->MarkerSize = 1000;

			cur_hor_point->Color = System::Drawing::Color::Black;
			cur_hor_point->MarkerColor = System::Drawing::Color::Black;
			cur_hor_point->MarkerSize = 1000;

			chart1->Series["Vertical"]->Points->Add(cur_ver_point);
			chart2->Series["Horizontal"]->Points->Add(cur_hor_point);
		}
		if(firstPhaseOfStepDetected  & secondPhaseOfStepDetected & thridPhaseOfStepDetected )
		{
			secondPhaseOfStepDetected = false;
			thridPhaseOfStepDetected = false;
			countTimeAfterScondPhase = 0;
			float moduleAcceleration = module(accX, accY, accZ);
			countStep++;
			this->labelCountStepNumber->Text = Convert::ToString(countStep);
			//timer1->Stop();
			return calculateLengthOfStep(moduleAcceleration);
		}
		if (countTimeAfterScondPhase > SECOND_PHASE_TIME) {
			secondPhaseOfStepDetected = false;
			countTimeAfterScondPhase = 0;
		}
		countTimeAfterScondPhase++;
		return 0;
	}


	float executeChatAlgorithm(float accX, float accY, float accZ){
		float result = 0;
		
		if(secondPhaseOfStepIsDetected(accX, accY, accZ)){
			secondPhaseOfStepDetected = true;
			DataPoint^ cur_ver_point = gcnew DataPoint(current_time, accY);
			
			cur_ver_point->Color = System::Drawing::Color::Red;
			cur_ver_point->MarkerColor = System::Drawing::Color::Red;
			cur_ver_point->MarkerSize = 1000;
			
			chart1->Series["Vertical"]->Points->Add(cur_ver_point);
			numberReadInBetweenPhase = 0;
			//thridPhaseOfStepDetected = false;
			//numberStep = 0;
		}
		if(thridPhaseOfStepIsDetected(accX, accY, accZ)){
			thridPhaseOfStepDetected = true;

			DataPoint^ cur_ver_point = gcnew DataPoint(current_time, accY);

			cur_ver_point->Color = System::Drawing::Color::Red;
			cur_ver_point->MarkerColor = System::Drawing::Color::Red;
			cur_ver_point->MarkerSize = 1000;

			chart1->Series["Vertical"]->Points->Add(cur_ver_point);

		}
		if(secondPhaseOfStepDetected && thridPhaseOfStepDetected){
			
			numberStep++;

			if(numberStep){
				merge();
				if(allAccDetected)
					return module(accX, accY, accZ);
			}
			
			x_current->Add(accY);	
			y_current->Add(accX);

			allAccDetected = checkCurrentSate(accX,accY,accZ, numberReadInBetweenPhase);
			numberReadInBetweenPhase++;
			
		}
		return 0;
	}

	void merge(){
		int limit = x_patern->Count >= x_current->Count?x_current->Count:x_patern->Count;
		
		array<float>^ x_curent_ar = x_current->ToArray(); 
		array<float>^ y_curent_ar = y_current->ToArray();

		array<float>^ x_patern_ar = x_patern->ToArray();
		array<float>^ y_patern_ar = y_patern->ToArray();

		x_current->Clear();
		y_current->Clear();
		x_patern->Clear();
		x_patern->Clear();

		for(int i = 0; i < limit; i++)
		{
			x_patern_ar[i] = (x_patern_ar[i] + x_curent_ar[i])/2;
			y_patern_ar[i] = (y_patern_ar[i] + y_curent_ar[i])/2;
		}
		
		x_patern->AddRange(x_patern_ar);
		y_patern->AddRange(y_patern_ar);

		delete[]x_curent_ar;
		delete[]y_curent_ar;
		delete[]x_patern_ar;
		delete[]y_patern_ar;

	}
	
	bool checkCurrentSate(float accX, float accY, float accZ, int index_patern){
		if(index_patern < x_patern->Count)
			return sqrt(pow(x_patern[index_patern] - accX, 2) + pow(y_patern[index_patern] - accY, 2)) < EPS * sqrt(2) / 2;
		return true;
	}


private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				int statusResponse = COMOpen();
				//accMaxVerticalForSecondPart = 110.0f;
				//accMinHorizontalForSecondPart = -100.0f;
				//accMaxHorizontalForSecondPart = 100.0f;
				if(statusResponse < 0)
				{
					System::Windows::Forms::MessageBox::Show("all are bad");
				}
				File::Delete("Log.txt");
				sw = File::CreateText("Log.txt");
				sw->WriteLine ("Second phage: vertical acceleration" + 
				" [ " + accMinVerticalForSecondPart + " ; " + accMaxVerticalForSecondPart + " ] " +
				"Horizontal acceleration" +
				" [ " + accMinHorizontalForSecondPart + " ; " + accMaxHorizontalForSecondPart + " ] ");

				sw->WriteLine ("Triad phage: vertical acceleration" + 
				" [ " + accMinVerticalForThridPart + " , " + accMaxVerticalForThridPart + " ] " +
				"Horizontal acceleration" +
				" [ " + accMinHorizontalForThridPart + " , " + accMaxHorizontalForThridPart + " ] ");
				databaseGenerate(map, way, pictureBox1);
				checker = gcnew MapChecker(map, way);
				timer1->Interval = 2;
				timer1->Start();
			 }
//	private: void draw(Graphics^ graph,)
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			
				if((startX != finishX)||(startY != finishY))
				 {  
					startX = finishX;
					startY = finishY;
					pointsX->Add(finishX += UIOffset);
					pointsY->Add(finishY += UIOffset);

				 }
					array<float>^ pointsArrayX = pointsX->ToArray();
					array<float>^ pointsArrayY = pointsY->ToArray();
					for(int i = 0; i < pointsX->Count - 1; i++)
					{
						 e->Graphics->DrawLine(pen, pointsArrayX[i],pointsArrayY[i], pointsArrayX[i+1], pointsArrayY[i+1]);
						 //e->Graphics->DrawLine(pen, current_time, current_time, current_time++, current_time++);
					}
					
					for (int i = 0; i < map->Count; i++) {
						e->Graphics->DrawLine(penMap, (float)map[i]->X1, (float)map[i]->Y1, (float)map[i]->X2, (float)map[i]->Y2);
					}

					for (int i = 0; i < way->Count; i++) {
						e->Graphics->DrawLine(penWay, (float)way[i]->X1, (float)way[i]->Y1, (float)way[i]->X2, (float)way[i]->Y2);
					}
					
					for (int i = 0; i < points->Count-1; i++) {
						e->Graphics->DrawLine(penPoints, (float)points[i].X, (float)points[i].Y, (float)points[i + 1].X, (float)points[i + 1].Y );
					}
				 //e->Graphics->DrawLine(pen, startX,startY, finishX, finishY);
				 //e->Graphics->DrawLines(pen,  
					
				 //canvas = e->Graphics;
			 }
	private: char*  readDataFromSensors()
			 {
				
				char* buff = new char[28];
				int statusResponseRead = Read(buff, 28);
				statusResponseRead /= 2;
				short* buffShort = (short*)buff;
				short tmp[14];
				//short tmp[14];
				//tmp = buff
				//float* intBuff = (float*)buff;
				//label1->Text = "";
				for(int i = 0; i < statusResponseRead; i++)
				{
					tmp[i] = buffShort[i];
				}
				return buff;
			 }
	private: void parseReadDate(char* readDate)
			 {
				 //int tmpX = (int)readDate[3];
				 accX = kalman_update(stateX, (double)((readDate[11] >> 8) + readDate[10]) / 256.0f * CONST_G)->x;
				 accY = kalman_update(stateY, (float)((readDate[13] >> 8) + readDate[12]) / 256.0f * CONST_G)->x;
				
				 //accX = (float)((readDate[11] >> 8) + readDate[10]) / 256.0f * CONST_G;
				 //accY = (float)((readDate[13] >> 8) + readDate[12]) / 256.0f * CONST_G;

				 accZ = (float)((readDate[15] >> 8) + readDate[14]) / 256.0f * CONST_G;
				 
				 if(secondPhaseOfStepDetected || thridPhaseOfStepDetected){
					
					chart1->Series["Vertical"]->Points->AddXY(current_time, accY);
					chart2->Series["Horizontal"]->Points->AddXY(current_time, accX);
				 }

				 angleX = (float)((readDate[23] << 8) + readDate[22]) / (100.0f * 180) * PI;
				 angleY = (float)((readDate[25] << 8) + readDate[24]) / (100.0f * 180) * PI;
				 angleZ = (float)((readDate[27] << 8) + readDate[26]) / (100.0f * 180) * PI;

				sw->WriteLine ("ACCELERATION: accY = " + accY + "accX = " + accX + " accZ = " + accZ);
				sw->WriteLine ("ANGLES: angleX = " + angleX + " angleY = " + angleY + " angleZ = " + angleZ);

			 }
	private: void calculateStartPointAndFinishpoint(float lengthOfstep, float angleX, float angleY, float angleZ)
			 {
				 //lengthOfstep = 1;
				 finishX = (float)(startX + cos(angleZ)*lengthOfstep);
				 finishY = (float)(startY + sin(angleZ)*lengthOfstep);
		
				 //test
				 //finishX = current_time;
				 //finishY = current_time;

				 sw->WriteLine ("CURRENT POINT: ( " + finishX + " , " + finishY + " ), sin of angle = " + sin(angleZ - lastAngle) + " pitch angle = "
					 + (angleZ) + " length os step = " + lengthOfstep);
				 
				 lastAngle = angleZ;
				 //Pen^ pen = gcnew Pen(Color::Black, 2); 
				 //canvas->DrawLine(pen, startX,startY, finishX, finishY );

			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 char* readDate = readDataFromSensors();
				 parseReadDate(readDate);
				 float lengthStep = execute(accX, accY, accZ);
				 calculateStartPointAndFinishpoint(lengthStep,angleX, angleY, angleZ);
				 Windows::Point cur_point = checker->checkOnMap(finishX + UIOffset, finishY + UIOffset);
				 sw->WriteLine("CURRENT POINT with check on map: ( " + cur_point.X  + " , " + cur_point.Y + ")");
				 sw->WriteLine("");
				 points->Add(cur_point);
				 pictureBox1->Invalidate();
				 current_time += 0.1f;
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buttonSuspend_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
}
private: System::Void buttonContinue_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
}
private: System::Void labelCountStep_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
	
	chart1->Series["Vertical"]->Points->Clear();
	chart2->Series["Horizontal"]->Points->Clear();
	countStep = 0;
	secondPhaseOfStepDetected = false;
	thridPhaseOfStepDetected = false;
	labelCountStepNumber->Text = "0";
}



private: System::Void buttonDraw_Click(System::Object^  sender, System::EventArgs^  e) {
	simpleGenerate(map, way, pictureBox1);
}
};
}