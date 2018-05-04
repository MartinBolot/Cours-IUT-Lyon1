package model;

/*
 * patterns mis en oeuvre :
 *  - Proxy
 *  - 
 */
public class ChessGame implements BoardGames {
	public ChessGame() {
		this.echiquier = new Echiquier();
	}
	
	public String toString() {
		return echiquier.toString() + echiquier.getMessage();
	}
	
	public boolean move (int xInit, int yInit, int xFinal, int yFinal) {
		boolean moveDone = false;
		if(echiquier.isMoveOk(xInit, yInit, xFinal, yFinal)) {
			moveDone = echiquier.move(xInit, yInit, xFinal, yFinal);
			if(moveDone) {
				echiquier.switchJoueur();
			}
		}
		return moveDone;
	}
	public boolean isEnd() {
		return echiquier.isEnd();
	}
	public String getMessage() {
		return echiquier.getMessage();
	}
	public Couleur getColorCurrentPlayer() {
		return echiquier.getColorCurrentPlayer();
	}

	public Couleur getPieceColor(int x, int y) {
		return echiquier.getPieceColor(x, y);
	}
	
	private Echiquier echiquier;
}
