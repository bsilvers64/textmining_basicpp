#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include "porter2_stemmer.h"
using namespace std;

int main () {

 fstream fout,f;
 string word;
 int wordcount=0;
 fout.open("sometext.txt",ios::in);
 f.open("sometext_2.txt",ios::out);

 if (fout.is_open()) {
        while (fout>>word) {
                //1. removing punctuation marks from each string

                for (int i = 0, len = word.size(); i < len; i++)
                {
                    if (ispunct(word[i]))
                   {
                    word.erase(i--, 1);
                    len = word.size();
                   }
                }

               wordcount++;         // word count

               for_each(word.begin(), word.end(), [](char & c)
               {c = tolower(c); }); // cases handled for uppercases

                                    // prepositions removal --
               if (word!="above"&&word!="at"&&word!="after"&&word!="across"&&word!="around"&&word!="before"&&word!="behind"&&word!="below"&&word!="beside"&&word!="between"&&word!="by"&&word!="for"&&word!="during"&&word!="in"&&word!="from"&&word!="inside"&&word!="of"&&word!="off"&&word!="onto"&&word!="on"&&word!="out"&&word!="through"&&word!="to"&&word!="under"&&word!="up"&&word!="with")
                {f<<" "<<word<<endl;}
        }
 }
 else {cout<<endl<<"file couldn't open";}

 cout<<endl<<" the total number of words in the file is : "<<wordcount<<endl;             // word count displayed for file 1, i.e. with prepositions.

 f.close();
 wordcount=0;
  f.open("sometext_2.txt",ios::in);
 if (f.is_open()) {
         while (f>>word) {
                wordcount++;         // word count my nigga
         }
  }
 cout<<endl<<" the total number of words in the file without prepositions is : "<<wordcount<<endl;    // word count displayed for file 2, i.e. without prepositions.

 f.close();
 fout.close();

// counting the words now --
vector<string> stringholder;
vector<string> unqstringholder;
f.open("sometext_2.txt",ios::in);

if (f.is_open()) {
         while (f>>word){
                stringholder.push_back(word);         //all words from file no.2 inserted to the vector
         }
  }

  sort(stringholder.begin(),stringholder.end());      // sorted in dictionary order

int vectorsize = stringholder.size();
    wordcount = 1;
    word = stringholder[0];

    for (int i=1;i<vectorsize;i++) {                  //each word is counted in this loop

        if (word!=stringholder[i]) {
            if (wordcount == 1 && wordcount < 2) {
                unqstringholder.push_back(word);        // storing all the unique words in another vector
            }
            else if (wordcount>=2)
            cout<<endl<<"  "<<word<<" appears "<<wordcount<<" times ";
            wordcount=0;
            word=stringholder[i];

        }
        wordcount++;

    }
    cout<<endl;
    cout<<endl<<"  here is the list of all the unique words : "<<endl;

vectorsize = unqstringholder.size();

 for (int i=0;i<vectorsize;i++)   {                      // now printing that vector which has unique values
        cout<<endl<<"  "<<unqstringholder[i];
 }
 cout<<endl;

 //PORTER STEMMING OF ALL THE WORDS IN THE STRINGHOLDER VECTOR (aka all the words) -- //
 cout<<" here are the roots words for all the words in the text file \n (parsed through the porter stemmer algorithm) : ";
     for (int i=0;i<vectorsize;i++) {
            word = stringholder[i];
            Porter2Stemmer::stem(word);
            cout<<"  "<<word<<endl;
     }


 cout<<endl;
  f.close();
  return 0;

}             
