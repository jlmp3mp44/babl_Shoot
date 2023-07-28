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

		// Додати новий PictureBox на форму
		this->Controls->Add(newPictureBox);

		return newPictureBox;
	}


	public: void makeBalls(PictureBox^ red, PictureBox^ yellow,
		PictureBox^ blue, PictureBox^ green) {
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 6; i++) {
				int t = rand() % 4;
				switch (t)
				{
				case(0): CopyPictureBox(red, 20 + i * 70, 500 - j * 70); break;
				case(1): CopyPictureBox(yellow, 20 + i * 70, 500 - j * 70); break;
				case(2): CopyPictureBox(blue, 20 + i * 70, 500 - j * 70); break;
				case(3): CopyPictureBox(green, 20 + i * 70, 500 - j * 70); break;
				default:
					break;
				}
			}
		}
	}

	public: PictureBox^  makeUpBall(PictureBox^ lastPic) {
		PictureBox^ upBall =  CopyPictureBox(lastPic, 180, 50);
		return upBall;
	}

	
	};
}
