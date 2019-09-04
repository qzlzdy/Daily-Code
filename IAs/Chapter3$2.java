/**
 * File Name: Chapter3$2.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 2
 * Date: Ver.1:2016-11-20 Ver.2:2016-12-10
 * Description: Output the factorial of a natural number N
 * Funcation List:
 * 	1. Chapter3$2::public static void main( String[])
 * 	2. Chapter3$2::private static long factorial( int n)
 */
public class Chapter3$2{
	public static void main(String args[]){
		int n = Integer.parseInt( args[0]);
		long rs = factorial( n);
		System.out.println("The factorial of " + n + " is : " + rs);
	}
	private static long factorial( int n){
		if( n > 0)
			return factorial( n - 1) * n;
		else if( n == 0)
			return 1;
		return 0;
	}
}