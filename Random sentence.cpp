// Random sentence.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"

void main_menu(){
	cout << "What is your choice?" << endl;
	cout << "1. Create a dictionary from a text file." << endl;
	cout << "2. Make a sentence based on the loaded dictionary" << endl;
	cout << "3. Exit" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	char choice, choice2;
	int length;
	string yourown;
	markov_dict example;
	do{
		main_menu();
		cin >> choice;
		switch (choice){
		case '1':
			cout << endl << "Choose the source sample" << endl;
			cout << "1. Les Miserables" << endl << "2. Potop" << endl << "3. Your own sample" << endl;
			cin >> choice2;
			switch (choice2){
			case '1': 
				example.create_dict("sample1_miserables.txt");
				break;
			case '2':
				example.create_dict("sample2_potop-t1.txt");
				break;
			case '3':
				cout << "Input filename" << endl;
				getchar();
				getline(cin, yourown);
				example.create_dict(yourown);
				break;
			}

			break;
		case '2': 
			cout << "Input the length of the sentence" << endl;
			cin >> length;
			example.make_sentence(length);
			cout << endl;
			break;
		}
	} while (choice != '3');		
	//system("Pause");
	return 0;
}

