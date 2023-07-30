#pragma once
#include <iostream>
#include <windows.h>


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


	public:System::Collections::Generic::List<PictureBox^>^  
		makeBalls(PictureBox^ red, PictureBox^ yellow,
		PictureBox^ blue, PictureBox^ green) {
		PictureBox^ picBox;
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 6; i++) {
				int t = rand() % 4;
				switch (t)
				{
				case(0):picBox =  CopyPictureBox(red, 20 + i * 70, 500 - j * 70);
					break;
				case(1):picBox = CopyPictureBox(yellow, 20 + i * 70, 500 - j * 70);
					break;
				case(2):picBox = CopyPictureBox(blue, 20 + i * 70, 500 - j * 70);
					break;
				case(3):picBox = CopyPictureBox(green, 20 + i * 70, 500 - j * 70);
					break;
				default:
					break;
				}
				allBalls->Add(picBox);
			}
		}
		return allBalls;
	}

	public: PictureBox^  makeUpBall(PictureBox^ lastPic) {
		PictureBox^ upBall =  CopyPictureBox(lastPic, 180, 50);
		return upBall;
	}

	public:void CheckBounds(System::Collections::Generic::List<PictureBox^>^% allBalls,
		PictureBox^% upBall, bool getBall, Timer^ timer) {
		for (int i = 0; i < allBalls->Count; i++) {
			if (upBall->Bounds.IntersectsWith(allBalls[i]->Bounds)) {
				if (upBall->ForeColor == allBalls[i]->ForeColor) {
					getBall = true;
					allBalls[i]->Location = Point(-60, -60);

				}
				else getBall = false;
				if (!getBall)
					timer->Stop();
			}
		}
	}

	
	};
}
