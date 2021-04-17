/**
 * File Name: IA$Stack.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-4
 * Description: A Data Structure
 * Funcation List:
 *	1. IA$Stack::public boolean isEmpty()
 *	2. IA$Stack::public void push(int x)throws IA$StackExc
 *	3. IA$Stack::public int pop()throws IA$StackExc
 */
class IA$Stack{
	protected int[] stack;
	protected int top;
	public IA$Stack(){
		this(5);
	}
	public int getNum(){
		return this.top;
	}
	public IA$Stack(int size){
		this.stack = new int[size];
		this.top = 0;
	}
	public boolean isEmpty(){
		if(this.top == 0)
			return true;
		else
			return false;
	}
	public void push(int x)throws IA$StackExc{
		if(this.top >= this.stack.length)
			throw new IA$StackExc("StackOverFlow");
		this.stack[this.top] = x;
		this.top++;
	}
	public int pop()throws IA$StackExc{
		if(this.isEmpty())
			throw new IA$StackExc("StackUnderFlow");
		this.top--;
		return this.stack[this.top];
	}
}
class IA$StackExc extends Exception{
	public IA$StackExc(){
	}
	public IA$StackExc(String s){
		super(s);
	}
}