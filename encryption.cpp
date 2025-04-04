#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Cipher 
{
	private:
	    // Alphabet array in reverse order
	    char alphabets[27] = {'_', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
	                          'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	public:
	    // Function to encrypt the input string
	    void encrypt(const string& input) 
		{
	        int length = input.length();
	        string encrypted;
	
	        // Loop through each character in the input string
	        for (int i = 0; i < length; i++) 
			{
	            char currentChar = input[i];
	
	            // Convert lowercase characters to uppercase
	            if (islower(currentChar)) 
				{
	                currentChar = toupper(currentChar);
	            }
	            
	            // Preserve spaces
	            if (currentChar == ' ') 
				{
	                encrypted += ' ';
	                continue;
	            }
	            // Encrypt the character
	            for (int j = 0; j <= 26; j++) 
				{
	                if (currentChar == alphabets[j])
					 {
	                    int Formula = (5 * j) + 3;
	                    int Index = Formula % 26;
	                    if(Index == 0)
	                    {
	                    	encrypted += alphabets[26];
						}
						else
						{	
	                    encrypted += alphabets[Index];
	                    break;
	               		}
					}
	            }
	        }
			// Output encrypted string
	       cout << "<<<<<<<<< Encrypted msg >>>>>>>>>>\n" << endl;
		   cout << "~~~  " << encrypted << endl;
	    }
	
	    // Function to decrypt the input string
	    void decrypt(const string& encryptedInput) 
		{
	        int length = encryptedInput.length();
	        string decrypted;
	
	        // Loop through each character in the encrypted string
	        for (int i = 0; i < length; i++) 
			{
	            char currentChar = encryptedInput[i];
	
	            // Convert lowercase characters to uppercase
	            if (islower(currentChar)) 
				{
	                currentChar = toupper(currentChar);
	            }
	            // Preserve spaces
				if (currentChar == ' ') 
				{
	                decrypted += ' ';
	                continue;
	            }
	            // Decrypt the character
	            for (int j = 0; j <= 26; j++) 
				{
	                if (currentChar == alphabets[j]) 
					{
	                    double Formula = static_cast<double>(j - 3) / 5;
	                    if (Formula == static_cast<int>(Formula))
						 {
	                        int temp = static_cast<int>(Formula);
	                        int Index = temp % 26;
							decrypted += alphabets[Index];
	                    } 
						else
						{
							if(Formula < 0)
							{
								int temp = ((Formula * 5) * 21);
								int Index = temp + 26;
								decrypted += alphabets[Index];
							}
							else
							{	
	                        int temp = ((Formula * 5) * 21);
	                        int Index = temp % 26;
	                        decrypted += alphabets[Index];
							}
	                    }
	                    break;
	                }
	            }
	        }
	
	       cout << "<<<<<<<<<< Decrypted msg >>>>>>>>>>\n" << endl;
		   cout << "~~~  " << decrypted << endl;
	    }
};

int main() 
{
	cout << "\t\t\t\t\tW     W  EEEEE  L        CCCC  OOO   M     M  EEEEE  \n";
    cout << "\t\t\t\t\tW     W  E      L       C     O   O  MM   MM  E     \n";
    cout << "\t\t\t\t\tW W W W  EEEE   L      C      O   O  M M M M  EEEE  \n";
    cout << "\t\t\t\t\tW W W W  E      L       C     O   O  M     M  E     \n";
    cout << "\t\t\t\t\t W W W   EEEEE  LLLLLL   CCCC  OOO   M     M  EEEEE  \n";
    cout << endl;
    cout << "\t\t\t\t     ===========================================================" << endl;
    cout << "\t\t\t\t\t  E N C R Y P T I O N   A N D   D E C R Y P T I O N" << endl;
    cout << "\t\t\t\t     ===========================================================" << endl;
    
    //Declaring Variables
    Cipher cipher;
    int choice;
    string msg;
    char again;
    
    A:
    do
    {   	
	cout << "\n\nPlease choose an option:\n";
    cout << "1. Encrypt a message\n";
    cout << "2. Decrypt a message\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
	cin.ignore();

    switch (choice) 
	{
        case 1:
            cout << "\nEnter the message to encrypt: " << endl;
            getline(cin, msg);
            cipher.encrypt(msg);
            break;
        case 2:
            cout << "\nEnter the message to decrypt: " << endl;
            getline(cin, msg);
            cipher.decrypt(msg);
            break;
        default:
            cout << "\n\nInvalid choice. Please enter 1 or 2." << endl;
            goto A;
    }
	cout << "\n\n\nDo you want to use it again? (y/n): \n\t\tY = Yes \n\t\t N = NO" << endl;
    cin >> again;
	}while(again =='y'|| again == 'Y');

    return 0;
}


