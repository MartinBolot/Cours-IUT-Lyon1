package decorator;
/*
The Design Patterns Java Companion

Copyright (C) 1998, by James W. Cooper

IBM Thomas J. Watson Research Center

http://www.java2s.com/Code/Java/Design-Pattern/DecoratorpatterninJava.htm

*/

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JComponent;



class CoolDecorator extends Decorator {
	boolean mouse_over; //true when mouse over button
	JComponent decoratedComp;
	JComponent thisComp;

	public CoolDecorator(JComponent c) {
		super(c);
		mouse_over = false;
		thisComp = this; //save this component
		this.decoratedComp = c;
		
		//catch mouse movements in inner class
		c.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent e) {
				super.mouseEntered(e);
				mouse_over = true; //set flag when mouse over
				thisComp.repaint();
			}

			public void mouseExited(MouseEvent e) {
				super.mouseExited(e);
				mouse_over = false; //clear flag when mouse not over
				thisComp.repaint();
			}
			public void mouseClicked(MouseEvent e) {
				super.mouseClicked(e);
				thisComp.repaint();
			}

		});

	}

	//paint the button
	public void paint(Graphics g) {
		super.paint(g); //first draw the parent button
		
		if (!mouse_over) {
			//if the mouse is not over the button
			//erase the borders		
			Dimension size = super.getSize();
			
			g.setColor(Color.blue);
			g.drawRect(0, 0, size.width - 1, size.height - 1);
			g.drawLine(size.width - 2, 0, size.width - 2, size.height - 1);
			g.drawLine(0, size.height - 2, size.width - 2, size.height - 2);
		}

	}
}
