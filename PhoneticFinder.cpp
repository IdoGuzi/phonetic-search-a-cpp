#include <iostream>
#include "PhoneticFinder.hpp"

string phonetic::find(string text, string word){
    int start=0,end=0;
    string temp;
    //lower case the word
    for (int i=0;i<word.length();i++) {
        //delete every character that isn't a letter
        if (!((95<word.at(i)&&word.at(i)<123) || (64<word.at(i)&&word.at(i)<91))) {
            word.erase(i,1);
            i--;
            continue;
        }
        word.at(i)=std::tolower(word.at(i));
    }

    //for every word in the string
    while(start<text.length()){
        //check for spaces
        if (text.at(start)==' ') {start++; end++; continue;}

        //getting the next word in the string.
        while(end<text.length() && text.at(end)!=' ') {end++;continue;}
        temp=text.substr(start,end-start);

        //converting all letter in the temporary word to lower case.
        int count_non_letter=0;
        for (int i=0;i<temp.length();i++) {
            //delete every character that isn't a letter.
            if (!((95<temp.at(i)&&temp.at(i)<123) || (64<temp.at(i)&&temp.at(i)<91))) {
                temp.erase(i,1);
                i--;
                count_non_letter++;
                continue;
            }
            temp.at(i)=std::tolower(temp.at(i));
        }

        //checking words:
        //assuming both word equal.
        bool equal=true;
        //length should be equal.
        if (word.length()!=temp.length()) {start=(++end);continue;}
        //checking each letter in the string.
        for (int i=0;i<word.length();i++){
            char c1=word.at(i);
            char c2=temp.at(i);
            if (c1==c2){
                continue;
            }else if ((c1=='v' || c1=='w') && (c2=='v' || c2=='w')) {
                continue;
            }else if ((c1=='b' || c1=='f' || c1=='p') && (c2=='b' || c2=='f' || c2=='p')) {
                continue;
            }else if ((c1=='g' || c1=='j') && (c2=='g' || c2=='j')){
                continue;
            }else if ((c1=='c' || c1=='k' || c1=='q') && (c2=='c' || c2=='k' || c2=='q')) {
                continue;
            }else if ((c1=='s' || c1=='z') && (c2=='s' || c2=='z')){
                continue;
            }else if ((c1=='d' || c1=='t') && (c2=='d' || c2=='t')){
                continue;
            }else if ((c1=='o' || c1=='u') && (c2=='o' || c2=='u')){
                continue;
            }else if ((c1=='i' || c1=='y') && (c2=='i' || c2=='y')){
                continue;
            }else{
                equal=false;
                start=end+1;
                end=start;
                break;
            }
        }
        if (equal) return text.substr(start,end-start+count_non_letter);
    }
    string err = "\"" + word + "\" is not a full word in the sentence";
    throw runtime_error(err);
}


