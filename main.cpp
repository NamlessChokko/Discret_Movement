#include "Dismov/Dismov.hpp" 
#include "Dismov/entities/Entities.hpp"


using std::cout;

int main (){
    system("clear");
    
    int width = 50;
    Map map(width, width / 2, 10);

    Chaser death(map);
    death.set_name("death");
    death.set_body('X');
    death.set_position({49, 0});
    death.set_isStatic(false);
    death.set_immortal(true);
    death.set_color(color::mg);
    death.born();
    
    Chaser carrot(map);
    carrot.set_name("carrot");
    carrot.set_body('C');
    carrot.set_position({49, 24});
    carrot.set_isStatic(false);
    carrot.set_immortal(true);
    carrot.set_color(color::gn);
    carrot.born();

    Chaser bunny(map);
    bunny.set_name("bunny");
    bunny.set_body('B');
    bunny.set_position({0, 24});
    bunny.set_isStatic(false);
    bunny.set_immortal(true);
    bunny.set_color(color::yl);
    bunny.born();

    Chaser wolf(map);
    wolf.set_name("wolf");
    wolf.set_body('W');
    wolf.set_position({0, 0});
    wolf.set_isStatic(false);
    wolf.set_immortal(true);
    wolf.set_color(color::rd);
    wolf.born();

    Cleaner cleaner1(map);
    cleaner1.set_name("cleaner");
    cleaner1.set_body('*');
    cleaner1.set_position({myMath::randInt(map.get_x() - 1), myMath::randInt(map.get_y() - 1)}); 
    cleaner1.set_isStatic(false);
    cleaner1.set_immortal(true);
    cleaner1.born();

    Cleaner cleaner2(map);
    cleaner2.set_name("cleaner");
    cleaner2.set_body('*');
    cleaner2.set_position({myMath::randInt(map.get_x() - 1), myMath::randInt(map.get_y() - 1)}); 
    cleaner2.set_isStatic(false);
    cleaner2.set_immortal(true);
    cleaner2.born();

    carrot.set_objective(&death);
    death.set_objective(&wolf);
    wolf.set_objective(&bunny);
    bunny.set_objective(&carrot);
    
    GameLoop game(&map);
    game.run(10);

    return 0;
}


