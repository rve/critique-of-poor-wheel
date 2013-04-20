#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define MAXN 100010
using namespace std;

int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};

int rect(char c)
{
	if (c == 'E') return 0;
	if (c == 'S') return 3;
	if (c == 'W') return 1;
	if (c == 'N') return 2;
}
int main()
{
    char dd[5][3]  = {"  ","NE", "SN", "SW", "ES"};
    int dr=-1;
    char str[MAXN];
	int n,sx,sy,ex,ey;
	cin>>n>>sx>>sy>>ex>>ey;
	int op[100010];
	for (int i = 0 ; i < n ; i++)
	{
		char temp;
		cin>>temp;
		op[i] = rect(temp);
	}
	int ddx = ex - sx;
	int ddy = ey - sy;
	bool flag[4] = {false,false,false,false};
	if (ddx<0) flag[rect('W')] = true;
   //
	if (ddx>0) flag[rect('E')] = true;
	if (ddy<0) flag[rect('S')] = true;
   //
	if (ddy>0) flag[rect('N')] = true;
    int iswin = 0;
    
    int i;
    int xn = 0, yn = 0;
    if (ex == sx) xn = 1;
    if (ey == sy) yn = 1;

    	int total = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total++;
		if (flag[op[i]])
		{ 
			ddx -= dx[op[i]];
			ddy -= dy[op[i]];
			if (ddx == 0) flag[0] = flag[1] = false;
			if (ddy == 0) flag[2] = flag[3] = false;
			if (ddx == 0 && ddy == 0) break;
		}
	}
	if (ddx != 0 || ddy != 0) total = -1;
	cout<<total<<endl;

}
