#include "ExternalSearch.h"
#include <stdio.h>
#include <string>
#include <fstream>

bool extern_search(string fileName, string toFind)
{
	FILE * input;
	input = fopen(fileName.c_str(), "r");	//opens input file
	char test[80];
	int chars = 0;
	char h;
	
	fseek(input, 0, SEEK_END);
	chars = ftell(input);
	fseek(input, 0, SEEK_SET);
	chars = chars/2;
	fseek(input, chars, SEEK_SET);
	char c;
	//cout << "search" << endl;
	c = getc(input);
	if (c == '\n') {
	  ungetc(c, input);
	  fseek(input, -1, SEEK_CUR);
	  c = getc(input);
	}
	
	while (c != '\n') {
	  //cout << "loop1" << endl;
	  ungetc(c, input);
	  if (fseek(input, -1, SEEK_CUR)) break;
	  c = getc(input);
	  //chars++;
	}
	string previous = string();
	ungetc(c, input);
	fseek(input, 1, SEEK_CUR);
	//chars++;
	int loop = chars;
	//int less = 0;
	int jump = chars;
	while(loop >= 1) {
	  //cout << "loop2" << endl;
	  //cout << loop << endl;
	  fscanf(input, "%s", test);
	  std::string comp(test);
	  //cout << previous << endl;
	  //int newLine = 0;
	  if (comp.compare(toFind) == 0) return true;
	  if (comp.compare(previous) == 0) {	//not enough characters to move up alone, so move up automatically
	    if (comp.compare(toFind) > 0) {
	      if(fseek(input, -1, SEEK_CUR)) break;;
	      c = getc(input);
	      int newLine = 0;
	      while (c != '\n' || newLine <= 1) {		//needs to move up by two newline characters
		ungetc(c,input);
	        if (fseek(input, -1, SEEK_CUR)) break;;
		c = getc(input);
	        if (c == '\n') newLine++;

	      }
	      //newLine++;
	      ungetc(c, input);
	      fseek(input, 1, SEEK_CUR);
	      fscanf(input, "%s", test);
	      std::string comp(test);
	    }
	    if (comp.compare(toFind) < 0) {
	      
	      fscanf(input, "%s", test);
	      fscanf(input, "%s", test);
	      //cout << "here" << endl;
	      std::string comp(test);
	    }
	    if (comp.compare(toFind) == 0) return true;
	  }
	  previous = comp;
	  if (comp.compare(toFind) == 0)		//word has been found
	    return true;
	  else if (comp.compare(toFind) < 0){		//word is higher than current
	    chars = (chars/2);
	    fseek(input, chars, SEEK_CUR);
	  }
	  else {					//word is lower than current
	    chars = chars/2;
	    fseek(input, -chars, SEEK_CUR);
	  }
	  c = getc(input);
	  if (c == EOF) break;	//EOF has reached, not found
	  if (c == '\n') {
	    ungetc(c, input);
	    fseek(input, -1, SEEK_CUR);
	    c = getc(input);
	  }
	  while (c != '\n') {		//find beginning of next word
	    ungetc(c,input);
	    if (fseek(input, -1, SEEK_CUR)) break;
	    c = getc(input);
	  }
	  ungetc(c, input);
	  fseek(input, 1, SEEK_CUR);
	  loop = loop/2;
	  //cout << comp << "comp" << endl;
	}
	//cout << comp << endl;
	//cout << toFind << endl;
	fscanf(input, "%s", test);
	std::string check(test);
	if (check.compare(toFind) == 0) return true;
	//cout << check << endl;
	fseek(input, -1, SEEK_CUR);
	c = getc(input);
	if (c == '\n') {
	  ungetc(c,input);
	  fseek(input, -1, SEEK_CUR);
	  c = getc(input);
	}
	//cout << c << endl;
	while (c != '\n') {
	  ungetc(c, input);
	  if(fseek(input, -1, SEEK_CUR)) break;
	  c = getc(input);
	}
	ungetc(c, input);
	fscanf(input, "%s", test);
	std::string before(test);
	//cout << before << "before" << endl;
	if (before.compare(toFind) == 0) return true;
	fseek(input, -2, SEEK_CUR);
	int line = 0;
	c = getc(input);
	while (c != '\n' || line <= 1) {
	  ungetc(c,input);
	  if(fseek(input, -1,SEEK_CUR)) break;
	  c = getc(input);
	  if (c == '\n') line++;
	}
	ungetc(c,input);
	fseek(input, 1, SEEK_CUR);
	//cout << c << endl;
	fscanf(input, "%s", test);
	std::string next(test);
	if (next.compare(toFind) == 0) return true;
	
	//cout << next << "next" << endl;
	//cout << toFind << endl;
	
	fseek(input, 0, SEEK_SET);
	fscanf(input, "%s", test);
	std::string comp(test);
	if (comp.compare(toFind) == 0) return true;	//first word of document
	fscanf(input, "%s", test);
	std::string second(test);
	if (second.compare(toFind) == 0) return true;
	fseek(input, -2, SEEK_END);	//check if last word is toFind
	c = getc(input);
	while (c != '\n') {
	  ungetc(c, input);
	  if (fseek(input, -1, SEEK_CUR)) break;
	  c = getc(input);
	}
	ungetc(c, input);
	fseek(input, 1, SEEK_CUR);
	fscanf(input, "%s", test);
	std::string last(test);
	if (last.compare(toFind) == 0) return true;	//last word	
	return false;
}
