/**
 * File Name: Chapter4$1.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: 2016-11-20
 * Description: Output a multiplication table
 * Funcation List:
 *   	1. Chapter4$1::public static void main( String[])
 */
public class Chapter4$1{
	public static void main(String args[]){
		for( int i = 1; i <= 9; i++){
			for( int j = 1; j <= i; j++){
				System.out.print(i + "×" + j + "=" + i * j + " ");
			}
			System.out.println("");
		}
	}
}