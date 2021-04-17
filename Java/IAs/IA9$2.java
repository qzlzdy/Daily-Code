/**
 * File Name: IA9$2.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 2
 * Date: Ver.1:2016-12-4 Ver.2:2016-12-10
 * Description: Randomized-Select
 * Funcation List:
 *	1. IA9$2::public static void main(String[])
 *	2. IA9$2::private int rSelect(int x,int r,int p)throws Exc9$2
 *	3. IA9$2::private int rPartition(int r,int p)
 */
public class IA9$2{
	int[] A = new int[50];
	public static void main(String[] args){
		IA9$2 IA = new IA9$2();
		System.out.print("原数组：");
		for(int i = 0; i < IA.A.length; i++){
			IA.A[i] = 50 - i;
			System.out.print(IA.A[i] + " ");
		}
		System.out.println("");
		try{
			int rs = IA.rSelect(Integer.parseInt(args[0]),0,IA.A.length - 1);
			System.out.println("数组中第" + args[0] + "小的是" + rs);
		}
		catch(Exc9$2 e){
			e.printStackTrace();
		}
	}
	private int rSelect(int x,int r,int p)throws Exc9$2{
		if((x > this.A.length)||(x <= 0))
			throw new Exc9$2("ArrayIndexOutOfBoundsException");
		if(p == r)
			return this.A[r];
		int q = this.rPartition(r,p);
		if(q + 1 == x)
			return this.A[q];
		else if(x < q + 1)
			return this.rSelect(x,r,q-1);
		else
			return this.rSelect(x,q+1,p);
	}
	private int rPartition(int r,int p){
		int x = (int)(Math.random() * (p - r + 1) + r);
		int temp; //用于数据交换
		temp = this.A[x];
		this.A[x] = A[p];
		this.A[p] = temp;
		int i = r;
		for(int j = r; j < p; j++){
			if(this.A[j] <= x){
				temp = this.A[i];
				this.A[i] = A[j];
				this.A[j] = temp;
				i++;
			}
		} 
		temp = this.A[i];
		this.A[i] = A[p];
		this.A[p] = temp;
		return i;
	}
}
class Exc9$2 extends Exception{
	public Exc9$2(){
	}
	public Exc9$2(String s){
		super(s);
	}
}