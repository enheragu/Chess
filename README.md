# Chess
This is still work in progress. Our intention is to create a two player Chess programmed in C++ (POO structure) without using bitmaps. Our code is based in Shannon codification proposal (extended with "error" cells). This work is for an university project

We codificate the chessboard in a 8x8 matrix whose cells will contain and integer variable (int) wich codificates what is contained in that cell. 

	     Blancas			   Pieza		Negras
		0			Empty cell  	  	   0
		1			Non moved pawn		  -1
		2			Moved pawn      	  -2   
		3			Knights				  -3
		4			Bishops			  	  -4
		5			Non moved rooks		  -5
		6			Moved rooks 		  -6
		7			Queen			  	  -7
		8			Non moved king		  -8
		9			Moved king		  	  -9


	
We are sorry because the project itself is written in spanish as it is for a university work for UPM (Universidad Politecnica de Madrid). Anyway we hope anyone can understand the code.

We use openGl to produce the graphics (glut.h library). Our intention is to separate the logic part of the game from the graphics so it is easy to change the graphic interface from ours to another. The function that goes as interface between logic and graphics is in "Ajedrez/src/Logico/LogicaAjedrez.cpp" and it's named "jugadaAjedrez()", it just need the origin and destination coordinates in a struc (syntax specified in the code).

Work done by Enrique Heredia Aguado and Pilar López Ruescas
	
