#include <fstream>
#include <iostream>
#include <cctype>
#include <regex>
#include <string>
#include <cstdio>

using namespace std;
using std::cout;

/* Functions to be utilized in main(). */
void capitalize(string &data);
void capitalizePostcode(string &data);
bool isNum(string &str);
bool isSpecialChar(string &str);
string sIsBack(string &str);
void terminate(string data, std::ofstream& outfile);
void startProgram();
string receiveName(string name);
bool validateName(string name);
string receiveDOB(string date, string user);
bool validateDOB(string date);
string receivePhoneNumber(string phone, string user);
bool validatePhoneNumber(string phone);
string receivePostcode(string postcode, string user);
bool validatePostcode(string postcode);
void nameErrors(string& name);

int main(int argc, char **argv){
    /* Declare the variables. */
    string data, possessiveProperNoun;
    bool loop = true;

    /* Open a file in write mode. Creates and writes to the 'output.txt' file. */
    ofstream outfile;
    outfile.open("output.txt");
    /* Set in a precaution if 'output.txt' fails to open. */
    if(outfile.fail()) {
        /* Display a message if 'output.txt' fails to open. */
        cout << "Couldn't open the file!" << endl;
        return 0;
    }
    /* Provide the user with instructions by invoking the startProgram() function. */
    startProgram();

    while(1) {

        /* Looping Name Section */
        while(loop == true) {
            /* Get the name from the user. */
            data = receiveName(data);

            /* Read file content and exit the program if 'q' is entered. */
            if(data == "q") {
                terminate(data, outfile);
                return 0;
            }
            /* Ensure the name input follows traditional naming conventions. */
            bool name = validateName(data);

            if(name == true) {
                /* Write inputted data into the file. */
                outfile << "Name: " << data << endl;
                /* Notify the user that their input has been accepted */
                cout << "[+] '" << data << "' has been accepted." << endl;

                /* Store the validated name in the applicant variable. */
                possessiveProperNoun = sIsBack(data);
                /* Exit the current loop. */
                break;
            }
            else {
                /* Display a message to indicate that the input entered was invalid. */   
                nameErrors(data);
                /* Loop the name prompt. */
                loop = true;
            }
        }

        /* Looping DOB Section. */
        while(loop == true) {
            /* Get the DOB from the user. */
            data = receiveDOB(data, possessiveProperNoun);

            /* Read file content and exit the program if 'q' is entered. */
            if(data == "q") {
                /* When exiting... ensure the other information is unavailable. */
                outfile << "Date of Birth: (not available)" << endl;
                outfile << "Phone Number: (not available)" << endl;
                outfile << "Postcode: (not available)" << endl;
                terminate(data, outfile);
                return 0;
            }

            /* Ensure the dob input follows the yyyy/mm/dd format. */
            bool dob = validateDOB(data);

            if(dob == true) {
                /* Write inputted data into the file. */
                outfile << "Date of Birth: " << data << endl;
                /* Notify the user that their input has been accepted */
                cout << "[+] '" << data << "' has been accepted." << endl;
                /* Exit the current loop. */
                break;
            }
            else if(data == "" && dob == false) {
                /* Write into the file that the DOB information is unavailable. */
                outfile << "Date of Birth: (not available)" << endl;
                /* Assure the user that the DOB information has been skipped. */
                cout << "Date of birth information has been skipped..." << endl;
                /* Exit the current loop. */
                break;
            }
            else {
                /* Indicate to the user that their input was invalid. */
                cout << "[*] Date of birth was considered to be invalid." << endl;
                /* Loop the DOB prompt. */
                loop = true;
            }
        }

        /* Looping Phone Number Section. */
        while(loop == true) {
            /* Receive the phone number from the user. */
            data = receivePhoneNumber(data, possessiveProperNoun);

            /* Read file content and exit the program if 'q' is entered. */
            if(data == "q") {
                /* When exiting... ensure the other information is unavailable. */
                outfile << "Phone Number: (not available)" << endl;
                outfile << "Postcode: (not available)" << endl;
                terminate(data, outfile);
                return 0;
            }

            /* Ensure the phone number input follows the UK phono. format. */
            bool phone = validatePhoneNumber(data);

            if(phone == true) {
                /* Write inputted data into the file. */
                outfile << "Phone Number: " << data << endl;
                /* Notify the user that their input has been accepted */
                cout << "[+] '" << data << "' has been accepted." << endl;
                /* Exit the current loop. */
                break;
            }
            else if(data == "" && phone == false) {
                /* Write unavailable information for the phone number section into the file. */
                outfile << "Phone Number: (not available)" << endl;
                /* Assure the user that the phone number information has been skipped. */
                cout << "Phone number information has been skipped..." << endl;
                /* Exit the current loop. */
                break;
            }
            else {
                /* Indicate to the user that the phone number entered is invalid. */
                cout << "[*] Phone number was considered to be invalid." <<  endl;
                /* Loop the phone number prompt back to the user. */
                loop = true;
            }
        }

        /* Looping Postcode Section. */
        while(loop == true) {
            /* Receive the phone number from the user. */
            data = receivePostcode(data, possessiveProperNoun);

            /* Read file content and exit the program if 'q' is entered. */
            if(data == "q") { 
                /* When exiting... ensure the other information is unavailable. */
                outfile << "Postcode: (not available)" << endl;
                terminate(data, outfile);
                return 0;
            }

            /* Ensure the postcode input follows the UK postcode format. */
            bool postcode = validatePostcode(data);

            if(postcode == true) {
                /* Write inputted data into the file. */
                outfile << "Postcode: " << data << endl;
                /* Notify the user that their input has been accepted */
                cout << "[+] '" << data << "' has been accepted." << endl;
                /* Exit the nested loop. */
                break;
            }
            else if(data == "" && postcode == false) {
                /* Write into the file that the postcode information is unavailable. */
                outfile << "Postcode: (not available)" << endl;
                /* Assure the user that the postcode information has been skipped. */
                cout << "Postcode information has been skipped..." << endl;
                /* Exit the current loop. */
                break;
            }
            else {
                /* Indicate to the user that the postcode entered is invalid. */
                cout << "[*] UK Postcode was considered to be invalid." <<  endl;
                /* Loop the phone number prompt back to the user. */
                loop = true;
            }
        }
        /* Write in a space/empty line to organize and distinguish the 
        information of different people. */
        outfile << "\n";
        /* Continue to loop through the prime while loop. */
        continue;
    }
    return 0;
}

