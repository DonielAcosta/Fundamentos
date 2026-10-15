#include "MyForm.h"


JuegoLider::MyForm::~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

void JuegoLider::MyForm::InitializeComponent(void)
		{
	this->components = (gcnew System::ComponentModel::Container());
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
	this->inicio = (gcnew System::Windows::Forms::Button());
	this->HHtext = (gcnew System::Windows::Forms::Label());
	this->HHabitantes = (gcnew System::Windows::Forms::Label());
	this->label_TS = (gcnew System::Windows::Forms::Label());
	this->suma_conejos = (gcnew System::Windows::Forms::Button());
	this->boton_conejos = (gcnew System::Windows::Forms::Button());
	this->resta_conejos = (gcnew System::Windows::Forms::Button());
	this->suma_TS = (gcnew System::Windows::Forms::Button());
	this->boton_TS = (gcnew System::Windows::Forms::Button());
	this->resta_TS = (gcnew System::Windows::Forms::Button());
	this->Tiempo_Simulacion = (gcnew System::Windows::Forms::Label());
	this->Terminar_Simulacion = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// timer1
	// 
	this->timer1->Enabled = true;
	this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
	// 
	// inicio
	// 
	this->inicio->BackColor = System::Drawing::Color::DarkSlateGray;
	this->inicio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->inicio->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->inicio->Location = System::Drawing::Point(505, 472);
	this->inicio->Name = L"inicio";
	this->inicio->Size = System::Drawing::Size(95, 35);
	this->inicio->TabIndex = 0;
	this->inicio->Text = L"inicio";
	this->inicio->UseVisualStyleBackColor = false;
	this->inicio->Click += gcnew System::EventHandler(this, &MyForm::iniciar_Click);
	// 
	// HHtext
	// 
	this->HHtext->AutoSize = true;
	this->HHtext->BackColor = System::Drawing::Color::White;
	this->HHtext->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->HHtext->ForeColor = System::Drawing::Color::Black;
	this->HHtext->Location = System::Drawing::Point(320, 567);
	this->HHtext->Name = L"HHtext";
	this->HHtext->Size = System::Drawing::Size(113, 18);
	this->HHtext->TabIndex = 10;
	this->HHtext->Text = L"Habitantes->";
	this->HHtext->Visible = false;
	// 
	// HHabitantes
	// 
	this->HHabitantes->AutoSize = true;
	this->HHabitantes->BackColor = System::Drawing::Color::White;
	this->HHabitantes->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->HHabitantes->ForeColor = System::Drawing::Color::Black;
	this->HHabitantes->Location = System::Drawing::Point(429, 567);
	this->HHabitantes->Name = L"HHabitantes";
	this->HHabitantes->Size = System::Drawing::Size(103, 18);
	this->HHabitantes->TabIndex = 11;
	this->HHabitantes->Text = L"Habitantes:";
	this->HHabitantes->Visible = false;
	// 
	// label_TS
	// 
	this->label_TS->AutoSize = true;
	this->label_TS->BackColor = System::Drawing::Color::White;
	this->label_TS->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->label_TS->ForeColor = System::Drawing::Color::Black;
	this->label_TS->Location = System::Drawing::Point(156, 567);
	this->label_TS->Name = L"label_TS";
	this->label_TS->Size = System::Drawing::Size(28, 18);
	this->label_TS->TabIndex = 20;
	this->label_TS->Text = L"TS";
	this->label_TS->Visible = false;
	// 
	// suma_conejos
	// 
	this->suma_conejos->BackColor = System::Drawing::Color::Gainsboro;
	this->suma_conejos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->suma_conejos->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->suma_conejos->Location = System::Drawing::Point(386, 444);
	this->suma_conejos->Name = L"suma_conejos";
	this->suma_conejos->Size = System::Drawing::Size(56, 43);
	this->suma_conejos->TabIndex = 26;
	this->suma_conejos->Text = L"+";
	this->suma_conejos->UseVisualStyleBackColor = false;
	this->suma_conejos->Click += gcnew System::EventHandler(this, &MyForm::Conejos_Mas_Click);
	// 
	// boton_conejos
	// 
	this->boton_conejos->BackColor = System::Drawing::Color::Gainsboro;
	this->boton_conejos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->boton_conejos->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->boton_conejos->Location = System::Drawing::Point(308, 444);
	this->boton_conejos->Name = L"boton_conejos";
	this->boton_conejos->Size = System::Drawing::Size(73, 43);
	this->boton_conejos->TabIndex = 25;
	this->boton_conejos->Text = L"C1";
	this->boton_conejos->UseVisualStyleBackColor = false;
	// 
	// resta_conejos
	// 
	this->resta_conejos->BackColor = System::Drawing::Color::Gainsboro;
	this->resta_conejos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->resta_conejos->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->resta_conejos->Location = System::Drawing::Point(245, 444);
	this->resta_conejos->Name = L"resta_conejos";
	this->resta_conejos->Size = System::Drawing::Size(56, 43);
	this->resta_conejos->TabIndex = 24;
	this->resta_conejos->Text = L"-";
	this->resta_conejos->UseVisualStyleBackColor = false;
	this->resta_conejos->Click += gcnew System::EventHandler(this, &MyForm::Conejos_Menos_Click);
	// 
	// suma_TS
	// 
	this->suma_TS->BackColor = System::Drawing::Color::Gainsboro;
	this->suma_TS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->suma_TS->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->suma_TS->Location = System::Drawing::Point(386, 490);
	this->suma_TS->Name = L"suma_TS";
	this->suma_TS->Size = System::Drawing::Size(56, 43);
	this->suma_TS->TabIndex = 31;
	this->suma_TS->Text = L"+";
	this->suma_TS->UseVisualStyleBackColor = false;
	this->suma_TS->Click += gcnew System::EventHandler(this, &MyForm::TS_Mas_Click);
	// 
	// boton_TS
	// 
	this->boton_TS->BackColor = System::Drawing::Color::Gainsboro;
	this->boton_TS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->boton_TS->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->boton_TS->Location = System::Drawing::Point(307, 490);
	this->boton_TS->Name = L"boton_TS";
	this->boton_TS->Size = System::Drawing::Size(73, 43);
	this->boton_TS->TabIndex = 30;
	this->boton_TS->Text = L"100";
	this->boton_TS->UseVisualStyleBackColor = false;
	// 
	// resta_TS
	// 
	this->resta_TS->BackColor = System::Drawing::Color::Gainsboro;
	this->resta_TS->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->resta_TS->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->resta_TS->Location = System::Drawing::Point(245, 489);
	this->resta_TS->Name = L"resta_TS";
	this->resta_TS->Size = System::Drawing::Size(56, 43);
	this->resta_TS->TabIndex = 29;
	this->resta_TS->Text = L"-";
	this->resta_TS->UseVisualStyleBackColor = false;
	this->resta_TS->Click += gcnew System::EventHandler(this, &MyForm::TS_Menos_Click_1);
	// 
	// Tiempo_Simulacion
	// 
	this->Tiempo_Simulacion->AutoSize = true;
	this->Tiempo_Simulacion->BackColor = System::Drawing::Color::White;
	this->Tiempo_Simulacion->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Tiempo_Simulacion->ForeColor = System::Drawing::Color::Black;
	this->Tiempo_Simulacion->Location = System::Drawing::Point(72, 567);
	this->Tiempo_Simulacion->Name = L"Tiempo_Simulacion";
	this->Tiempo_Simulacion->Size = System::Drawing::Size(74, 18);
	this->Tiempo_Simulacion->TabIndex = 34;
	this->Tiempo_Simulacion->Text = L"TIEMPO";
	this->Tiempo_Simulacion->Visible = false;
	// 
	// Terminar_Simulacion
	// 
	this->Terminar_Simulacion->BackColor = System::Drawing::Color::DarkSlateGray;
	this->Terminar_Simulacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Terminar_Simulacion->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
	this->Terminar_Simulacion->Location = System::Drawing::Point(606, 472);
	this->Terminar_Simulacion->Name = L"Terminar_Simulacion";
	this->Terminar_Simulacion->Size = System::Drawing::Size(95, 35);
	this->Terminar_Simulacion->TabIndex = 35;
	this->Terminar_Simulacion->Text = L"Finalizar";
	this->Terminar_Simulacion->UseVisualStyleBackColor = false;
	this->Terminar_Simulacion->Visible = false;
	this->Terminar_Simulacion->Click += gcnew System::EventHandler(this, &MyForm::terminar);
	// 
	// MyForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::Azure;
	this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
	this->ClientSize = System::Drawing::Size(861, 594);
	this->Controls->Add(this->Terminar_Simulacion);
	this->Controls->Add(this->Tiempo_Simulacion);
	this->Controls->Add(this->suma_TS);
	this->Controls->Add(this->boton_TS);
	this->Controls->Add(this->resta_TS);
	this->Controls->Add(this->suma_conejos);
	this->Controls->Add(this->boton_conejos);
	this->Controls->Add(this->resta_conejos);
	this->Controls->Add(this->label_TS);
	this->Controls->Add(this->HHabitantes);
	this->Controls->Add(this->HHtext);
	this->Controls->Add(this->inicio);
	this->DoubleBuffered = true;
	this->KeyPreview = true;
	this->Name = L"MyForm";
	this->Text = L"Modelo Predador - Presa";
	this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
	this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::FrmJuego_Paint);
	this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::FrmJuego_KeyDown);
	this->ResumeLayout(false);
	this->PerformLayout();

}


	
		System::Void JuegoLider::MyForm::FrmJuego_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			g = this->CreateGraphics();
			BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
			bg = bfc->Allocate(g, this->ClientRectangle);
		}
		System::Void JuegoLider::MyForm::FrmJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::W) this->teclaPulsada = Direccion::Arriba;
			if (e->KeyCode == Keys::A) this->teclaPulsada = Direccion::Izquierda;
			if (e->KeyCode == Keys::S) this->teclaPulsada = Direccion::Derecha;
			if (e->KeyCode == Keys::Z) this->teclaPulsada = Direccion::Abajo;
			if (e->KeyCode == Keys::O)
			{
				Terminar_Simulacion->Visible = true;
			}
			if (e->KeyCode == Keys::I)
			{


				Terminar_Simulacion->Visible = false;
			}
			//juego->cambiarDireccion(this->teclaPulsada);
		}
		System::Void JuegoLider::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			

				if (iniciar)
				{
					//int ancho = g->VisibleClipBounds.Width;
					//int alto = g->VisibleClipBounds.Height;
					//bg->Graphics->DrawImage(Fig_Fondo, 0, 0, ancho, alto);
					juego->mover(this->teclaPulsada, Fig_Conejo);
					juego->dibujar(bg, Fondo_Espacio, Fig_Conejo);
					//this->HHabitantes->Text = (juego->N_Conejos).ToString();
					//this->label_TS->Text = this->tiempo.ToString();

					bg->Render(g);
				}
			
		}
		System::Void JuegoLider::MyForm::FrmJuego_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		System::Void JuegoLider::MyForm::iniciar_Click(System::Object^ sender, System::EventArgs^ e) {
			juego = new Juego( Fondo_Espacio, Fig_Conejo,Num_C, 100);
			iniciar = true;
			
			delete inicio;
			delete suma_TS;
			delete boton_TS;
			delete resta_TS;
			delete boton_conejos;
			delete suma_conejos;
			delete resta_conejos;

		}
		
		
		



		System::Void JuegoLider::MyForm::Conejos_Mas_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Num_C++;
			boton_conejos->Text = "C" + Num_C.ToString();
		}
		System::Void JuegoLider::MyForm::Conejos_Menos_Click(System::Object^ sender, System::EventArgs^ e) {
			if (Num_C >= 2)
			{
				Num_C--;
				boton_conejos->Text = "C" + Num_C.ToString();
			}
		}
		System::Void JuegoLider::MyForm::TS_Mas_Click(System::Object^ sender, System::EventArgs^ e) {

			this->tiempo += 50;
			cout << tiempo << endl;
			boton_TS->Text = tiempo.ToString();

		}
		System::Void JuegoLider::MyForm::button15_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		System::Void JuegoLider::MyForm::TS_Menos_Click_1(System::Object^ sender, System::EventArgs^ e) {
			if (this->tiempo > 100)
			{
				this->tiempo -= 10;
				boton_TS->Text = tiempo.ToString();
			}
		}

		System::Void JuegoLider::MyForm::terminar(System::Object^ sender, System::EventArgs^ e) {
			Terminar_Simulacion->Visible = false;
			terminamos = false;
			ya = true;
			Tiempo_Simulacion->Visible = false;//el tiempo
			this->label_TS->Visible = false;
			this->HHabitantes->Visible = false;
			this->HHtext->Visible = false;

		}
		System::Void JuegoLider::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}



