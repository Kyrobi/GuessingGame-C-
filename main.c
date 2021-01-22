#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int main() {

    char correctWord[256] = "Test";
    char guess[256];

    // A char pointer variable so that the string can be changed later in the code
    /*
        drawline is a char[][256] array (which you've declared as char * drawLine[256];), 
        which means that it is a double pointer array (or an array of Strings)
    */

    char drawLine[256];

    int wordLength;
    int guessesCounter = 0;
    int tempGuessesCounter = 0;

    printf("Input a word for user to guess:");
    scanf("%s", correctWord);

    //Converts the word to lowercase to easier match
    //strlwr only exists on Microsoft
    correctWord[0] = tolower(correctWord[0]); 
    system("clear");

    wordLength = strlen(correctWord);

    //Fills the drawLine buffer with underscores representing amout of characters in word
    for(int i = 0; i < wordLength; i++){
        //drawLine[i] = "_";
        //Appends _ to the string to make a blank buffer
        strcat(drawLine, "_");

        //it's a character array, so you can't use double quotes to modify it.
        //"_" is a string, whereas '_' is a character
    }


    //Strcmp compares the value of the two strings. Also loops the guess if they don't match
    while (strcmp(guess, correctWord)){

        system("clear");

        //Prints the blanks onto the screen
        printf("\t");
        for(int i = 0; i < wordLength; i++){
            printf("%c", drawLine[i]);
        }

        printf("\nGuesses Made:%d\nEnter guess: ", guessesCounter);
        scanf("%s", guess);
        tempGuessesCounter++;
        guessesCounter++;

        //For every 4 wrong guesses, give a character hint
        if(tempGuessesCounter == 1){
            tempGuessesCounter = 0;

            //Generate a random number in range: rand() % (max_number + 1 - minimum_number) + minimum_number
            srand(time(0));
            int randomNum = rand() % (wordLength + 1 - 0) + 0;

            //Replaces a random blank with a letter
            //printf("Random num:%d\tDrawline:%s\tCorrectedWord:%c\n", randomNum, drawLine[randomNum], correctWord[randomNum]);
            drawLine[randomNum] = correctWord[randomNum];


            //If the string matches, it returns a false value (0)
            //Kill the game if all the words on the blanks are shown
            if(!strcmp(drawLine, correctWord)){
                break;
            }
        }
    }

    printf("\n\nThe correct word was: %s You lose.", correctWord);
  
    //printf("\n\n\nDebug:\tWord: %s\tLength:%d", correctWord, wordLength);
}