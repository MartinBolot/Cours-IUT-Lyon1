package strategies;

import model.Couleur;

public class ComportementReine implements ComportementPieces {

	@Override
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible, Couleur couleur, boolean premierCoup) {
		
		boolean ret = false;
		
		if (Math.abs(yFinal - yInit) == Math.abs(xFinal - xInit)
				|| ((yFinal == yInit) || (xFinal == xInit))) {
			ret =  true;
		}
		
		return ret;
	}

}
