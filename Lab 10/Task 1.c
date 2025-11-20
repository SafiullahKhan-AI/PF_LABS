#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max_lim 10
#define Max_len 150 

void load_play_list(char play_list[][Max_len], int *counter) {
    FILE *fp = fopen("play_list.txt", "r");
    
    if(!fp) 
	return;

    *counter = 0;
    while(*counter < Max_lim && fgets(play_list[*counter], Max_len, fp)){
        play_list[*counter][strcspn(play_list[*counter], "\n")] = '\0';
        (*counter)++;
    }
    
    fclose(fp);
}

void save_play_list(char play_list[][Max_len], int counter) {
    FILE *fp = fopen("play_list.txt", "w");
    int i;
    for(i = 0; i < counter; i++){
        fprintf(fp, "%s\n", play_list[i]);
    }
    
    fclose(fp);
}

void sort_play_list(char play_list[][Max_len], int counter) {
	int i,j;
    for (i = 0; i < counter - 1; i++) {
        for (j = i + 1; j < counter; j++){

            if (strcmp(play_list[i], play_list[j]) > 0){
                char temp[Max_len];
                strcpy(temp, play_list[i]);
                strcpy(play_list[i], play_list[j]);
                strcpy(play_list[j], temp);
            }
        }
    }
}

int searchSong(char play_list[][Max_len], int counter, char *title) {
	int i;
    for (i = 0; i < counter; i++) {
        if (strcmp(play_list[i], title) == 0) 
		return i;
    }
    return -1;
}

int main() {
    char play_list[Max_lim][Max_len];
    int counter = 0;

    load_play_list(play_list, &counter);

    while (1) {
        printf("\n...PLAYLIST MENU...\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Update Song\n");
        printf("4. Search Song\n");
        printf("5. Display play_list\n");
        printf("Enter -1 to Exit\n");
        printf("Choice: ");

        char choiceStr[10];
        fgets(choiceStr, 10, stdin);
        
        if(strcmp(choiceStr, "-1\n") == 0) 
		break;

        int choice = atoi(choiceStr);
        char title[Max_len];

        switch (choice) {

            case 1:
                if(counter >= Max_lim){
                    printf("play_list is full.\n");
                    break;
                }
                
                printf("Enter the Song Title: ");
                fgets(title, Max_len, stdin);
                title[strcspn(title, "\n")] = '\0';
                strcpy(play_list[counter++], title);
                printf("Added!\n");
                break;

            case 2:
                printf("Enter The Title to delete: ");
                fgets(title, Max_len, stdin);
                title[strcspn(title, "\n")] = '\0';
                int pos;
                pos = searchSong(play_list, counter, title);
                
                if (pos == -1) {
                    printf("Not found in List!\n");
                } 
				else {
                	int i;
                    for (i = pos; i < counter - 1; i++)
                        strcpy(play_list[i], play_list[i + 1]);
                        
                    counter--;
                    printf("Deleted!\n");
                }
                break;

            case 3:
                printf("Enter the Title to update: ");
                fgets(title, Max_len, stdin);
                title[strcspn(title, "\n")] = '\0';
                pos = searchSong(play_list, counter, title);
                
                if(pos == -1){
                    printf("Not found in List!\n");
                } 
				else{
                    printf("Enter new Title: ");
                    fgets(play_list[pos], Max_len, stdin);
                    play_list[pos][strcspn(play_list[pos], "\n")] = '\0';
                    printf("Updated!\n");
                }
                break;

            case 4:
                printf("Enter the Title to Search: ");
                fgets(title, Max_len, stdin);
                title[strcspn(title, "\n")] = '\0';
                pos = searchSong(play_list, counter, title);
                
                if (pos == -1){
				printf("Not found in List!\n");
				}
                else {
				printf("Found at position no %d in playlist\n", pos + 1);
				}
                break;

            case 5:
                sort_play_list(play_list, counter);
                printf("\n--- Playlist (Sorted) ---\n");
                int i;
                for (i = 0; i < counter; i++) printf("%d. %s\n", i + 1, play_list[i]);
                break;

            default:
                printf("Invalid Option!!!\n");
        }
    }

    sort_play_list(play_list, counter);
    save_play_list(play_list, counter);

    return 0;
}


