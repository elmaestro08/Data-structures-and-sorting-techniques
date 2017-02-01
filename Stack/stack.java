import java.awt.*;
import javax.swing.*;
import java.awt.event.*;


class Stack1 extends JFrame implements ActionListener
{
int[]S;
int top;
JPanel v1,v2,b,i,all,v_1,v_2;
JLabel val1,val2,tot;
JTextField val_1;
JButton add,clr,dis;

int sum=0,total_sum=0,x=0,y=0;

public Stack1()
{
setTitle("Queue Implementation");
setSize(350,250);
setLocation(200,200);
setDefaultCloseOperation(EXIT_ON_CLOSE);
v_1=new JPanel();
v_2=new JPanel();
b =new JPanel();
i = new JPanel();

all=new JPanel(new FlowLayout(FlowLayout.CENTER,1000,20));


val1=new JLabel("Input  ");
val2=new JLabel("Output ");
val_1=new JTextField(10);
tot=new JLabel("The Stack is ");
add=new JButton("Push/Add");
clr=new JButton("Pop/Delete");
dis = new JButton("Display");
}


public void init()
{
setLayout(new BorderLayout());
v_1.add(val1);
v_1.add(val_1);
v_2.add(val2);

b.add(add);
b.add(clr);
b.add(dis);
i.add(tot);

all.add(v_1);
all.add(v_2);
all.add(i);

add(b,BorderLayout.SOUTH);
add(all,BorderLayout.CENTER);
add.addActionListener(this);
clr.addActionListener(this);
dis.addActionListener(this);
S = new int[10];
top = -1;
}
	public void actionPerformed(ActionEvent e)
	{
		try
		{
			if(add==e.getSource())
			{
				x=Integer.parseInt(val_1.getText());
				if(top==19)
				{   String s1 = "Stack is full";
         			val2.setText(s1);
				}
      			else
      			{
         			top = top+1;
         			S[top]= x;
            	}
            }
			else if(clr==e.getSource())
			{
				if(top==-1)
				{
					String s1 = "Stack is empty";
      				val2.setText(s1);
				}
   				else
   				{
   					String s1 = "popped"+S[top];
      				val2.setText(s1);
      				top = top-1;
   				}
			}
			else if (dis==e.getSource())
			{
				if(top==-1)
				{
					String s1 = "Stack is empty";
					val2.setText(s1);
				}
    			else
   				{   String s1="";
      				for(int i=top; i>=0;i--)
      					s1 = s1+ S[i];
          				val2.setText(s1);   
   				}
			}
		}
		catch(NumberFormatException n)
		{
			val_1.setText("0");
		}
	}
}

class QueJava
{
	public static void main(String args[])
	{
       Stack1 values =new Stack1();

	    values.init();
	    values.setVisible(true);
        values.setResizable(false);
        values.setLocation(200,200);
}
}
