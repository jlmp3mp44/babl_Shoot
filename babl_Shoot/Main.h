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
			//
			//TODO: Add the constructor code here
			//
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

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
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
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(588, 706);
			this->Name = L"Main";
			this->Text = L"Main";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Main::Main_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
		array <Color>^ colors = makeColors();
		bool mainCircle = false;
	protected: virtual void OnPaint(PaintEventArgs^ e) override
		{
			Form::OnPaint(e);
			
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 7; i++) {
					int t = rand() % 4;

					DrawCircle(colors[t], 40 + i * 50, 500-j*50);

				}
			}
		
		}
	private: System::Void Main_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			mainCircle = true;
			Graphics^ upCircle =  DrawCircle(colors[2], 200, 200);
			move(upCircle);
		}
	}
	public:void  move(Graphics^ circle) {
		delete circle;
		for (int i = 0; i < 10; i++) {
			DrawCircle(colors[2], 200 + i*50, 200);
			
			
		}
	}
	};
}
