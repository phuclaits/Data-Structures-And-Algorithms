#include<stdio.h>
#include<conio.h>
#include<math.h>

int UCLN(int a, int b);
int KTSNT(int n);
void Result(int n);


int KTSNT(int n)
{
	if(n < 2)
	{
		return 0;
	}
	int i;
	for(i = 2 ; i < sqrt(n) ; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;		
}

int sum(int n){
	int sum = 0;
	for(int i = 1 ; i <= n ;i++){
		sum+= i;
	}
	return sum;
}

void Result(int n)
{
	if (KTSNT(n) == 1)
	{
		printf("\n So %d la so nguyen to !",n);
	}
	else{
		printf("\n So %d KO PHAI so nguyen to !",n);
	}
} 

int main()
{
    int a,b,c,d,e,f,n;
    do
	{
	    printf("\nNhap vao so nguyen duong a va b: ");
	    scanf("%d%d",&a,&b);
	    if(a <= 0 || b <= 0 )
	    {
	    	printf("\n Vui Long nhap lai so nguyen duong !");
		}
	}
	while (a <= 0 || b <= 0);
	printf("\nUoc chung lon nhat cua 2 so la: %d\n",UCLN(a,b));
	printf("\n Nhap so n = ");
	scanf("%d",&n);
	Result(n);
	printf("Tong ")
	return 0;
	
}
int UCLN(int a, int b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
}

