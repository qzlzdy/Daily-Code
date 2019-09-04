/**
 * File Name: Chapter4$3.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: 2016-11-20
 * Description: Output the follow graph
 * 
 * 	#
 *     ###
 *    #####
 *   #######
 *  #########
 * ###########
 *  #########
 *   #######
 *    #####
 *     ###
 *      #
 *      
 * Funcation List: 
 * 	1. Chapter4$3::public static void main( String[])
 */
public class Chapter4$3{
	public static void main(String args[]){
		for( int i = 1; i <= 6; i++){
			for( int j = 6 - i; j > 0; j--){
				System.out.print(" ");
			}
			for( int j = 2 * i - 1; j > 0; j--){
				System.out.print("#");
			}
			System.out.println("");
		}
		for( int i = 5; i > 0; i--){
			for( int j = 6 - i; j > 0; j--){
				System.out.print(" ");
			}
			for( int j = 2 * i - 1; j > 0; j--){
				System.out.print("#");
			}
			System.out.println("");
		}
	}
}