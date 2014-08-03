#pragma once
using namespace std;
#include <string>
#include <list>
#include <iostream>

//the class consists of two words and (a pointer to ) a list of words, that can succeed the two given 
//i.e. in a loaded sample of text there exist sequences "word1 word2 x", for any x in successor list
//if a sequence "word1 word2 x" was in the sample more than once, then more than one copy of x is added to a list
//this makes a choice of more common successor more probable

class word_extended
{
	string word1;
	string word2;
public:
	mutable list<string> *successor;						//it is mutable so that we can add elements while in a set structure; it is safe, because the key will be (word1, word2)

	word_extended();
	word_extended(string, string);							//word1, word2 as arguments, empty list
	~word_extended();
	string get_word1();										//returns word1
	string get_word2();										//returns word2
	bool operator<(const word_extended& right) const;		//lexicographic in word1, then word2
	bool operator==(const word_extended& right) const;		//if word1, word2 are equal, with respect to the order
};

