#pragma once
#include "BaseForm.h"
#include <iostream>
namespace bablShoot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : BaseForm
	{
	public:
		Main(void)
		{
			InitializeComponent();
		    upBall = makeUpBall(red);
			i = true;
			allBalls = gcnew System::Collections::Generic::List<PictureBox^>();
			lastBallColor = Color::White;
			getBall = false;
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ yellow;
	private: System::Windows::Forms::PictureBox^ red;
	private: System::Windows::Forms::PictureBox^ blue;
	private: System::Windows::Forms::PictureBox^ green;
	private: PictureBox^ upBall;
	private: bool i;
	private: System::Collections::Generic::List<PictureBox^>^ allBalls;
	private: Color^ lastBallColor;
	private: bool getBall;


	private: System::Windows::Forms::Timer^ moveTimer;

	private: System::Windows::Forms::Timer^ secondTimer;

	protected:

	protected:

	protected:

	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->yellow = (gcnew System::Windows::Forms::PictureBox());
			this->red = (gcnew System::Windows::Forms::PictureBox());
			this->blue = (gcnew System::Windows::Forms::PictureBox());
			this->green = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yellow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->red))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->green))->BeginInit();
			this->SuspendLayout();
			// 
			// yellow
			// 
			this->yellow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"yellow.Image")));
			this->yellow->Location = System::Drawing::Point(-100, -100);
			this->yellow->Name = L"yellow";
			this->yellow->Size = System::Drawing::Size(81, 81);
			this->yellow->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->yellow->ForeColor = Color::Yellow;
			this->yellow->TabIndex = 0;
			this->yellow->TabStop = false;
			// 
			// red
			// 
			this->red->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"red.Image")));
			this->red->Location = System::Drawing::Point(-100, -100);
			this->red->Name = L"red";
			this->red->Size = System::Drawing::Size(83, 81);
			this->red->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->red->ForeColor = Color::Red;
			this->red->TabIndex = 1;
			this->red->TabStop = false;
			// 
			// blue
			// 
			this->blue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blue.Image")));
			this->blue->Location = System::Drawing::Point(-100, -100);
			this->blue->Name = L"blue";
			this->blue->Size = System::Drawing::Size(83, 81);
			this->blue->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->blue->ForeColor = Color::Blue;
			this->blue->TabIndex = 2;
			this->blue->TabStop = false;
			// 
			// green
			// 
			this->green->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"green.Image")));
			this->green->Location = System::Drawing::Point(-100, -100);
			this->green->Name = L"green";
			this->green->Size = System::Drawing::Size(83, 81);
			this->green->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->green->ForeColor = Color::Green;
			this->green->TabIndex = 3;
			this->green->TabStop = false;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(588, 706);
			this->Controls->Add(this->green);
			this->Controls->Add(this->blue);
			this->Controls->Add(this->red);
			this->Controls->Add(this->yellow);
			this->Name = L"Main";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Main::Main_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yellow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->red))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->blue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->green))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	

	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
		allBalls = makeBalls(red, yellow, blue,green);
		
		moveTimer = gcnew Timer();
		moveTimer->Interval = 100; // Встановіть інтервал в мілісекундах (тут 100 мс)
		moveTimer->Tick += gcnew EventHandler(this, &Main::moveTimer_Tick);
		moveTimer->Start();

		secondTimer = gcnew Timer();
		secondTimer->Interval = 100;
		secondTimer->Tick += gcnew EventHandler(this, &Main::secondTimer_Tick);
		
	}


	private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		int posX = upBall->Location.X;
		int posY = upBall->Location.Y;

		// Переміщення PictureBox вправо до певної позиції (тут до 300)
		if (i) {
			upBall->Location = Point(posX + 10, posY);
			if (posX >= 380) {
				i = false; // Змінюємо напрямок руху
			}
		}
		// Переміщення PictureBox вліво
		else {
			upBall->Location = Point(posX - 10, posY);
			if (posX <= 20) {
				i = true; // Змінюємо напрямок руху
			}
		}
	}
			
 
	private: System::Void Main_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if(e->KeyCode==Keys::Enter){
			secondTimer->Start();
			moveTimer->Stop();
		}
	}

	public: System::Void secondTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		  if(upBall->Location.Y<=500) 
			  upBall->Location = Point(upBall->Location.X, upBall->Location.Y + 10);
		  CheckBounds(allBalls, upBall, getBall, secondTimer);
		 
	   }

	
};
}

