#pragma once

#include "Data.h"
#include "windows.h"

#include "Canvas.h"

#include "Line.h"
#include "Figure.h"

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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::RadioButton^ radioButtonCircle;

	private: System::Windows::Forms::RadioButton^ radioButtonSquare;


	private: System::Windows::Forms::RadioButton^ radioButtonTriangle;



	private: System::Windows::Forms::RadioButton^ radioButtonLine;

		   const int lenDataForFigures = 50;

		   Graphics^ MyGraphics;
		   ApplicationData::Action curAction;

		   Point firstPointOfLine;
		   Point tempSeconfPointOfLine;

		   int countClicksOfLine = 0;

		   bool canMove = false;
		   Point pointMove;

	private: System::Windows::Forms::RadioButton^ radioButtonMove;
	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::Button^ button_save;
	private: System::Windows::Forms::Button^ button_clear;

		   Canvas* canvas;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// ��������� ����� ��� ��������� ������������ � �� ��������� 
		   /// ���������� ����� ������ � ������� ��������� ����.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->radioButtonCircle = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonSquare = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonTriangle = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonLine = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonMove = (gcnew System::Windows::Forms::RadioButton());
			   this->button_load = (gcnew System::Windows::Forms::Button());
			   this->button_save = (gcnew System::Windows::Forms::Button());
			   this->button_clear = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // radioButtonCircle
			   // 
			   this->radioButtonCircle->AutoSize = true;
			   this->radioButtonCircle->Location = System::Drawing::Point(27, 27);
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
			   this->radioButtonSquare->Location = System::Drawing::Point(27, 54);
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
			   this->radioButtonTriangle->Location = System::Drawing::Point(27, 81);
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
			   this->radioButtonLine->Location = System::Drawing::Point(27, 121);
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
			   this->radioButtonMove->Location = System::Drawing::Point(27, 159);
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
			   this->button_load->Location = System::Drawing::Point(964, 27);
			   this->button_load->Name = L"button_load";
			   this->button_load->Size = System::Drawing::Size(54, 26);
			   this->button_load->TabIndex = 8;
			   this->button_load->Text = L"Load";
			   this->button_load->UseVisualStyleBackColor = true;
			   this->button_load->Click += gcnew System::EventHandler(this, &MyForm::button_load_Click);
			   // 
			   // button_save
			   // 
			   this->button_save->Location = System::Drawing::Point(904, 27);
			   this->button_save->Name = L"button_save";
			   this->button_save->Size = System::Drawing::Size(54, 26);
			   this->button_save->TabIndex = 9;
			   this->button_save->Text = L"Save";
			   this->button_save->UseVisualStyleBackColor = true;
			   this->button_save->Click += gcnew System::EventHandler(this, &MyForm::button_save_Click);
			   // 
			   // button_clear
			   // 
			   this->button_clear->Location = System::Drawing::Point(964, 59);
			   this->button_clear->Name = L"button_clear";
			   this->button_clear->Size = System::Drawing::Size(54, 26);
			   this->button_clear->TabIndex = 10;
			   this->button_clear->Text = L"Clear";
			   this->button_clear->UseVisualStyleBackColor = true;
			   this->button_clear->Click += gcnew System::EventHandler(this, &MyForm::button_clear_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::White;
			   this->ClientSize = System::Drawing::Size(1062, 467);
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
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			   this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			   this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		MyGraphics = this->CreateGraphics();
		this->radioButtonCircle->Select();

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

		cp.X -= lenDataForFigures / 2;
		cp.Y -= lenDataForFigures / 2;
		/// Render figure in the Center of mouse, not in upper left corner

		switch (curAction)
		{
		case ApplicationData::Action::Circle:

			canvas->CreateObject(Figure::Type::Circle, Color::Black, cp);
			canvas->UpdateCanvas(MyGraphics);

			break;

		case ApplicationData::Action::Triangle:

			canvas->CreateObject(Figure::Type::Triangle, Color::Black, cp);
			canvas->UpdateCanvas(MyGraphics);

			break;

		case ApplicationData::Action::Square:

			canvas->CreateObject(Figure::Type::Square, Color::Black, cp);
			canvas->UpdateCanvas(MyGraphics);

			break;

		case ApplicationData::Action::Line:

			if (countClicksOfLine == 0) {

				firstPointOfLine = canvas->TakeClosestCenter(e->Location);
				tempSeconfPointOfLine = e->Location;

				countClicksOfLine = 1;

				MyGraphics->DrawLine(gcnew Pen(Color::Black), firstPointOfLine, tempSeconfPointOfLine);
			}
			else if (countClicksOfLine == 1) {

				// create Line
				FigurePtr object;

				// object = canvas->CreateObject(Figure::Type::Line, Color::Black, firstPointOfLine, tempSeconfPointOfLine);
				canvas->CreateObject(Figure::Type::Line, Color::Black, firstPointOfLine, tempSeconfPointOfLine);
				canvas->UpdateCanvas(MyGraphics);

				// canvas->GetObjectPointer(firstPointOfLine)->AddLine(std::static_pointer_cast<Line>(object));
				// canvas->GetObjectPointer(tempSeconfPointOfLine)->AddLine(std::static_pointer_cast<Line>(object));

				countClicksOfLine = 0;
			}

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

		if (curAction == ApplicationData::Action::Move && canMove == true) {
			Point pos = e->Location;

			pos.X -= len / 2;
			pos.Y -= len / 2;

			canvas->ClearRenderLines(MyGraphics);

			objectToMove->Draw(MyGraphics, Color::White);
			objectToMove->SetPosition(pos);

			canvas->UpdateCanvas(MyGraphics);

		}

		if (curAction == ApplicationData::Action::Line && countClicksOfLine == 1) {

			MyGraphics->DrawLine(gcnew Pen(Color::White), firstPointOfLine, tempSeconfPointOfLine);

			tempSeconfPointOfLine = canvas->TakeClosestCenter(e->Location);
			MyGraphics->DrawLine(gcnew Pen(Color::Black), firstPointOfLine, tempSeconfPointOfLine);

			canvas->UpdateCanvas(MyGraphics);
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
		canvas->UpdateCanvas(MyGraphics);
	}

	private: System::Void button_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		canvas->ClearCanvas();
		canvas->UpdateCanvas(MyGraphics);
	}

};
}
