/*
 * Name: Roxanne Calderon
 * ID: 2613650
 * Project: MiniProject 2
 * Date: 2/26/2015
 */

#include "Decoder.h"
using namespace std;

Decoder::Decoder(){
} 

/*
 *  @param: input stream to initialize dictionary
 *  Set dictionary up as hash table.  
 */ 
Decoder::Decoder(std::istream& input){
    head = new Node*[16];
    
    for(int i = 0; i < 16; i++){
	head[i] = nullptr; 
    }
    
    string val; 
    while(input >> val){
         int strLen = val.length(); 
	 
	 Node* newNode = new Node; 
	 newNode -> value = val;
	 newNode -> next = nullptr; 
	 
	 if(head[strLen] == nullptr){
	     head[strLen] = newNode; 
	  } 
	else{
	    Node* currentNode = head[strLen]; 
	    while(currentNode -> next != nullptr){
	       currentNode = currentNode -> next;
	    } 
	    currentNode -> next = newNode; 
	}   
   }   
} 

/*
 *  Clean out hash table. 
 *  
 */ 
Decoder::~Decoder(){
  for(int i = 0; i < 16; i++)
  {
    Node* temp;
    while(head[i] != nullptr){
      temp = head[i]; 
      head[i] = head[i] -> next;
      delete head[i]; 
     } 
  } 
  
} 


/*
 *  @param: string for cipher text, length of key and fwlength
 *  Run through all possible keys and compare with dictonary.
 */ 
void Decoder::retrieveInput(string cipherText, int keyLength, int fwLength){
    
    //generate loop length, and starter string
    int loopLength = pow(26,keyLength); 
    string alphGuess = "";
     
    for(int i = 0; i < keyLength; i++){
       alphGuess += 'A';
     } 
     
     //run through all loop lengths
     for(int i = 0; i < loopLength; i++){ 	  
        //current string is send to decoder 
        string result = decoder(cipherText, alphGuess, fwLength); 
	
	//run through dictionary for all possible nodes
	Node* fwNode = head[fwLength]; 
	 while(fwNode != nullptr){
	    string decodeFW = fwNode -> value; 
	    if(result.compare(decodeFW) == 0){
		 string validWord = decoder(cipherText, alphGuess, cipherText.length());
		 cout << alphGuess << ":  " << validWord << "\n \n"; 
	    } 
	   fwNode = fwNode -> next; 
	 }
	 
	 //add in new string character, if z, wrap around. 
	 if(alphGuess[keyLength - 1] == 'Z'){
	      string newString = ""; 
	      
	      bool changeNext = true;
	   //   alphGuess[keyLength - 1] = 'A'; 
	      
	      for(int i = keyLength - 1; i >= 0; i--){
		  if(changeNext){
		      if(alphGuess[i] != 'Z'){
			   alphGuess[i]++; 
			  changeNext = false;   
		      }  
		     else{
		          alphGuess[i] = 'A'; 
			  changeNext == true;
		     } 
		    
		  }
		
		  newString = alphGuess[i] + newString; 
	      } 
	      
	     alphGuess = newString; 
	   
	 } 
	 else{
		char newEnd = alphGuess[keyLength - 1];
		alphGuess = alphGuess.substr(0, keyLength - 1);  
		newEnd++; 
		alphGuess = alphGuess + newEnd; 
	 } 
	 
    } 
}

/*
 *  @param: string of message and key, integer for string length. 
 *  Run through all possible keys and compare with dictonary.
 */ 
string Decoder::decoder(string message, string key, int strLength){
 string result = ""; 
 
 for(int i = 0, j = 0; i < strLength; i++){

     result += (message[i] - key[j] + 26) % 26 + 'A';
    
    j = (j + 1) % key.length(); 
   
 }  
 return result;  
} 