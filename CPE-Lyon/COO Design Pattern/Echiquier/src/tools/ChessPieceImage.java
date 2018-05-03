package tools;


/**
 * @author francoise.perrin
 *
 */
public enum ChessPieceImage {

	TOURBLANC("TourBLANC", "tourBlancS.png"),
	CAVALIERBLANC("CavalierBLANC", "cavalierBlancS.png"), 
	FOUBLANC("FouBLANC",  "fouBlancS.png"), 
	REINEBLANC("ReineBLANC", "reineBlancS.png"), 
	ROIBLANC("RoiBLANC", "roiBlancS.png"),
	PIONBLANC("PionBlancBLANC", "pionBlancS.png"),
	//PIONBLANC("PionBLANC", "pionBlancS.png"),
			
	TOURNOIR("TourNOIR", "tourNoireS.png"),
	CAVALIERNOIR("CavalierNOIR", "cavalierNoirS.png"), 
	FOUNOIR( "FouNOIR", "fouNoirS.png"), 
	REINENOIR("ReineNOIR", "reineNoireS.png"), 
	ROINOIR("RoiNOIR", "roiNoirS.png"),
	PIONNOIR("PionNoirNOIR", "pionNoirS.png")   
	//PIONNOIR("PionNOIR", "pionNoirS.png")   
	; 
	
	
	
	public String nom;
	public  String imageFile ;   

	ChessPieceImage(String nom,  String imageFile) { 
		this.nom = nom;
		this.imageFile = imageFile;
	} 


	public static void main(String[] args) {
		for (int i = 0; i < ChessPieceImage.values().length; i++) {
			System.out.print(ChessPieceImage.values()[i].nom + " \t"); 
			System.out.print(ChessPieceImage.values()[i].imageFile + " \t"); 
			System.out.println();
		}
	}
}

