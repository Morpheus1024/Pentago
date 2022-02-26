#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool czy_wygrana(string player1, string player2, vector<vector<vector<char>>> plansza, int& stan, int runda, char zeton_player1, char zeton_player2)
{
    if (runda % 2 == 1) stan = 1;
    else if (runda % 2 == 0) stan = 2;

    if (runda > 36) // sprawdzenie remisu 1.
    {
        stan = 3;
        return false;
    }
    else if (runda > 1)
    {
        //sprawdzenie "ukosnych" warunkow z lewej do prawej
        if ((plansza[0][2][2] != ' ') && (plansza[0][0][0] == plansza[0][1][1]) && (plansza[0][1][1] == plansza[0][2][2]) && (plansza[0][2][2] == plansza[3][0][0]) && (plansza[3][0][0] == plansza[3][1][1])) return false;
        else if ((plansza[2][0][0] != ' ') && (plansza[0][1][0] == plansza[0][2][1]) && (plansza[0][2][1] == plansza[2][0][0]) && (plansza[2][0][0] == plansza[3][1][0]) && (plansza[3][1][0] == plansza[3][2][1])) return false;
        else if ((plansza[1][2][0] != ' ') && (plansza[0][0][1] == plansza[0][1][2]) && (plansza[0][1][2] == plansza[1][2][0]) && (plansza[1][2][0] == plansza[3][0][1]) && (plansza[3][0][1] == plansza[3][1][2])) return false;
        else if ((plansza[3][0][0] != ' ') && (plansza[0][1][1] == plansza[0][2][2]) && (plansza[0][2][2] == plansza[3][0][0]) && (plansza[3][0][0] == plansza[3][1][1]) && (plansza[3][1][1] == plansza[3][2][2])) return false;
        //sprawdzenie "ukosnych" warunkow z prawej do lewej
        else if ((plansza[1][2][0] != ' ') && (plansza[1][0][2] == plansza[1][1][1]) && (plansza[1][1][1] == plansza[1][2][0]) && (plansza[1][2][0] == plansza[2][0][2]) && (plansza[2][0][2] == plansza[2][1][1])) return false;
        else if ((plansza[3][0][0] != ' ') && (plansza[1][1][2] == plansza[1][2][1]) && (plansza[1][2][1] == plansza[3][0][0]) && (plansza[3][0][0] == plansza[1][1][2]) && (plansza[1][1][2] == plansza[1][2][1])) return false;
        else if ((plansza[0][2][2] != ' ') && (plansza[1][0][1] == plansza[1][1][0]) && (plansza[1][1][0] == plansza[0][2][2]) && (plansza[0][2][2] == plansza[2][0][1]) && (plansza[2][0][1] == plansza[2][1][0])) return false;
        else if ((plansza[2][0][2] != ' ') && (plansza[1][1][1] == plansza[1][2][0]) && (plansza[1][2][0] == plansza[2][0][2]) && (plansza[2][0][2] == plansza[2][1][1]) && (plansza[2][1][1] == plansza[2][2][0])) return false;

        for (int i = 0; i < 3; i++)
        {
            //sprawdzanie "poziomych" warunkow
            if ((plansza[0][i][2] != ' ') && (plansza[0][i][0] == plansza[0][i][1]) && (plansza[0][i][1] == plansza[0][i][2]) && (plansza[0][i][2] == plansza[1][i][0]) && (plansza[1][i][0] == plansza[1][i][1])) return false;
            else if ((plansza[2][i][2] != ' ') && (plansza[2][i][0] == plansza[2][i][1]) && (plansza[2][i][1] == plansza[2][i][2]) && (plansza[2][i][2] == plansza[3][i][0]) && (plansza[3][i][0] == plansza[3][i][1])) return false;
            else if ((plansza[1][i][0] != ' ') && (plansza[0][i][1] == plansza[0][i][2]) && (plansza[0][i][2] == plansza[1][i][0]) && (plansza[1][i][0] == plansza[1][i][1]) && (plansza[1][i][0] == plansza[1][i][1])) return false;
            else if ((plansza[3][i][0] != ' ') && (plansza[2][i][1] == plansza[2][i][2]) && (plansza[2][i][2] == plansza[3][i][0]) && (plansza[3][i][0] == plansza[3][i][1]) && (plansza[3][i][0] == plansza[3][i][1])) return false;
            //sprawdzenie "pionowych" warunkow
            else if ((plansza[0][2][i] != ' ') && (plansza[0][0][i] == plansza[0][1][i]) && (plansza[0][1][i] == plansza[0][2][i]) && (plansza[0][2][i] == plansza[2][0][i]) && (plansza[2][0][i] == plansza[2][1][i])) return false;
            else if ((plansza[1][2][i] != ' ') && (plansza[1][0][i] == plansza[1][1][i]) && (plansza[1][1][i] == plansza[1][2][i]) && (plansza[1][2][i] == plansza[3][0][i]) && (plansza[3][0][i] == plansza[3][1][i])) return false;
            else if ((plansza[2][0][i] != ' ') && (plansza[0][1][i] == plansza[0][2][i]) && (plansza[0][2][i] == plansza[2][0][i]) && (plansza[2][0][i] == plansza[2][1][i]) && (plansza[2][1][i] == plansza[2][2][i])) return false;
            else if ((plansza[1][0][i] != ' ') && (plansza[1][1][i] == plansza[1][2][i]) && (plansza[1][2][i] == plansza[3][0][i]) && (plansza[3][0][i] == plansza[3][1][i]) && (plansza[3][1][i] == plansza[3][2][i])) return false;

        }
    }
    else //sprawdzenie remisu 2.
    {
        unsigned n = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (plansza[i][j][k] != ' ') n++;
                }
            }
        }
        if (n == 36)
        {
            stan = 3;
            return false;
        }

    }
        return true;
}

