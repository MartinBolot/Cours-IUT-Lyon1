package model;

public class PieceIHM implements PieceIHMs{
	public int getX() {
		return this.x;
	}
	public int getY() {
		return this.y;
	}
	public Couleur getCouleur() {
		return this.couleur;
	}
	public String getNamePiece() {
		return this.name;
	}
	
	@Override
	public String toString() {
		return "";
	}
	
	private int x;
	private int y;
	private Couleur couleur;
	private String name;
}
