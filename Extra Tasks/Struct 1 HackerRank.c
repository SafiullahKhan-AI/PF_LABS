#include <stdio.h>
struct Student {
    int age;
    char first_name[51];
    char last_name[51];
    int standard;
};
int main(){
    struct Student st;
    scanf("%d", &st.age);
    scanf("%s", st.first_name);
    scanf("%s", st.last_name);
    scanf("%d", &st.standard);
    printf("%d %s %s %d", st.age, st.first_name, st.last_name, st.standard);
    return 0;
}
