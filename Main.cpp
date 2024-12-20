int main() {
    Grafo<string> mappaMilitare;

    mappaMilitare.aggiungiNodo("COMANDO");
    mappaMilitare.aggiungiNodo("DCM");
    mappaMilitare.aggiungiNodo("DS");
    mappaMilitare.aggiungiNodo("DIPARTIMENTO");
    mappaMilitare.aggiungiNodo("CORPO DI GUARDIA");

    mappaMilitare.aggiungiArco("COMANDO", "DCM", 1);
    mappaMilitare.aggiungiArco("COMANDO", "DS", 2);
    mappaMilitare.aggiungiArco("DCM", "DIPARTIMENTO", 1);
    mappaMilitare.aggiungiArco("DS", "DIPARTIMENTO", 3);
    mappaMilitare.aggiungiArco("DIPARTIMENTO", "CORPO DI GUARDIA", 2);
    mappaMilitare.aggiungiArco("CORPO DI GUARDIA", "COMANDO", 4);

    mappaMilitare.stampa();

    cout << "Esiste la postazione 'DS'? " << (mappaMilitare.verificaNodo("DS") ? "Sì" : "No") << endl;

    cout << "Esiste un percorso tra 'COMANDO' e 'DCM'? " << (mappaMilitare.verificaArco("COMANDO", "DCM") ? "Sì" : "No") << endl;
    cout << "Esiste un percorso tra 'COMANDO' e 'DIPARTIMENTO'? " << (mappaMilitare.verificaArco("COMANDO", "DIPARTIMENTO") ? "Sì" : "No") << endl;

    mappaMilitare.nodiAdiacenti("COMANDO");

    mappaMilitare.rimuoviArco("COMANDO", "DCM");
    cout << "Matrice dopo la rimozione del percorso tra 'COMANDO' e 'DCM':" << endl;
    mappaMilitare.stampa();

    mappaMilitare.rimuoviNodo("DS");
    cout << "Matrice dopo la rimozione della postazione 'DS':" << endl;
    mappaMilitare.stampa();

    mappaMilitare.aggiungiNodo("PALESTRA");
    mappaMilitare.aggiungiArco("CORPO DI GUARDIA", "PALESTRA", 5);
    cout << "Matrice dopo l'aggiunta di 'PALESTRA' e del percorso tra 'CORPO DI GUARDIA' e 'PALESTRA':" << endl;
    mappaMilitare.stampa();

    cout << "La postazione 'COMANDO' è connessa alla postazione 'CORPO DI GUARDIA'? " 
         << (mappaMilitare.verificaArco("COMANDO", "CORPO DI GUARDIA") ? "Sì" : "No") << endl;

    int percorsoMinimo = mappaMilitare.percorsoConPesoMinore("CORPO DI GUARDIA");
    if (percorsoMinimo != -1) {
        cout << "Il percorso con il peso minimo da 'CORPO DI GUARDIA' ha un tempo di: " << percorsoMinimo << " minuti." << endl;
    } else {
        cout << "Non ci sono percorsi uscenti da 'CORPO DI GUARDIA'." << endl;
    }

    return 0;
}
