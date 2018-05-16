package decorator;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JComponent;

class SlashDecorator extends Decorator {
	int x1, y1, w1, h1;

	public SlashDecorator(JComponent c) {
		super(c);
		c.repaint();
	}

	public void setBounds(int x, int y, int w, int h) {
		x1 = x;
		y1 = y;
		w1 = w;
		h1 = h;
		super.setBounds(x, y, w, h);
	}

	public void paint(Graphics g) {
		super.paint(g);
		g.setColor(Color.red);
		g.drawLine(0, 0, w1, h1);
	}

}