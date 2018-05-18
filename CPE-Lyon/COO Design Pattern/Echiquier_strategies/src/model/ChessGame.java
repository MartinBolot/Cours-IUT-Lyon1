package model;


import java.util.ArrayList;
import java.util.List;

import tools.AbstractSubject;

/*
 * patterns mis en oeuvre :
 *  - Proxy
 *  - 
 */
public class ChessGame extends AbstractSubject implements BoardGames {
	public ChessGame() {
		this.echiquier = new Echiquier();
		this.saveState();
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
				this.saveState();
			}
		}
		this.notifyObservers(echiquier.getPieceIHMs());
		return moveDone;
	}
	
	public void undoMove() {
		this.echiquier = this.states.get(this.states.size()-2);
		this.notifyObservers(echiquier.getPieceIHMs());
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
	
	private void saveState() {
		if(this.states.size() == MAX_SIZE) {
			this.states.remove(0);
		}
		this.states.add((Echiquier) this.echiquier.clone());
		System.out.println(this.states);
	}
	
	private Echiquier echiquier;
	private List<Echiquier> states = new ArrayList<Echiquier>();
	private final int MAX_SIZE = 10;
}