void przesuniecie_Y(int Y)
{
    for (int i = 0; i < Y; i++)
    {
        cout << endl;
    }
}

void rysowanie_planszy(int wybor, int runda, string player1, string player2, vector<vector<vector<char>>> pole, char zeton_player1, char zeton_player2)
{
    string dX1 = " "; 
    int X = 0;// odleglosc pozioma od krawedzi i miedzy ramkami. MAX= 25
    int Y = 0; //odleglosc pionowa miedzy planszami. MAX=5;

    if(X>0)
    {
        for (int i = 0; i < X; i++)
        {
            dX1 = dX1 + " ";
        }
    }

    cout <<endl<< "Runda " << runda << "." << endl;

    if (runda % 2 != 0) cout << "Runda gracza " << player1 << endl << endl;
    else cout << "Runda gracza " << player2 << endl << endl;

    const char rog_lg = 201;//╔
    const char rog_pg = 187;//╗
    const char rog_ld = 200;//╚
    const char rog_pd = 188;//╝

    const char T_g = 203;//╦
    const char T_d = 202;//╩
    const char T_l = 204;//╠
    const char T_p = 185;//╣

    const char pozioma = 205; //═
    const char pionowa = 186;//║

    const char krzyz = 206;//╬

        cout << "   "<<dX1 << rog_lg << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << rog_pg << " " <<dX1<< rog_lg << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << rog_pg << endl;
        cout << "   " <<dX1<< pionowa << " " << pole[0][0][0] << " " << pionowa << " " << pole[0][0][1] << " " << pionowa << " " << pole[0][0][2] << " " << pionowa << " " << dX1 << pionowa << " " << pole[1][0][0] << " " << pionowa << " " << pole[1][0][1] << " " << pionowa << " " << pole[1][0][2] << " " << pionowa << " " << endl;
        cout << "   " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << " " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << endl;
        cout << "   " << dX1 << pionowa << " " << pole[0][1][0] << " " << pionowa << " " << pole[0][1][1] << " " << pionowa << " " << pole[0][1][2] << " " << pionowa << " " << dX1 << pionowa << " " << pole[1][1][0] << " " << pionowa << " " << pole[1][1][1] << " " << pionowa << " " << pole[1][1][2] << " " << pionowa << " " << endl;
        cout << "   " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << " " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << endl;
        cout << "   " << dX1 << pionowa << " " << pole[0][2][0] << " " << pionowa << " " << pole[0][2][1] << " " << pionowa << " " << pole[0][2][2] << " " << pionowa << " " << dX1 << pionowa << " " << pole[1][2][0] << " " << pionowa << " " << pole[1][2][1] << " " << pionowa << " " << pole[1][2][2] << " " << pionowa << " " << endl;
        cout << "   " << dX1 << rog_ld << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << rog_pd << " " << dX1 << rog_ld << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << rog_pd << endl;
        przesuniecie_Y(Y);
        cout << "   " << dX1 << rog_lg << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << rog_pg << " " << dX1 << rog_lg << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << T_g << pozioma << pozioma << pozioma << rog_pg << endl;
        cout << "   " << dX1 << pionowa << " " << pole[2][0][0] << " " << pionowa << " " << pole[2][0][1] << " " << pionowa << " " << pole[2][0][2] << " " << pionowa << " "  << dX1 << pionowa << " " << pole[3][0][0] << " " << pionowa << " " << pole[3][0][1] << " " << pionowa << " " << pole[3][0][2] << " " << pionowa << " " << endl;
        cout << "   " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << " " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << endl;
        cout << "   " << dX1 << pionowa << " " << pole[2][1][0] << " " << pionowa << " " << pole[2][1][1] << " " << pionowa << " " << pole[2][1][2] << " " << pionowa << " "  << dX1 << pionowa << " " << pole[3][1][0] << " " << pionowa << " " << pole[3][1][1] << " " << pionowa << " " << pole[3][1][2] << " " << pionowa << " " << endl;
        cout << "   " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << " " << dX1 << T_l << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << krzyz << pozioma << pozioma << pozioma << T_p << endl;
        cout << "   " << dX1 << pionowa << " " << pole[2][2][0] << " " << pionowa << " " << pole[2][2][1] << " " << pionowa << " " << pole[2][2][2] << " " << pionowa << " " << dX1 << pionowa << " " << pole[3][2][0] << " " << pionowa << " " << pole[3][2][1] << " " << pionowa << " " << pole[3][2][2] << " " << pionowa << " " << endl;
        cout << "   " << dX1 << rog_ld << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << rog_pd << " " << dX1 << rog_ld << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << T_d << pozioma << pozioma << pozioma << rog_pd << endl << endl;

        cout << player1 << " - zeton: " << zeton_player1 << endl;
        cout << player2 << " - zeton: " << zeton_player2 << endl<<endl;
}

