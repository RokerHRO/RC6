#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "RC6.hpp"

#define RC6_W 32
#define RC6_R 20


/******************************************************************
 * Function: keyLength
 * Input: <std::string> key
 * Output: unsigned int
 * Description: Determines b for the RC6-w/r/b cryptography.
 *              It outputs the length of the encryption key in bytes
 ******************************************************************/
void remove_whitespace(std::string& str){
  str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void to_upper_ascii(std::string& str)
{
	for(char& c : str)
	{
		if(c>='a' && c<='z')
		{
			c -= 32;
		}
	}
}

/******************************************************************
 * Function: keyLength
 * Input: <std::string> key
 * Output: unsigned int
 * Description: Determines b for the RC6-w/r/b cryptography.
 *              It outputs the length of the encryption key in bytes
 ******************************************************************/
unsigned int keylength(const std::string& key){
  return key.length() / 2;
}

/******************************************************************
 * Function: main
 * Input: <int> argc, <char **> argv
 * Output: int
 * Description: ./run ./input.txt ./output.txt 
 *              Runs RC6 program to encrypt the message in 
 *              given to the program. The input.txt contains
 *              the user key and the plaintext or ciphertext.
 *              If plaintext, then an encryption is performed.
 *              If ciphertext, then a decryption is performed.
 *              The output of the program is either the ciphertext 
 *              (for encryption) or the plaintext (for decryption).
 ******************************************************************/
int main(int argc, char *argv[]){

  if(argc != 4){
    std::cerr << "Incorrect number of arguments" << std::endl;
    return 9;
  }
  
  const std::string plaintext(argv[1]);
  const std::string key(argv[2]);
  const std::string ciphertext(argv[3]);

  RC6 rc6 = RC6(RC6_W, RC6_R, keylength(key));
  std::string result = rc6.run("Encryption", key, plaintext);
  remove_whitespace(result);
  to_upper_ascii(result);
  
  if(result != ciphertext)
  {
     std::cerr << "Encrytpion failed.!\n"
     		"Plaintext: \"" << plaintext << "\".\n"
     		"Key        \"" << key << "\".\n"
     		"encrypt to \"" << result << "\",\n"
     		"I expected \"" << ciphertext << "\"\n"
     		"\n";
     return 1;
  }

  return 0;
}
