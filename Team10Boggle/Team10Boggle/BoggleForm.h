#pragma once
#include "Boggle.h"
#include "BoggleSolver.h"
#include "Die.h"
#include "DieCollection.h"
#include "BoggleForm.h"
#include "PlayerManager.h"
#include "Player.h"

delegate void IterateFunction(int, int);
namespace view{
	using namespace model;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;

	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;
	using namespace System::Collections::ObjectModel;
	using namespace System::Collections::Specialized;

	/// <summary>
	/// Summary for BoggleForm
	/// </summary>
	enum class Row : int { BELOW = 1, ABOVE = -1, MAX = 4, MIN = 0 };
	enum class Column : int { BEFORE = -1, AFTER = 1, MAX = 4, MIN = 0 };
	public ref class BoggleForm : public System::Windows::Forms::Form
	{
	public:
		BoggleForm();
		void InitializeComponent(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BoggleForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: PlayerManager^ playerManager;

	private: System::Windows::Forms::Button^  rotateButton;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  highScorePanel;















	private: System::Windows::Forms::Panel^  mainMenuPanel;

	private: System::Windows::Forms::Button^  highscoresButton;
	private: System::Windows::Forms::Button^  startGameButton;





			 bool gameRunning;
	private: System::Windows::Forms::ListView^  scoreBoard;
	private: System::Windows::Forms::ColumnHeader^  col1;
	private: System::Windows::Forms::ColumnHeader^  col2;






			 ObservableCollection<String^>^ letters;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::Panel^  endGamePanel;

	private: System::Windows::Forms::ListBox^  allPossibleWordBox;
	private: System::Windows::Forms::Panel^  gamePanel;
	private: System::Windows::Forms::Label^  label5;





	private: System::Windows::Forms::Button^  addWordButton;
	private: System::Windows::Forms::Panel^  endGamePrompt;
	private: System::Windows::Forms::ComboBox^  nameBox;
	private: System::Windows::Forms::Button^  submitNameButton;
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::Label^  timeUpLabel;
	private: System::Windows::Forms::Button^  mainMenuPanelReturnButton;
	private: System::Windows::Forms::TabControl^  endGameWordTabs;
	private: System::Windows::Forms::TabPage^  allWordsTab;
	private: System::Windows::Forms::TabPage^  playerWordsTab;




	private: System::Windows::Forms::ListBox^  userSubmittedWordBox;
	private: System::Windows::Forms::TableLayoutPanel^  checkBoxContainer;
	private: System::Windows::Forms::CheckBox^  checkBox17;
	private: System::Windows::Forms::CheckBox^  checkBox16;
	private: System::Windows::Forms::CheckBox^  checkBox15;
	private: System::Windows::Forms::CheckBox^  checkBox14;
	private: System::Windows::Forms::CheckBox^  checkBox13;
	private: System::Windows::Forms::CheckBox^  checkBox12;
	private: System::Windows::Forms::CheckBox^  checkBox11;
	private: System::Windows::Forms::CheckBox^  checkBox10;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::CheckBox^  checkBox8;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::Label^  endScoreLabel;
private: System::Windows::Forms::Label^  finalScoreLabel;
private: System::Windows::Forms::Button^  newGameButton;
private: System::Windows::Forms::Button^  mainMenuButton2;













































































			 int draggedOverBoxCount;
			 CheckBox^ getCheckBox(int column, int row);
			 bool clickedValidCheckedBox(CheckBox^ checkBox);
			 bool allUnchecked;
			 bool mouseDown;
			 bool clickedValidUncheckedBox(CheckBox^ checkBox);
			 void handleChangedCheckState(CheckState checkState, CheckBox^ checkButton);
			 void updateCheckedBoxesList();
			 void updateLastBoxChecked();
			 void removeEntry(CheckBox^ checkBox);
			 void refresh();
			 void addEntry(CheckBox^ checkBox);
			 void removeLastLetterFromWord(CheckBox^ checkBox);
			 void addLetterToWord();
			 void calculateNeighborsAt(Row neighboringRow);
			 bool lastBoxCheckedHas(Row neighboringRow);
			 bool lastBoxCheckedHas(Column neighboringColumn);
			 void updateCurrentNeighbors();
			 void setAllBoxesUncheckable();
			 void uncheckAllBoxes();
			 void updateLetters();
			 void iterate(IterateFunction^ func);
			 void addLetter(int row, int column);
			 void changeCheckBoxLetter(int row, int column);
			 void getMissedWords();
			 array<String^, 2>^ getBoardArray();
			 bool resizing;
			 Boggle^ boggle;
			 BoggleSolver^ boggleSolver;
			 List<String^>^ missedWords;
			 int second;
			 int minute;
			 CheckBox^ lastBoxChecked;
			 String^ secondString;
			 String^ minuteString;
			 System::ComponentModel::BackgroundWorker^  backgroundWorker1;
			 array<CheckBox^, 2>^ diceButtons;
			 List<CheckBox^>^ checkedBoxes;
			 List<CheckBox^>^ currentNeighbors;



















			 System::Windows::Forms::ListBox^  listBox1;

			 IterateFunction^ addLetters;

			 System::Windows::Forms::Label^  label1;
			 System::Windows::Forms::Label^  label2;
			 System::Windows::Forms::Timer^  timer1;
			 System::Windows::Forms::Label^  label3;
			 System::Windows::Forms::ColumnHeader^  columnHeader1;
			 System::ComponentModel::IContainer^  components;
			 System::Void BoggleForm_Load(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_CheckStateChanged(System::Object^  sender, System::EventArgs^  e);
			 System::Void addWordButton_Click(System::Object^  sender, System::EventArgs^  e);
			 System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_MouseEnter(System::Object^  sender, System::EventArgs^  e);
			 System::Void checkBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 System::Void checkBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
			 System::Void checkBox_MouseHover(System::Object^  sender, System::EventArgs^  e);
			 System::Void button_GotFocus(System::Object^  sender, System::EventArgs^  e);
			 System::Void rotateButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void nameBox_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void submitNameButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void scoreBoard_SizeChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void startGameButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void highscoresButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void mainMenuPanelReturnButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void newGameButton_Click(System::Object^  sender, System::EventArgs^  e);
	
};

}