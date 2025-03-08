#include <iostream>
#include <string>
#define N 2000

using namespace std;

int n = 0, lastKm[N], key;
double kilometraj[N];
string matricol[N];

string aux2;
string newMatricol[2000];

int main()
{

    cout << "\n---- Registru flota masini, Service Ford Baneasa ---- \n \n";
    cout << "1. Adaugarea unei noi masini \n";
    cout << "2. Afisarea listei cu masini \n";
    cout << "3. Afisarea masinilor care necesita revizie (masini care au depasit 15 000 de km de la ultima revizie) \n";
    cout << "4. Filtrarea masinilor dupa un interval de kilometraj (vei introduce un kilometraj minim si maxim). \n";
    cout << "5. Actualizarea kilometrajului (vei introduce numarul de inmatriculare al masinii pentru care dorim sa actualizam kilometrajul) \n";
    cout << "6. Stergerea unei masini dupa numarul de inmatriculare \n";
    cout << "7. Sortarea masinilor dupa kilometraj, in ordine crescatoare \n";
    cout << "8. Afisarea masinii (masinilor) cu cel mai mare numar de km, respectiv cu cel mai mic nr de km \n";
    cout << "9. Calcularea numarului mediu de km al tuturor masinilor \n";
    cout << "0. Iesire din program \n \n";

    do {
        cout << endl;
        cout << "Selecteaza optiune: ";
        cin >> key;
        cin.ignore();

        switch (key)
        {
            case 1:
                {
                    cout << "Introduceti numarul de inmatriculare al masinii:";
                    cin >> matricol[n];
                    cin.ignore();
                    cout << "Introduceti kilometrajul masinii:";
                    cin >> kilometraj[n];
                    cin.ignore();
                    cout << "Introduceti kilometrii de la ultima revizie:";
                    cin >> lastKm[n];
                    cin.ignore();
                    n++;
                    break;
                }

            case 2:
                {
                    if (n == 0)
                    {
                        cout << "Nu exista nicio masina in flota! \n";
                        break;
                    }
                    else {
                        for (int i = 0; i < n; i++) cout << "Masina " << i+1 << " cu nr de inmatriculare " << matricol[i] << ", kilometraj " << kilometraj[i] << "km, si cu " << lastKm[i] << "km de la ultima revizie \n";
                        cout << "\n";
                    }
                    break;
                }

            case 3:
                {
                    if (n == 0)
                    {
                        cout << "Nu exista nicio masina in flota! \n";
                        break;
                    }
                    else {
                        bool gasit = false;
                        for (int i = 0; i < n; i++)
                        {
                            if (lastKm[i] > 15000)
                            {
                                if (!gasit) gasit = true;
                                cout << "Masina " << i+1 << " cu nr de inmatriculare " << matricol[i] << " are nevoie de revizie (" << lastKm[i] << "km de la ultima revizie) \n";
                            }
                        }
                        if (gasit == false) if (n == 0) cout << "Nicio masina nu are nevoie de revizie! \n";
                        cout << "\n";
                     }
                    break;
                }

            case 4:
                {
                    if (n == 0)
                    {
                        cout << "Nu exista nicio masina in flota! \n";
                        break;
                    }

                    int minim, maxim;
                    cout << "Introduceti minimul: ";
                    cin >> minim;
                    cout << "Introduceti maximul: ";
                    cin >> maxim;
                    if (minim > maxim)
                    {
                        cout << "Valori invalide! \n";
                        break;
                    }

                    for (int i = 0; i < n; i++)
                    {
                        if (kilometraj[i] >= minim && kilometraj[i] <= maxim) cout << "Masina " << i+1 << " cu nr de inmatriculare " << matricol[i] << " indeplineste conditiile \n";
                    }
                    break;
                }

            case 5:
                {
                    if (n == 0)
                    {
                        cout << "Nu exista nicio masina in flota! \n";
                        break;
                    }

                    string cautare;
                    cout << "Introduceti numarul de inmatriculare al masinii:";
                    cin >> cautare;

                    bool gasit = false;

                    for (int i = 0; i < n; i++)
                    {
                        if (matricol[i] == cautare)
                        {
                            cout << "Masina gasita! \n \n";
                            cout << "Introduceti noul kilometraj al masinii:";
                            cin >> kilometraj[i];
                            gasit = true;
                            break;
                        }
                    }
                    if (!gasit) cout << "Nicio masina nu are nr matricol " << cautare << "! \n";
                    break;
                }

            case 6:
                {
                    if (n == 0)
                    {
                        cout << "Nu exista nicio masina in flota! \n";
                        break;
                    }

                    string cautare;
                    cout << "Introduceti numarul de inmatriculare al masinii:";
                    cin >> cautare;

                    bool gasit = false;

                    for (int i = 0; i < n; i++)
                    {
                        if (matricol[i] == cautare)
                        {
                            int j = i;
                            for (j = i; i < n - 1; i++)
                            {
                                kilometraj[j] = kilometraj[j+1];
                                lastKm[j] = lastKm[j+1];
                                matricol[j] = matricol[j+1];
                            }
                            kilometraj[j] = 0;
                            lastKm[j] = 0;
                            matricol[j] = ' ';
                            n--;
                            cout << "Masina stearsa din registru! \n";
                            gasit = true;
                            break;
                        }
                    }
                    if (!gasit) cout << "Nicio masina nu are nr matricol " << cautare << "! \n";
                    break;
                }

            case 7:
                {
                    if (n == 0)
                    {
                        cout << "Nu exista nicio masina in flota! \n";
                        break;
                    }

                    int aux;
                    double newKilometraj[N];


                    for (int i = 0; i < n; i++)
                    {
                        newMatricol[i] = matricol[i];
                        newKilometraj[i] = kilometraj[i];
                    }

                    for (int i = 0; i < n; i++)
                    {
                        for (int j = i+1; j < n; j++)
                        {
                            if (newKilometraj[i] > newKilometraj[j])
                            {
                                aux = newKilometraj[i];
                                newKilometraj[i] = newKilometraj[j];
                                newKilometraj[j] = aux;

                                aux2 = newMatricol[i];
                                newMatricol[i] = newMatricol[j];
                                newMatricol[j] = aux2;
                            }
                        }
                    }
                    cout << "Lista ordonata dupa kilometraj: \n";
                    for (int i = 0; i < n; i++) cout << "Masina cu nr de inmatriculare " << newMatricol[i] << ", kilometraj " << newKilometraj[i] << "\n";
                    cout << endl;
                    break;
                }

            case 8:
            {
                int minim = 99999999, maxim = 0;
                int id;

                for (int i = 0; i < n; i++)
                {
                    if (kilometraj[i] < minim)
                    {
                        minim = kilometraj[i];
                        id = i;
                    }
                    if (kilometraj[i] > maxim)
                    {
                        maxim = kilometraj[i];
                        id = i;
                    }
                }

                cout << "Kilometrajul minim este detinut de masina cu nr de inmatriculare " << matricol[id] << " cu valoarea de " << minim << "\n";
                cout << "Kilometrajul maxim este detinut de masina cu nr de inmatriculare " << matricol[id] << " cu valoarea de " << maxim << "\n \n";
                break;
            }

            case 9:
                {
                    double suma = 0;
                    double nrMasini = n;
                    for (int i = 0; i < n; i++) suma += kilometraj[i];
                    double medie = suma / nrMasini;

                    cout << "Media de kilometraj a masinilor este de " << medie << "km \n";
                }

            case 0:
                {
                    cout << "Iesire din program.";
                    break;
                }

            default:
                cout << "Tasta invalida! \n";

        }

    } while(key != 0);

    return 0;
}
