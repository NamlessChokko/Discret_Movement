#include "Dismov/Dismov.hpp" 
#include "Dismov/entities/Chaser.hpp"
#include "Dismov/entities/Dummy.hpp"


using std::cout;

int main (){
    system("clear");

    Map map(20, 10, 10);

    Chaser wolf(map);
    wolf.set_name("Wolf");
    wolf.set_body('W');
    wolf.set_position({5, 5});
    wolf.set_isStatic(false);
    wolf.born();

    Chaser sheep(map);
    sheep.set_name("Sheep");
    sheep.set_body('S');
    sheep.set_position({1, 1});
    sheep.set_isStatic(false);
    sheep.born();
    
    Dummy fruit(map);
    fruit.set_name("Fruit");
    fruit.set_body('F');
    fruit.set_position({3, 3});
    fruit.set_isStatic(false);
    fruit.born();
    
    wolf.set_objective(&sheep);
    sheep.set_objective(&fruit);
    
    GameLoop game(&map, 10);
    game.run();

    return 0;
}


