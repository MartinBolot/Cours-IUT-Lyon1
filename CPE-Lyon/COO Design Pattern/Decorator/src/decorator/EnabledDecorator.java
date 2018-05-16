package decorator;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JComponent;

public class EnabledDecorator extends Decorator {
	JComponent thisComp;
	
	public EnabledDecorator(JComponent c) {
		super(c);
		c.repaint();
		thisComp = c;
		c.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				setDisabled();
			}
		});
	}
	
	public void setDisabled() {
		thisComp.setEnabled(false);
	}

	public void paint(Graphics g) {
		super.paint(g);
		Dimension size = super.getSize();
		g.setColor(Color.red);
		g.drawLine(0, 0, size.width, size.height);
	}
}
