/* By: Cauã Grigolatto Domingos */
/* 
    Projeto final da disciplina Programação
    Estruturada e algoritimos 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void drawCardAndIncrementPoints(char card[12], int *points);
void getRandomCard(char card[12]);
void getRandomNumericCard(char card[12]);
void getRandomTenPoweredCard(char card[12]);
int getRoundPoints(char card[12]);
int isWinner(int points);
void showSeparator();

void main() {
    //default setting for random number
    srand(time (NULL));
    
    int playerPoints = 0;
    int dealerPoints = 0;

    char playerCard[12];
    char dealerCard[12];

    //

    drawCardAndIncrementPoints(playerCard, &playerPoints);
    printf("Você tirou: %s!\n", playerCard);
    drawCardAndIncrementPoints(playerCard, &playerPoints);
    printf("Você tirou: %s!\n", playerCard);

    drawCardAndIncrementPoints(dealerCard, &dealerPoints);
    printf("Dealer tirou: %s!\n", dealerCard);
    drawCardAndIncrementPoints(dealerCard, &dealerPoints);
    printf("Dealer tirou: %s!\n", dealerCard);

    showSeparator();
        
    //

    int isPlayerLoser = FALSE;
    int isDealerLoser = FALSE;
    int isGameOver = FALSE;
    
    int decision = 1;

    while (isGameOver == FALSE) {
        printf("Seus pontos: %d\n", playerPoints);
        printf("Pontos do dealer: %d\n\n", dealerPoints);
        
        if (decision != 0) {
            printf("\n");
            printf("1- Sortear  |  0- Sair\n\n");
            scanf("%d", &decision);
        }

        showSeparator();

        if (decision != 0) {
            drawCardAndIncrementPoints(playerCard, &playerPoints);
            printf("Player tirou: %s!\n", playerCard);

            isPlayerLoser = (isWinner(dealerPoints)) || playerPoints > 21;

            if (isPlayerLoser == FALSE) {
                drawCardAndIncrementPoints(dealerCard, &dealerPoints);
                printf("Dealer tirou: %s!\n", dealerCard);
                isDealerLoser = (isWinner(playerPoints)) || dealerPoints > 21;
            }
        }
        else {
            isPlayerLoser = playerPoints < dealerPoints;

            while ((isPlayerLoser == FALSE) && (isDealerLoser == FALSE)) {
                drawCardAndIncrementPoints(dealerCard, &dealerPoints);
                printf("Dealer tirou: %s!\n", dealerCard);

                isDealerLoser = dealerPoints > 21;
                isPlayerLoser = playerPoints < dealerPoints && (! isDealerLoser);
            }
        }

        showSeparator();
        
        if (isPlayerLoser || isDealerLoser)
            isGameOver = TRUE;
    }

    

    if (isPlayerLoser) {
        printf("Você perdeu!\n");
    }
    else {
        printf("Você ganhou!\n");
    }

    printf("\n\nSeus pontos: %d", playerPoints);
    printf("\nPontos do dealer: %d\n", dealerPoints);
}   


// other functions ///////////////////////////////////////

void drawCardAndIncrementPoints(char card[12], int *points) {
    getRandomCard(card);
    *points += getRoundPoints(card);
}

void getRandomCard(char card[12]) {
    int deckChooser = rand() % 2;

    switch (deckChooser) {
    case 0:
        getRandomNumericCard(card);
        break;
    
    case 1:
        getRandomTenPoweredCard(card);
        break;
    }
}

void getRandomNumericCard(char card[12]) {
    char numericCards[][12] = {"Às", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
    int arraySize = sizeof(numericCards) / sizeof(numericCards[0]);

    int selector = rand() % arraySize; 
    char randomNumericCard[12];

    strcpy(randomNumericCard, numericCards[selector]);
    strcpy(card, randomNumericCard);
}

void getRandomTenPoweredCard(char card[12]) {
    char tenPoweredCards[][12] = {"Dez", "Valete (J)", "Dama (Q)", "Reis (K)"};
    int arraySize = sizeof(tenPoweredCards) / sizeof(tenPoweredCards[0]);

    int selector = rand() % arraySize;
    char randomTenPoweredCard[12];

    strcpy(randomTenPoweredCard, tenPoweredCards[selector]);
    strcpy(card, randomTenPoweredCard);
}

int getRoundPoints(char card[12]) {
    int points;

    if ((strcmp(card, "Às") == 0)) {
        points = 1;
    }
    else if (strcmp(card, "Dois") == 0) {
        points = 2;    
    }
    else if (strcmp(card, "Três") == 0) {
        points = 3;
    }
    else if (strcmp(card, "Quatro") == 0) {
        points = 4;
    }
    else if (strcmp(card, "Cinco") == 0) {
        points = 5;
    }
    else if (strcmp(card, "Seis") == 0) {
        points = 6;
    }
    else if (strcmp(card, "Sete") == 0) {
        points = 7;
    }
    else if (strcmp(card, "Oito") == 0) {
        points = 8;
    }
    else if (strcmp(card, "Nove") == 0) {
        points = 9;
    }
    else {
        points = 10;
    }

    return points;
}

int isWinner(int points) {
    return points == 21;
}

void showSeparator() {
    printf("--------------------------------------------------------------");
    printf("\n");
}