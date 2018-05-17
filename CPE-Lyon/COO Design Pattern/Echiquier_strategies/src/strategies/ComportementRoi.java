package strategies;

import model.Couleur;

public class ComportementRoi implements ComportementPieces {

	@Override
	public boolean isMoveOk(int xInit, int yInit, int xFinal, int yFinal, boolean isCatchOk,
			boolean isCastlingPossible, Couleur couleur, boolean premierCoup) {
		boolean ret = false;
		
		if ((Math.abs(yFinal - yInit) <= 1)
				&& (Math.abs(xFinal - xInit) <= 1)) {
			ret = true;
		}
		
		
		return ret;
	}

}