void zapis_planszy(vector<vector<vector<char>>> pole, vector<vector<vector<char>>>& pop_plansza_1, vector<vector<vector<char>>>& pop_plansza_2, vector<vector<vector<char>>>& pop_plansza_3, vector<vector<vector<char>>>& pop_plansza_4)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                pop_plansza_4[i][j][k] = pop_plansza_3[i][j][k];
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
               pop_plansza_3[i][j][k] = pop_plansza_2[i][j][k];
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                pop_plansza_2[i][j][k] = pop_plansza_1[i][j][k];
            }
        }
    }
  
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                pop_plansza_1[i][j][k] = pole[i][j][k];
            }
        }
    }
}

void ruch_gracza(string IN1, int& plansza, int& wiersz, int& kolumna)
{
    if (IN1.substr(0, 1) == "q") plansza = 0;
    else if (IN1.substr(0, 1) == "w") plansza = 1;
    else if (IN1.substr(0, 1) == "a") plansza = 2;
    else if (IN1.substr(0, 1) == "s") plansza = 3;

    if (IN1.substr(1, 1) == "1")
    {
        wiersz = 2;
        kolumna = 0;
    }
    else if (IN1.substr(1, 1) == "2")
    {
        wiersz = 2;
        kolumna = 1;
    }
    else if (IN1.substr(1, 1) == "3")
    {
        wiersz = 2;
        kolumna = 2;
    }
    else if (IN1.substr(1, 1) == "4")
    {
        wiersz = 1;
        kolumna = 0;
    }
    else if (IN1.substr(1, 1) == "5")
    {
        wiersz = 1;
        kolumna = 1;
    }
    else if (IN1.substr(1, 1) == "6")
    {
        wiersz = 1;
        kolumna = 2;
    }
    else if (IN1.substr(1, 1) == "7")
    {
        wiersz = 0;
        kolumna = 0;
    }
    else if (IN1.substr(1, 1) == "8")
    {
        wiersz = 0;
        kolumna = 1;
    }
    else if (IN1.substr(1, 1) == "9")
    {
        wiersz = 0;
        kolumna = 2;
    }
}

