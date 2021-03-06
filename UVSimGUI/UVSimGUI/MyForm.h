#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>
#include <vector>
#include "ALU.h"
#include "File.h"

#pragma warning(disable : 4996)

namespace UVSimGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//memory had to be global to fix the user input problem
	//(someone can try to make it not global, but please don't break the code lol)
	const int MEMSIZE = 1000;
	int memory[MEMSIZE];

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			myALU = new ALU;
			myFile = new File;
			//TODO: Add the constructor code here
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
	private: System::Windows::Forms::Label^  TitleL;
	protected:

	private: System::Windows::Forms::TextBox^  MemoryTB;
	private: System::Windows::Forms::Label^  MemoryL;
	protected:


	private: System::Windows::Forms::TextBox^  AccumTB;
	private: System::Windows::Forms::TextBox^  InRegTB;
	private: System::Windows::Forms::TextBox^  InCouTB;
	private: System::Windows::Forms::Label^  AccumL;
	private: System::Windows::Forms::Label^  InRegL;
	private: System::Windows::Forms::Label^  InCouL;






	private: System::Windows::Forms::TextBox^  OpCodTB;
	private: System::Windows::Forms::TextBox^  OprndTB;
	private: System::Windows::Forms::Label^  OpCodL;
	private: System::Windows::Forms::Label^  OprndL;




	private: System::Windows::Forms::Label^  InputL;

	private: System::Windows::Forms::TextBox^  InputTB;


	private: System::Windows::Forms::Label^  RunL;

	private: System::Windows::Forms::TextBox^  OutInputTB;
	private: System::Windows::Forms::TextBox^  OutLabelTB;

	private:
		//declare any variables here that are needed
		/// <summary>
		//instance for ALU class
		ALU* myALU;
		File* myFile;

		msclr::interop::marshal_context context;

		//var for user input
		int myInput = 0;
		bool needInput = false;
		bool firstCompile = true;

		//vars for data and memory conversion
		int numLines = 0;
		char* recentLine;
		char* subStr;
		bool newFileOption = false;
		bool loadFileOption = false;
		bool saveFileOption = false;

		//variable for running the code
		int counter = 0;

	private: System::Windows::Forms::Button^  InputB;
	private: System::Windows::Forms::Button^  RunB;
	private: System::Windows::Forms::MenuStrip^  Menu;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  FileLabelTB;
	private: System::Windows::Forms::TextBox^  FileTB;
	private: System::Windows::Forms::Button^  FileB;
			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->TitleL = (gcnew System::Windows::Forms::Label());
				 this->MemoryTB = (gcnew System::Windows::Forms::TextBox());
				 this->MemoryL = (gcnew System::Windows::Forms::Label());
				 this->AccumTB = (gcnew System::Windows::Forms::TextBox());
				 this->InRegTB = (gcnew System::Windows::Forms::TextBox());
				 this->InCouTB = (gcnew System::Windows::Forms::TextBox());
				 this->AccumL = (gcnew System::Windows::Forms::Label());
				 this->InRegL = (gcnew System::Windows::Forms::Label());
				 this->InCouL = (gcnew System::Windows::Forms::Label());
				 this->OpCodTB = (gcnew System::Windows::Forms::TextBox());
				 this->OprndTB = (gcnew System::Windows::Forms::TextBox());
				 this->OpCodL = (gcnew System::Windows::Forms::Label());
				 this->OprndL = (gcnew System::Windows::Forms::Label());
				 this->InputL = (gcnew System::Windows::Forms::Label());
				 this->InputTB = (gcnew System::Windows::Forms::TextBox());
				 this->RunL = (gcnew System::Windows::Forms::Label());
				 this->OutInputTB = (gcnew System::Windows::Forms::TextBox());
				 this->OutLabelTB = (gcnew System::Windows::Forms::TextBox());
				 this->InputB = (gcnew System::Windows::Forms::Button());
				 this->RunB = (gcnew System::Windows::Forms::Button());
				 this->Menu = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->FileLabelTB = (gcnew System::Windows::Forms::TextBox());
				 this->FileTB = (gcnew System::Windows::Forms::TextBox());
				 this->FileB = (gcnew System::Windows::Forms::Button());
				 this->Menu->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // TitleL
				 // 
				 this->TitleL->AutoSize = true;
				 this->TitleL->BackColor = System::Drawing::Color::Transparent;
				 this->TitleL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->TitleL->Location = System::Drawing::Point(5, 27);
				 this->TitleL->Name = L"TitleL";
				 this->TitleL->Size = System::Drawing::Size(135, 48);
				 this->TitleL->TabIndex = 0;
				 this->TitleL->Text = L"UVSim";
				 // 
				 // MemoryTB
				 // 
				 this->MemoryTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->MemoryTB->Location = System::Drawing::Point(442, 116);
				 this->MemoryTB->Multiline = true;
				 this->MemoryTB->Name = L"MemoryTB";
				 this->MemoryTB->ReadOnly = true;
				 this->MemoryTB->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				 this->MemoryTB->Size = System::Drawing::Size(423, 291);
				 this->MemoryTB->TabIndex = 1;
				 // 
				 // MemoryL
				 // 
				 this->MemoryL->AutoSize = true;
				 this->MemoryL->BackColor = System::Drawing::Color::Transparent;
				 this->MemoryL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->MemoryL->Location = System::Drawing::Point(760, 75);
				 this->MemoryL->Name = L"MemoryL";
				 this->MemoryL->Size = System::Drawing::Size(105, 31);
				 this->MemoryL->TabIndex = 2;
				 this->MemoryL->Text = L"Memory";
				 // 
				 // AccumTB
				 // 
				 this->AccumTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->AccumTB->Location = System::Drawing::Point(266, 97);
				 this->AccumTB->Name = L"AccumTB";
				 this->AccumTB->ReadOnly = true;
				 this->AccumTB->Size = System::Drawing::Size(147, 23);
				 this->AccumTB->TabIndex = 3;
				 // 
				 // InRegTB
				 // 
				 this->InRegTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InRegTB->Location = System::Drawing::Point(266, 167);
				 this->InRegTB->Name = L"InRegTB";
				 this->InRegTB->ReadOnly = true;
				 this->InRegTB->Size = System::Drawing::Size(147, 23);
				 this->InRegTB->TabIndex = 4;
				 // 
				 // InCouTB
				 // 
				 this->InCouTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InCouTB->Location = System::Drawing::Point(266, 238);
				 this->InCouTB->Name = L"InCouTB";
				 this->InCouTB->ReadOnly = true;
				 this->InCouTB->Size = System::Drawing::Size(147, 23);
				 this->InCouTB->TabIndex = 5;
				 // 
				 // AccumL
				 // 
				 this->AccumL->AutoSize = true;
				 this->AccumL->BackColor = System::Drawing::Color::Transparent;
				 this->AccumL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->AccumL->Location = System::Drawing::Point(262, 75);
				 this->AccumL->Name = L"AccumL";
				 this->AccumL->Size = System::Drawing::Size(97, 19);
				 this->AccumL->TabIndex = 6;
				 this->AccumL->Text = L"Accumulator";
				 // 
				 // InRegL
				 // 
				 this->InRegL->AutoSize = true;
				 this->InRegL->BackColor = System::Drawing::Color::Transparent;
				 this->InRegL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InRegL->Location = System::Drawing::Point(262, 145);
				 this->InRegL->Name = L"InRegL";
				 this->InRegL->Size = System::Drawing::Size(151, 19);
				 this->InRegL->TabIndex = 7;
				 this->InRegL->Text = L"Instruction Register";
				 // 
				 // InCouL
				 // 
				 this->InCouL->AutoSize = true;
				 this->InCouL->BackColor = System::Drawing::Color::Transparent;
				 this->InCouL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InCouL->Location = System::Drawing::Point(262, 216);
				 this->InCouL->Name = L"InCouL";
				 this->InCouL->Size = System::Drawing::Size(148, 19);
				 this->InCouL->TabIndex = 8;
				 this->InCouL->Text = L"Instruction Counter";
				 // 
				 // OpCodTB
				 // 
				 this->OpCodTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->OpCodTB->Location = System::Drawing::Point(266, 304);
				 this->OpCodTB->Name = L"OpCodTB";
				 this->OpCodTB->ReadOnly = true;
				 this->OpCodTB->Size = System::Drawing::Size(147, 23);
				 this->OpCodTB->TabIndex = 9;
				 // 
				 // OprndTB
				 // 
				 this->OprndTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->OprndTB->Location = System::Drawing::Point(266, 370);
				 this->OprndTB->Name = L"OprndTB";
				 this->OprndTB->ReadOnly = true;
				 this->OprndTB->Size = System::Drawing::Size(147, 23);
				 this->OprndTB->TabIndex = 10;
				 // 
				 // OpCodL
				 // 
				 this->OpCodL->AutoSize = true;
				 this->OpCodL->BackColor = System::Drawing::Color::Transparent;
				 this->OpCodL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->OpCodL->Location = System::Drawing::Point(262, 282);
				 this->OpCodL->Name = L"OpCodL";
				 this->OpCodL->Size = System::Drawing::Size(117, 19);
				 this->OpCodL->TabIndex = 11;
				 this->OpCodL->Text = L"Operation Code";
				 // 
				 // OprndL
				 // 
				 this->OprndL->AutoSize = true;
				 this->OprndL->BackColor = System::Drawing::Color::Transparent;
				 this->OprndL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->OprndL->Location = System::Drawing::Point(262, 348);
				 this->OprndL->Name = L"OprndL";
				 this->OprndL->Size = System::Drawing::Size(69, 19);
				 this->OprndL->TabIndex = 12;
				 this->OprndL->Text = L"Operand";
				 // 
				 // InputL
				 // 
				 this->InputL->AutoSize = true;
				 this->InputL->BackColor = System::Drawing::Color::Transparent;
				 this->InputL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InputL->Location = System::Drawing::Point(12, 75);
				 this->InputL->Name = L"InputL";
				 this->InputL->Size = System::Drawing::Size(48, 19);
				 this->InputL->TabIndex = 13;
				 this->InputL->Text = L"Input";
				 // 
				 // InputTB
				 // 
				 this->InputTB->AcceptsReturn = true;
				 this->InputTB->AllowDrop = true;
				 this->InputTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InputTB->Location = System::Drawing::Point(13, 97);
				 this->InputTB->Multiline = true;
				 this->InputTB->Name = L"InputTB";
				 this->InputTB->Size = System::Drawing::Size(216, 227);
				 this->InputTB->TabIndex = 14;
				 this->InputTB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::InputTB_KeyPress);
				 // 
				 // RunL
				 // 
				 this->RunL->AutoSize = true;
				 this->RunL->BackColor = System::Drawing::Color::Transparent;
				 this->RunL->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->RunL->Location = System::Drawing::Point(10, 339);
				 this->RunL->Name = L"RunL";
				 this->RunL->Size = System::Drawing::Size(213, 16);
				 this->RunL->TabIndex = 17;
				 this->RunL->Text = L"Press RUN to execute your program";
				 this->RunL->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // OutInputTB
				 // 
				 this->OutInputTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->OutInputTB->Location = System::Drawing::Point(578, 86);
				 this->OutInputTB->Name = L"OutInputTB";
				 this->OutInputTB->Size = System::Drawing::Size(87, 23);
				 this->OutInputTB->TabIndex = 18;
				 // 
				 // OutLabelTB
				 // 
				 this->OutLabelTB->BackColor = System::Drawing::SystemColors::Control;
				 this->OutLabelTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->OutLabelTB->Location = System::Drawing::Point(442, 86);
				 this->OutLabelTB->Name = L"OutLabelTB";
				 this->OutLabelTB->ReadOnly = true;
				 this->OutLabelTB->Size = System::Drawing::Size(130, 23);
				 this->OutLabelTB->TabIndex = 19;
				 // 
				 // InputB
				 // 
				 this->InputB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->InputB->Location = System::Drawing::Point(671, 86);
				 this->InputB->Name = L"InputB";
				 this->InputB->Size = System::Drawing::Size(83, 20);
				 this->InputB->TabIndex = 20;
				 this->InputB->Text = L"Submit";
				 this->InputB->UseVisualStyleBackColor = true;
				 this->InputB->Click += gcnew System::EventHandler(this, &MyForm::InputB_Click);
				 // 
				 // RunB
				 // 
				 this->RunB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->RunB->Location = System::Drawing::Point(13, 368);
				 this->RunB->Name = L"RunB";
				 this->RunB->Size = System::Drawing::Size(216, 42);
				 this->RunB->TabIndex = 21;
				 this->RunB->Text = L"RUN";
				 this->RunB->UseVisualStyleBackColor = true;
				 this->RunB->Click += gcnew System::EventHandler(this, &MyForm::RunB_Click);
				 // 
				 // Menu
				 // 
				 this->Menu->BackColor = System::Drawing::Color::Lime;
				 this->Menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
				 this->Menu->Location = System::Drawing::Point(0, 0);
				 this->Menu->Name = L"Menu";
				 this->Menu->Size = System::Drawing::Size(877, 24);
				 this->Menu->TabIndex = 22;
				 this->Menu->Text = L"Menu";
				 // 
				 // fileToolStripMenuItem
				 // 
				 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->newToolStripMenuItem,
						 this->loadToolStripMenuItem, this->saveToolStripMenuItem
				 });
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
				 this->fileToolStripMenuItem->Text = L"File";
				 // 
				 // newToolStripMenuItem
				 // 
				 this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
				 this->newToolStripMenuItem->Size = System::Drawing::Size(100, 22);
				 this->newToolStripMenuItem->Text = L"New";
				 this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
				 // 
				 // loadToolStripMenuItem
				 // 
				 this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
				 this->loadToolStripMenuItem->Size = System::Drawing::Size(100, 22);
				 this->loadToolStripMenuItem->Text = L"Load";
				 this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadToolStripMenuItem_Click);
				 // 
				 // saveToolStripMenuItem
				 // 
				 this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
				 this->saveToolStripMenuItem->Size = System::Drawing::Size(100, 22);
				 this->saveToolStripMenuItem->Text = L"Save";
				 this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
				 // 
				 // FileLabelTB
				 // 
				 this->FileLabelTB->BackColor = System::Drawing::SystemColors::Control;
				 this->FileLabelTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->FileLabelTB->Location = System::Drawing::Point(442, 57);
				 this->FileLabelTB->Name = L"FileLabelTB";
				 this->FileLabelTB->ReadOnly = true;
				 this->FileLabelTB->Size = System::Drawing::Size(130, 23);
				 this->FileLabelTB->TabIndex = 23;
				 // 
				 // FileTB
				 // 
				 this->FileTB->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->FileTB->Location = System::Drawing::Point(578, 57);
				 this->FileTB->Name = L"FileTB";
				 this->FileTB->Size = System::Drawing::Size(87, 23);
				 this->FileTB->TabIndex = 24;
				 // 
				 // FileB
				 // 
				 this->FileB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->FileB->Location = System::Drawing::Point(671, 60);
				 this->FileB->Name = L"FileB";
				 this->FileB->Size = System::Drawing::Size(83, 20);
				 this->FileB->TabIndex = 25;
				 this->FileB->Text = L"Submit";
				 this->FileB->UseVisualStyleBackColor = true;
				 this->FileB->Click += gcnew System::EventHandler(this, &MyForm::FileB_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::Lime;
				 this->ClientSize = System::Drawing::Size(877, 419);
				 this->Controls->Add(this->FileB);
				 this->Controls->Add(this->FileTB);
				 this->Controls->Add(this->FileLabelTB);
				 this->Controls->Add(this->RunB);
				 this->Controls->Add(this->InputB);
				 this->Controls->Add(this->OutLabelTB);
				 this->Controls->Add(this->OutInputTB);
				 this->Controls->Add(this->RunL);
				 this->Controls->Add(this->InputTB);
				 this->Controls->Add(this->InputL);
				 this->Controls->Add(this->OprndL);
				 this->Controls->Add(this->OpCodL);
				 this->Controls->Add(this->OprndTB);
				 this->Controls->Add(this->OpCodTB);
				 this->Controls->Add(this->InCouL);
				 this->Controls->Add(this->InRegL);
				 this->Controls->Add(this->AccumL);
				 this->Controls->Add(this->InCouTB);
				 this->Controls->Add(this->InRegTB);
				 this->Controls->Add(this->AccumTB);
				 this->Controls->Add(this->MemoryL);
				 this->Controls->Add(this->MemoryTB);
				 this->Controls->Add(this->TitleL);
				 this->Controls->Add(this->Menu);
				 this->MainMenuStrip = this->Menu;
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->Menu->ResumeLayout(false);
				 this->Menu->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
			 /*
			 This is where the logic starts, everything above is for the GUI
			 */

	private: System::Void InputTB_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		//Do Nothing Lol
		//Don't add anything here
	};

	private: System::Void InputB_Click(System::Object^  sender, System::EventArgs^  e) {
		OutLabelTB->Text = "PRESS RUN AGAIN";
		myInput = int::Parse(OutInputTB->Text);

		//split
		int mem1 = myInput / 10000;
		int mem2 = myInput % 10000;
		memory[myALU->getLocation()] = mem1;
		myALU->setLocation(myALU->getLocation() + 1);
		memory[myALU->getLocation()] = mem2;

		needInput = false;
	};

			 //This will run when the user presses "RUN"
	private: System::Void RunB_Click(System::Object^  sender, System::EventArgs^  e) {
		if (firstCompile) {
			for (int i = 0; i < MEMSIZE; i++) {
				memory[i] = 0;
			}

			//put the code into main memory
			array<String^>^ tempArray = gcnew array<String^>(InputTB->Lines->Length);
			tempArray = InputTB->Lines;
			for (int i = 0; i < tempArray->Length; i++) {
				tempArray[i] = tempArray[i]->Substring(1, 4);
				memory[i] = int::Parse(tempArray[i]);
			}

			myALU->setCount(tempArray->Length);

			//information for the compiler
			numLines = tempArray->Length;

			//ensures the setup information won't happen again
			firstCompile = false;
		}

		//run all of the code
		while (myALU->getInstr() != 43 && counter < myALU->getCount() && !needInput) {

			//parse the instruction and the location
			int a = memory[counter];
			int b = memory[counter + 1];
			myALU->setInstr(a / 100);
			myALU->setLocation(b);
			counter += 2;
			//run through all of the possible instructions

			if (myALU->getInstr() == 10) { //read
				OutLabelTB->Text = "Input an integer:";
				needInput = true;
				continue;
			}
			else if (myALU->getInstr() == 11) { //write
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				MemoryTB->AppendText(myALU->write(mem2, myALU->getLocation()));
			}
			else if (myALU->getInstr() == 20) { //load
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(mem2);
			}
			else if (myALU->getInstr() == 21) { //store
				if (myALU->getAccu() > 9999) {
					//split
					int ans = myALU->getAccu();
					int mem1 = ans / 10000;
					int mem2 = ans % 10000;
					memory[myALU->getLocation()] = mem1;
					myALU->setLocation(myALU->getLocation() + 1);
					memory[myALU->getLocation()] = mem2;
					// myALU->setLocation(myALU->getLocation() + 1);
				}
				else memory[myALU->getLocation() + 1] = myALU->getAccu();
			}
			else if (myALU->getInstr() == 30) { //addition
				//combine
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(myALU->add(myALU->getAccu(), mem2));
			}
			else if (myALU->getInstr() == 31) { //subtraction
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(myALU->subtract(myALU->getAccu(), mem2));
			}
			else if (myALU->getInstr() == 32) { //division
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(myALU->divide(myALU->getAccu(), mem2));
			}
			else if (myALU->getInstr() == 33) { //multiplication
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(myALU->multiply(myALU->getAccu(), mem2));
			}
			else if (myALU->getInstr() == 34) { //exponential
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(myALU->exponent(myALU->getAccu(), mem2));
			}
			else if (myALU->getInstr() == 35) { //remainder
				int mem1 = memory[myALU->getLocation()];
				int mem2 = memory[myALU->getLocation() + 1];
				if (mem1 > 0) {
					mem2 = (mem1 * 10000) + mem2;
				}
				myALU->setAccu(myALU->remainder(myALU->getAccu(), mem2));
			}
			else if (myALU->getInstr() == 40) { //branch
				counter = myALU->getLocation();
			}
			else if (myALU->getInstr() == 41) { //branch negative
				if (myALU->getAccu() < 0)
				{
					counter = myALU->getLocation();
				}
			}
			else if (myALU->getInstr() == 42) { //branch zero
				if (myALU->getAccu() == 0)
				{
					counter = myALU->getLocation();
				}
			}
			else if (myALU->getInstr() == 43) { //halt instruction
				break;
			}
			else if (myALU->getInstr() == 50) { //memdump
				this->MemoryTB->Text += "---MAIN MEMORY---" + "\r\n" + "\r\n";
				for (int i = 0; i < MEMSIZE / 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (memory[(i * 10) + j] < 10)
							this->MemoryTB->Text += " 000" + memory[(i * 10) + j]; //four spaces
						else if (memory[(i * 10) + j] < 100)
							this->MemoryTB->Text += " 00" + memory[(i * 10) + j]; //three spaces
						else if (memory[(i * 10) + j] < 1000)
							this->MemoryTB->Text += " 0" + memory[(i * 10) + j]; //two spaces
						else if (memory[(i * 10) + j] < 10000)
							this->MemoryTB->Text += " " + memory[(i * 10) + j]; //one space
					}
					this->MemoryTB->Text += "\r\n";
				}
			}
			else if (myALU->getInstr() == 51) { //break
				break;
			}
			else if (myALU->getInstr() == 52) { //continue
				continue;
			}
		}

		if (!needInput) {

			//Prints out all of the output
			this->AccumTB->Text += myALU->getAccu();
			this->InRegTB->Text += myALU->getInstr();
			this->InCouTB->Text += myALU->getCount();
			this->OpCodTB->Text += myALU->getInstr();
			this->OprndTB->Text += myALU->getLocation();

			//Prints out memory
			this->MemoryTB->Text += "---MAIN MEMORY---" + "\r\n" + "\r\n";
			for (int i = 0; i < MEMSIZE / 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (memory[(i * 10) + j] < 10)
						this->MemoryTB->Text += " 000" + memory[(i * 10) + j]; //four spaces
					else if (memory[(i * 10) + j] < 100)
						this->MemoryTB->Text += " 00" + memory[(i * 10) + j]; //three spaces
					else if (memory[(i * 10) + j] < 1000)
						this->MemoryTB->Text += " 0" + memory[(i * 10) + j]; //two spaces
					else if (memory[(i * 10) + j] < 10000)
						this->MemoryTB->Text += " " + memory[(i * 10) + j]; //one space
				}
				this->MemoryTB->Text += "\r\n";
			}

		};

	};

	private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FileLabelTB->Text = "Specify Filename:";
		FileTB->ReadOnly = false;
		newFileOption = true;
	};


	private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FileLabelTB->Text = "Specify Filename:";
		FileTB->ReadOnly = false;
		loadFileOption = true;
	};


	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FileLabelTB->Text = "Specify Filename:";
		FileTB->ReadOnly = false;
		saveFileOption = true;
	};


	private: System::Void FileB_Click(System::Object^  sender, System::EventArgs^  e) {
		FileLabelTB->Text = "";

		std::string newContent;

		//takes the mangaged TB and converts it to a managed array we can use
		cli::array<String^>^ tempArray = gcnew cli::array<String^>(InputTB->Lines->Length);
		tempArray = InputTB->Lines;

		//converting and setting the file path
		System::String^ example = FileTB->Text;
		std::string path = context.marshal_as<std::string, System::String^>(example);
		myFile->setFilePath(path);



		//Make a new file and clear out InputTB
		if (newFileOption) {
			myFile->New();
			InputTB->Text = "";
			newFileOption = false;

		}
		//Get a pointer to the file array and print it out to InputTB
		else if (loadFileOption) {
			newContent = myFile->Load();
			//convert from unmanaged to managed
			String^ ms = gcnew String(newContent.c_str());
			InputTB->Text += ms + "\n";
			loadFileOption = false;

		}
		//Take the InputTB and save to file
		else if (saveFileOption) {
			std::vector<std::string> strArr;

			for (int i = 0; i < tempArray->Length; i++) {
				System::String^ a = tempArray[i];
				std::string un = context.marshal_as<std::string, System::String^>(a);
				strArr.push_back(un);
			}
			std::string saveString;
			for (int i = 0; i < tempArray->Length; i++) {
				saveString += strArr[i];
				saveString += "\n";
			}

			bool saveSuccessful = myFile->Save(saveString);

			if (!saveSuccessful) {
				MessageBox::Show("There was an error saving your file");
			}
			else {
				MessageBox::Show("Your file was saved successfully");
			}
			saveFileOption = false;
		}
	};
	};
};