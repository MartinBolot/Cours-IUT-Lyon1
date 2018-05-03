package model;

public class PionNoir extends AbstractPion{
	public PionNoir(Coord coord) {
		super(Couleur.NOIR, coord);
	}
	
	public boolean checkOutOfBounds(int yFinal) {
		if (yFinal - this.getY() > 0) {
			return true;
		}
		return false;
	}
	
	public boolean checkDiago(int xFinal, int yFinal) {
		if ((yFinal == this.getY()+1 && xFinal == this.getX()+1) 
				|| (yFinal == this.getY()+1 && xFinal == this.getX()-1)) {
			return true;
		}
		return false;
	}
}
