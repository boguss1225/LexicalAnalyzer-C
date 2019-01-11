# LexicalAnalyzer-C
&nbsp;&nbsp; Simple lexical Analyzer in C
# Preface
&nbsp;&nbsp; This program is mainly focused on the solution of the exercise number 5 and 6 in the textbook, Concepts of Programming Languages 10th edition(chapter 4).\
&nbsp;&nbsp; Already given the big picture and algorithm of the Lexical Analyzer in the textbook, all I had done on this was adding some extra functions such as recognizing reserved words(include for, if, else, while, do, int, float, switch) and returning token code. \
&nbsp;&nbsp; Finally, coding Lexical Analyzer made in C language to Python language Again. 
# Description
## 1. Purpose of program
&nbsp;&nbsp; Focused on recognizing series of strings in a text file (or .in) format, categorizing them as reserved words and that are not, and Tokenizing.
## Core methods
* **main()** –Outermost function of forming an input stream that recognizes the text file(front.in) and executing the entire code. If there is no loaded file (Null), the error message ("ERROR - cannot open front.in \n") will be displayed through stdout. It is implemented to continue calling the key method, the lex() function, until the token reaches the EOF.
* **lookup()** – Implemented in a format that finds through which character-type factors it receives correspond to through a switch sentence. This is a format in which characters that are not Digit and Letter are filtered out of the flex() function and then classified, If one wants to add another character later, it can be easily implemented by adding case sentence.
* **addChar()** – Function that makes words by adding recognized character variables to words.
* **getChar()** – Function that determines a character class by reading one character from a file and classifying whether it is an alphabet, a number, or something else. Determined variables affect global variables, allowing reference within other functions.
getNonBlank() – Function that handles gaps.
* **lex()** – As a function of key algorithms in the vocabulary analyzer, it starts by initializing the length of the lexeme.(This is the preparation to accept the new lexeme.) First, categorize by character class in switch sentence.
  1) If a word is categorized as a letter (LETTER), accept the word until the end and check that if it is a reserved word. In this task, it did not prepare a separate function to check the reservation language, but if there are more number of reserved words, it would be better to separate and make them a function for future modification.
  2) If classified as Digit (DIGIT), it accepts the digit to the end and return it as an int token.
  3) If classified as UNKNOWN, it sends the character type data to the lookup function described above and recognizes.

