/*
 * Name: Roxanne Calderon
 * ID: 2613650
 * Project: MiniProject 2
 * Date: 2/26/2015
 */
#include "Decoder.h"
#include <ctime>
using namespace std; 


int main(int argc, char* argv[])
{
     //load in dictionary file
     ifstream inputFile; 
     inputFile.open("Dictionary.txt");
     cout << "Dictionary is loading.....\n";  
     Decoder dc(inputFile); 

     bool timeToExit = false; 
     
     //prompt users for information. 
     while(!timeToExit){
	 cout << "\nWhat is the ciphertext? \n"; 
	 string message; 
	 cin >> message; 
	 
	 bool validKey = false; 
	 int keyLength; 

	 bool validFW = false;
	 int fwLength;
  
	 bool validExitInt = false; 
	 int exitInt; 

	 while(!validKey){
	  cout << "\nHow long is the key?\n";
	  cin >> keyLength;
	
	  if(cin.fail()){
	      cin.clear();
	      cin.ignore();
	      cout << "Please enter a number. \n \n";	
	    }
	 
	  else validKey = true; 
	  
	}
	 
	 while(!validFW){
	  cout << "\nHow long is the first word?\n";
	   cin >> fwLength; 
	 
	  if(cin.fail()){
	    cin.clear();
	    cin.ignore();
	    cout << "Please enter a number. \n \n";	
	  }
	  else validFW = true; 
	 } 
	 
	 //time input
	 clock_t start;
	 start = clock(); 
	 dc.retrieveInput(message,keyLength,fwLength); 
	 cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms \n";


	while(!validExitInt){
	  cout << "\nAnother? (1) yes (2) no\n"; 
	  cin >> exitInt; 
	  
	  if(cin.fail()){
	      cin.clear();
	      cin.ignore();
	      cout << "Please enter a number. \n \n";	
	    }
	  else validExitInt = true; 
	  
	} 
	if(exitInt == 2)
	  timeToExit = true; 
       
    
     } 
     
     
     return 0; 
} 