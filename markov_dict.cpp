#include "markov_dict.h"


markov_dict::markov_dict()
{
	dict = new set<word_extended>;
}


markov_dict::~markov_dict()
{
}

void markov_dict::create_dict(string filename){
	ifstream infile(filename);

	if (!infile.is_open()){
		cerr << "Blad odczytu pliku" << endl;
		return;
	}

	cout << "Please wait..." << endl << endl;	

	string word1, word2, word3;
	set<word_extended>::iterator it;

	//initialization - read two first words
	
	if (infile.good()) infile >> word1;
	if (infile.good()) infile >> word2;
	word_extended *wta = new word_extended(word1, word2);

	//main loop
	while (infile.good())
	{
		infile >> word3;
		it = (*dict).find(*wta);						//checks if the tuple already exists in the set
		if (it != (*dict).end())						
			(*(*it).successor).push_back(word3);		//if it does, add successor to his list
		else{
			(*(*wta).successor).push_back(word3);		//if not, add new element to the set
			(*dict).insert(*wta);
		}
		wta = new word_extended(word2, word3);
		word2 = word3;
	} 
	infile.close();

	//TODO: write set to file
	/*
	ofstream outfile("dict", ofstream::binary);
	for (set<word_extended>::iterator it = (*dict).begin(); it != (*dict).end(); ++it)
	{
		
	}
	*/
}

word_extended markov_dict::random_word(){
	int size = (*dict).size();
	int random_number = rand() % size;
	set<word_extended>::iterator it = (*dict).begin();
	for (int i = 0; i < random_number; ++i, ++it);
	return (*it);
}

void markov_dict::make_sentence(int length){
	if ((*dict).empty()) {
		cout << "Please load a sample file first" << endl;
		return;
	}
	//two first words will be random
	srand((unsigned int)time(NULL));
	set<word_extended>::iterator found;
	list<string>::iterator it;
	word_extended previous = random_word();
	int rand_index;
	//we want the first letter of the first word to be uppercase
	cout << uppercase << previous.get_word1()[0] << nouppercase << previous.get_word1().substr(1) << " " << previous.get_word2() << " ";

	//main loop
	for (int i = 0; i < length - 2; ++i){
		found = (*dict).find(previous);														//localize pair of previous words in the set
		if (found != (*dict).end()){
			rand_index = rand() % (*(*found).successor).size();								//if it exists, we choose the successor ra
			it = (*(*found).successor).begin();
			for (int j = 1; j < rand_index; ++j, ++it);
			previous = word_extended(previous.get_word2(), *it);
		}
		else
			previous = word_extended(previous.get_word2(), random_word().get_word1());		//else we just choose any random word, remark: that should not occur
		
		cout << previous.get_word2() << " ";
	}
	cout << '\b' << "." << endl;	//delete last space and add a dot and new line
}