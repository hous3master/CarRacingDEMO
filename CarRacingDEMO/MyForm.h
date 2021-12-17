#pragma once
#include "Game.h"
namespace CarRacingDEMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			objGame = new Game();
			bmpCar = gcnew Bitmap("vehicle.png");
			bmpObstacles = gcnew Bitmap("obstacles.png");
			bmpBG = gcnew Bitmap("background.png");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Game* objGame;
		Bitmap^ bmpCar;
		Bitmap^ bmpObstacles;
	private: System::Windows::Forms::Label^ label1;
		   Bitmap^ bmpBG;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Yellow;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 753);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(800, 800);
			this->MinimumSize = System::Drawing::Size(800, 800);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objGame->new_orientation(direction::left);
		if (e->KeyCode == Keys::Right) objGame->new_orientation(direction::right);
		if (e->KeyCode == Keys::Up) objGame->new_orientation(direction::up);
		if (e->KeyCode == Keys::Down) objGame->new_orientation(direction::down);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//BACKGROUND
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = space->Allocate(g, ClientRectangle);
		//bf->Graphics->Clear(Color::White); //Solid color
		bf->Graphics->DrawImage(bmpBG, 0, 0, bmpBG->Width, bmpBG->Height); //Custom BG

		//Execution
		objGame->Draw_Car(bf->Graphics, bmpCar);
		objGame->Draw_Obstacle(bf->Graphics, bmpObstacles);
		objGame->Colision();
		objGame->Insert_Obstacles();
		if (objGame->End_Game())
			timer1->Enabled = false;
		label1->Text = objGame->return_text_lifes();
		bf->Render(g);
		delete bf, space, g;
	}
	};
}
