// compile: cl validate.cpp
// compile with: /EHa
#include <fstream>
#include <iostream>
#include <cctype>
#include <regex>
#include <string>
#include <cstdio>

using namespace std;
using std::cout;

/* Create a function that converts the first letter of every name. */
void capitalize(string &data)
{
    /* Implement a for loop to parse through each letter of the string. */
    for(int i = 0; i < data.length(); i++)
    {
        /* Capitalize the first letter of the string. */
        if(i == 0 && data[0] != 'q')
        {
            data[i] = toupper(data[i]);
        }
        /* Capitalize the letter that comes after a space. */
        else if(data[i - 1] == ' ')
        {
            data[i] = toupper(data[i]);
        }
    }
}

int main(int argc, char **argv)
{
    /* Declare the variables. */
    string data;
    int mcguffin = 0, mcguffin2 = 0, mcguffin3 = 0, mcguffin4 = 0;

    /* Open a file in write mode. Creates and writes to the 'output.txt' file. */
    ofstream outfile;
    outfile.open("output.txt");
    /* Set in a precaution if 'output.txt' fails to open. */
    if(outfile.fail())
    {
        /* Display a message if 'output.txt' fails to open. */
        cout << "Couldn't open the file!" << endl;
        return 0;
    }

    cout << "\nINSTRUCTIONS:" << endl;
    cout << "(1) Enter q to exit." << endl;
    cout << "(2) Enter a blank space to skip (does not apply to NAME prompts)." << endl;

    putchar('\n');
    /* Indicate to the user that they are now entering information that will transfer into 'output.txt'. */
    cout << "Writing to the file..." << endl;

    while(1)
    {
        /* Set loop to a true condition. */
        while(mcguffin == 0)
        {
            putchar('\n');
            /* Allow the user to enter the name. */
            cout << "Enter the name: ";
            /* Receive name from the user. */
            getline(cin, data);
            
            /* Utilize the capitalize function. */
            capitalize(data);

            /* Declare the regular expression that will be used to validate the name. */
            regex regname("^[A-Z]([a-z]{0,32}(([',.-]{1}([A-Z]{1}))?([a-z',.-]+(\\s[A-Z]{1})*))*)$");

            /* Determine if the user input matches the regular expression for the name. */
            if(regex_match(data, regname))
            {
                /* Write inputted data into the file. */
                outfile << "Name: " << data << endl;
                /* Exit the nested loop. */
                break;
            }
            /* Determine if 'q' has been entered. */
            else if(data == "q")
            {
                /* Exit the nested loop. */
                break;
            }
            else
            {
                /* Display a message to indicate that the input entered was invalid. */   
                cout << "Name was considered to be invalid." << endl;
                /* Loop the name prompt. */
                mcguffin = 0;
            }
        }
        if(data == "q")
        {
            /* Exit the prime loop. */
            break;
        }
        else
        {
            /* Declare a nested loop through a true condition. */
            while(mcguffin2 == 0)
            {
                /* Allow the user to enter the date of birth of the name previously entered. */
                cout << "Enter the date of birth (yyyy/mm/dd): ";
                /* Receive DOB from the user. */
                getline(cin, data);

                /* Declare the regular expression that is used to validate the DOB. */

                regex regdate("((18|19|20)[0-9]{2}[\\/.](0[13578]|1[02])[\\/.](0[1-9]|[12][0-9]|3[01]))|(18|19|20)[0-9]{2}[\\/.](0[469]|11)[\\/.](0[1-9]|[12][0-9]|30)|(18|19|20)[0-9]{2}[\\/.](02)[\\/.](0[1-9]|1[0-9]|2[0-8])|(((18|19|20)(04|08|[2468][048]|[13579][26]))|2000)[\\/.](02)[\\/.]29");

                /* Determine if the user input is validated by the regular expression. */
                if(regex_match(data, regdate))
                {
                    /* Write inputted data into the file. */
                    outfile << "Date of Birth: " << data << endl;
                    /* Exit the nested loop. */
                    break;
                }
                else if(data == "q")
                {
                    /* When exiting... ensure the other information is unavailable. */
                    outfile << "Date of Birth: (not available)" << endl;
                    outfile << "Phone Number: (not available)" << endl;
                    outfile << "Postcode: (not available)" << endl;
                    /* Exit the nested loop if 'q' was entered. */
                    break;
                }
                /* If the user enters nothing, then there will be unavailable data in file. */
                else if(data == "")
                {
                    /* Write into the file that the DOB information is unavailable. */
                    outfile << "Date of Birth: (not available)" << endl;
                    /* Assure the user that the DOB information has been skipped. */
                    cout << "Date of birth information has been skipped..." << endl;
                    /* Exit the nested loop. */
                    break;
                }
                else
                {
                    /* Indicate to the user that their input was invalid. */
                    cout << "Date of birth was considered to be invalid." << endl;
                    /* Loop the DOB prompt to the user. */
                    mcguffin2 = 0; 
                }
            }
            if(data == "q")
            {
                /* Exit the prime loop if 'q' has been entered. */
                break;
            }
            else
            {
                /* Declare a nested loop through a true condition. */
                while(mcguffin3 == 0)
                {
                    /* Persuade the user to enter the phone number of the specific name
                    previously entered. */
                    cout << "Enter the phone number: ";
                    /* Receive the phone number from user. */
                    getline(cin, data);

                    /* Declare the regular expression that will be used to validate the phone number. */
                    regex regphone("^[0](([0-9]){10}|([0-9]{4}\\s([0-9]{6}))$)");

                    /* Determine if the input is valid through the regular expression of the phone number. */
                    if(regex_match(data, regphone))
                    {
                        /* Write inputted data into the file. */
                        outfile << "Phone Number: " << data << endl;
                        /* Exit the nested loop. */
                        break;
                    }
                    else if(data == "q")
                    {
                        /* When exiting... ensure the other information is unavailable. */
                        outfile << "Phone Number: (not available)" << endl;
                        outfile << "Postcode: (not available)" << endl;
                        /* If 'q' is entered, exit the nested loop. */
                        break;
                    }
                    else if(data == "")
                    {
                        /* Write unavailable information for the phone number section into the file. */
                        outfile << "Phone Number: (not available)" << endl;
                        /* Assure the user that the phone number information has been skipped. */
                        cout << "Phone number information has been skipped..." << endl;
                        /* Exit the nested loop. */
                        break;
                    }
                    else
                    {
                        /* Indicate to the user that the phone number entered is invalid. */
                        cout << "Phone number was considered to be invalid." <<  endl;
                        /* Loop the phone number prompt back to the user. */
                        mcguffin3 = 0;
                    }
                }
                if(data == "q")
                {
                    /* Make sure to exit the prime loop if 'q' was entered. */
                    break;
                }
                else
                {
                    /* Declare another nested loop through a true condition. */
                    while(mcguffin4 == 0)
                    {
                        /* Allow the user to enter the postcode information of the specific name
                        previously entered. */
                        cout << "Enter the postcode: ";
                        /* Receive the postcode information from the user. */
                        getline(cin, data);

                        regex regpost("^[A-Z]{1,2}([0-9]{1,2})(\\s[0-9]{1})([A-Z]{2})$");
                        if(regex_match(data, regpost))
                        {
                            /* Write inputted data into the file. */
                            outfile << "Postcode: " << data << endl;
                            /* Exit the nested loop. */
                            break;
                        }
                        else if(data == "q")
                        {
                            /* When exiting... ensure the other information is unavailable. */
                            outfile << "Postcode: (not available)" << endl;
                            /* Exit the nested loop if 'q' was entered. */
                            break;
                        }
                        else if(data == "")
                        {
                            /* Write into the file that the postcode information is unavailable. */
                            outfile << "Postcode: (not available)" << endl;
                            /* Assure the user that the postcode information has been skipped. */
                            cout << "Postcode information has been skipped..." << endl;
                            /* Exit the nested loop. */
                            break;
                        }
                        else
                        {
                            /* Display a message to let user know that the postcode entered is invalid. */
                            cout << "Postcode was considered to be invalid." << endl;
                            /* Loop the postcode prompt back to the user. */
                            mcguffin4 = 0;
                        }
                    }
                    if(data == "q")
                    {
                        /* Make sure to exit the prime loop if user enters 'q'. */
                        break;
                    }
                    else
                    {
                        /* Write in a space/empty line to organize and distinguish the 
                        information of different people. */
                        outfile << "\n";
                        /* Continue to loop through the prime while loop. */
                        continue;
                    }
                }
            }
        }
    }
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
    while(getline(infile, data))
    {
        /* Write the data at the screen. */
        cout << data << endl;
    }

    /* Close the opened file. */
    /* It is consiered good practice, and it can clean up unnecessary memory space. */
    infile.close();

    return 0;
}