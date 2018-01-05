#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20
typedef struct node{
    int data;
    struct node *next;
} Node;


Node* head = NULL;
int size = 0;

int readLine(char str[]){
    char ch;
    int i=0;
    printf("$ ");
    while((ch = getchar()) != '\n'){
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void createList(int n){
    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = n;
        head->next = NULL;
    }
    else{
        Node* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->data = n;
        tmp->next = NULL;
        p->next = tmp;
        
    }
    size++;
}

void addFirst(int n){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = n;
    tmp->next = head;
    
    head = tmp;
    size++;
}

void addAtIndex(int index, int n){
    Node* p = head;
    int i = 0;
    if(index == 0){
        addFirst(n);
        return;
    }
    while(i < index-1){
        p = p->next;
        i++;
    }
    
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = n;
    tmp->next = p->next;
    p->next = tmp;
    size++;
}

void removeAtIndex(int index){
    Node* p = head;
    int i =0;
    while(i < index-1){
        p = p->next;
        i++;
    }
    
    Node* tmp= p->next;
    p->next = tmp->next;
    free(tmp);
    size--;
}
void delete(int num){
    Node* p = head;
    Node* tmp = NULL;
    while(p->data != num){
        tmp = p;
        p = p->next;
    }
    tmp->next = p->next;
    free(p);
    size--;
}

void swap(int index1, int index2){
    Node* p = head;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    int i = 0;
    while(i<index1-1){
        p = p->next;
        i++;
    }
    prev1 = p;
    while(i < index2-1){
        p = p->next;
        i++;
    }
    prev2 = p;
    
    Node* tmp1 = NULL;
    Node* tmp2 = NULL;
    Node* tmp3 = NULL;
    tmp1 = prev1->next;
    tmp2 = prev2->next;
    prev1->next = prev2->next;
    prev2->next = tmp1;
    tmp3 = tmp2->next;
    tmp2->next = tmp1->next;
    tmp1->next = tmp3;
    
}

void printList(){
    Node* p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {

    char input[BUFFER_SIZE];
    char* command;
    char* argument;
    char* num;
    while(1){
        readLine(input);
        command =strtok(input, " ");
        printf("%s\n", command);
        if(strcmp(command, "create") == 0){
            num = strtok(NULL, " ");
            while(num != NULL) {
                createList(atoi(num));
                num = strtok(NULL, " ");
            }
        }
        else if(strcmp(command, "add") == 0){
            argument = strtok(NULL, " ");
            if(strcmp(argument, "-f") == 0){
                num = strtok(NULL, " ");
                addFirst(atoi(num));
            }
            else if(strcmp(argument, "-i") == 0){
                char* index;
                index = strtok(NULL, " ");
                num = strtok(NULL, " ");
                addAtIndex(atoi(index), atoi(num));
            }
        }
        else if(strcmp(command, "remove") == 0){
            argument = strtok(NULL, " ");
            if(strcmp(argument, "-i") == 0){
                num = strtok(NULL, " ");
                removeAtIndex(atoi(num));
            }
            else if(strcmp(argument, "-v") == 0){
                num = strtok(NULL, " ");
                delete(atoi(num));
            }
        }
        else if(strcmp(command, "swap") == 0){
            argument = strtok(NULL, " ");
            char* argument2 = strtok(NULL, " ");
            swap(atoi(argument), atoi(argument2));
        }
        else if(strcmp(command, "size") == 0){
            printf("%d\n", size);
        }
        else if(strcmp(command, "print") == 0){
            printList();
        }
        else if(strcmp(command, "exit") == 0){
            break;
        }
    }
    
    return 0;
}
