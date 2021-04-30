// Sudoko Resolver OOB.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Playboard.h"
#include <chrono>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	Playboard myplayboard;

	myplayboard.setupBoard();

	//row 0
	//myplayboard.setNumber(1, 0, 2, false);
	//myplayboard.setNumber(3, 0, 1, false);
	//myplayboard.setNumber(4, 0, 7, false);
	//myplayboard.setNumber(5, 0, 8, false);
	//myplayboard.setNumber(7, 0, 3, false);
	////row 1
	//myplayboard.setNumber(1, 1, 4, false);
	//myplayboard.setNumber(3, 1, 3, false);
	//myplayboard.setNumber(5, 1, 2, false);
	//myplayboard.setNumber(7, 1, 9, false);
	////row 2
	//myplayboard.setNumber(0, 2, 1, false);
	//myplayboard.setNumber(8, 2, 6, false);
	//
	////row 3
	//myplayboard.setNumber(2, 3, 8, false);
	//myplayboard.setNumber(3, 3, 6, false);
	//myplayboard.setNumber(5, 3, 3, false);
	//myplayboard.setNumber(6, 3, 5, false);
	////row4
	//myplayboard.setNumber(0, 4, 3, false);
	//myplayboard.setNumber(8, 4, 4, false);
	////row5
	//myplayboard.setNumber(2, 5, 6, false);
	//myplayboard.setNumber(3, 5, 7, false);
	//myplayboard.setNumber(5, 5, 9, false);
	//myplayboard.setNumber(6, 5, 2, false);
	//
	////row6
	//myplayboard.setNumber(0, 6, 9, false);
	//myplayboard.setNumber(8, 6, 2, false);
	////row7
	//myplayboard.setNumber(1, 7, 8, false);
	//myplayboard.setNumber(3, 7, 9, false);
	//myplayboard.setNumber(5, 7, 1, false);
	//myplayboard.setNumber(7, 7, 6, false);
	////row8
	//myplayboard.setNumber(1, 8, 1, false);
	//myplayboard.setNumber(3, 8, 4, false);
	//myplayboard.setNumber(4, 8, 3, false);
	//myplayboard.setNumber(5, 8, 6, false);
	//myplayboard.setNumber(7, 8, 5, false);

	//udoku try 2
	//row0
	//myplayboard.setNumber(3, 0, 6, false);
	//myplayboard.setNumber(5, 0, 1, false);
	//myplayboard.setNumber(8, 0, 9, false);
	////row1
	//myplayboard.setNumber(1, 1, 6, false);
	//myplayboard.setNumber(5, 1, 3, false);
	//myplayboard.setNumber(8, 1, 2, false);
	////row2
	//myplayboard.setNumber(5, 2, 2, false);
	//myplayboard.setNumber(6, 2, 3, false);
	//myplayboard.setNumber(7, 2, 6, false);
	////row3
	//myplayboard.setNumber(0, 3, 2, false);
	//myplayboard.setNumber(4, 3, 1, false);
	////row4
	//myplayboard.setNumber(2, 4, 4, false);
	//myplayboard.setNumber(3, 4, 5, false);
	//myplayboard.setNumber(4, 4, 2, false);
	//myplayboard.setNumber(7, 4, 8, false);
	////row5
	//myplayboard.setNumber(1, 5, 5, false);
	//myplayboard.setNumber(3, 5, 9, false);
	//myplayboard.setNumber(4, 5, 4, false);
	////row6
	//myplayboard.setNumber(3, 6, 8, false);
	//myplayboard.setNumber(4, 6, 3, false);
	//myplayboard.setNumber(8, 6, 6, false);
	////row7
	//myplayboard.setNumber(1, 7, 3, false);
	//myplayboard.setNumber(3, 7, 1, false);
	//myplayboard.setNumber(6, 7, 2, false);
	//myplayboard.setNumber(7, 7, 9, false);
	//myplayboard.setNumber(8, 7, 7, false);
	////row8
	//myplayboard.setNumber(7, 8, 3, false);
	//
	//Sudoku try 3
	// row0
	myplayboard.setNumber(2, 0, 4, false);
	myplayboard.setNumber(3, 0, 6, false);
	myplayboard.setNumber(7, 0, 2, false);
	//row1
	myplayboard.setNumber(6, 1, 3, false);
	//row2
	myplayboard.setNumber(0, 2, 8, false);
	myplayboard.setNumber(1, 2, 9, false);
	myplayboard.setNumber(2, 2, 2, false);
	myplayboard.setNumber(5, 2, 1, false);
	myplayboard.setNumber(7, 2, 7, false);
	myplayboard.setNumber(8, 2, 6, false);
	//row3
	myplayboard.setNumber(1, 3, 8, false);
	myplayboard.setNumber(2, 3, 7, false);
	myplayboard.setNumber(3, 3, 1, false);
	myplayboard.setNumber(5, 3, 2, false);
	//row4
	myplayboard.setNumber(1, 4, 6, false);
	myplayboard.setNumber(8, 4, 7, false);
	//row5
	myplayboard.setNumber(1, 5, 4, false);
	myplayboard.setNumber(2, 5, 1, false);
	myplayboard.setNumber(4, 5, 7, false);
	myplayboard.setNumber(5, 5, 6, false);
	
#	//row6
	myplayboard.setNumber(3, 6, 9, false);
	myplayboard.setNumber(4, 6, 8, false);
	
	//row7
	myplayboard.setNumber(5, 7, 4, false);
	//row8
	myplayboard.setNumber(1, 8, 5, false);
	myplayboard.setNumber(2, 8, 3, false);
	myplayboard.setNumber(4, 8, 6, false);
	myplayboard.setNumber(8, 8, 9, false);




	myplayboard.solveSudoku();
	myplayboard.showBoard();
	//myplayboard.print_numbers_with_only_one_candidate();
	std::cout << "ENDE";
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
