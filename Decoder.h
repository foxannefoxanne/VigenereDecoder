/*
 * Name: Roxanne Calderon
 * ID: 2613650
 * Project: MiniProject 2
 * Date: 2/26/2015
 */

#include <iostream> 
#include <string>
#include <fstream> 
#include <cmath>

#ifndef DICTIONARY_H
#define DICTIONARY_H


class Decoder{

  
  struct Node {
       		 std::string value;
       		 Node *next;
	};	
	
      private:
	  Node** head;  
	  
      public:
	  Decoder(); 
	  Decoder(std::istream& input); 
	  ~Decoder(); 
	  void retrieveInput(std::string cipherText, int keyLength, int fwLength);
	  std::string decoder(std::string message, std::string key, int strLength); 
	  
}; 

#endif 