#pragma once
#include <msclr\marshal_cppstd.h>
#include <string>

namespace impl_funcs {
	int playRtspUrlVideo(std::string rtsp_url, bool secure, std::string username, std::string password, std::string cert, std::string key);
	void setEnvironmentVariable(System::String^ variable, System::String^ value);
}

namespace gstplayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		static StartForm^ startFormInstance;
		StartForm(void)
		{
			InitializeComponent();
			startFormInstance = this;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  rtsp_url_text;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  play_button;
	private: System::Windows::Forms::CheckBox^  secure_check;
	private: System::Windows::Forms::Panel^  secure_details;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  password_text;

	private: System::Windows::Forms::TextBox^  username_text;


	private: System::Windows::Forms::Button^  key_select_button;


	private: System::Windows::Forms::Button^  certificate_select_button;

	private: System::Windows::Forms::TextBox^  key_text;

	private: System::Windows::Forms::TextBox^  certificate_text;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	public: System::Windows::Forms::TextBox^  log_text;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  gst_debug_text;
	private: System::Windows::Forms::Button^  gst_debug_button;
	public:



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->rtsp_url_text = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->play_button = (gcnew System::Windows::Forms::Button());
			this->secure_check = (gcnew System::Windows::Forms::CheckBox());
			this->secure_details = (gcnew System::Windows::Forms::Panel());
			this->key_select_button = (gcnew System::Windows::Forms::Button());
			this->certificate_select_button = (gcnew System::Windows::Forms::Button());
			this->key_text = (gcnew System::Windows::Forms::TextBox());
			this->certificate_text = (gcnew System::Windows::Forms::TextBox());
			this->password_text = (gcnew System::Windows::Forms::TextBox());
			this->username_text = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->log_text = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->gst_debug_text = (gcnew System::Windows::Forms::TextBox());
			this->gst_debug_button = (gcnew System::Windows::Forms::Button());
			this->secure_details->SuspendLayout();
			this->SuspendLayout();
			// 
			// rtsp_url_text
			// 
			this->rtsp_url_text->Location = System::Drawing::Point(137, 27);
			this->rtsp_url_text->Margin = System::Windows::Forms::Padding(4);
			this->rtsp_url_text->Name = L"rtsp_url_text";
			this->rtsp_url_text->Size = System::Drawing::Size(464, 26);
			this->rtsp_url_text->TabIndex = 0;
			this->rtsp_url_text->TextChanged += gcnew System::EventHandler(this, &StartForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(29, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"RTSP Url";
			this->label1->Click += gcnew System::EventHandler(this, &StartForm::label1_Click);
			// 
			// play_button
			// 
			this->play_button->Location = System::Drawing::Point(639, 27);
			this->play_button->Margin = System::Windows::Forms::Padding(4);
			this->play_button->Name = L"play_button";
			this->play_button->Size = System::Drawing::Size(80, 25);
			this->play_button->TabIndex = 2;
			this->play_button->Text = L"PLAY";
			this->play_button->UseVisualStyleBackColor = true;
			this->play_button->Click += gcnew System::EventHandler(this, &StartForm::button1_Click);
			// 
			// secure_check
			// 
			this->secure_check->AutoSize = true;
			this->secure_check->Location = System::Drawing::Point(32, 78);
			this->secure_check->Name = L"secure_check";
			this->secure_check->Size = System::Drawing::Size(133, 24);
			this->secure_check->TabIndex = 3;
			this->secure_check->Text = L"Secure RTSP";
			this->secure_check->UseVisualStyleBackColor = true;
			this->secure_check->CheckedChanged += gcnew System::EventHandler(this, &StartForm::checkBox1_CheckedChanged);
			// 
			// secure_details
			// 
			this->secure_details->Controls->Add(this->key_select_button);
			this->secure_details->Controls->Add(this->certificate_select_button);
			this->secure_details->Controls->Add(this->key_text);
			this->secure_details->Controls->Add(this->certificate_text);
			this->secure_details->Controls->Add(this->password_text);
			this->secure_details->Controls->Add(this->username_text);
			this->secure_details->Controls->Add(this->label5);
			this->secure_details->Controls->Add(this->label4);
			this->secure_details->Controls->Add(this->label3);
			this->secure_details->Controls->Add(this->label2);
			this->secure_details->Location = System::Drawing::Point(32, 126);
			this->secure_details->Name = L"secure_details";
			this->secure_details->Size = System::Drawing::Size(420, 162);
			this->secure_details->TabIndex = 4;
			this->secure_details->Visible = false;
			// 
			// key_select_button
			// 
			this->key_select_button->Location = System::Drawing::Point(322, 117);
			this->key_select_button->Name = L"key_select_button";
			this->key_select_button->Size = System::Drawing::Size(75, 24);
			this->key_select_button->TabIndex = 9;
			this->key_select_button->Text = L"Select";
			this->key_select_button->UseVisualStyleBackColor = true;
			this->key_select_button->Click += gcnew System::EventHandler(this, &StartForm::button3_Click);
			// 
			// certificate_select_button
			// 
			this->certificate_select_button->Location = System::Drawing::Point(322, 88);
			this->certificate_select_button->Name = L"certificate_select_button";
			this->certificate_select_button->Size = System::Drawing::Size(75, 23);
			this->certificate_select_button->TabIndex = 8;
			this->certificate_select_button->Text = L"Select";
			this->certificate_select_button->UseVisualStyleBackColor = true;
			this->certificate_select_button->Click += gcnew System::EventHandler(this, &StartForm::button2_Click);
			// 
			// key_text
			// 
			this->key_text->Location = System::Drawing::Point(105, 118);
			this->key_text->Name = L"key_text";
			this->key_text->Size = System::Drawing::Size(199, 26);
			this->key_text->TabIndex = 7;
			this->key_text->TextChanged += gcnew System::EventHandler(this, &StartForm::textBox5_TextChanged);
			// 
			// certificate_text
			// 
			this->certificate_text->Location = System::Drawing::Point(105, 88);
			this->certificate_text->Name = L"certificate_text";
			this->certificate_text->Size = System::Drawing::Size(199, 26);
			this->certificate_text->TabIndex = 6;
			this->certificate_text->TextChanged += gcnew System::EventHandler(this, &StartForm::textBox4_TextChanged);
			// 
			// password_text
			// 
			this->password_text->Location = System::Drawing::Point(105, 50);
			this->password_text->Name = L"password_text";
			this->password_text->Size = System::Drawing::Size(199, 26);
			this->password_text->TabIndex = 5;
			// 
			// username_text
			// 
			this->username_text->Location = System::Drawing::Point(105, 20);
			this->username_text->Name = L"username_text";
			this->username_text->Size = System::Drawing::Size(199, 26);
			this->username_text->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 116);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 20);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Key";
			this->label5->Click += gcnew System::EventHandler(this, &StartForm::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 20);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Certificate";
			this->label4->Click += gcnew System::EventHandler(this, &StartForm::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Username";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// log_text
			// 
			this->log_text->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->log_text->Location = System::Drawing::Point(475, 126);
			this->log_text->Multiline = true;
			this->log_text->Name = L"log_text";
			this->log_text->ReadOnly = true;
			this->log_text->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->log_text->Size = System::Drawing::Size(304, 162);
			this->log_text->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(32, 317);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(290, 20);
			this->label6->TabIndex = 6;
			this->label6->Text = L"GStreamer Log Level (GST_DEBUG)";
			this->label6->Click += gcnew System::EventHandler(this, &StartForm::label6_Click);
			// 
			// gst_debug_text
			// 
			this->gst_debug_text->Location = System::Drawing::Point(328, 317);
			this->gst_debug_text->Name = L"gst_debug_text";
			this->gst_debug_text->Size = System::Drawing::Size(284, 26);
			this->gst_debug_text->TabIndex = 7;
			this->gst_debug_text->Text = L"3";
			// 
			// gst_debug_button
			// 
			this->gst_debug_button->Location = System::Drawing::Point(628, 317);
			this->gst_debug_button->Name = L"gst_debug_button";
			this->gst_debug_button->Size = System::Drawing::Size(151, 26);
			this->gst_debug_button->TabIndex = 8;
			this->gst_debug_button->Text = L"Apply";
			this->gst_debug_button->UseVisualStyleBackColor = true;
			this->gst_debug_button->Click += gcnew System::EventHandler(this, &StartForm::gst_debug_button_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 385);
			this->Controls->Add(this->gst_debug_button);
			this->Controls->Add(this->gst_debug_text);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->log_text);
			this->Controls->Add(this->secure_details);
			this->Controls->Add(this->secure_check);
			this->Controls->Add(this->play_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->rtsp_url_text);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Indigo;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"StartForm";
			this->Text = L"RTSP Player";
			this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
			this->secure_details->ResumeLayout(false);
			this->secure_details->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rtsp_url = msclr::interop::marshal_as<std::string>(rtsp_url_text->Text);
		if (rtsp_url.empty()) {
			MessageBox::Show("Invalid RTSP Url", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			return;
		}
		if ((rtsp_url.rfind("rtsps", 0) == 0) && !secure_check->Checked) {
			MessageBox::Show("For RTSP Secure enter security details", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			return;
		}
		if (secure_check->Checked && (rtsp_url.rfind("rtsps", 0) != 0)) {
			MessageBox::Show("For RTSP Secure use RTSPS protocol", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
			return;
		}
		/* Check for secure details if enabled*/
		std::string username;
		std::string password;
		std::string certificate;
		std::string key;
		if (secure_check->Checked) {
			username = msclr::interop::marshal_as<std::string>(username_text->Text);
			if (username.empty()) {
				MessageBox::Show("Invalid Username", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				return;
			}
			password = msclr::interop::marshal_as<std::string>(password_text->Text);
			if (password.empty()) {
				MessageBox::Show("Invalid Password", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				return;
			}
			certificate = msclr::interop::marshal_as<std::string>(certificate_text->Text);
			if (certificate.empty()) {
				MessageBox::Show("Invalid Certificate", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				return;
			}
			key = msclr::interop::marshal_as<std::string>(key_text->Text);
			if (key.empty()) {
				MessageBox::Show("Invalid Key", "Error", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
				return;
			}
		}
		int ret = impl_funcs::playRtspUrlVideo(msclr::interop::marshal_as<std::string>(rtsp_url_text->Text),
			secure_check->Checked, username, password, certificate, key);
		return;
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void StartForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->InitialDirectory = "c:\\";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			certificate_text->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->InitialDirectory = "c:\\";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			key_text->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (secure_check->Checked) {
			secure_details->Visible = TRUE;
		}
		else {
			secure_details->Visible = FALSE;
		}

	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void gst_debug_button_Click(System::Object^  sender, System::EventArgs^  e) {
		impl_funcs::setEnvironmentVariable("GST_DEBUG", gst_debug_text->Text);
	}
	};
}