/* Create a function that converts the first letter of every name. */
void capitalize(string &data)
{
    /* Implement a for loop to parse through each letter of the string. */
    for(int i = 0; i < data.length(); i++) {
        /* Capitalize the first letter of the string. */
        if(i == 0 && data[0] != 'q') {
            data[i] = toupper(data[i]);
        }
        /* Capitalize the letter that comes after a space. */
        else if(data[i - 1] == ' ') {
            data[i] = toupper(data[i]);
        }
    }
}

/* Construct a function to determine if a string contains number(s). */
bool isNum(string &str) {
    return std::any_of(str.begin(), str.end(), ::isdigit);
}

/* Construct a function to determine if a string contains special characters. */
bool isSpecialChar(string &str) {
    return std::all_of(str.begin(), str.end(), ::isalnum);
}

/* Create a function that figures out whether the name entered has 's' as the last letter. */
/* For grammar purposes when asking for a person's dob, phone number, and postcode. */
string sIsBack(string &str) {
    if(str.back() == 's') {
        return str + "'";
    }
    else {
        return str + "'s";
    }
}

/* Add a function to read the content of the file when program terminates. */
void terminate(string data, std::ofstream& outfile)
{
    /* Close the opened file. */
    outfile.close();

    /* Open a file in read mode. Reads from files. */
    ifstream infile;
    infile.open("output.txt");

    putchar('\n');
    /* Indicate to the user that the information being presented is information 
    inside of the 'output.txt' file. */
    cout << "Reading from the file..." << endl;
    putchar('\n');

    /* Be able to read every single word/space in the file. */
    while(getline(infile, data)) {
        /* Write the data at the screen. */
        cout << data << endl;
    }

    /* Close the opened file. */
    /* It is consiered good practice, and it can clean up unnecessary memory space. */
    infile.close();
}

void startProgram() {
    
    cout << "\nINSTRUCTIONS:" << endl;
    cout << "(1) Enter q to exit." << endl;
    cout << "(2) Enter a blank space to skip (does not apply to NAME prompts)." << endl;

    putchar('\n');
    /* Indicate to the user that they are now entering information that will transfer into 'output.txt'. */
    cout << "Writing to the file..." << endl;
}

/* Construct a function that receives a validated name from user. */
string receiveName(string name) {
    putchar('\n');
    /* Allow the user to enter the name. */
    cout << "Enter the name: ";
    /* Receive name from the user. */
    getline(cin, name);
            
    /* Utilize the capitalize function. */
    capitalize(name);

    /* Return the name that was entered by the user. */
    return name;
}

