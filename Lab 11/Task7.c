#include <stdio.h>
#include <string.h>
#define max_user 50
#define max_sign 12
struct Forecast{
    char sign[20];
    char lucky_color[20];
    int lucky_number;
    char advice[100];
};

struct User
{
    char name[50];
    int day, month, year;
    char zodiac[20];
    struct Forecast *f;
};

void assignZodiac(struct User *u);
void inputUser(struct User *u, struct Forecast *allForecasts);
void displayUserHoroscope(struct User u);
void updateForecast(struct Forecast *allForecasts);
void loadDefaultForecasts(struct Forecast *allForecasts);

int main()
{

    struct User users[max_user];
    struct Forecast zodiacForecasts[max_sign];

    int userCount = 0;
    int choice;

    loadDefaultForecasts(zodiacForecasts);

    do{
        printf("\n===== ASTROLOGY APP MENU =====\n");
        printf("1. Add new user\n");
        printf("2. Show horoscope for a user\n");
        printf("3. Update zodiac forecast\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1){
            inputUser(&users[userCount], zodiacForecasts);
            userCount++;
        }

        else if (choice == 2){
            char uname[50];
            printf("Enter username to search: ");
            scanf("%s", uname);

            int found = 0;
            for (int i = 0; i < userCount; i++){
                if (strcmp(users[i].name, uname) == 0){
                    displayUserHoroscope(users[i]);
                    found = 1;
                    break;
                }
            }
            if (!found){
                printf("User not found.\n");
            }
        }
        else if(choice == 3){
            updateForecast(zodiacForecasts);
        }

    }
    while(choice != 4);
    return 0;
}

void assignZodiac(struct User *u){
    int d = u->day, m = u->month;

    if ((d >= 21 && m == 3) || (d <= 19 && m == 4))
        strcpy(u->zodiac, "Aries");
    else if ((d >= 20 && m == 4) || (d <= 20 && m == 5))
        strcpy(u->zodiac, "Taurus");
    else if ((d >= 21 && m == 5) || (d <= 20 && m == 6))
        strcpy(u->zodiac, "Gemini");
    else if ((d >= 21 && m == 6) || (d <= 22 && m == 7))
        strcpy(u->zodiac, "Cancer");
    else if ((d >= 23 && m == 7) || (d <= 22 && m == 8))
        strcpy(u->zodiac, "Leo");
    else if ((d >= 23 && m == 8) || (d <= 22 && m == 9))
        strcpy(u->zodiac, "Virgo");
    else if ((d >= 23 && m == 9) || (d <= 22 && m == 10))
        strcpy(u->zodiac, "Libra");
    else if ((d >= 23 && m == 10) || (d <= 21 && m == 11))
        strcpy(u->zodiac, "Scorpio");
    else if ((d >= 22 && m == 11) || (d <= 21 && m == 12))
        strcpy(u->zodiac, "Sagittarius");
    else if ((d >= 22 && m == 12) || (d <= 19 && m == 1))
        strcpy(u->zodiac, "Capricorn");
    else if ((d >= 20 && m == 1) || (d <= 18 && m == 2))
        strcpy(u->zodiac, "Aquarius");
    else
        strcpy(u->zodiac, "Pisces");
}

void inputUser(struct User *u, struct Forecast *allForecasts){

    printf("\nEnter name: ");
    scanf("%s", u->name);

    printf("Enter birthdate (DD MM YYYY): ");
    scanf("%d %d %d", &u->day, &u->month, &u->year);

    assignZodiac(u);
    
    for (int i = 0; i < max_sign; i++){
        if (strcmp(allForecasts[i].sign, u->zodiac) == 0){
            u->f = &allForecasts[i];
            break;
        }
    }

    printf("Zodiac assigned: %s\n", u->zodiac);
}

void displayUserHoroscope(struct User u){
    printf("\n---- DAILY HOROSCOPE ----\n");
    printf("Name: %s\n", u.name);
    printf("Zodiac: %s\n", u.zodiac);
    printf("Lucky Color: %s\n", u.f->lucky_color);
    printf("Lucky Number: %d\n", u.f->lucky_number);
    printf("Advice: %s\n", u.f->advice);
}

void updateForecast(struct Forecast *all){

    char signName[20];
    printf("Enter zodiac sign to update: ");
    scanf("%s", signName);

    int found = 0;
    for (int i = 0; i < max_sign; i++){
        if (strcmp(all[i].sign, signName) == 0)
        {
            printf("New lucky color: ");
            scanf("%s", all[i].lucky_color);

            printf("New lucky number: ");
            scanf("%d", &all[i].lucky_number);

            printf("New advice message: ");
            scanf(" %s", all[i].advice);

            found = 1;
            printf("Forecast updated!\n");
            break;
        }
    }

    if (!found){
        printf("Invalid zodiac sign.\n");
    }
}

void loadDefaultForecasts(struct Forecast *f){
    char *names[max_sign] = {
        "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo",
        "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};

    for (int i = 0; i < max_sign; i++){
        strcpy(f[i].sign, names[i]);
        strcpy(f[i].lucky_color, "Blue");
        f[i].lucky_number = i + 3;
        strcpy(f[i].advice, "Stay positive and focused today.");
    }
}
