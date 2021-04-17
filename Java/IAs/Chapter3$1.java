/**
 * File Name: Chapter3$1.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: 2016-11-20
 * Description: For a four digit X,output the sum of each digit of the X (ignoring the positive and negative numbers)
 * Funcation List: 
 * 	1. Chapter3$1::public static void main( String[])
 */
public class Chapter3$1{
	public static void main( String args[]){
		int X = Integer.parseInt( args[0]);
		int sum = 0;
		for( int i = 0; i < 4; i++){
			sum += X / Math.pow( 10, i) % 10;
		}
		System.out.println( "The sum of each digit of " + X + " is : " + sum);
	}
}