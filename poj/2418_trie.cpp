#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct node {
    int data;
    struct node * next[129];
};
int num=0;
char o[51];
struct node* build() {
    node *p = new node;
    p->data = 0;
    for (int i=0; i<=128; i++) {
        p->next[i] = NULL;
    }
    return p;
}
void insert(struct node *head, char *str) {
    node* p = head;
    for (int i=0; i<strlen(str); i++) {
        if (NULL == p->next[str[i]]) { // Rember YODA!
            p->next[str[i]] = build();
        }
        p = p->next[str[i]];
    }
    p -> data ++;
}
void dfs(node* head, int step) {
    node * p = head;
    if (p->data > 0) {
        o[step] = '\0';
        printf("%s %.4f\n", o, p->data * 100.0 / num);
    }
    for (int i=0; i<=128; i++) {
        if (p->next[i] != NULL) {
            o[step] = i;
            dfs(p->next[i], step+1);
        }
    }
}
int main()
{
    char p[51];
    node* head;
    head = build();
    while(gets(p) !=0) {
        insert(head, p);
        num ++;
    }
    dfs(head, 0);
    return 0;
}
