package strategies;

import model.Couleur;

public class ComportementTour implements ComportementPieces {

	@Override
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible, Couleur couleur, boolean premierCoup) {
		
		boolean ret = false;
		
		if ((yFinal == yInit) || (xFinal == xInit)) {
			ret = true;
		}
		
		return ret;
	}

}
