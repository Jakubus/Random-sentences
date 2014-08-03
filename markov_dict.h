#pragma once
using namespace std;
#include "word_extended.h"
#include "stdafx.h"

//The class has one field: (a pointer to ) a set of word_extended variables.
//It is generated by method create_dict(string), which takes filename as an argument and adds every triplet of consecutive words into a set.
//Then one can use make_sentence(int) to generate pseudorandom sentence (actually there is no guarantee it'll be a sentence) 
//of a given length, based on statistics from source file.
//For a given two consecutive words, it choose a random successor, with probability proportional to number of corresponding triplets in the source,
//e.g. if we have one "I am stupid" and three "I am hungry" and no other "I am" in a source file, 
//then in a generated sentence after the words "I am" there is Pr(stupid)=1/4, Pr(hungry)=3/4 (in general, Pr(C|(A,B))  = #(A,B,C) / #(A,B))

class markov_dict
{
	set<word_extended> *dict;
public:
	markov_dict();
	~markov_dict();
	void create_dict(string);				//as described above
	word_extended random_word();			//returns a random element of a set (*dict)
	void make_sentence(int);				//as described above
};

