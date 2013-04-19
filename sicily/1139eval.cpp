#include<iostream>
#include<cstring>
#include<stack>
#include<cstdio>
#include<algorithm>
#define MAXN 10010
#define INF 0x3f3f3f3f
using namespace std;
int n;
char str[MAXN];
float prob[28]; char in[MAXN];
int acc_i=0, acc_p=0;
char post[MAXN];
int prece(char c);
void toin();
void topost();
void eval();
void solve();

int main()
{
    scanf("%d", &n);
    scanf("%s", &str);
    for (int i=0; i<n; i++) {
        scanf("%f", &prob[i]);
    }
    solve();
}
void toin() {
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == ',') {
            in[acc_i++] = '+';}
        else if (str[i] == ')' && str[i+1] == '(') {
            in[acc_i++] = ')';
            in[acc_i++] = '*';
            in[acc_i++] = '(';
            i++;}
        else {
            in[acc_i++] = str[i];
        }}
    in[acc_i] = '\0';
}
void topost() {
    stack<char> sym;
    for(int i=0; i<strlen(in); i++) {
        char c = in[i];
        if (c >= 'A' && c <= 'Z') {
            post[acc_p++] = c;
        }
        else if (c == '+'|| c == '*') {
            if (sym.empty() || prece(c) > prece(sym.top())) {
                
                sym.push(c);
            }
            else {
                while(!sym.empty() && sym.top() != '(') {
                    post[acc_p++] = sym.top();
                    sym.pop();
                }
                sym.push(c);
            }

        }
        else if (c =='(')
        {
            sym.push(c);

        }
        else if (c == ')') {
            while(sym.top() != '(') {
                post[acc_p++] = sym.top();
                sym.pop();
            }

            sym.pop();
        }
    }
    while(!sym.empty()) {
        post[acc_p++] = sym.top();
        sym.pop();
        post[acc_p+1] = '\0';

    }
}

void eval() {
    stack<float> n;
    float ans = 0;
    for (int i=0; i<strlen(post); i++) {
        if (post[i] == '*') {
            float c2 = n.top(); n.pop();
            float c1 = n.top(); n.pop();
            ans = c2 * c1;
            n.push(ans);
        }
        else if (post[i] == '+') {
            float c2 = n.top(); n.pop();
            float c1 = n.top(); n.pop();
            ans = 1 - (1-c2) * (1-c1);
            n.push(ans);
        }
        else 
        {
            float t = prob[post[i]-'A'];
            n.push(t);
        }
    }

    ans = n.top(); n.pop();
    printf("%.4f\n", ans);
}
int prece(char c)
{
    if (c == '*') return 4;
    if (c == '+') return 2;
    if (c == '(') return 0;
}
void solve() {
    toin();
    topost();
    eval();
}
