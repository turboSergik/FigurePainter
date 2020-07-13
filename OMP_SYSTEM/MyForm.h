#pragma once

#include "Data.h"
#include "windows.h"

#include "Canvas.h"

#include "Figure.h"
#include "PowerMethodForGraphVisualization.h"

#include <msclr\marshal_cppstd.h>

FigurePtr objectToMove;

namespace OMPSYSTEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>

	private: System::Windows::Forms::RadioButton^ radioButtonCircle;

	private: System::Windows::Forms::RadioButton^ radioButtonSquare;


	private: System::Windows::Forms::RadioButton^ radioButtonTriangle;



	private: System::Windows::Forms::RadioButton^ radioButtonLine;

		   ApplicationData::Action curAction;

		   Point firstPointOfLine;
		   Point tempSecondPointOfLine;

		   bool canMove = false;
		   bool powerMethod = false;

		   Point pointMove;

		   Canvas* canvas;

	private: System::Windows::Forms::RadioButton^ radioButtonMove;
	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::Button^ button_save;
	private: System::Windows::Forms::Button^ button_clear;
	private: System::Windows::Forms::CheckBox^ PowerMethodCheckBox;

	private: System::Windows::Forms::Timer^ render_timer;





#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->radioButtonCircle = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonSquare = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonTriangle = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonLine = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonMove = (gcnew System::Windows::Forms::RadioButton());
			   this->button_load = (gcnew System::Windows::Forms::Button());
			   this->button_save = (gcnew System::Windows::Forms::Button());
			   this->button_clear = (gcnew System::Windows::Forms::Button());
			   this->render_timer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->PowerMethodCheckBox = (gcnew System::Windows::Forms::CheckBox());
			   this->SuspendLayout();
			   // 
			   // radioButtonCircle
			   // 
			   this->radioButtonCircle->AutoSize = true;
			   this->radioButtonCircle->Location = System::Drawing::Point(22, 22);
			   this->radioButtonCircle->Name = L"radioButtonCircle";
			   this->radioButtonCircle->Size = System::Drawing::Size(60, 20);
			   this->radioButtonCircle->TabIndex = 3;
			   this->radioButtonCircle->TabStop = true;
			   this->radioButtonCircle->Text = L"Cirlce";
			   this->radioButtonCircle->UseVisualStyleBackColor = true;
			   this->radioButtonCircle->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonCircle_CheckedChanged);
			   // 
			   // radioButtonSquare
			   // 
			   this->radioButtonSquare->AutoSize = true;
			   this->radioButtonSquare->Location = System::Drawing::Point(22, 42);
			   this->radioButtonSquare->Name = L"radioButtonSquare";
			   this->radioButtonSquare->Size = System::Drawing::Size(70, 20);
			   this->radioButtonSquare->TabIndex = 4;
			   this->radioButtonSquare->TabStop = true;
			   this->radioButtonSquare->Text = L"Square";
			   this->radioButtonSquare->UseVisualStyleBackColor = true;
			   this->radioButtonSquare->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonSquare_CheckedChanged);
			   // 
			   // radioButtonTriangle
			   // 
			   this->radioButtonTriangle->AutoSize = true;
			   this->radioButtonTriangle->Location = System::Drawing::Point(22, 65);
			   this->radioButtonTriangle->Name = L"radioButtonTriangle";
			   this->radioButtonTriangle->Size = System::Drawing::Size(76, 20);
			   this->radioButtonTriangle->TabIndex = 5;
			   this->radioButtonTriangle->TabStop = true;
			   this->radioButtonTriangle->Text = L"Triangle";
			   this->radioButtonTriangle->UseVisualStyleBackColor = true;
			   this->radioButtonTriangle->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonTriangle_CheckedChanged);
			   // 
			   // radioButtonLine
			   // 
			   this->radioButtonLine->AutoSize = true;
			   this->radioButtonLine->Location = System::Drawing::Point(22, 97);
			   this->radioButtonLine->Name = L"radioButtonLine";
			   this->radioButtonLine->Size = System::Drawing::Size(51, 20);
			   this->radioButtonLine->TabIndex = 6;
			   this->radioButtonLine->TabStop = true;
			   this->radioButtonLine->Text = L"Line";
			   this->radioButtonLine->UseVisualStyleBackColor = true;
			   this->radioButtonLine->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonLine_CheckedChanged);
			   // 
			   // radioButtonMove
			   // 
			   this->radioButtonMove->AutoSize = true;
			   this->radioButtonMove->Location = System::Drawing::Point(22, 126);
			   this->radioButtonMove->Name = L"radioButtonMove";
			   this->radioButtonMove->Size = System::Drawing::Size(60, 20);
			   this->radioButtonMove->TabIndex = 7;
			   this->radioButtonMove->TabStop = true;
			   this->radioButtonMove->Text = L"Move";
			   this->radioButtonMove->UseVisualStyleBackColor = true;
			   this->radioButtonMove->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButtonMove_CheckedChanged);
			   // 
			   // button_load
			   // 
			   this->button_load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->button_load->Location = System::Drawing::Point(933, 22);
			   this->button_load->Name = L"button_load";
			   this->button_load->Size = System::Drawing::Size(67, 27);
			   this->button_load->TabIndex = 8;
			   this->button_load->Text = L"Load";
			   this->button_load->UseVisualStyleBackColor = true;
			   this->button_load->Click += gcnew System::EventHandler(this, &MyForm::button_load_Click);
			   // 
			   // button_save
			   // 
			   this->button_save->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->button_save->Location = System::Drawing::Point(850, 22);
			   this->button_save->Name = L"button_save";
			   this->button_save->Size = System::Drawing::Size(67, 27);
			   this->button_save->TabIndex = 9;
			   this->button_save->Text = L"Save";
			   this->button_save->UseVisualStyleBackColor = true;
			   this->button_save->Click += gcnew System::EventHandler(this, &MyForm::button_save_Click);
			   // 
			   // button_clear
			   // 
			   this->button_clear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->button_clear->Location = System::Drawing::Point(933, 65);
			   this->button_clear->Name = L"button_clear";
			   this->button_clear->Size = System::Drawing::Size(67, 27);
			   this->button_clear->TabIndex = 10;
			   this->button_clear->Text = L"Clear";
			   this->button_clear->UseVisualStyleBackColor = true;
			   this->button_clear->Click += gcnew System::EventHandler(this, &MyForm::button_clear_Click);
			   // 
			   // render_timer
			   // 
			   this->render_timer->Enabled = true;
			   this->render_timer->Interval = 1;
			   this->render_timer->Tick += gcnew System::EventHandler(this, &MyForm::render_timer_Tick);
			   // 
			   // PowerMethodCheckBox
			   // 
			   this->PowerMethodCheckBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->PowerMethodCheckBox->AutoSize = true;
			   this->PowerMethodCheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			   this->PowerMethodCheckBox->Location = System::Drawing::Point(22, 417);
			   this->PowerMethodCheckBox->Name = L"PowerMethodCheckBox";
			   this->PowerMethodCheckBox->Size = System::Drawing::Size(393, 24);
			   this->PowerMethodCheckBox->TabIndex = 11;
			   this->PowerMethodCheckBox->Text = L"Enable/Disable Power Method of graph visualisation";
			   this->PowerMethodCheckBox->UseVisualStyleBackColor = true;
			   this->PowerMethodCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::PowerMethod_CheckedChanged);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->BackColor = System::Drawing::Color::White;
			   this->ClientSize = System::Drawing::Size(1030, 467);
			   this->Controls->Add(this->PowerMethodCheckBox);
			   this->Controls->Add(this->button_clear);
			   this->Controls->Add(this->button_save);
			   this->Controls->Add(this->button_load);
			   this->Controls->Add(this->radioButtonMove);
			   this->Controls->Add(this->radioButtonLine);
			   this->Controls->Add(this->radioButtonTriangle);
			   this->Controls->Add(this->radioButtonSquare);
			   this->Controls->Add(this->radioButtonCircle);
			   this->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->Name = L"MyForm";
			   this->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			   this->Text = L"Figure Painter for omp-system";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			   this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			   this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			   this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		// this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;

		this->radioButtonCircle->Select();
		this->PowerMethodCheckBox->Checked = true;
		this->DoubleBuffered = true;

		canvas = Canvas::GetInstance();
	}

	private: System::Void radioButtonCircle_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		curAction = ApplicationData::Action::Circle;
	}
	private: System::Void radioButtonTriangle_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		curAction = ApplicationData::Action::Triangle;
	}
	private: System::Void radioButtonSquare_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		curAction = ApplicationData::Action::Square;
	}
	private: System::Void radioButtonLine_CheckedChanged(System::Object^ sender, System::EventArgs^ se) {
		curAction = ApplicationData::Action::Line;
	}
	private: System::Void radioButtonMove_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		curAction = ApplicationData::Action::Move;
	}


	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		Point cp;
		cp = e->Location;

		cp.X -= len / 2;
		cp.Y -= len / 2;
		/// Render figure in the Center of mouse, not in upper left corner

		FigurePtr object;

		switch (curAction)
		{
		case ApplicationData::Action::Circle:

			canvas->CreateObject(Figure::Type::Circle, Color::Black, cp);

			break;

		case ApplicationData::Action::Triangle:

			canvas->CreateObject(Figure::Type::Triangle, Color::Black, cp);

			break;

		case ApplicationData::Action::Square:

			canvas->CreateObject(Figure::Type::Square, Color::Black, cp);

			break;

		case ApplicationData::Action::Line:

			firstPointOfLine = canvas->TakeClosestCenter(e->Location);
			tempSecondPointOfLine = e->Location;

			curAction = ApplicationData::Action::LineSecondPoint;
			
			break;

		case ApplicationData::Action::LineSecondPoint:

			if (firstPointOfLine == tempSecondPointOfLine) return;

			canvas->CreateObject(Figure::Type::Line, Color::Black, firstPointOfLine, tempSecondPointOfLine);
			curAction = ApplicationData::Action::Line;

			break;

		case ApplicationData::Action::Move:

			objectToMove = canvas->GetObjectPointer(cp);

			if (objectToMove == nullptr) canMove = false;
			else canMove = true;

		default:
			break;
		}
	}

	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		PowerMethod::SetFixedFigure(nullptr);
		if (curAction == ApplicationData::Action::Move && canMove == true) {
			Point pos = e->Location;

			pos.X -= len / 2;
			pos.Y -= len / 2;

			objectToMove->SetPosition(pos);
			PowerMethod::SetFixedFigure(objectToMove);
		}

		if (curAction == ApplicationData::Action::LineSecondPoint) {

			auto ClosestCenter = canvas->TakeClosestCenter(e->Location);

			if (ClosestCenter.X == tempSecondPointOfLine.X && ClosestCenter.Y == ClosestCenter.Y) return;

			tempSecondPointOfLine = ClosestCenter;
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		canMove = false;
	}

	private: System::Void button_save_Click(System::Object^ sender, System::EventArgs^ e) {
		
		SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
		
		saveDialog->ShowDialog();

		System::String^ fileName = saveDialog->FileName;

		msclr::interop::marshal_context context;
		std::string fileNameStdString = context.marshal_as<std::string>(fileName);

		canvas->SaveDataInFile(fileNameStdString);

	}
	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ loadDialog = gcnew OpenFileDialog();

		loadDialog->ShowDialog();

		System::String^ fileName = loadDialog->FileName;

		msclr::interop::marshal_context context;
		std::string fileNameStdString = context.marshal_as<std::string>(fileName);

		canvas->LoadDataFromFile(fileNameStdString);
	}

	private: System::Void button_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		canvas->ClearCanvas();
	}

	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
		canvas->UpdateCanvas(e->Graphics);
		if (curAction == ApplicationData::Action::LineSecondPoint) e->Graphics->DrawLine(gcnew Pen(Color::Black), firstPointOfLine, tempSecondPointOfLine);
	}

	private: System::Void render_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (powerMethod == true) PowerMethod::PowerMethodIteration(canvas->GetCanvasObjects());
		this->Invalidate();
	}

	private: System::Void PowerMethod_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		powerMethod = this->PowerMethodCheckBox->Checked;
	}
};
}
