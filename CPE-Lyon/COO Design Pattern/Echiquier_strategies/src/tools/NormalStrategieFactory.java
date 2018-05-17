package tools;

import strategies.ComportementPieces;

public class NormalStrategieFactory implements ModeFactory {

	@Override
	public ComportementPieces getComportement(int x, int y, String ownClass) {
		return this.getInitialComportement(ownClass);
	}

	@Override
	public ComportementPieces getInitialComportement(String ownClass) {
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
