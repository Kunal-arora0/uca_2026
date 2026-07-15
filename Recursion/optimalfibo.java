import java.util.Scanner;

class OptimalFibo{

	public static void main(String []args){

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int sum = 0;

		int first = 2;
		int second = 8;

		while(first <=n){

			sum+=first;
			int next = 4*second + first;
			first = second;
			second = next;
		}

		System.out.println(sum);
	}
}
