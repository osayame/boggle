#include "FileIO.h"
#include "PlayerManager.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

/// <summary>
/// IO Class that handles reading and writing
/// game objects from files.
/// </summary>
namespace fileio{
	/// <summary>
	/// Initializes a new instance of the <see cref="FileIO"/> class.
	/// </summary>
	FileIO::FileIO()
	{

	}

	/// <summary>
	/// Loads the dictionary.
	/// </summary>
	/// <returns></returns>
	Trie^ FileIO::loadDictionary(){
		Trie^ trie = gcnew Trie();

		String^ fileName = L"dictionary.txt";

		try {
			StreamReader^ input = File::OpenText(fileName);

			String^ line;
			while ((line = input->ReadLine()) != nullptr) {
				trie->addWord(line);
			}
			input->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}

		return trie;
	}

	/// <summary>
	/// Loads the players.
	/// </summary>
	/// <returns></returns>
	List<Player^>^ FileIO::loadPlayers(){
		List<Player^>^ players = gcnew List<Player^>();

		String^ fileName = L"players.txt";

		StreamReader^ input;

		try {
			input = File::OpenText(fileName);

			String^ line;
			while ((line = input->ReadLine()) != nullptr) {
				array<String^>^ playerInfo = splitString(line);
				Player^ newPlayer = gcnew Player(playerInfo[0], Convert::ToInt32(playerInfo[1]));
				players->Add(newPlayer);
			}
			input->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}


		return players;
	}

	/// <summary>
	/// Saves the players.
	/// </summary>
	/// <param name="players">The players.</param>
	void FileIO::savePlayers(List<Player^>^ players){
		String^ fileName = L"players.txt";

		try {
			StreamWriter^ output = gcnew StreamWriter(fileName);

			for each (Player^ currPlayer in players)
			{
				output->WriteLine(currPlayer->Name + "," + currPlayer->Score);
			}
			output->Close();
		}
		catch (Exception^ exception) {
			Console::WriteLine(L"Error: " + exception->Message);
		}
	}

	array<String^>^ FileIO::splitString(String^ text) {
		String^ delimStr = ",";

		array<Char>^ delimiter = delimStr->ToCharArray();
		array<String^>^ words;

		words = text->Split(delimiter);

		return words;
	}
}