#include <iostream>
using namespace std; 

int main() {
  // 1. make a choice for encryption or decryption
  int select;
  cout << "Select your choice\n 1) Encryption\n 2) Decryption\n\n >>";
  cin >> select;
  cin.ignore();

  //encryption
  if(select == 1){
    string mgs;
    int key;
    
    cout << "Enter your text to encryption: ";
    getline(cin, mgs);

    cout << "Enter the key: ";
    cin >> key;
    cin.ignore();

    string encrypted_text = mgs; //all text will store in encryption variable.
    // now using for loop to access all text one by one
    for(int i = 0; i < mgs.size(); i++){

      //now using ASCII table
      if (mgs[i] == 32){
        continue;
      }
      else {
        //after adding key, if it cross 122 i mean z(small letter) then it will start from a which is 97
        if((mgs[i] + key) > 122){
          int temp = (mgs[i] + key) - 122;
          encrypted_text[i] = 96 + temp;
        }
        else if((mgs[i] + key) > 90 && mgs[i] <= 96){
          int temp = (mgs[i] + key) - 90;
          encrypted_text[i] = 64 + temp;
        }
        else{
          encrypted_text[i] += key;
        }
      }
    }
  cout << "Encrypted text: " << encrypted_text;
  }
  else if(select ==2){
    string mgs;
    cout << "Enter your message to decrypt: ";
    getline(cin, mgs);

    int key;
    cout << "Enter the key: ";
    cin >> key;
    cin.ignore();

    string decrypted_text = mgs;
    for(int i = 0; i < mgs.size(); i++){
      if(mgs[i] == 32){
        continue;
      }
      else{
        if((mgs[i] - key) < 97 && (mgs[i] - key) > 90){
          decrypted_text[i] = (mgs[i] - key) + 26;
        }
        else if((mgs[i] - key) < 65){
          decrypted_text[i] = (mgs[i] - key) + 26;
        }
        else{
          decrypted_text[i] = mgs[i] - key;
        } 
      }
    }
  cout << "Decrypted Text: " << decrypted_text << endl;
  }
  else{
    cout << "Invalid Input!!";
  }


  
  return 0;
}