void obrot_z(char& k1, char& k2, char& k3, char& k4, char& k5, char& k6, char& k7, char& k8, char& k9) //k od komórka
{
    char zmiana1, zmiana2, zmiana3, zmiana4, zmiana5, zmiana6, zmiana7, zmiana8, zmiana9;
    zmiana1 = k1;
    zmiana2 = k2;
    zmiana3 = k3;
    zmiana4 = k4;
    zmiana5 = k5;
    zmiana6 = k6;
    zmiana7 = k7;
    zmiana8 = k8;
    zmiana9 = k9;

    k7 = zmiana1;
    k8 = zmiana4;
    k9 = zmiana7;
    k6 = zmiana6;
    k3 = zmiana9;
    k2 = zmiana6;
    k1 = zmiana3;
    k4 = zmiana2;
}

void help(int wybor)
{
    cout << endl << "   HELP:" << endl;
    cout << "Dozwolone ruchy wpływające na rozgrywkę:" << endl;
    cout << "1. <nazwa_planszy><numer_pola>" << endl;
    if (wybor == 2) cout<< "2. <nazwa_planszy><kierunek_obrotu>" << endl;
    cout << "<nazwa_planszy>: {q, w, a, z}" << endl;
    cout << "<numer_pola>: {1-9}" << endl;
    if (wybor == 2)
    {
        cout << "<kierunek_obrotu>: {z, x}" << endl;
        cout << "   z - kierunek zgodny z ruchem wskazuwek zegara" << endl;
        cout << "   x - kierunek przeciwny do kierunku obrotu wskazuwek zegara" << endl << endl;
    }
    cout << "   Inne komendy:" << endl;
    cout << "m - menu opcji" << endl;
    cout << "h - Help - wyświetlenie widzianego aktualnie tekstu z pomocą" << endl << endl;
}

void zmiana_zeton(int runda, char& zeton_player1, char& zeton_player2, vector<vector<vector<char>>>& pole)
{
    char zeton_nowy, z1=' ', z2=' ';
    cout << "podaj nowy symbol zetonu: ";

    if (runda % 2 == 1)
    {
        z1 = zeton_player1;
        z2 = zeton_player2;
    }
    else if (runda % 2 == 0)
    {
        z1 = zeton_player2;
        z2 = zeton_player1;
    }

    do
    {
        cin >> zeton_nowy;
        cout << endl;
        if (z1==zeton_nowy)
        {
            cout << "Twoj nowy zeton jest identyczny jak poprzedni." << endl << "Musi miec inny symbol.Ponow wpisanie : ";
        }
        else if(z2==zeton_nowy)
        {
            cout << "Twoj nowy zeton jest identyczny jak przeciwnika." << endl << "Musicie miec inne zetony.Ponow wpisanie : ";
        }
    } while (zeton_nowy == zeton_player1 || zeton_nowy == zeton_player2);

    if (runda % 2 == 1) zeton_player1 = zeton_nowy;
    else zeton_player2 = zeton_nowy;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (pole[i][j][k] == z1)
                {
                    pole[i][j][k] = zeton_nowy;
                }
            }
        }
    }
}

void Menu(char& menu, unsigned& cofanie, int wybor, int runda, char& zeton_player1, char& zeton_player2, vector<vector<vector<char>>>& pole)
{
    char IN_menu;
    cout << endl << "Dostepne opcje:" << endl;
   // cout << "p - pauza" << endl;
    cout << "u - undo" << endl;
    cout << "o - wczytanie predefiniowanej planszy" << endl;
    cout << "h - wejscie do opisu programu"<<endl;
    cout << "z - zmiana symbolu zetonu na nowy" << endl;

    cin >> IN_menu;
    if (IN_menu == 'o') menu = 1;
    else if (IN_menu == 'u')
    {
        menu = 2;
        cout << "Do ilu rund wstecz chcesz cofnac ruch?";
        cin >> cofanie;
    }
    else if (IN_menu == 'h') help(wybor);
    else if (IN_menu == 'z') zmiana_zeton(runda, zeton_player1, zeton_player2, pole);
    else 
    {
        cout << "Nienznana komenda";
        Menu(menu,cofanie,wybor, runda, zeton_player1, zeton_player2, pole);
    }
}

