namespace Text
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:MyForm(void)
	{
		InitializeComponent();
	}
	protected:~MyForm()
	{
		if (components)
		{
			delete components;
		}
	}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::ComponentModel::Container ^components;
			 void InitializeComponent(void)
			 {
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->SuspendLayout();
				 this->textBox1->Location = System::Drawing::Point(12, 12);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(100, 20);
				 this->textBox1->TabIndex = 0;
				 this->textBox2->Location = System::Drawing::Point(12, 38);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(100, 20);
				 this->textBox2->TabIndex = 1;
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(12, 117);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(65, 13);
				 this->label1->TabIndex = 2;
				 this->label1->Text = L"Результат: ";
				 this->button1->Location = System::Drawing::Point(12, 91);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(75, 23);
				 this->button1->TabIndex = 3;
				 this->button1->Text = L"Посчитать";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Сложение", L"Вычитание", L"Умножение", L"Деление" });
				 this->comboBox1->Location = System::Drawing::Point(12, 64);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(121, 21);
				 this->comboBox1->TabIndex = 4;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(284, 261);
				 this->Controls->Add(this->comboBox1);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->textBox1);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->ResumeLayout(false);
				 this->PerformLayout();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->Text != "" && textBox2->Text != "") {
			int a = Convert::ToInt32(textBox1->Text);
			int b = Convert::ToInt32(textBox2->Text);
			int res;
			switch (comboBox1->SelectedIndex)
			{
			case 0:
			{
				res = a + b;
				break;
			}
			case 1:
			{
				res = a - b;
				break;
			}
			case 2:
			{
				res = a * b;
				break;
			}
			case 3:
			{
				if (b)
				{
					res = a / b;
				}
				else
				{
					label1->Text = "Деление на 0";
					return;
				}
				break;
			}
			default:
			{
				label1->Text = "Действие не выбрано!";
				break;
			}
			}
			if (comboBox1->SelectedIndex != -1)
			{
				label1->Text = "Результат: " + Convert::ToString(res);
			}
		}
		else
		{
			label1->Text = "Значения не введены!";
		}
	}
	}
}
