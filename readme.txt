The point of the project is to generate pseudorandom sentences using Markov chains. The program first loads a sample file (e.g. a book) and generates a form of a dictionary. Then it generates the sentence using that dictionary. 

The idea is simple: for given two consecutive words, it choose a random successor, with probability proportional to the number of corresponding triplets in the source. 
E.g. if we have one "I am stupid" and three "I am hungry" and no other "I am" in a source file, then in a generated sentence after the words "I am" there is:
Pr(stupid)=1/4, 
Pr(hungry)=3/4.

In general, Pr(C|(A,B))  = #(A,B,C) / #(A,B).

As an example, I add two sample files, from which one can generate a dictionary: 
- V.Hugo, Les Misérables (from gutenberg.org) - in English,
- H.Sienkiewicz, Potop (en. The Deluge), Vol.I (from wolnelektury.pl) - in Polish.
One can also upload any (long enough) text file, with UTF-8 encoding. Regard that current speed of loading a file is about 80 kB/s. If someone has any idea to improve this result, please let mi know.

