#define MAXNUM 150000     //权值上限,两点间默认距离
#define MAXPT 50           //顶点数量上限

int a[MAXPT][MAXPT],n;   //两点之间没有路，则两点间距离为MAXNUM
int lowest[MAXPT];         //最近点距离
int close[MAXPT];          //最近点
int mark[MAXPT];

int prim(int s)
{
	int i,j,k,min,sum=0;

	for(i=1;i<=n;i++)  
	{
		lowest[i]=a[s][i];
		close[i]=s; 
		mark[i]=false;
	}
	mark[s]=true;

	for(i=2;i<=n;i++)
	{
		min=MAXNUM; j=0;
		for(k=1;k<=n;k++)
			if(!mark[k] && lowest[k]<min) 
			{
				min=lowest[k];j=k;
			}

		if(j==0) {/*error*/; return -1;} 
		mark[j]=true;  sum+=min;

		for(k=1;k<=n;k++)
			if(!mark[k] && a[j][k]<lowest[k])
			{
				lowest[k]=a[j][k];close[k]=j;
			}
	}
	return sum;
}
