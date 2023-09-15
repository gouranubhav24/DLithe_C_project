#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[50];
    int vote_count;
} Candidate;

typedef struct {
    int id;
    char name[50];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void addCandidate(const char *name) {
    if (candidate_count < MAX_CANDIDATES) {
        candidates[candidate_count].id = candidate_count + 1;
        strcpy(candidates[candidate_count].name, name);
        candidates[candidate_count].vote_count = 0;
        candidate_count++;
        printf("Candidate added successfully.\n");
    } else {
        printf("Maximum candidate limit reached.\n");
    }
}

void listCandidates() {
    printf("List of Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

void castVote(int voter_id, int candidate_id) {
    if (voter_id >= 0 && voter_id < voter_count &&
        candidate_id > 0 && candidate_id <= candidate_count &&!voters[voter_id].has_voted) {
        candidates[candidate_id - 1].vote_count++;
        voters[voter_id].has_voted = 1;
        printf("Vote cast successfully.\n");
    } else {
        printf("Invalid voter or candidate.\n");
    }
}


int isAdmin(char *password) {
    //char tempPassword[50];
    //strcpy(tempPassword, password); // Create a temporary copy before encrypting
    //encrypt(tempPassword);
    if(password == "admin123")
    {
        return 1;
    }



}



void displayResults(char *password) {
    if (isAdmin(password)) {
        printf("Voting Results:\n");
        for (int i = 0; i < candidate_count; i++) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
        }
    } else {
        printf("Unauthorized access.\n");
    }
}
int main() {
    int choice, voter_id, candidate_id;
    char voter_name[50], candidate_name[50];
    char adminPassword[50];


        while (1) {
        printf("\nOnline Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. List Candidates\n");
        printf("3. Register Voter\n");
        printf("4. Cast Vote\n");
        printf("5. Display Results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", candidate_name);
                addCandidate(candidate_name);
                break;
            case 2:
                listCandidates();
                break;
            case 3:
                printf("Enter voter name: ");
                scanf("%s", voter_name);
                if (voter_count < MAX_VOTERS) {
                    voters[voter_count].id = voter_count + 1;
                    strcpy(voters[voter_count].name, voter_name);
                    voters[voter_count].has_voted = 0;
                    voter_count++;
                    printf("Voter registered successfully.\n");
                } else {
                    printf("Maximum voter limit reached.\n");
                }
                break;
            case 4:
                printf("Enter voter ID: ");
                scanf("%d", &voter_id);
                printf("Enter candidate ID: ");
                scanf("%d", &candidate_id);
                castVote(voter_id - 1, candidate_id);
                break;
            case 5:
                printf("Enter admin password: ");
                scanf("%s", adminPassword);
                displayResults(adminPassword);
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
