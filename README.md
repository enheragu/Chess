# Chess
This is still work in progress. Our intention is to create a two player Chess programmed in C++ (POO structure) without using bitmaps. Our code is based in Shannon codification proposal (extended with "error" cells). This work is for an university project

We codificate the chessboard in a 10x12 matrix whose cells will contain and integer variable (int) wich codificates what is it that cell. 

	     Blancas			   Pieza		Negras
		0			Empty cell  	  	   0
		1			Non moved pawn		  -1
		2			Moved pawn      	  -2   (2 cells	forward)
		3			Knights			  -3
		4			Bishops			  -4
		5			Non moved rooks		  -5
		6			Moved rooks 		  -6
		7			Queen			  -7
		8			Non moved king		  -8
		9			Moved king		  -9
		255   Restricted cell     255

	
(There are some of the pieces wich are codificated with two numbers, this happends to allow some special moves as Castling, En passant, etc.)
	
We are sorry because the project itself is written in spanish as it is for UPM (Universidad Politecnica de Madrid). Anyway we hope anyone can understand the code.
	
