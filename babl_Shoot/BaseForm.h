#pragma once
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <chrono>


namespace bablShoot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BaseForm
	/// </summary>
	public ref class BaseForm : public System::Windows::Forms::Form
	{
	public:
		BaseForm(void)
		{
			InitializeComponent();
			allBalls = gcnew System::Collections::Generic::List<PictureBox^>();
			startX = 90;
			startY = 50;
		}

	protected:
		
		~BaseForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	    
		System::ComponentModel::Container ^components;
		System::Collections::Generic::List<PictureBox^>^ allBalls;
		int startX;
		int startY;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// BaseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 574);
			this->Name = L"BaseForm";
			this->Text = L"BaseForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	
	public: PictureBox^ CopyPictureBox(PictureBox^ sourcePictureBox, int x, int y)
	{
		PictureBox^ newPictureBox = gcnew PictureBox();
		newPictureBox->Image = sourcePictureBox->Image;
		newPictureBox->Location = System::Drawing::Point(x, y);
		newPictureBox->Size = sourcePictureBox->Size;
		newPictureBox->SizeMode = sourcePictureBox->SizeMode;
		newPictureBox->TabIndex = sourcePictureBox->TabIndex;
		newPictureBox->TabStop = sourcePictureBox->TabStop;
		newPictureBox->ForeColor = sourcePictureBox->ForeColor;
		

		this->Controls->Add(newPictureBox);

		return newPictureBox;
	}


	public:System::Collections ::Generic::List<PictureBox^>^ makeBalls(PictureBox^ red, PictureBox^ yellow,
		PictureBox^ blue, PictureBox^ green) {
		PictureBox^ picBox;
		System::Collections::Generic::List<PictureBox^>^ allBalls =
			gcnew System::Collections::Generic::List<PictureBox^>();
		array<PictureBox^>^ colors = gcnew array<PictureBox^>{ red, yellow, blue, green };

		srand(static_cast<unsigned>(time(0)));

		int colorIndex;
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 6; i++) {
				colorIndex = rand() % 4;
				picBox = CopyPictureBox(colors[colorIndex], 20 + i * 70, 500 - j * 70);
				allBalls->Add(picBox);
			}
		}
		return allBalls;
	}

	public: PictureBox^  makeUpBall(PictureBox^ lastPic) {
		PictureBox^ upBall =  CopyPictureBox(lastPic, startX, startY);
		return upBall;
	}

	public:bool CheckBounds(System::Collections::Generic::List<PictureBox^>^% allBalls,
		PictureBox^% upBall, bool% getBall, Timer^ timer, PictureBox^% lastBall,
		bool% touch, Label^% label, int% score, int% last) {
		for (int i = 0; i < allBalls->Count; i++) {
			if (upBall->Bounds.IntersectsWith(allBalls[i]->Bounds)) {
				touch = true;
				
				if (upBall->ForeColor != allBalls[i]->ForeColor) {
					getBall = false;
					touch = true;
					
					timer->Stop();

					break;
				}
				else {
					PlayAudio(L"D:/C++/babl_Shoot/sound/bubble.wav");
					Sleep(200);
					getBall = true;
					lastBall = allBalls[i];
					allBalls[i]->Location = Point(-60, -60);
					allBalls->RemoveAt(i);
					updateScore(label, score, last);
					last +=1;
					break;
					
				}
				if (!getBall) {
					timer->Stop();
					break;
				}
			}

		}
		return getBall;
	}

	public: void updateBall(PictureBox^% ball, PictureBox^ sourceBall) {
		ball->Image = sourceBall->Image;
		ball->Location = System::Drawing::Point(startX, startY);
		ball->TabIndex = sourceBall->TabIndex;
		ball->TabStop = sourceBall->TabStop;
		ball->ForeColor = sourceBall->ForeColor;
	}

	public: PictureBox^ makeRandomBall(PictureBox^% ball, PictureBox^ red, PictureBox^ yellow,
			  PictureBox^ blue, PictureBox^ green) {
			  array<PictureBox^>^ colors = gcnew array<PictureBox^>{ red, yellow, blue, green };

			  srand(static_cast<unsigned>(time(0)));

			  int colorIndex;
			  colorIndex = rand() % 4;
			  ball = CopyPictureBox(colors[colorIndex], startX, startY);
			  ball->Location = Point(-100, -100);

					  return ball;
				  }

	 public: void whatSide(bool% i) {
		 int randI = rand() % 2;

		 switch (randI)
		 {
		 case(0): i = 0; break;
		 case(1): i = 1; break;
		 }
	 }

	public: void updateScore(Label^% label, int% score, int% last) {
		if (last>0)  score += last * 2;
		else score += 1;
		std::cout << last;
		label->Text = "SCORE " + score.ToString();
	}

	public: bool checkBallsNull(System::Collections::Generic::List<PictureBox^>^% allBalls, Timer^ timer) {
		if (allBalls->Count == 0) {
			return 1;
			timer->Stop();
		}
			  else return 0;

	 }
	public: void checkCorrectBallPos(PictureBox^% ball) {
		while (ball->Location.Y != 430 && ball->Location.Y != 360 &&
			ball->Location.Y != 290 && ball->Location.Y != 220 ) {
			ball->Location = Point(ball->Location.X, ball->Location.Y - 1);

		}
	}
	public: void PlayAudio(const wchar_t* audioFilePath) {
			  PlaySound(audioFilePath, NULL, SND_ASYNC | SND_FILENAME);
		  }

	};
}
