#pragma once

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
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BaseForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
	
	public: Graphics^ DrawCircle(Color fillColor, int X, int Y)
		{

			Graphics^ g = this->CreateGraphics();

			SolidBrush^ brush = gcnew SolidBrush(fillColor);

			int diameter = 50;

			g->FillEllipse(brush, X, Y, diameter, diameter);

			//delete g;
			return g;
		}
	

	public: array<Color>^ makeColors() {
		array<Color>^ colorsArray;
		colorsArray = gcnew array<Color> {
			Color::Red,
			Color::Green,
			Color::Blue,
			Color::Yellow
		};
		return colorsArray;
	}
	};
}
