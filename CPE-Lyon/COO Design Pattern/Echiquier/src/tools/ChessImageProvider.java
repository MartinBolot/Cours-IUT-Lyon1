package tools;

import java.io.File;
import java.util.HashMap;
import java.util.Map;
import model.Couleur;

/**
 * @author francoise.perrin
 * Inspiration Jacques SARAYDARYAN, Adrien GUENARD
 * 
 * Cette classe s'appuie sur ChessPieceImage
 * pour fournir les noms des images des pièces
 * qui sont utilisées dans l'IHM 
 *  
 */
public class ChessImageProvider {
	
	private static Map<String, String> mapImage;

	static {		
		mapImage = new HashMap<String, String>();
		for (int i = 0; i < ChessPieceImage.values().length; i++) {
			mapImage.put(ChessPieceImage.values()[i].nom, ChessPieceImage.values()[i].imageFile);
		}	
	}

	/**
	 * private pour ne pas instancier d'objets
	 */
	private ChessImageProvider() {

	}	
	
	/**
	 * @param pieceType
	 * @param pieceCouleur
	 * @return nom fichier contenant image de la pi�ce
	 */
	public static String getImageFile(String pieceType, Couleur pieceCouleur){
		String ret, key, value;
		ret = null;
		key = pieceType + pieceCouleur.name();
		value = mapImage.get(key);
		File g=new File("");
		ret = g.getAbsolutePath()+"\\images\\" + value;
		return ret;		
	}

	/**
	 * Test unitaires
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println(ChessImageProvider.getImageFile("Cavalier", Couleur.BLANC));
	}

}
