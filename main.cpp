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

    long car_points = 0;
    long herb_points = 0;

    while(herbivorous.doesExist()){
        system("clear");
        cout << "\033[31mCarnivorous points: \033[37m" << car_points << endl;
        cout << "\033[33mHerbivorous points: \033[37m" << herb_points << endl;

        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 20; x++){
                duo pos = {x,y};
                


                if ((pos.x == carnivorous.position().x) && pos.y == carnivorous.position().y){
                    cout << "\033[31m" << carnivorous.body() << "\033[37m_";
                }else if ((pos.x == herbivorous.position().x) && pos.y == herbivorous.position().y){
                    cout << "\033[33m" << herbivorous.body() << "\033[37m_";
                }else if ((pos.x == herbivorous.objective().x) && (pos.y == herbivorous.objective().y)) {
                    cout << "\033[32m0\033[37m_";
                }else {
                    cout << "\033[37m" << "__" ;
                }
            }
            cout << endl;
        }
        if ((herbivorous.position().x == herbivorous.objective().x) && (herbivorous.position().y == herbivorous.objective().y)){
            herb_points++;
            usleep(100000); 
            herbivorous.objective({randNum(19), randNum(19)});
        }

        if ((carnivorous.position().x == herbivorous.position().x) && (carnivorous.position().y == herbivorous.position().y)){
            car_points++;
            usleep(100000);
            herbivorous.position({randNum(19), randNum(19)});
        }
        herbivorous.move(herbivorous.objective());
        carnivorous.move(herbivorous.position());
        usleep(100000);
    }

    return 0;
}