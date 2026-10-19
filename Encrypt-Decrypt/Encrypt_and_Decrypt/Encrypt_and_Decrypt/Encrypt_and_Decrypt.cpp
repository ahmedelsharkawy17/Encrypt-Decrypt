#include <iostream>
#include <string>
using namespace std;


string encryptCaesarCipher(const string& message, int shift) {
    string encryptedMessage = message;

   
    for (char& ch : encryptedMessage) {
        if (isalpha(ch)) {
            
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + shift) % 26 + offset;
        }
    }

    return encryptedMessage;
}


string decryptCaesarCipher(const string& message, int shift) {
    string decryptedMessage = message;

    
    for (char& ch : decryptedMessage) {
        if (isalpha(ch)) {
           
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset - shift + 26) % 26 + offset;
        }
    }

    return decryptedMessage;
}

int main() {
    while (true) {
        cout << "Do you want to:\n";
        cout << "1. Encrypt a message\n";
        cout << "2. Decrypt a message\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";

        int choice;
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            
            cout << "Enter the message to encrypt: ";
            string originalMessage;
            getline(cin, originalMessage);

            cout << "Enter the shift value (key): ";
            int shift;
            cin >> shift;
            cin.ignore();

            string encryptedMessage = encryptCaesarCipher(originalMessage, shift);
            cout << "\nEncrypted Message: " << encryptedMessage << endl;

        }
        else if (choice == 2) {
            
            cout << "Enter the encrypted message: ";
            string encryptedMessage;
            getline(cin, encryptedMessage);

            cout << "Enter the shift value (key): ";
            int shift;
            cin >> shift;
            cin.ignore();

            string decryptedMessage = decryptCaesarCipher(encryptedMessage, shift);
            cout << "\nDecrypted Message: " << decryptedMessage << endl;
        }
        else if (choice == 3) {
            cout << "Exiting the program. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }

        cout << "\n";
    }

    return 0;
}
