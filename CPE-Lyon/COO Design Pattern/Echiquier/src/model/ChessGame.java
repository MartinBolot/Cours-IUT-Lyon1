package model;

public class ChessGame implements BoardGames {
	public ChessGame() {
		this.echiquier = new Echiquier();
	}
	
	public String toString() {
		return "";
	}
	public boolean move (int xInit, int yInit, int xFinal, int yFinal) {
		return true;
	}
	public boolean isEnd() {
		return true;
	}
	public String getMessage() {
		return "";
	}
	public Couleur getColorCurrentPlayer() {
		return Couleur.BLANC;
	}

	public Couleur getPieceColor(int x, int y) {
		return Couleur.BLANC;
	}
	
	private Echiquier echiquier;
}
