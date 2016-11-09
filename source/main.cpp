/*
C Strings
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/


#include <iostream>
#include <cstring>

int main() {

    // You may remember that a char (character) is a single byte (8-bit) block of memory
    // The memory can be used as a number betwen 0 and 255, or to represent an ASCII character: https://en.wikipedia.org/wiki/ASCII
    // In C, characters are often stored as an array. We call this a string.

    
    {
        // We can create an array of letters like this:
        char letters[] = { 'h','e','l','l','o', '\0' };
        // The last value here:  \0  is called the null terminator, or sometimes just null.

        // The null terminator has the numeric value 0, but don't confuse it with the 0 character.
        // The 0 character actually has a value of 48!
        // At first it might be a little confusing, but it makes sense if you think about it.
        // If they were the same, you wouldn't be able to print the character 0!

        // In order to show why the null terminator is useful, here is a string without one:
        char badLetters[] = { 'h', 'e', 'l', 'l', 'o' };

        // Now, we print both strings:
        std::cout << "\nPrint null-terminated string:" << std::endl;        // This will print out fine.
        std::cout << letters << std::endl;
        std::cout << "\nPrint non null-terminated string:" << std::endl;    // This will print out a bunch of other nonsense after the letters in the string.
        std::cout << badLetters << std::endl;


        // Obviously there's a better way to do this:
        char betterLetters[] = "hello";     // C++ will automatically make the array from a string formatted like this.
                                            // No need to add the null terminator yourself.

        std::cout << "\nPrint null-terminated string initialized with quotes:" << std::endl;
        std::cout << betterLetters << std::endl;
    }
    std::cin.get();


    {
        // Strings ara arrays, and arrays are const pointers, so they can't be modified like this:
        char sentence1[] = "const pointer to char";
        std::cout << sentence1 << std::endl;;
        // sentence1 = "no writing to const pointers";

        // You can however create an array as a pointer:
        char* sentence2 = "Ternary Operators:";
        std::cout << sentence2 << std::endl;;

        // This one can be changed.
        sentence2 = "Not Even Once.";
        std::cout << sentence2 << std::endl;;



        std::cin.get();


        // Since they are just arrays:
        char sentence[] = "Programming is hard.";
        std::cout << sentence << std::endl;
        std::cin.get();

        // Individual characters can be accessed and manipulated just like any other data.
        sentence[15] += -3;
        sentence[17] = 's';
        sentence[18] += 0x15;
        std::cout << sentence << std::endl;

    }
    std::cin.get();





    {
        // If we #include  <cstring> there are many other functions that also help when using c strings


        // the simplest of these is strlen.
        // strlen takes a pointer to a character, and returns the number of characters from that pointer until a null terminator is reached.
        char letters[] = "She sells sea shells by the seashore.";
        std::cout << "strlen(letters): " << strlen(letters) << std::endl;

        // this is the same regardless of the length of the array that the characters are in.
        char earlyTerminator[20] = "hi";
        std::cout << "strlen(earlyTerminator): " << strlen(earlyTerminator) << std::endl;
    }
    std::cin.get();
    
    
    
    {
        std::cout << "strcmp and strncmp" << std::endl;

        // strcmp compares two strings until it finds two characters that aren't the same, then returns which is higher.
        char word1[] = "fiesta";
        char word2[] = "fiery";

        int cmp = strcmp(word1, word2);    // Since numeric values are used to determine order, this can be used to determine which string comes first alphabetically.
                                            // Be careful not to mix upper and lower case letters though, they have different numeric values, so Z is lower than a.

        if (cmp < 0)
        {
            // If the first parameter is lower, strcmp returns a number less than one.
            std::cout << word1 << " comes before " << word2 << std::endl;
        }
        else if (cmp > 0)
        {
            // If the first parameter is higher, strcmp returns a number greater than one.
            std::cout << word1 << " comes after " << word2 << std::endl;
        }
        else
        {
            // If the null terminator is reached with no differences, the words are determined to be the same.
            std::cout << word1 << " and " << word2 << " are the same." << std::endl;
        }




        // strncmp is a variant of strcmp, but takes in a max number of characters to compare.
        // If that max or the null terminator is reached, it returns 0.

        if (strncmp(word1, word2, 3) == 0)
        {
            std::cout << "The first 3 letters of " << word1 << " and " << word2 << " are the same." << std::endl;
        }

        if (strncmp(word1, word2, 4) != 0)
        {
            std::cout << "The first 4 letters of " << word1 << " and " << word2 << " are not the same." << std::endl;
        }
    }
    std::cin.get();




    {
        std::cout << "strchr and strrchr" << std::endl;

        // strchr searches a string for a specific character, and returns a pointer to that location in the string.
        char words[] = "Don't do it!";
        std::cout << words << std::endl;


        // Search for a space in the string, and get the character directly after it.
        char* temp = strchr(words, ' ') + 1;
        std::cout << temp << std::endl;


        // strrchr does the opposite, and instead finds the last matching character in a string.
        temp = strrchr(words, ' ') + 1;
        std::cout << temp << std::endl;

    }
    std::cin.get();



    {
        std::cout << "strstr" << std::endl;
        // strstr searches for one string in another, and returns a pointer to the first location it occurs.

        char groceryList[] = "bread: 2, eggs: 12, apples: 6, milk: 1";
        std::cout << groceryList << std::endl;

        std::cout << strstr(groceryList, "apples") << std::endl;    // Search for the string apples, print everything after it.
    }
    std::cin.get();



    {
        std::cout << "strpbrk" << std::endl;
        // strpbrk searches for a collection of letters, and then returns a pointer to the first location that any of them appear.
        char todoList[] = "10,29.32.44,46,10";      // numbers taken from today's lottery
        char* temp = todoList;


        while (temp != nullptr)                     // Loop until strpbrk returns a nullptr 
        {
            std::cout << temp << std::endl;         // Print the string starting with our temp pointer.
            temp = strpbrk(temp, ",.");  // Skip until reaching a break character (, or .)

            if (temp != nullptr)                    // if temp isn't null, skip it (, or .)
            {
                temp++;
            }
        }
    }
    std::cin.get();


    {
        // strcspn finds the number of characters in a string before any specific characters are found, but returns the distance instead of a pointer.
        std::cout << "strcspn(\"bananas\", \"na\"): " << strcspn("bananas", "s") << std::endl;

        // strspn does the oppsite, only skipping characters in the given 
        std::cout << "strspn(\"bananas\", \"ba\"): " << strspn("bananas", "bna") << std::endl;
    }
    std::cin.get();





    {
        std::cout << "strcpy and strncopy" << std::endl;
        // strcpy takes a source string and copies into a destination array.
        // The destination array needs to be large enough to include the source string (including the null terminator)

        char testArray[16];

        for (int i = 0; i < sizeof(testArray) - 4; i += 4)  // Loop over the array, skip over 4 indices at a time.
        {                                                   // Also make sure there's enough room for the string to fit.

            strcpy(testArray + i, "COPY");                  // Copy the string copy into the array at that location.
        }

        std::cout << testArray << std::endl;                // Print out the resulting array.
                                                            // You might expect this to print copy 4 times, but it only prints 3.
                                                            // That's because strcpy adds the null terminator, so it needs 17 characters for 4 to fit.



        // strncpy is a slightly better strcpy that only copies a number of characters instead of the whole string.
        // This does not add a null terminator, so be careful with it.

        char phrase[] = "never gonna give you up let you down run around and desert you";

        char song[128];

        strncpy(song, phrase, 12);              // never gonna
        strncpy(song + 12, phrase + 12, 12);    // give you up

        strncpy(song + 24, phrase, 12);         // never gonna
        strncpy(song + 36, phrase + 24, 13);    // let you down

        strncpy(song + 49, phrase, 12);         // never gonna
        strncpy(song + 61, phrase + 37, 26);    // run around and desert you (include null terminator here)

        std::cout << song << std::endl;
    }
    std::cin.get();






    {
        std::cout << "strcat and strncat" << std::endl;
        // strcat is similar to strcpy in that it writes to a string, but different, in that it automatically writes to the end of it.
        // strcat will start writing at the null terminator of the previous string, and stop after writing the null terminator of the appended string.


        char phrase1[] = "never gonna ";
        char phrase2[] = "make you cry ";
        char phrase3[] = "say goodbye ";
        char phrase4[] = "tell a lie and hurt you ";

        char song[128];

        strcpy(song, phrase1);  // Start with strcpy to write the first line of the song.
        strcat(song, phrase2);  // Use strcat to add every following line.
        strcat(song, phrase1);
        strcat(song, phrase3);
        strcat(song, phrase1);
        strcat(song, phrase4);  // Wow, that was so much more convenient than the strcpy example!

        std::cout << song << std::endl;


        // strncat works just like strcat, but only adds a given number of characters from the source string.
        // unlike strncpy, strncat does add a null terminator, even if you don't reach the end of the source string.


        char sentence[128] = "Sometimes I ";
        strncat(sentence, "finish sentences too early.", 16);   // Only adds the first 16 characters.


        std::cout << sentence << std::endl;
    }
    std::cin.get();





    {
        std::cout << "strtok" << std::endl;
        // strtok is one of the weirdest functions included in cstring
        // It tokenizes a string (splits it up), by adding null terminators as you use it to parse the string.


        // first, we need a string to split up
        char testString[] = "bacon, eggs , toast, ,milk";

        char* temp = strtok(testString, " ,");   // Strtok takes in the string to start with, and a string of characters to skip over.
                                                 // Each time it is called, it adds a null terminator at the first delimiter it finds.
                                                 // It then returns the string location that it had started at.

                                                 // strtok returns nullptr when there are no tokens left.
        while (temp != nullptr)
        {
            // If there's something to print, print it.
            std::cout << temp << std::endl;
            temp = strtok(nullptr, " ,");       // strtok continues where it left off if you pass in nullptr.
        }

        // If you think this function is confusing, you're right.
        // It's really old and bad and don't use it.
    }
    std::cin.get();

}
