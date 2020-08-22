#include <iostream>
#include <array>
#include <random>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int userChoice, holder, prizeWon;
    
    char switching;
    
    array<bool, 3> doors;
    
    array<bool, 3> doorsOpen;
    
    cout << "Choose doors 1, 2, or 3" << endl;
    
    cin >> userChoice;
    
    doorsOpen[userChoice - 1] = true;
    
    random_device rd{};
    
    default_random_engine engine{ rd() };
    
    uniform_int_distribution<int> rangeGoat{0, 2};
    
    int goat1 = rangeGoat(engine);
    
    int goat2 = rangeGoat(engine);
    
    while (goat1 == goat2)
    
        goat2 = rangeGoat(engine);
    
    uniform_int_distribution<int> rangeWin(0, 2);
    
    int winDoor = rangeWin(engine);
    
    while (winDoor == goat1 || winDoor == goat2)
        
        winDoor = rangeWin(engine);
    
    uniform_int_distribution<int> rangePrizes(1, 5);
    
    prizeWon = rangePrizes(engine);
    
    doors[goat1] = false;
    
    doors[goat2] = false;
    
    doors[winDoor] = true;
    
    if (goat1 > goat2) {
        
        holder = goat1;
    
        goat1 = goat2;
        
        goat2 = holder;
    }
        
    if (userChoice == goat1 + 1) {
        
        cout << "Behind door number " << goat2 + 1 << " is a goat!" << endl;
        
        doorsOpen[goat2] = true;
    }
    
    else {
        
        cout << "Behind door number " << goat1 + 1 << " is a goat!" << endl;
        
        doorsOpen[goat1] = true;
    }
    
    cout << "Would you like to switch your selection to the other door? y/n" << endl;
    
    cin >> switching;
    
    if (switching == 'y'){
        
        for(int i = 0; i < doorsOpen.size(); i++){
            
            if (doorsOpen[i] == false){
                
                userChoice = i;
            }
        }
    }
    
    else
        
        userChoice--;
    
    if (doors[userChoice] == true){
        
        cout << "Congratulations, you've won";
        
        if (prizeWon == 1)
            
            cout << " a brand new car!" << endl;
        
        else if (prizeWon == 2)
            
            cout << " a brand new house!" << endl;
        
        else if (prizeWon == 3)
            
            cout << " a trip to Disneyland!" << endl;
        
        else if (prizeWon == 4)
            
            cout << " a $500 gift card to IKEA!" << endl;
        
        else
            
            cout << " a million dollars!" << endl;
    }
    
    else
        
        cout << "Too bad, you've lost, you don't get to keep the goat" << endl;
        
    return 0;
}
