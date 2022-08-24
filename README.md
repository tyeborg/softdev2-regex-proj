# Software Development 2: Regex Project

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
