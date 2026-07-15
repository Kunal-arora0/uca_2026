import java.util.Scanner;

class Fibonacci{


	public static int sumOfEvenFibonacci(int n){
		return helper(1,1,0 , n);
	}

	public static int helper(int a , int b , int sum ,  int n){

		if(a > n) return sum;

		if (a % 2 ==0){
			sum +=a;
		}

		return helper(b,  a+b , sum ,  n);
	}

	public static void main(String []args){
		Scanner sc  = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.println(sumOfEvenFibonacci(n));
		
	}
}
