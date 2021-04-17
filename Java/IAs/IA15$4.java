/**
 * File Name: IA15$4.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2017-1-1
 * Description: Dynamic Programming Of Longest-Common-Subsequence Problem
 * Funcation List:
 *	1. IA15$4::public static void main(String[] args)
 *	2. IA15$4::private void printLCS(String X,int[][] memo,int i,int j)
 *	3. IA15$4::private int[][] LCSLength(String X,String Y)
 */
public class IA15$4{
	public static void main(String[] args){
		IA15$4 IA = new IA15$4();
		int[][] temp = IA.LCSLength(args[0],args[1]);
		if(temp[args[0].length()][args[1].length()] == 0)
			System.out.println("无最长公共子序列");
		else{
			System.out.print("最长公共子序列为：");
			IA.printLCS(args[0],temp,args[0].length(),args[1].length());
			System.out.println("");
		}
	}
	private void printLCS(String X,int[][] memo,int i,int j){
		if((i != 0)&&(j != 0)){
			if(memo[i - 1][j] > memo[i - 1][j - 1])
				this.printLCS(X,memo,i - 1,j);
			else if(memo[i][j - 1] > memo[i - 1][j - 1])
				this.printLCS(X,memo,i,j - 1);
			else if(memo[i][j] > memo[i - 1][j - 1]){
				this.printLCS(X,memo,i - 1,j - 1);
				System.out.print(X.substring(i - 1,i));
			}
		}
	}
	private int[][] LCSLength(String X,String Y){
		char[] temp_X = X.toCharArray();
		char[] temp_Y = Y.toCharArray();
		int[][] temp = new int[temp_X.length + 1][temp_Y.length + 1];
		for(int i = 1; i <= temp_X.length; i++){
			for(int j = 1; j <= temp_Y.length; j++){
				if(temp_X[i - 1] == temp_Y[j - 1])
					temp[i][j] = temp[i - 1][j - 1] + 1;
				else if(temp[i - 1][j] > temp[i][j - 1])
					temp[i][j] = temp[i -1][j];
				else
					temp[i][j] = temp[i][j - 1];
			}
		}
		return temp;
	}
}