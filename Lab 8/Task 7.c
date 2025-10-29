#include <stdio.h>
int main(){
    int inventory[2][3][4];
    int section, shelf, item;

    printf("Enter the quantity of each item:\n");
    for (section = 0; section < 2; section++){
        for (shelf = 0; shelf < 3; shelf++){
            for (item = 0; item < 4; item++){
                printf("Section %d, Shelf %d, Item %d: ", section + 1, shelf + 1, item + 1);
                scanf("%d", &inventory[section][shelf][item]);
            }
        }
    }

    int sectiontotal[2] = {0};
    for (section = 0; section < 2; section++){
        for (shelf = 0; shelf < 3; shelf++){
            for (item = 0; item < 4; item++){
                sectiontotal[section] += inventory[section][shelf][item];
            }
        }
    }

    printf("\nTotal items present in each section:\n");
    for (section = 0; section < 2; section++){
        printf("Section %d: %d items\n", section + 1, sectiontotal[section]);
    }

    int maxtotal = 0, maxsection = 0, maxshelf = 0, shelftotal = 0;;

    for (section = 0; section < 2; section++){
        for (shelf = 0; shelf < 3; shelf++){
            for (item = 0; item < 4; item++){
                shelftotal += inventory[section][shelf][item];
            }
            if (shelftotal > maxtotal){
                maxtotal = shelftotal;
                maxsection = section;
                maxshelf = shelf;
            }
        }
    }

    printf("\nShelf with the highest total quantity is Section %d, Shelf %d with %d total items\n", maxsection + 1, maxshelf + 1, maxtotal);

    return 0;
}
