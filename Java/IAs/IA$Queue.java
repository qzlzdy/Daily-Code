/**
 * File Name: IA$Queue.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2016-12-10
 * Description: A Data Structure
 * Funcation List:
 *	1. IA$Queue::public void enqueue(int x)throws IA$QueueExc
 *	2. IA$Queue::public int dequeue()throws IA$QueueExc
 */
class IA$Queue{
	protected int[] queue;
	protected int head;
	protected int tail;
	protected int num;
	public IA$Queue(){
		this(5);
	}
	public IA$Queue(int size){
		this.queue = new int[size + 1];
		this.head = 0;
		this.tail = 0;
		this.num = 0;
	}
	public int getNum(){
		return this.num;
	}
	public void enqueue(int x)throws IA$QueueExc{
		if(this.tail + 1 == this.head)
			throw new IA$QueueExc("QueueOverFlow");
		else if((this.tail == this.queue.length - 1)&&(this.head == 0))
			throw new IA$QueueExc("QueueOverFlow");
		this.queue[this.tail] = x;
		if(this.tail == this.queue.length - 1)
			this.tail = 0;
		else
			this.tail++;
		this.num++;

	}
	public int dequeue()throws IA$QueueExc{
		if(this.head == this.tail)
			throw new IA$QueueExc("QueueUndeFlow");
		int rs = this.queue[this.head];
		if(this.head == this.queue.length - 1)
			this.head = 0;
		else
			this.head++;
		this.num--;
		return rs;
	}
}
class IA$QueueExc extends Exception{
	public IA$QueueExc(){
	}
	public IA$QueueExc(String s){
		super(s);
	}
}