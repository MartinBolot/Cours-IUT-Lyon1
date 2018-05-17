package model;

public class PieceIHM implements PieceIHMs{
	public PieceIHM(Pieces piece) {
		this.piece = piece;
	}
	
	public int getX() {
		return piece.getX();
	}
	public int getY() {
		return piece.getY();
	}
	public Couleur getCouleur() {
		return piece.getCouleur();
	}
	public String getNamePiece() {
		return piece.getName();
	}
	
	@Override
	public String toString() {
		return piece.getX() + "-" + piece.getY();
	}
	
	private Pieces piece;
}
