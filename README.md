# Software Development 2: Regex Project

The objective of this project is to write a program that accepts four pieces of information (that are specific from the user): `name`, `date of birth`, `phone number`, `postcode`. Furthermore, the program will tend to ask the users for input until `q` is entered in which all the information that was entered is transferred into a txt file called: `output.txt`.

<img width="1236" alt="Screen Shot 2022-08-26 at 2 09 42 AM" src="https://user-images.githubusercontent.com/96035297/186795391-9024e589-7aea-4ba9-bb0d-4d8980ba3e68.png">

## Installation 
* Clone this repository: `git clone https://github.com/tyeborg/softdev2-regex-project.git`
* Open your terminal, and in the project directory prepare to compile `main.cpp`
  *  Mac OS: `g++ main.cpp -o main`
  * Windows: `cl main.cpp` followed with `/EHa` as this program attempts to catch an exception that’s raised by something other than a throw
* Run the program by entering the following: `./main`

## Program Functionality
Throughout the process of entering input for the `date of birth`, `phone number`, or `postcode`, users will have the option to skip the providence of input for a given section and proceed to the next prompt. To enable the skip function, the user will have to enter a blank statement after the prompt. 

In the output file, the result will be classified as `(not available)` for the section that was skipped.  This option is excluded for the `name` prompt because the name input distinguishes the upcoming prompt input/information by the name entered by the user.

<img width="1236" alt="program-functionality-01" src="https://user-images.githubusercontent.com/96035297/187001913-ef8d5772-61f2-4ad9-a903-ee4980945bf7.png">

Much of the data read by this program is not validated. That is, it is possible to enter data that is not in the correct format. You must extend the program so that only correctly entered data can be accepted into the store of employees.

* The name must only contain letters and appropriate symbols.
  * For example, the following are acceptable:
    * Kevin Chalmers
    * Kimia Aksir
    * Mary O’Neil
    * Ahmed Al-Dubai
  * The following are not acceptable:
    * Kevin4 – contains a number
    * Pelumi @Roehampton – contains an inappropriate symbol.
   
* The date of birth must use the format `yyyy/mm/dd` – this is to allow quick sorting of dates.
  * For example, the following are acceptable:
    * `2021/01/24`
    * `2021/10/01`
    * `1984/07/19`
  * The following are not acceptable:
    * `21/10/15` – year must be four digits.
    * `2021/1/16` – month must be two digits.
    * `2021/01/1` – day must be two digits.
    * `2021/13/12` – there is no month greater than 12.
    * `2021/05/32` – there is no day greater than 31.
  * Your organisation thinks it would be fantastic and will pay a bonus if you can ensure the date is valid. That is, only the correct number of days for a month are stored, including leap years. That is:
    * `2021/04/31` – is invalid, as April only has 30 days.
    * `2021/02/29` – is invalid, as February only has 29 days in 2021.
    * `2020/02/29` – is valid, as February had 29 days in 2020.
    
* Phone numbers are of the right length, starting with a `0`.
  * For example, the following are acceptable:
    * 01224565501
    * 07777000000
  * The following are not acceptable:
    * 9520111111 – doesn’t start with a `0`
    * 01234 – isn’t 11 digits long
    * 01234 567890 – has a space
    
* Postcodes must follow the correct format for a postcode. That is one to two uppercase letters, one to two numbers, a space, a number, then two uppercase letters.
  * For example, the following are acceptable:
    * SW15 1PU
    * E1 5RF
    * G12 6PT
    * EH1 1HR
  * The following are not acceptable:
    * SSS5 9PU – has three letters at the start.
    * S154 9LP – has three numbers before the space.
    
You can choose whichever method you like to ensure that the data structure will contain correct data, but your mark will depend on the approach you use. For example, regular expressions are considered a hard approach, input validation medium, and simply asking one at a time and looping is considered easy.