void wgranie_planszy_pokazowej(vector<vector<vector<char>>>& pole, char player1_zeton, char player2_zeton, int runda)
{
    //zapis planszy pokazowej w wierszach
    const char tab_q_0[] = { ' ','2',' ' };
    const char tab_q_1[] = { '1','1','2' };
    const char tab_q_2[] = { ' ','1',' ' };

    const char tab_w_0[] = { ' ','1',' ' };
    const char tab_w_1[] = { '1','2',' ' };
    const char tab_w_2[] = { ' ',' ',' ' };

    const char tab_a_0[] = { '1','1',' ' };
    const char tab_a_1[] = { '2',' ','1' };
    const char tab_a_2[] = { ' ','2',' ' };

    const char tab_s_0[] = { ' ',' ',' ' };
    const char tab_s_1[] = { ' ','2',' ' };
    const char tab_s_2[] = { ' ','2','2' };

    for (int i = 0; i < 3; i++)
    {
        pole[0][0][i] = tab_q_0[i];
        pole[0][1][i] = tab_q_1[i];
        pole[0][2][i] = tab_q_2[i];

        pole[1][0][i] = tab_w_0[i];
        pole[1][1][i] = tab_w_1[i];
        pole[1][2][i] = tab_w_2[i];

        pole[2][0][i] = tab_a_0[i];
        pole[2][1][i] = tab_a_1[i];
        pole[2][2][i] = tab_a_2[i];

        pole[3][0][i] = tab_s_0[i];
        pole[3][1][i] = tab_s_1[i];
        pole[3][2][i] = tab_s_2[i];
    }

    if (runda % 2 == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (pole[i][j][k] == '1') pole[i][j][k] = player1_zeton;
                    else if (pole[i][j][k] == '2') pole[i][j][k] = player2_zeton;
                }
            }
        }
    }
    else if (runda % 2 == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (pole[i][j][k] == '1') pole[i][j][k] = player2_zeton;
                    else if (pole[i][j][k] == '2') pole[i][j][k] = player1_zeton;
                }
            }
        }
    }
}

void wygrywanie_poprzedniej_planszy(vector<vector<vector<char>>>& pole, vector<vector<vector<char>>> pole_do_zmiany)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                pole[i][j][k] = pole_do_zmiany[i][j][k];
            }
        }
    }
}

void zakonczenie(int stan)
{
    cout << endl << "KONIEC GRY!!!" << endl;
    if (stan == 0);
    else if (stan == 1) cout << "Wygrywa gracz 1.! Gratulacje!";
    else if (stan == 2) cout << "Wygrywa gracz 2.! Gratulacje!";
    else if (stan == 3) cout << "Ogłaszam remis!";
}

