#include <stdio.h>
#include <string.h>

#define team_max 20
#define max_round 10
#define threshold 150

struct team{
    char name[50];
    int rounds;
    int scores[max_round];
};

int totalscore(int scores[], int index){
    if(index < 0)
        return 0;
    return scores[index] + totalscore(scores, index - 1);
}


void input(struct team t[], int *n){
    int i, j;
    printf("Enter no of Teams: ");
    scanf("%d", n);

    for(i = 0; i < *n; i++){
        printf("\nEnter Team %d name: ", i+1);
        scanf("%s", t[i].name);
        printf("Enter no of Rounds: ");
        scanf("%d", &t[i].rounds);

        printf("Enter score for each round:\n");
        for(j = 0; j < t[i].rounds; j++){
            printf("Round %d: ", j+1);
            scanf("%d", &t[i].scores[j]);
        }
    }
}


void high_scorers(struct team t[], int n){
    printf("\nTeams above threshold %d:\n", threshold);
    int found = 0;
    for(int i = 0; i < n; i++){
        int total = totalscore(t[i].scores, t[i].rounds - 1);
        
        if(total > threshold){
            printf("%s  Total = %d\n", t[i].name, total);
            found = 1;
        }
    }
    if(found==0){
        printf("No team have Total score above threshold");
    }
}

int main(){
    struct team t[team_max];
    int n = 0, choice, flag = 1;

    while(flag){
        printf("\nQUIZ MANAGEMENT SYSTEM\n");
        printf("1. Input team scores\n");
        printf("2. Display total score of each team\n");
        printf("3. Display high scoring teams\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                input(t, &n);
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    printf("Team: %s  Total Score = %d\n",
                           t[i].name,
                           totalscore(t[i].scores, t[i].rounds - 1));
                }
                break;
            case 3:
                high_scorers(t, n);
                break;
            case 4:
                flag = 0;
                break;
        }
    }
}
