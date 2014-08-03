#include "word_extended.h"
using namespace std;

word_extended::word_extended(string a, string b)
{
	word1 = a;
	word2 = b;
	successor = new list<string>;
}

word_extended::word_extended()
{
	successor = new list<string>;
}

word_extended::~word_extended()
{
}

string word_extended::get_word1(){
	return word1;
}

string word_extended::get_word2(){
	return word2;
}

bool word_extended::operator<(const word_extended& right) const {
	return ((word1.compare(right.word1) < 0) || ((word1.compare(right.word1) == 0) && (word2.compare(right.word2) < 0)));
}

bool word_extended::operator==(const word_extended& right) const {
	return ((word1.compare(right.word1) == 0) && (word2.compare(right.word2) == 0));
}