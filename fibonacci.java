import java.util.Scanner;

class Fibonacci{

	private static int sum = 0;

	public static void sumOfEvenFibonacci(int n){
		
		int a = 1;
		int b = 1;
		int c=0;	
		while(c <= n){
			c = a+b;
			if(c % 2 ==0){
				sum+=c;
			}
			a=b;
			b=c;
		}
		

	}

	public static void main(String []args){
		Scanner sc  = new Scanner(System.in);
		int n = sc.nextInt();
		sumOfEvenFibonacci(n);
		System.out.println(Fibonacci.sum);
	}
}
