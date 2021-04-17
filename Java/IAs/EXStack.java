/**
 * File Name: EXStack.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2017-1-2
 * Description: Extended IA$Stack
 * Funcation List:
 *	1. EXStack::public void push(int x)
 *	2. EXStack::public int pop()throws IA$StackExc
 *	3. IA$Stack::public boolean isEmpty()
 */
class EXStack extends IA$Stack{
	public EXStack(){
		this.stack = new int[2];
		this.top = 0;
	}
	public void push(int x){
		if(this.top == this.stack.length){
			int[] temp = new int[2 * this.stack.length];
			for(int i = 0; i < this.top; i++){
				temp[i] = this.stack[i];
			}
			this.stack = temp;
		}
		this.stack[this.top] = x;
		this.top++;
	}
	public int pop()throws IA$StackExc{
		if(this.isEmpty())
			throw new IA$StackExc("EXStackUnderFlow");
		this.top--;
		int pop = this.stack[this.top];
		if((!this.isEmpty())&&(this.top/this.stack.length <= 0.25)){
			int[] temp = new int[this.stack.length / 2];
			for(int i = 0; i < this.top; i++){
				temp[i] = this.stack[i];
			}
			this.stack = temp;
		}
		return pop;
	}
}