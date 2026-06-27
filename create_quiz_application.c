#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_QUESTIONS 5
#define MAX_TOPICS 3

typedef struct {
    const char *question;
    const char *options[4];
    char answer;
} QuizQuestion;

static int getInt(const char *prompt, int min, int max) {
    char buffer[32];
    int value;

    while (1) {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            return min;
        }
        if (sscanf(buffer, "%d", &value) == 1 && value >= min && value <= max) {
            return value;
        }
        printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
    }
}

int main(void) {
    QuizQuestion topics[MAX_TOPICS][MAX_QUESTIONS] = {
        {
            {"What is 5 + 7?", {"A) 10", "B) 11", "C) 12", "D) 13"}, 'C'},
            {"What is 9 * 3?", {"A) 18", "B) 27", "C) 24", "D) 30"}, 'B'},
            {"What is 20 / 4?", {"A) 4", "B) 5", "C) 6", "D) 8"}, 'B'},
            {"What is 15 - 6?", {"A) 7", "B) 8", "C) 9", "D) 10"}, 'B'},
            {"What is 7 + 8?", {"A) 13", "B) 14", "C) 15", "D) 16"}, 'C'}
        },
        {
            {"What planet is known as the Red Planet?", {"A) Earth", "B) Mars", "C) Venus", "D) Jupiter"}, 'B'},
            {"What gas do plants use to make food?", {"A) Oxygen", "B) Nitrogen", "C) Carbon dioxide", "D) Hydrogen"}, 'C'},
            {"What is the boiling point of water at sea level?", {"A) 100°C", "B) 90°C", "C) 80°C", "D) 120°C"}, 'A'},
            {"What part of the body pumps blood?", {"A) Brain", "B) Liver", "C) Heart", "D) Lungs"}, 'C'},
            {"What force keeps us on the ground?", {"A) Magnetism", "B) Friction", "C) Gravity", "D) Electricity"}, 'C'}
        },
        {
            {"Who was the first President of the United States?", {"A) Abraham Lincoln", "B) George Washington", "C) Thomas Jefferson", "D) John Adams"}, 'B'},
            {"What year did World War II end?", {"A) 1945", "B) 1939", "C) 1950", "D) 1941"}, 'A'},
            {"Which ancient civilization built the pyramids?", {"A) Romans", "B) Greeks", "C) Egyptians", "D) Aztecs"}, 'C'},
            {"What document declared American independence?", {"A) Constitution", "B) Bill of Rights", "C) Federalist Papers", "D) Declaration of Independence"}, 'D'},
            {"Who discovered America in 1492?", {"A) Christopher Columbus", "B) Marco Polo", "C) Ferdinand Magellan", "D) James Cook"}, 'A'}
        }
    };

    const char *topicNames[MAX_TOPICS] = {"Math", "Science", "History"};
    int topicChoice;
    int questionsToAsk;
    int score = 0;
    int asked[MAX_QUESTIONS] = {0};

    srand((unsigned int)time(NULL));

    printf("Choose a topic:\n");
    for (int i = 0; i < MAX_TOPICS; i++) {
        printf("%d) %s\n", i + 1, topicNames[i]);
    }

    topicChoice = getInt("Enter topic number: ", 1, MAX_TOPICS);
    questionsToAsk = getInt("How many questions do you want? (1-5): ", 1, MAX_QUESTIONS);

    topicChoice -= 1;
    printf("\nStarting quiz on %s...\n\n", topicNames[topicChoice]);

    for (int q = 0; q < questionsToAsk; q++) {
        int index;
        do {
            index = rand() % MAX_QUESTIONS;
        } while (asked[index]);
        asked[index] = 1;

        QuizQuestion *item = &topics[topicChoice][index];
        printf("Question %d: %s\n", q + 1, item->question);
        for (int opt = 0; opt < 4; opt++) {
            printf("%s\n", item->options[opt]);
        }
        printf("Your answer: ");
        char answer[8];
        if (!fgets(answer, sizeof(answer), stdin)) {
            printf("Invalid response. Correct answer is %c.\n\n", item->answer);
            continue;
        }

        size_t len = strlen(answer);
        if (len > 0 && answer[len - 1] == '\n') {
            answer[len - 1] = '\0';
            len--;
        }

        if (len == 1) {
            char userAnswer = toupper(answer[0]);
            if (userAnswer == item->answer) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Wrong. Correct answer is %c.\n\n", item->answer);
            }
        } else {
            printf("Invalid response. Correct answer is %c.\n\n", item->answer);
        }
    }

    printf("Quiz complete. You scored %d out of %d.\n", score, questionsToAsk);
    return 0;
}
