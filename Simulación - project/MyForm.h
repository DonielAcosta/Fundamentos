#pragma once
#include "Juego.hpp"
#include <iostream>
namespace JuegoLider {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyForm : public Form
	{
	private:

		System::ComponentModel::IContainer^ components;
		System::Windows::Forms::Timer^ timer1;
		
		System::Windows::Forms::Button^ inicio;
		System::Windows::Forms::Button^ Terminar_Simulacion;
		System::Windows::Forms::Label^ HHtext;
		System::Windows::Forms::Label^ HHabitantes;
		System::Windows::Forms::Label^ Tiempo_Simulacion;
		System::Windows::Forms::Label^ label_TS;
	public:
		System::Windows::Forms::Button^ suma_conejos;
		System::Windows::Forms::Button^ boton_conejos;
		System::Windows::Forms::Button^ resta_conejos;
		System::Windows::Forms::Button^ suma_TS;
		System::Windows::Forms::Button^ boton_TS;
		System::Windows::Forms::Button^ resta_TS;

		Bitmap^ Fondo_Espacio;
		Bitmap^ Fig_Conejo;
		Bitmap^ Fig_Conejo_Macho;
		Bitmap^ Fig_Conejo_Enfermo;
		Bitmap^ Fig_Fondo;
		Graphics^ g;
		BufferedGraphics^ bg;

		int Num_C;
		int tiempo = 100;
		bool iniciar;
		bool ya = false;
		bool terminamos = false;
		int miliseguntos;
		bool centinela;

		Juego* juego;
		
		Direccion teclaPulsada;

		MyForm()
		{
			iniciar = false;
			Num_C = 15;
			InitializeComponent();
			Fondo_Espacio = gcnew Bitmap("Pista.png");
			Fig_Conejo = gcnew Bitmap("Fig_Conejo.png");
			Fig_Conejo_Macho = gcnew Bitmap("Fig_Conejo_Macho.png");
			Fig_Conejo_Enfermo = gcnew Bitmap("Fig_Conejo_Enfermo.png");
			Fig_Fondo = gcnew Bitmap("FONDO1.png");
			juego = new Juego(Fondo_Espacio, Fig_Conejo, Num_C, 100);
			boton_conejos->Text = "C" + Num_C.ToString();
			HHabitantes->Text = Num_C.ToString();
			label_TS->Text = "no disponible";
			centinela = false;
		}

	protected:
		~MyForm();
		void InitializeComponent(void);

	private:
		System::Void FrmJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
		System::Void FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
		System::Void FrmJuego_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void iniciar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Conejos_Mas_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Conejos_Menos_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TS_Mas_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void button15_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TS_Menos_Click_1(System::Object^ sender, System::EventArgs^ e);
		System::Void terminar(System::Object^ sender, System::EventArgs^ e);
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Boton_Zorros_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
