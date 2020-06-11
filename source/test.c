int aaa,bbb,ccc;


//斐波那契
int fibo(int a) {
    if (a==1 || a==2) 
        return 1;
    return fibo(a-1)+fibo(a-2);
}

int test(int x,int y)
{   int a,b;  //注释1
 /*  注释2
     a=0；
*/  b=1;
    a*/*b+x*/b;
    return 1;
}



/* main函数 */
int main(){
    int m,n,i;
	
    int array[2][3];
    int total=100;
	
	m=0xAB;
    array[0][0]=1;


    m=read();
    i=1;

    while (i<=m)
	{
	    n=fibo(i);
	    write(n);
	    i=i+1;
	}
    
   
    i=i+1;
    return 1;
}
