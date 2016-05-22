# InsideOutWordLookup
A C++ binary search algorithm that searches up instances of matching "inside-out words" within an input text file.

An inside-out word is created by splitting a word in half, reversing both halves, and joining them back afterwards.

Ex: 
String A: "conner"  -> parsed and updated into "nocren"

For each word within the text file, it is returned as an inside-out word via the wordTurn() method, and then the entire text file is searched via binary search (O(logn)) for additional instances of the inside-out word, which is defined within dictlookupDP.cpp.  

The wordTurn() method utilizes a specially defined data structure in StackPairDP.h, a StackPair<T>.  This data structure holds the same initial functionality as a normal Stack<T>, but is able to pop and push elements onto either the rear or front of the vector within the data structure, unlike a Stack which can push/pop from the front only.  

The overall runtime of the algorithm is O(nlogn), due to that each string within the input file is run through binary search to find matching inside-out words.

Written in November 2013.
