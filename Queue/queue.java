package queue1;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
public class queue extends JFrame implements ActionListener
{

	JTextField t1;
	JButton enq,deq,disp;
	JLabel l1;
	int a[];
	int front,rear;
	int count;
	queue() {
		count=0;
		front=-1;
		rear=-1;
		a=new int[10];
		setTitle("QUEUE");
		setSize(500,500);
		setLayout(new FlowLayout());
		t1=new JTextField(10);
		add(t1);
		enq=new JButton("Enqueue");
		add(enq);
		enq.addActionListener(this);
		deq=new JButton("Dequeue");
		add(deq);
		deq.addActionListener(this);
		disp=new JButton("Display");
		add(disp);
		disp.addActionListener(this);
		l1=new JLabel("");
		add(l1);
		
	}
	
	public void actionPerformed(ActionEvent e)
	{
		
		int n;
		String s="";
		s=e.getActionCommand();
		if(s.equals("Enqueue"))
		{
			String r=t1.getText();
			if(r.equals(""))
			{
				JOptionPane.showMessageDialog(null, "Enter data to be enqueued","Error",0);
			}
			else
			{
			if(count==5)
			{
				t1.setText("");
				JOptionPane.showMessageDialog(null, "Queue overflow","Error",0);
			}
			else
			{
				
				
				
			 n=Integer.parseInt(t1.getText());
			if((front==-1)&&(rear==-1))
			{
				count++;
				++front;
				++rear;
				a[rear]=n;
			}
			else
			{
				count++;
				++rear;
				a[rear]=n;				
			}
			t1.setText("");
			}
			}
		}
		else if(s.equals("Dequeue"))
		{
			if(count==0)
			{
				l1.setText("");
				JOptionPane.showMessageDialog(null, "Queue underflow","Error",0);
			}
			else
			{
				l1.setText("");
				count--;
				++front;
				for(int i=0;i<rear;i++)
				{
					a[i]=a[i+1];
					
				}
				--rear;
			}
		}
		else if(s.equals("Display"))
		{
			String s1="";
			for(int i=0;i<=rear;i++)
			{
				s1=s1+" "+a[i];
			}
			if(s1=="")
			{
				JOptionPane.showMessageDialog(null, "Queue empty","Error",0);
			}
			else
			{
			l1.setText(s1);
			}
		}
	}

	public static void main(String[] args) {
		queue q=new queue();
		q.setVisible(true);
	

	}

}

