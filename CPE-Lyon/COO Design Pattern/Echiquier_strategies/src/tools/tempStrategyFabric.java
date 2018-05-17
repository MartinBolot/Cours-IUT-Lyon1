package tools;

import strategies.*;

public class tempStrategyFabric {
	public static ComportementPieces getComportement(int x, int y, String ownClass) {
		System.out.println(ownClass);
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
			try {
				comportement = (ComportementPieces) Class.forName("strategies.Comportement" + ownClass).newInstance();
			}
			catch(Exception e) {
				e.printStackTrace();
				comportement = null;
			}
		}
		return comportement;
	}
}
