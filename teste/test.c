#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//tirar variaveis globais
#define MAX_EVENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {event
    char name[MAX_NAME_LENGTH];
    // Add more event details as needed 
    //data
    //preço
} Event;

typedef struct {//nome da estrutura
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    // Add more user details as needed
} User;

User users[MAX_EVENTS];
Event events[MAX_EVENTS];
int numUsers = 0;
int numEvents = 0;

void registerUser() {
    if (numUsers >= MAX_EVENTS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[numUsers++] = newUser;
    printf("Registration successful.\n");
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return i; // Return the index of the logged-in user
        }
    }

    printf("Invalid username or password.\n");
    return -1; // Return -1 if login fails
}

void createEvent() {
    if (numEvents >= MAX_EVENTS) {
        printf("Maximum number of events reached.\n");
        return;
    }

    Event newEvent;
    printf("Enter event name: ");
    scanf("%s", newEvent.name);

    events[numEvents++] = newEvent;
    printf("Event created successfully.\n");
}

void editEvent(int eventIndex) {
    if (eventIndex < 0 || eventIndex >= numEvents) {
        printf("Invalid event index.\n");
        return;
    }

    printf("Enter new event name: ");
    scanf("%s", events[eventIndex].name);

    printf("Event edited successfully.\n");
}

void changeEvent() {
    int eventIndex;
    printf("Enter event index: ");
    scanf("%d", &eventIndex);

    editEvent(eventIndex);
}

int main() {
    int choice;
    int loggedInUserIndex = -1;

    while (1) {
        printf("\n--- Event Organizer Software ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Create Event\n");
        printf("4. Edit Event\n");
        printf("5. Change Event\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2: //meter dados aqui, e pedir em baixo
                loggedInUserIndex = loginUser();
                break;
            case 3:
                if (loggedInUserIndex == -1) {
                    printf("Please login first.\n");
                } else {
                    createEvent();
                }
                break;
            case 4:
                if (loggedInUserIndex == -1) {
                    printf("Please login first.\n");
                } else {
                    editEvent(loggedInUserIndex);
                }
                break;
            case 5:
                if (loggedInUserIndex == -1) {
                    printf("Please login first.\n");
                } else {
                    changeEvent();
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}