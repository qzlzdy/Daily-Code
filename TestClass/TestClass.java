/**
 *
 * @һֻ��������Ʈ����ʵ�����ض�M��
 *
 */
import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;
import java.awt.*;
public class TestClass extends JFrame implements ActionListener{
	JLabel ltip = new JLabel("���忪������Ӧ��ver");
	JButton b[] = {new JButton("��ǩ"),new JButton("��ť"),new JButton("�ı���")};
	public TestClass(){
		this.setTitle("���忪������Ӧ��ver(1.01.00)");
		Image icon = this.getToolkit().getImage("H13.jpg");
		this.setIconImage(icon);
		this.setLayout(null);
		ltip.setBounds(5,5,140,30);
		this.add(ltip);
		for(int i = 0; i <b.length; i++){
			b[i].setBounds(5,40+35*i,140,30);
			this.add(b[i]);
			b[i].addActionListener(this);
		}
		b[0].setMnemonic('l');
		b[1].setMnemonic('b');
		b[2].setMnemonic('t');
		this.setBounds(300,250,170,200);
		this.setResizable(false);
		this.setVisible(true);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	public static void main(String args[]){
		new TestClass();
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource() == b[0]){
			TestLabel.getTestLabel().setVisible(true);
		}
		else if(e.getSource() == b[1]){
			TestButton.getTestButton().setVisible(true);
		}
		else{
			TestTextField.getTestTextField().setVisible(true);
		}
	}
}
class TestLabel extends JFrame{
	JLabel l[] = {new JLabel("�����꣺"),new JLabel("�����꣺"),new JLabel("��ȣ�"),new JLabel("�߶ȣ�"),new JLabel("�ı���"),new JLabel("��С��")};
	JTextField tf[] = {new JTextField("46"),new JTextField("250"),new JTextField("80"),new JTextField("30"),new JTextField("qzlzdy"),new JTextField("16")};
	JButton b = new JButton("����");
	JLabel testl = new JLabel("qzlzdy");
	private static TestLabel tl;
	public static TestLabel getTestLabel(){
		if(tl == null){
			tl = new TestLabel();
		}
		return tl;
	}
	private TestLabel(){
		this.setTitle("��ǩ����");
		Image icon = this.getToolkit().getImage("H13.jpg");
		this.setIconImage(icon);
		this.setLayout(null);
		for(int i = 0;i < l.length;i++){
			l[i].setBounds(5,5+35*i,60,30);
			this.add(l[i]);
			tf[i].setBounds(70,5+35*i,100,30);
			this.add(tf[i]);
		}
		b.setBounds(46,215,80,30);
		this.add(b);
		b.addActionListener(new ActionListener()
				{
					public void actionPerformed(ActionEvent e){
						testl.setBounds(Integer.parseInt(tf[0].getText()),Integer.parseInt(tf[1].getText()),Integer.parseInt(tf[2].getText()),Integer.parseInt(tf[3].getText()));
						testl.setText(tf[4].getText());
						testl.setFont(new Font("����",Font.PLAIN,Integer.parseInt(tf[5].getText())));
					}
				});
		testl.setBounds(46,250,80,30);
		this.add(testl);
		this.setBounds(300,285,300,290);
		this.setDefaultCloseOperation(HIDE_ON_CLOSE);
	}
}
class TestButton extends JFrame{
	JLabel l[] = {new JLabel("�����꣺"),new JLabel("�����꣺"),new JLabel("��ȣ�"),new JLabel("�߶ȣ�"),new JLabel("�ı���")};
	JTextField tf[] = {new JTextField("46"),new JTextField("215"),new JTextField("80"),new JTextField("30"),new JTextField("qzlzdy")};
	JButton b = new JButton("����");
	JButton testb = new JButton("qzlzdy");
	private static TestButton tb;
	public static TestButton getTestButton(){
		if(tb == null){
			tb = new TestButton();
		}
		return tb;
	}
	private TestButton(){
		this.setTitle("��ť����");
		Image icon = this.getToolkit().getImage("H13.jpg");
		this.setIconImage(icon);
		this.setLayout(null);
		for(int i = 0;i < l.length;i++){
			l[i].setBounds(5,5+35*i,60,30);
			this.add(l[i]);
			tf[i].setBounds(70,5+35*i,100,30);
			this.add(tf[i]);
		}
		b.setBounds(46,180,80,30);
		this.add(b);
		b.addActionListener(new ActionListener()
				{
					public void actionPerformed(ActionEvent e){
						testb.setBounds(Integer.parseInt(tf[0].getText()),Integer.parseInt(tf[1].getText()),Integer.parseInt(tf[2].getText()),Integer.parseInt(tf[3].getText()));
						testb.setText(tf[4].getText());
					}
				});
		testb.setBounds(46,215,80,30);
		this.add(testb);
		this.setBounds(300,250,300,290);
		this.setDefaultCloseOperation(HIDE_ON_CLOSE);
	}
}
class TestTextField extends JFrame{
	JLabel l[] = {new JLabel("�����꣺"),new JLabel("�����꣺"),new JLabel("��ȣ�"),new JLabel("�߶ȣ�")};
	JTextField tf[] = {new JTextField("46"),new JTextField("215"),new JTextField("80"),new JTextField("30")};
	JButton b = new JButton("����");
	JTextField testtf = new JTextField();
	private static TestTextField ttf;
	public static TestTextField getTestTextField(){
		if(ttf == null){
			ttf = new TestTextField();
		}
		return ttf;
	}
	private TestTextField(){
		this.setTitle("�ı������");
		Image icon = this.getToolkit().getImage("H13.jpg");
		this.setIconImage(icon);
		this.setLayout(null);
		for(int i = 0;i < l.length;i++){
			l[i].setBounds(5,5+35*i,60,30);
			this.add(l[i]);
			tf[i].setBounds(70,5+35*i,100,30);
			this.add(tf[i]);
		}
		b.setBounds(46,145,80,30);
		this.add(b);
		b.addActionListener(new ActionListener()
				{
					public void actionPerformed(ActionEvent e){
						testtf.setBounds(Integer.parseInt(tf[0].getText()),Integer.parseInt(tf[1].getText()),Integer.parseInt(tf[2].getText()),Integer.parseInt(tf[3].getText()));
					}
				});
		testtf.setBounds(46,180,80,30);
		this.add(testtf);
		this.setBounds(300,250,300,290);
		this.setDefaultCloseOperation(HIDE_ON_CLOSE);
	}
}