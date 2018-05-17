package strategies;

import model.Couleur;

public interface ComportementPieces {
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible, Couleur couleur, boolean premierCoup);
}