/* Create a function that utilizes regex to validate the Name entered by the user. */
bool validateName(string name) {   
    /* Declare the regular expression that will be used to validate the name. */
    regex regname("^[A-Z]([a-z]{1,32}(([',.-]{1}([A-Z]{1}))?([a-z',.-]+(\\s[A-Z]{1})*))*)$");

    /* Determine if the user input matches the regular expression for the name. */
    if(regex_match(name, regname)) {   
        /* Name is true if it passes regex conditions. */
        return true;
    }
    else {
        /* Name is flase if it fails to pass regex conditions. */ 
        return false; 
    }
}

/* Create a function that notifies the user of the name errors. */
void nameErrors(string& name) {

    /* Find out if the name contains a number */
    if(isNum(name) == true) {
        cout << "[*] Names should not contain any numbers" << endl;
    } 

    /* Find out if the name is less than two characters. */
    if(name.length() <= 1 && name != "") {
        cout << "[*] '" << name << "' is too short to be considered a name" << endl;
    }

    /* Check if the name contains any special characters. */
    if(isSpecialChar(name) == false) {
        cout << "[*] Names should not contain special characters" << endl;
    }

    /* Cannot skip the name */
    if(name == "") {
        cout << "[*] Skipping the Name label is not permitted" << endl;
    }
}

/* Create a function that asks the user to enter DOB. */
string receiveDOB(string date, string user) {
    putchar('\n');
    /* Allow the user to enter the date of birth of the name previously entered. */
    cout << "Enter " << user << " date of birth (yyyy/mm/dd): ";
                
    /* Receive DOB from the user. */
    getline(cin, date);

    return date;
}

/* Create a function that utilizes regex to validate DOB. */
bool validateDOB(string date) {
    /* Declare the regular expression that is used to validate the DOB. */
    regex regdate("((18|19|20)[0-9]{2}[\\/.](0[13578]|1[02])[\\/.](0[1-9]|[12][0-9]|3[01]))|(18|19|20)[0-9]{2}[\\/.](0[469]|11)[\\/.](0[1-9]|[12][0-9]|30)|(18|19|20)[0-9]{2}[\\/.](02)[\\/.](0[1-9]|1[0-9]|2[0-8])|(((18|19|20)(04|08|[2468][048]|[13579][26]))|2000)[\\/.](02)[\\/.]29");

    /* Determine if the user input is validated by the regular expression. */
    if(regex_match(date, regdate)) {
        /* DOB passes regex conditions. */
        return true;
    }
    else {
        /* DOB fails regex conditions. */
        return false;
    }
}

/* Construct a function that receives a validated phone number from user. */
string receivePhoneNumber(string phone, string user) {
    putchar('\n');
    /* Allow the user to enter the phone number. */
    cout << "Enter " << user << " phone number: ";
    /* Receive phone number from the user. */
    getline(cin, phone);
            
    /* Return the phone number that was entered by the user. */
    return phone;
}

/* Create a function that utilizes regex to validate phone numbers. */
bool validatePhoneNumber(string phone) {
    /* Declare the regular expression that will be used to validate the phone number. */
    regex regphone("^[0](([0-9]){10}|([0-9]{4}\\s([0-9]{6}))$)");

    /* Determine if the user input is validated by the regular expression. */
    if(regex_match(phone, regphone)) {
        /* Phone number passes regex conditions. */
        return true;
    }
    else {
        /* Phone number fails regex conditions. */
        return false;
    }
}

/* Create a function that capitalizes each letter of postcode input. */
void capitalizePostcode(string &data) {
    /* Implement a for loop to parse through each letter of the string. */
    for(int i = 0; i < data.length(); i++) {
        /* Capitalize every letter of the postcode. */
        if(isalpha(data[i]) == true) {
            data[i] = toupper(data[i]);
            continue;
        }
        else {
            continue;
        }
    }
}

/* Construct a function that receives a validated UK postcode from user. */
string receivePostcode(string postcode, string user) {
    putchar('\n');
    /* Allow the user to enter the postcode. */
    cout << "Enter " <<  user << " postcode: ";
    /* Receive postcode from the user. */
    getline(cin, postcode);

    /* Capitalize each letter of the postcode. */
    capitalizePostcode(postcode);
            
    /* Return the postcode that was entered by the user. */
    return postcode;
}

/* Create a function that utilizes regex to validate UK postcodes. */
bool validatePostcode(string postcode) {
    /* Declare the regular expression that will be used to validate the UK postcode. */
    regex regpost("^[A-Z]{1,2}([0-9]{1,2})(\\s[0-9]{1})([A-Z]{2})$");

    /* Determine if the user input is validated by the regular expression. */
    if(regex_match(postcode, regpost)) {
        /* UK postcode passes regex conditions. */
        return true;
    }
    else {
        /* UK postcode number fails regex conditions. */
        return false;
    }
}