/* 
 * File:   main.cpp
 * Author: Mario Victorino
 *
 * Created on July 20, 2024, 12:30 PM
 * This is a BlackJack
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

void addCard(int &, int &);
int hand(int &, int &);
void choice(int &, int &);
void showdown(int &);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));
    
    char y;     //input to play or not
    y = 'y';
    string suit;//card suit
    suit = "";
    int cHand;  //current cards in hand
    cHand = 0;  //new player should have 0 cards
    int hValue; //hand value add all card values
    hValue = 0; //new player should have no cards
    int cValue;
    cValue = 0;
    
    bool cont;  //condition to continue or not
    cont = true;
    
    do{
        cHand = 0;
        hValue = 0;
        cout << "Play Round of Blackjack? (y/n)" << endl;
        cin >> y;
        
        if(y != 'y'){
            cont = false;
        }else if (cont){
            hand(cHand, hValue);
            choice(cHand,hValue);  
        }
    }while(cont);
    
    return 0;
}

int hand(int &cHand, int &cValue){
    //current hand
    if(cHand == 0){
        addCard(cHand, cValue);
        addCard(cHand, cValue);
    }else{
        addCard(cHand, cValue);
    }
    return cHand;
}

void addCard(int &cHand, int &cValue){
    int check;
    check = 0;
    int pickS;
    pickS = 0;
    string suit;
    suit = "";
    pickS = rand()%4+1; //pick a random suit
    
    if(pickS == 1){
        suit = "Spade";  
        check = rand()%11;      //get random card
        if (check == 10){     //if card is 10, decide if it's a face card or not
            pickS = rand()%4+1; //random pick between 10,J,Q,K
            if (pickS == 1){
                cout << "10 of Spades" << endl;
                cValue += check;
            }
            if (pickS == 2){
                cout << "Jack of Spades" << endl;
                cValue += check;
            }
            if (pickS == 3){
                cout << "Queen of Spades" << endl;
                cValue += check;
            }
            if (pickS == 4){
                cout << "King of Spades" << endl;
                cValue += check;
            }
        }
        if (check == 11){
            if ((cValue + check) > 21){
                cout << "Ace of Spades" << endl;
                cValue += 1;
            } else {cValue += 11;}
        }
        if(check < 10){
            cout << check << " of Spades" << endl;
            cValue += check;
        }
    }
    if(pickS == 2){
        suit = "Heart";
        check = rand()%11;  //get random card
        if (check == 10){     //if card is 10, decide if it's a face card or not
            pickS = rand()%4+1; //random pick between 10,J,Q,K
            if (pickS == 1){
                cout << "10 of Hearts" << endl;
                cValue += check;
            }
            if (pickS == 2){
                cout << "Jack of Hearts" << endl;
                cValue += check;
            }
            if (pickS == 3){
                cout << "Queen of Hearts" << endl;
                cValue += check;
            }
            if (pickS == 4){
                cout << "King of Hearts" << endl;
                cValue += check;
            }
        }
        if (check == 11){
            if ((cValue + check) > 21){
                cout << "Ace of Hearts" << endl;
                cValue += 1;
            } else {cValue += 11;}
        }
        if(check < 10){
            cout << check << " of Hearts" << endl;
            cValue += check;
        }
    }
    if(pickS == 3){
        suit = "Clover";
        check = rand()%11;      //get random card
        if (check == 10){     //if card is 10, decide if it's a face card or not
            pickS = rand()%4+1; //random pick between 10,J,Q,K
            if (pickS == 1){
                cout << "10 of Clubs" << endl;
                cValue += check;
            }
            if (pickS == 2){
                cout << "Jack of Clubs" << endl;
                cValue += check;
            }
            if (pickS == 3){
                cout << "Queen of Clubs" << endl;
                cValue += check;
            }
            if (pickS == 4){
                cout << "King of Clubs" << endl;
                cValue += check;
            }
        }
        if (check == 11){
            if ((cValue + check) > 21){
                cout << "Ace of Clubs" << endl;
                cValue += 1;
            } else {cValue += 11;}
        }
        if(check < 10){
            cout << check << " of Clubs" << endl;
            cValue += check;
        }
    }
    if(pickS == 4){
        suit = "Diamond";
        check = rand()%11;      //get random card
        if (check == 10){     //if card is 10, decide if it's a face card or not
            pickS = rand()%4+1; //random pick between 10,J,Q,K
            if (pickS == 1){
                cout << "10 of Diamonds" << endl;
                cValue += check;
            }
            if (pickS == 2){
                cout << "Jack of Diamonds" << endl;
                cValue += check;
            }
            if (pickS == 3){
                cout << "Queen of Diamonds" << endl;
                cValue += check;
            }
            if (pickS == 4){
                cout << "King of Diamonds" << endl;
                cValue += check;
            }
        }
        if (check == 11){
            if ((cValue + check) > 21){
                cout << "Ace of Diamonds" << endl;
                cValue += 1;
            } else {cValue += 11;}
        }
        if(check < 10){
            cout << check << " of Diamonds" << endl;
            cValue += check;
        }
    }
    cHand++;
}

void choice(int &cHand, int &cValue){
    string hs;
    hs = "";
    cout << "Hit or stand? (h/s)" << endl;
    cin >> hs;
    if (hs.compare("h") == 0){
        hand(cHand,cValue);
    }
    if(hs.compare("s") == 0){
        showdown(cValue);
    }
}

void showdown(int &cValue){
    float dValue;     //dealer hand value
    dValue = 0;
    
    dValue += rand()%11;
    dValue += rand()%11;
    cout << "Dealer: " << dValue << endl;
    
    if (cValue > dValue && cValue < 22){
        cout << "You Win!" << endl;
    } else {
        cout << "You Lose!" << endl;
    }
}