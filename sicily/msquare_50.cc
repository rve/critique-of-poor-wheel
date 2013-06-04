#include <cstdio> // 用于scanf()、putchar()、printf()等I/O函数 
char  hash[ 1 << 24 ]; // hash[i]=得到状态i所用的操作 
inline  int  A( int  n) { return  (n & 4095 ) << 12 | n >> 12 ;} // 4095=2^12-1 
inline  int  B( int  n) { return  (( 7 << 9 | 7 << 21 ) & n) >> 9   |  ( ~ ( 7 << 9 | 7 << 21 ) & n) << 3 ;} 
inline  int  C( int  n) { return  ( 7 | 7 << 9 | 7 << 12 | 7 << 21 ) & n  |  (( 7 << 3 ) & n) << 3   |  (( 7 << 6 ) & n) << 12   |  (( 7 << 18 ) & n) >> 3   |  (( 7 << 15 ) & n) >> 12 ;} 
inline  int  zip( int  a[]) { // 用于将8个数压缩为1个小于2^24(约1670万)的整数 
    int  s = 0 ;
    for ( int  i = 0 ;i < 8 ; ++ i) s |= (a[i] - 1 ) << ( 3 * i);
    return  s;
} 
int  a[] = { 1 , 2 , 3 , 4 , 8 , 7 , 6 , 5 } ; // 初始状态 
const   int  QLen = 10000 ; // 队列长度 
int  q[QLen],b = 0 ,e = 0 ; // 循环队列及首、尾指针 
inline  void  inc( int &  p){ if(++ p ==QLen) p=0;} //用于移动队列首尾指针
int main(){//因为用记事本写的，排版不是很好，请见谅
    int i,j,n,bgn=zip(a);//bgn是初始状态（压缩后）
    hash[bgn]='E';
    q[b]=bgn; inc(b);
    while(b!=e){
        i=q[e]; inc(e);//取队首
        j=A(i);//生成新状态,未访问过则压入hash表和队列
        if(!hash[j]) hash[j]='A', q[b]=j, inc(b);
        j=B(i);
        if(!hash[j]) hash[j]='B', q[b]=j, inc(b);
        j=C(i);
        if(!hash[j]) hash[j]='C', q[b]=j, inc(b);
    }
    char s[100];//s[]用于保存生成的操作序列
    while(scanf("%d",&n),n!=-1){
        for(i=0; i<8; ++i) scanf("%d",&a[i]);
        for(i=zip(a),j=0; i!=bgn; ++j){
            s[j]=hash[i];
            switch(s[j]){//逐步回溯到前一状态
                case 'A': i=A(i);        break;
                case 'B': i=B(B(B(i)));    break;
                case 'C': i=C(C(C(i)));    break;
            }
        }
        if(j>n) printf("-1\n");
        else{
            printf("%d ",j);
            while(j--) putchar(s[j]);
            putchar('\n');
        }
    }
    return 0;
}