int main()
{
    //plansze do zapisu stanu gry
    vector<vector<vector<char>>> pop_plansza_1(4, vector<vector<char> >(3, vector<char>(3)));
    vector<vector<vector<char>>> pop_plansza_2(4, vector<vector<char> >(3, vector<char>(3)));
    vector<vector<vector<char>>> pop_plansza_3(4, vector<vector<char> >(3, vector<char>(3)));
    vector<vector<vector<char>>> pop_plansza_4(4, vector<vector<char> >(3, vector<char>(3)));

    int plansza = 0, wiersz = 0, kolumna = 0;

    //okreslenie do ktorej planszy w tyl sie cofnac
    unsigned cofanie;

    int stan = 0;
    //stan=0 - nikt nie wygrał
    //stan=1 - wygrał player1
    //stan=2 - wygrał player2
    //stan=3 - remis

    //nazwy graczy
    string player1;
    string player2;

    //zetony graczy
    char player1_zeton;
    char player2_zeton;
    
    char menu;

    //zmienna wyboru gry
    int wybor=0;
    string wybor_string;
    int runda = 0;

    string IN1, IN2;

    bool ruch = true;
    bool ruch_1 = true;

    cout << "Witaj w Pentago/kolko i krzyzyk"<<endl<<endl;

    //deklaracja nazwy graczy
    cout << "Niech gracz 1. poda swoja nazwe: ";
    cin >> player1;
    cout << player1 << "! Podaj symbol twojego zetonu: ";
    cin >> player1_zeton;
    cout << "Niech gracz 2. poda swoja nazwe: ";
    cin >> player2;

    while (player2 == player1)
    {
        cout << "Twoje imie nie moze być taki sam jak przeciwnika. Podaj ponownie: ";
        cin >> player2;
    }
    cout << player2 << "! Podaj symbol twojego zetonu: ";
    cin >> player2_zeton;

    while (player2_zeton == player1_zeton)
    {
        cout << player2 << "! Twoj zeton nie moze byc taki sam jak przeciwnika. Podaj ponownie: ";
        cin >> player2_zeton;
    }

    cout << endl << "Witajcie w grze!" << endl << "Wybierz akcje:" << endl;
    cout << "1. Gra w kolko i krzyzyk na planszy 6x6" << endl;
    cout << "2. Pentago" << endl;

    do
    {
         cin >> wybor_string; 
         if (wybor_string != "1" && wybor_string != "2") cout << "Wybor nieprawidlowy. Sprobujcie jeszcze raz: ";
         else cout << endl;
    } while (wybor_string != "1" && wybor_string != "2");
        
    wybor = stoi(wybor_string);

    switch (wybor)
    {
        
        case 1: // kolko i krzyzyk 6x6
        {
            cout << "Wybraliscie kolko i krzyzyk 6x6" << endl<<endl;
            cout << "Zasady:" << endl << "Celem gry jest ulozenie 5 zetonow w jednej linii tj. w jednym rzedzie lub jedej kolumnie lub po przekatnej.";

            vector<vector<vector<char>>> OX(4, vector<vector<char> >(3, vector<char>(3)));
            // OX[plansza][wiersz][kolumna]

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++) OX[i][j][k] = ' ';
                }
            }

            do
            {
                runda++;
                rysowanie_planszy(wybor, runda, player1, player2, OX, player1_zeton, player2_zeton);
                do
                { 
                    cout << "Komenda: ";
                    cin >> IN1;
                    if (IN1 == "m")
                    {
                        Menu(menu, cofanie, wybor, runda, player1_zeton, player2_zeton, OX);
                        if (menu == 1)
                        {
                            wgranie_planszy_pokazowej(OX, player1_zeton, player2_zeton, runda);
                            rysowanie_planszy(wybor, runda, player1, player2, OX, player1_zeton, player2_zeton);
                        }
                        else if (menu == 2)
                        {
                            switch (cofanie)
                            {
                                case 1:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_1);
                                    break;
                                }
                                case 2:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_2);
                                    break;
                                }
                                case 3:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_3);
                                    break;
                                }
                                case 4:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_4);
                                    break;
                                }
                            }
                        }
                    }
                    else if (IN1 == "o")
                    {
                        cout << "Prawdopodobnie chciales wczytac predefiniowana plansze." << endl << "Przenosze do opcji, gdzie jest to mozliwe";

                        Menu(menu, cofanie, wybor, runda, player1_zeton, player2_zeton, OX);
                        if (menu == 1)
                        {
                            wgranie_planszy_pokazowej(OX, player1_zeton, player2_zeton,runda);
                            rysowanie_planszy(wybor, runda, player1, player2, OX, player1_zeton, player2_zeton);
                        }
                        else if (menu == 2)
                        {
                            switch (cofanie)
                                {
                                case 1:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_1);
                                    break;
                                }
                                case 2:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_2);
                                    break;
                                }
                                case 3:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_3);
                                    break;
                                }
                                case 4:
                                {
                                    wygrywanie_poprzedniej_planszy(OX, pop_plansza_4);
                                    break;
                                }
                            }
                        }
                    }
                    else if (IN1 == "p")
                    {
                        system("cls");
                        cout << "Aktywowano pauze"<<endl;
                        system("pause");
                        system("cls");
                        rysowanie_planszy(wybor, runda, player1, player2, OX, player1_zeton, player2_zeton);
                    }
                    else if (IN1 == "h") help(wybor); //wejscie do opisu programu
                    else if (IN1.substr(0, 1) == "q" || IN1.substr(0, 1) == "w" || IN1.substr(0, 1) == "a" || IN1.substr(0, 1) == "s") //wybór planszy padl
                    { 
                        while (ruch_1)
                        {
                            ruch_gracza(IN1, plansza, wiersz, kolumna);
                            if (OX[plansza][wiersz][kolumna] == player1_zeton || OX[plansza][wiersz][kolumna] == player2_zeton)
                            {
                                cout << "Pole jest zajete, podaj jeszcze raz" << endl;
                                cin >> IN1;
                            }
                            else
                            {
                                if (runda % 2 == 1)
                                {
                                    OX[plansza][wiersz][kolumna] = player1_zeton;
                                    ruch_1 = false;
                                }
                                else if (runda % 2 == 0)
                                {
                                    OX[plansza][wiersz][kolumna] = player2_zeton;
                                    ruch_1 = false;
                                }

                            }
                        
                        }
                        ruch = false;
                        ruch_1 = true;
                    }
                    else cout << "Nieznana komenda. Sproboj jeszcze raz." << endl;
                } while (ruch);

            } while (czy_wygrana(player1, player2, OX, stan, runda, player1_zeton, player2_zeton));

            rysowanie_planszy(wybor, runda, player1, player2, OX, player1_zeton, player2_zeton);
            zakonczenie(stan);
            break;
        }

        case 2: //Pentago
        {
            cout << endl << "Wybraliscie Pentago!";

            vector<vector<vector<char>>> pole(4, vector<vector<char> >(3, vector<char>(3)));
            // pole[plansza][wiersz][kolumna]

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++) pole[i][j][k] = ' ';
                }
            }

            do
            {
                runda++;
                rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);

                do
                {
                    cout << "Komenda_1: ";
                    cin >> IN1;
                    if (IN1 == "h") help(wybor);
                    else if (IN1 == "m")
                    {
                        Menu(menu,cofanie,wybor, runda, player1_zeton, player2_zeton,pole);
                        if (menu == 1)
                        {
                            wgranie_planszy_pokazowej(pole, player1_zeton, player2_zeton, runda);
                            rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);
                        }
                        else if (menu == 2)
                        {
                            switch (cofanie)
                            {
                                case 1:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_1);
                                    break;
                                }
                                case 2:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_2);
                                    break;
                                }
                                case 3:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_3);
                                    break;
                                }
                                case 4:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_4);
                                    break;
                                }
                            }
                        }
                    }
                    else if (IN1 == "p")
                    {
                        system("cls");
                        cout << "Aktywowano pauze"<<endl;
                        system("pause");
                        system("cls");
                        rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);
                    }
                    else if (IN1.substr(0, 1) == "q" || IN1.substr(0, 1) == "w" || IN1.substr(0, 1) == "a" || IN1.substr(0, 1) == "s") //wybór planszy padl
                    {
                        while (ruch_1)
                        {
                            ruch_gracza(IN1, plansza, wiersz, kolumna);

                            if (pole[plansza][wiersz][kolumna] == player1_zeton || pole[plansza][wiersz][kolumna] == player2_zeton)
                            {
                                    cout << "Pole jest zajete, podaj jeszcze raz" << endl;
                                    cin >> IN1;
                            }
                            else
                            {
                                if (runda % 2 == 1)
                                {
                                    pole[plansza][wiersz][kolumna] = player1_zeton;
                                        ruch_1 = false;
                                }
                                else if(runda%2==0)
                                {
                                    pole[plansza][wiersz][kolumna] = player2_zeton;
                                    ruch_1 = false;
                                }
                            }
                        }
                        ruch = false;
                        ruch_1 = true;
                    }
                    else cout << "Nieznana komenda. Sproboj jeszcze raz." << endl;
                } while (ruch);
                ruch = true;

                rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);

                do
                {
                    cout << "Komenda_2: ";
                    cin >> IN2;
                    if (IN2 == "h") help(wybor);
                    else if (IN2 == "m")
                    {
                        Menu(menu, cofanie, wybor, runda, player1_zeton, player2_zeton,pole);
                        if (menu == 1)
                        {
                            wgranie_planszy_pokazowej(pole, player1_zeton, player2_zeton, runda);
                            rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);
                        }
                        else if (menu == 2)
                        {
                            switch (cofanie)
                            {
                                case 1:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_1);
                                    break;
                                }
                                case 2:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_2);
                                    break;
                                }
                                case 3:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_3);
                                    break;
                                }
                                case 4:
                                {
                                    wygrywanie_poprzedniej_planszy(pole, pop_plansza_4);
                                    break;
                                }
                            }
                        }
                    }
                    else if (IN2 == "p")
                    {
                        system("cls");
                        cout << "Aktywowano pauze"<<endl;
                        system("pause");
                        system("cls");
                        rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);
                    }
                    else if (IN2.substr(0, 1) == "q" || IN2.substr(0, 1) == "w" || IN2.substr(0, 1) == "a" || IN2.substr(0, 1) == "s") //wybór planszy planszy padl
                    {
                        if (IN2 == "qz")
                        {
                            obrot_z(pole[0][2][0], pole[0][2][1], pole[0][2][2], pole[0][1][0], pole[0][1][1], pole[0][1][2], pole[0][0][0], pole[0][0][1], pole[0][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "qx")
                        {
                            obrot_z(pole[0][2][0], pole[0][2][1], pole[0][2][2], pole[0][1][0], pole[0][1][1], pole[0][1][2], pole[0][0][0], pole[0][0][1], pole[0][0][2]); // trzy obroty w prawo to jeden obrót w lewo;
                            obrot_z(pole[0][2][0], pole[0][2][1], pole[0][2][2], pole[0][1][0], pole[0][1][1], pole[0][1][2], pole[0][0][0], pole[0][0][1], pole[0][0][2]);
                            obrot_z(pole[0][2][0], pole[0][2][1], pole[0][2][2], pole[0][1][0], pole[0][1][1], pole[0][1][2], pole[0][0][0], pole[0][0][1], pole[0][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "wz")
                        {
                            obrot_z(pole[1][2][0], pole[1][2][1], pole[1][2][2], pole[1][1][0], pole[1][1][1], pole[1][1][2], pole[1][0][0], pole[1][0][1], pole[1][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "wx")
                        {
                            obrot_z(pole[1][2][0], pole[1][2][1], pole[1][2][2], pole[1][1][0], pole[1][1][1], pole[1][1][2], pole[1][0][0], pole[1][0][1], pole[1][0][2]);
                            obrot_z(pole[1][2][0], pole[1][2][1], pole[1][2][2], pole[1][1][0], pole[1][1][1], pole[1][1][2], pole[1][0][0], pole[1][0][1], pole[1][0][2]);
                            obrot_z(pole[1][2][0], pole[1][2][1], pole[1][2][2], pole[1][1][0], pole[1][1][1], pole[1][1][2], pole[1][0][0], pole[1][0][1], pole[1][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "az")
                        {
                            obrot_z(pole[2][2][0], pole[2][2][1], pole[2][2][2], pole[2][1][0], pole[2][1][1], pole[2][1][2], pole[2][0][0], pole[2][0][1], pole[2][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "ax")
                        {
                            obrot_z(pole[2][2][0], pole[2][2][1], pole[2][2][2], pole[2][1][0], pole[2][1][1], pole[2][1][2], pole[2][0][0], pole[2][0][1], pole[2][0][2]);
                            obrot_z(pole[2][2][0], pole[2][2][1], pole[2][2][2], pole[2][1][0], pole[2][1][1], pole[2][1][2], pole[2][0][0], pole[2][0][1], pole[2][0][2]);
                            obrot_z(pole[2][2][0], pole[2][2][1], pole[2][2][2], pole[2][1][0], pole[2][1][1], pole[2][1][2], pole[2][0][0], pole[2][0][1], pole[2][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "sz")
                        {
                            obrot_z(pole[3][2][0], pole[3][2][1], pole[3][2][2], pole[3][1][0], pole[3][1][1], pole[3][1][2], pole[3][0][0], pole[3][0][1], pole[3][0][2]);
                            ruch = false;
                        }
                        else if (IN2 == "sx")
                        {
                        obrot_z(pole[3][2][0], pole[3][2][1], pole[3][2][2], pole[3][1][0], pole[3][1][1], pole[3][1][2], pole[3][0][0], pole[3][0][1], pole[3][0][2]);
                        obrot_z(pole[3][2][0], pole[3][2][1], pole[3][2][2], pole[3][1][0], pole[3][1][1], pole[3][1][2], pole[3][0][0], pole[3][0][1], pole[3][0][2]);
                        obrot_z(pole[3][2][0], pole[3][2][1], pole[3][2][2], pole[3][1][0], pole[3][1][1], pole[3][1][2], pole[3][0][0], pole[3][0][1], pole[3][0][2]);
                        ruch = false;
                        }
                        else cout << "Nieznana komenda. Sproboj jeszcze raz." << endl;
                    }
                    else cout << "Nieznana komenda. Sproboj jeszcze raz." << endl;
                } while (ruch);
                ruch = true;

                zapis_planszy( pole, pop_plansza_1, pop_plansza_2, pop_plansza_3, pop_plansza_4);

            } while (czy_wygrana(player1, player2, pole, stan, runda, player1_zeton, player2_zeton));

            rysowanie_planszy(wybor, runda, player1, player2, pole, player1_zeton, player2_zeton);
            zakonczenie(stan);
            break;
        }
    }

    cout <<endl<< "Dziekuje za zagranie w moja gre :)";

    return 0;
}

