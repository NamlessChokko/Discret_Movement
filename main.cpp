#include "include.hpp"



int main (){
    Entity herbivorous;
    herbivorous.name("sheep");
    herbivorous.body('#');
    herbivorous.position({randNum(19), randNum(19)});
    herbivorous.objective({randNum(19), randNum(19)});

    Entity carnivorous;
    carnivorous.name("wolf");
    carnivorous.body('@');
    carnivorous.position({randNum(19), randNum(19)});
    carnivorous.objective(herbivorous.position());

    while(herbivorous.doesExist()){
        system("clear");
        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 20; x++){
                duo pos = {x,y};
                if ((herbivorous.position().x == herbivorous.objective().x) && (herbivorous.position().y == herbivorous.objective().y)){
                    herbivorous.objective({randNum(19), randNum(19)});
                }

                if ((pos.x == herbivorous.position().x) && pos.y == herbivorous.position().y){
                    cout << herbivorous.body();
                } else if ((pos.x == herbivorous.objective().x) && (pos.y == herbivorous.objective().y)) {
                    cout << 'O';
                }else {
                    cout << '-';
                }
            }
            cout << endl;
        }
        herbivorous.move(herbivorous.objective());
        usleep(100000);
    }

    return 0;
}