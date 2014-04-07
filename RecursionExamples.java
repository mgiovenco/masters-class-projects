import java.util.Scanner;

public class Recursion {

	
	// public version: test user input!
	public static int factorial(int n) {
		if (n < 0)
			throw new IllegalArgumentException();
		if (n == 0) return 1;
		return n*factorial(n-1);
	}  
	
	
	// private version: when debugging check precondition 
	private static int factorial2(int n) {
		// Precondition: n >= 0
		assert n >= 0;  // throws exception if 
		                // expression is false
		if (n == 0) return 1;
		return n*factorial2(n-1);
	}  

	// Return length of s without calling s.length()
	public static int length(String s) {
		if (s == null)
			throw new NullPointerException();

		if (s.equals(""))
			return 0;
		else
			return length(s.substring(1)) + 1;
	}
	
	// Returns true if array contains value
	// Poor implementation because it needs to make a copy 
	// of the array, one element shorter each recursive call.
	public static boolean containsBad(int[] A, int value) {
		if (A.length == 0) return false;
		else if (A[0] == value) return true;
		else {
			int[] shorter = new int[A.length-1];
			System.arraycopy(A, 1, shorter, 0, A.length-1);
			return containsBad(shorter, value);
		}
	}
	
	// Return true if array contains value
	// Wrapper method to the recursive method with additional
	// parameter.
	public static boolean contains(int[] data, int value) {
		return contains(data, value, 0);		
	}
	
	// Helper method that updates an index to make the recursive
	// call to a smaller problem.
	// Return true if array[index], array[index+1]...
	// contains value
	private static boolean contains(int[] data, int value, int index) {
		if (index == data.length) return false;
		else if (data[index] == value) return true;
		else return contains(data, value, index+1);		
	}
	

	// Print the input in reverse.
	// Uses system stack to save the values already
	// read.
	public static void reverse(Scanner scan) {
		if (scan.hasNextLine()) {
			String text = scan.nextLine();
			reverse(scan);
			System.out.println(text);
		}		
	}

	// Return index of data that equals value
	public static int indexOf(int[] data, int value) {
		return indexOf(data, value, 0);		
	}
	
	// Return index of array[index], array[index+1]...
	// that equal value value
	private static int indexOf(int[] data, int value, int index) {
		if (index == data.length) return -1;
		else if (data[index] == value) return index;
		else return indexOf(data, value, index+1);		
	}

	// Fibonacci number: Two recursive calls results in O(2^n) calls Yikes!!
	public static int fibonacci(int n) {
		if (n <= 0)
			throw new IllegalArgumentException();

		assert n > 0;
		if (n <= 2) 
			return 1;
		else
			return fibonacci(n-1) + fibonacci(n-2);
	}


}
