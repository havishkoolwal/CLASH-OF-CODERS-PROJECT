#include <stdio.h>
#include <string.h>

int main() {
    char secret_word[] = "MENTOR";   // The hidden word
    char display_word[10];           // Player’s view of the word
    int lives = 6;                   // Number of chances
    int length = strlen(secret_word);
    char guess;
    int i;
    int correct;
    int won = 0;

    // Fill display_word with underscores
    for (i = 0; i < length; i++) {
        display_word[i] = '_';
    }
    display_word[length] = '\0';  // End of string

    printf("Welcome to Hangman Game!\n");

    // Game loop
    while (lives > 0 && won == 0) {
        printf("\nWord: %s\n", display_word);
        printf("Lives left: %d\n", lives);
        printf("Enter your guess: ");
        scanf(" %c", &guess); // Space before %c to skip enter key

        correct = 0;

        // Check each letter in the word
        for (i = 0; i < length; i++) {
            if (secret_word[i] == guess) {
                display_word[i] = guess;
                correct = 1;
            }
        }

        if (correct == 0) {
            lives--;
            printf("Wrong guess!\n");
        } else {
            printf("Good guess!\n");
        }

        // Check if the player has won
        won = 1;
        for (i = 0; i < length; i++) {
            if (display_word[i] == '_') {
                won = 0;
                break;
            }
        }
    }

    if (won == 1) {
        printf("\nCongratulations! You guessed the word: %s\n", secret_word);
    } else {
        printf("\nYou lost! The word was: %s\n", secret_word);
    }

    return 0;
}