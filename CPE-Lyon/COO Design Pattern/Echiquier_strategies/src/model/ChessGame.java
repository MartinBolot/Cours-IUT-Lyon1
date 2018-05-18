package model;


import tools.AbstractSubject;

/*
 * patterns mis en oeuvre :
 *  - Proxy
 *  - 
 */
public class ChessGame extends AbstractSubject implements BoardGames {
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
				//this.notifyObservers(echiquier.getPieceIHMs());
				echiquier.switchJoueur();
			}
		}
		this.notifyObservers(echiquier.getPieceIHMs());
		return moveDone;
	}
	
	public void undoMove() {
		return;
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
	
	public boolean isMoveOk(Coord initCoord, Coord finalCoord) {
		return this.echiquier.isMoveOk(initCoord.x, initCoord.y, finalCoord.x, finalCoord.y);
	}
	
	private Echiquier echiquier;
}
