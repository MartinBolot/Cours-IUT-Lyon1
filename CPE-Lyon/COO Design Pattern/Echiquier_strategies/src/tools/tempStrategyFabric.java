package tools;

import strategies.*;

public class tempStrategyFabric {
	public static ComportementPieces getComportement(int x, int y, String ownClass) {
		ComportementPieces comportement = null;
		if(x == 0 || x == 7) {
			comportement = new ComportementTour();
		}
		else if(x == 1 || x == 6) {
			comportement = new ComportementCavalier();
		}
		else if(x == 2 || x == 5) {
			comportement = new ComportementFou();
		}
		else {
			comportement = tempStrategyFabric.getInitialComportement(ownClass);
		}
		return comportement;
	}
	
	public static ComportementPieces getInitialComportement(String ownClass) {
		ComportementPieces comportement = null;
		try {
			comportement = (ComportementPieces) Class.forName("strategies.Comportement" + ownClass).newInstance();
		}
		catch(Exception e) {
			e.printStackTrace();
			comportement = null;
		}
		return comportement;
	}
}
