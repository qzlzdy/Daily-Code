/**
 * File Name: IA15$1.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2017-1-1
 * Description: Dynamic Programming Of Cut-Rod
 * Funcation List:
 *	1. IA15$1::public static void main(String[] args)
 *	2. IA15$1::private void printCutRodSolution(int[] p,int len)
 *	3. IA15$1::private int[] cutRod(int[] p,int len)
 */
public class IA15$1{
	int[] p;
	public static void main(String[] args){
		IA15$1 IA = new IA15$1();
		int rod_len = Integer.parseInt(args[0]);
		IA.p = new int[rod_len + 1];
		for(int i = 0; i < IA.p.length; i++){
			IA.p[i] = (int)(Math.random() * (2 * i + 1) + i);
			System.out.println(i + "长度的钢条价格为" + IA.p[i]);
		}
		IA.printCutRodSolution(IA.p,rod_len);
	}
	private void printCutRodSolution(int[] p,int len){
		int[] rs =  this.cutRod(p,len);
		System.out.println("钢条最大利润为" + rs[0]);
		System.out.print("钢条切割长度为：");
		while(len > 0){
			System.out.print(rs[len] + " ");
			len -= rs[len];
		}
	}
	private int[] cutRod(int[] p,int len){
		int[] r = new int[len + 1];
		int[] s = new int[len + 1];
		int q;
		for(int i = 1; i <= len; i++){
			q = 0;
			for(int j = 1; j <= i; j++){
				if(q < p[j] + r[i - j]){
					q = p[j] + r[i - j];
					s[i] = j;
				} 
			}
			r[i] = q;
		}
		s[0] = r[len];
		return s;
	}
}