package model;
	/**
	 * Cette interface permet de réduire l'interface de Pieces  
	 * en ne donnant que des getters
	 */
public interface PieceIHMs {
		
		/**
		 * @return indice de la colonne où est positionnée la piece
		 */
		public int getX();
		
		/**
		 * @return indice de la ligne où est positionnée la piece
		 */
		public int getY();
		
		/**
		 * @return couleur de la piece
		 */
		public Couleur getCouleur();
		

		/**
		 * @return le nom de la pièce
		 *
		 */
		public String getNamePiece();
		
		@Override
		public String toString();
		
}
