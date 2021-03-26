#pragma once
#include "Juego.h"
#include "string"
#include "sstream"

namespace CarreraAutos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			bmpCarro = gcnew Bitmap("imagen/sprite_carros.png");
			objJuego = new Juego();
			objJuego->AgregarCarros(6 , g , bmpCarro);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		Graphics^ g;
		Juego* objJuego;
	    Bitmap^ bmpCarro;
	private: 
		System::Windows::Forms::Timer^ timer1;

		string toString(int numero) {
			stringstream cadena;
			cadena << numero;
			return cadena.str();
		}

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1083, 452);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::LightGreen);

		objJuego->AnimacionCarros(buffer->Graphics , bmpCarro);

		objJuego->AnimacionObstaculos(buffer->Graphics);
		objJuego->Colision();

		buffer->Render(g);
		delete buffer;
		delete espacio;

		if (objJuego->LlegoCarrosMeta()) {
			this->timer1->Enabled = false;
			String ^cadena = "";

			objJuego->OrdenarPuestos();
			for (int i = 0; i < objJuego->getCantCarros();i++) {
				Carro* obj = objJuego->ObtenerCarro(i);
				
				cadena = cadena + "Puesto : " + obj->getPuesto() +" => Carro N. " + obj->getNroCarro() + "\n";
			}
			MessageBox::Show(cadena, "Resultados");
			this->Close();
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Space:
			// lanzamos
			objJuego->MoverObstaculo();
			break;
		}
	}   
	};
}
