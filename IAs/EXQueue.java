/**
 * File Name: EXQueue.java
 * Author: 一只骑着轮子飘在天际的萝莉控抖M羊
 * Version: 1
 * Date: Ver.1:2017-1-2
 * Description: Extended IA$Queue
 * Funcation List:
 *	1. EXQueue::public void enqueue(int x)
 *	2. EXQueue::public int dequeue()throws IA$QueueExc
 */
class EXQueue extends IA$Queue{
	public EXQueue(){
		this.queue = new int[2];
		this.head = 0;
		this.tail = 0;
		this.num = 0;
	}
	public void enqueue(int x){
		if(this.num == this.queue.length){
			int[] temp = new int[2 * this.queue.length];
			int j = 0;
			int i = this.head;
			while(j <= this.num){
				temp[j] = this.queue[i];
				j++;
				i++;
				if(i == this.queue.length)
					i = 0;
			}
			this.queue = temp;
			this.head = 0;
			this.tail = j;
		}
		this.queue[this.tail] = x;
		this.tail++;
		if(this.tail == this.queue.length)
			this.tail = 0;
		this.num++;
	}
	public int dequeue()throws IA$QueueExc{
		if(this.num == 0)
			throw new IA$QueueExc("EXQueueUnderFlow");
		int de = this.queue[this.head];
		this.head++;
		if(this.head == this.queue.length)
			this.head = 0;
		this.num--;
		if((this.num != 0)&&(this.num / this.queue.length <= 0.25)){
			int[] temp = new int[this.queue.length / 2];
			int j = 0;
			int i = this.head;
			while(j <= this.num){
				temp[j] = this.queue[i];
				j++;
				i++;
				if(i == this.queue.length)
					i = 0;
			}
			this.queue = temp;
			this.head = 0;
			this.tail = j;
		}
		return de;
	}
}