// Benitez Barbara
// Morales Ignacio

#include <iostream>

using namespace std;


int main() {
    bool salirDelJuego = false;
    int opcion;
    int juegoActivo = 1;
    string decision;
    string nombreJugador;

    while (!salirDelJuego) {
        do {
            system("clear");
            cout << R"(
 _______  _______  _______  _______                          
|       ||   _   ||       ||       |                         
|       ||  |_|  ||  _____||   _   |                         
|       ||       || |_____ |  | |  |                         
|      _||       ||_____  ||  |_|  |                         
|     |_ |   _   | _____| ||       |                         
|_______||__| |__||_______||_______|                         
 _______  _______  ___   _______  ______    _______  _______ 
|   _   ||  _    ||   | |       ||    _ |  |       ||       |
|  |_|  || |_|   ||   | |    ___||   | ||  |_     _||   _   |
|       ||       ||   | |   |___ |   |_||_   |   |  |  | |  |
|       ||  _   | |   | |    ___||    __  |  |   |  |  |_|  |
|   _   || |_|   ||   | |   |___ |   |  | |  |   |  |       |
|__| |__||_______||___| |_______||___|  |_|  |___|  |_______|
)" << endl;

            cout << "1. Jugar" << endl;
            cout << "2. Créditos" << endl;
            cout << "Seleccione una opción: ";
            cin >> opcion;
        } while (opcion != 1 && opcion != 2);

        switch (opcion) {
            case 1:
                system("clear");
                cout << R"(
  .OOOOOOOOOOOOOOO @@         By Barby y Nachi        @@ OOOOOOOOOOOOOOOO.
  OOOOOOOOOOOOOOOO @@                                    @@ OOOOOOOOOOOOOOOO
  OOOOOOOOOO'''''' @@                                    @@ ```````OOOOOOOOO
  OOOOO'' aaa@@@@@@@@@@@@@@@@@@@@"""                   """"""""@@aaaa `OOOO
  OOOOO,""""@@@@@@@@@@@@@@""""                                     a@"" OOOA
  OOOOOOOOOOoooooo,                                            |OOoooooOOOOOS
  OOOOOOOOOOOOOOOOo,       ¿Estaré siguiendo las pistas        |OOOOOOOOOOOOC
  OOOOOOOOOOOOOOOOOO         correctamente?                    ,|OOOOOOOOOOOOI
  OOOOOOOOOOOOOOOOOO @     ¿Lograré resolver este caso?        |OOOOOOOOOOOOOI
  OOOOOOOOOOOOOOOOO'@                                          OOOOOOOOOOOOOOb
  OOOOOOOOOOOOOOO'a'                                           |OOOOOOOOOOOOOy
  OOOOOOOOOOOOOO''              Misterio por resolver...    aa`OOOOOOOOOOOP
  OOOOOOOOOOOOOOb,..                                           `@aa``OOOOOOOh
  OOOOOOOOOOOOOOOOOOo                                          `@@@aa OOOOo
  OOOOOOOOOOOOOOOOOOO|                                           @@@ OOOOe
  OOOOOOOOOOOOOOOOOOO@                               aaaaaaa       @@',OOOOn
  OOOOOOOOOOOOOOOOOOO@                        aaa@@@@@@@@""        @@ OOOOOi
  OOOOOOOOOO~~ aaaaaa"a                 aaa@@@@@@@@@@""            @@ OOOOOx
  OOOOOO aaaa@"""""""" ""            @@@@@@@@@@@@""               @@@|`OOOO'
  OOOOOOOo`@@a                  aa@@  @@@@@@@""         a@        @@@@ OOOO9
  OOOOOOO'  `@@a               @@a@@   @@""           a@@   a     |@@@ OOOO3
  `OOOO'       `@    aa@@       aaa"""          @a        a@     a@@@',OOOO'
)" << endl;
cout << "Ingrese su nombre de detective: ";
                cin >> nombreJugador;

                while (juegoActivo) {
                    system("clear");

                    // PANTALLA 1

cout << R"(
               .-.     /-_--__-/_--_-\-_--\
               |=|    /-_---__/__-__-\__-_\
           . . |=| ._/-__-__\===========/-__\_
           !!!!!!!!!\========[ /]]|[[\ ]=====/
          /-_--_-_-_[[[[[[[[[||==  == ||]]]]]]
         /-_--_--_--_|=  === ||=/^|^\ ||== =|
        /-_-/^|^\-_--| /^|^\=|| | | | ||^\= |
       /_-_-| | |-_--|=| | | ||=|_|_|=||"|==|
      /-__--|_|_|_-_-| |_|_|=||______=||_| =|
     /_-__--_-__-___-|_=__=_.`---------'._=_|__
    /-----------------------\===========/-----/
   ^^^\^^^^^^^^^^^^^^^^^^^^^^[[|]]|[[|]]=====/
       |.' ..==::'"'::==.. '.[ /~~~~~\ ]]]]]]]
       | .'=[[[|]]|[[|]]]==`._||==  =  || =\ ]
       ||== =|/ _____ \|== = ||=/^|^\=||^\ ||
       || == `||-----||' = ==|| | | |=|| |=||
       ||= == ||:^s^:|| = == ||=| | | || |=||
       || = = ||:___:||= == =|| |_|_| ||_|=||
      _||_ = =||o---.|| = ==_||_= == =||==_||_
      \__/= = ||:   :||= == \__/[][][][][]\__/
      [||]= ==||:___:|| = = [||]\//\//\[||]
      }  {---'"'-----'"'- --}  {//\//\//}  {
    __[==]__________________[==]\//\//\[==]_
)" << endl;
                    cout << "Te llamaron urgentemente a una vieja mansión." << endl;
                    cout << "Hace horas encontraron un cadáver en la biblioteca." << endl;
                    cout << "Detective " << nombreJugador << ", ¿Querés entrar a investigar? (SI/NO): ";
                    cin >> decision;

                    if (decision != "SI" && decision != "si" && decision != "Si" && decision != "sI") {
                        cout << "Decidiste no intervenir. El misterio queda sin resolver." << endl;
                        break;
                    }

                    // PANTALLA 2

                    system("clear");
                    cout << "Al entrar ves dos objetos sospechosos: una nota arrugada y un cuchillo ensangrentado." << endl;
                    cout << R"(
⠀⠀⠀⣀⣤⣶⡶⠿⢿⣿⣶⣶⣤⣀⠀⠀⠀
⠀⢀⣾⣿⠋⠁⠀⠀⠀⠀⠙⢿⣿⣿⣷⣄⠀
⠀⣿⣿⣿⡀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⡄
⠘⣿⣿⣿⣷⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇
⠀⠹⢿⣿⠟⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⠇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⠟⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⡿⠋⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠟⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⡿⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣾⡏⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠘⠋⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠀⠀⠀
)" << endl;

cout << "¿Cuál querés inspeccionar primero?" << endl;
                    cout << "1. La nota" << endl;
                    cout << "2. El cuchillo" << endl;
                    int eleccion;
                    cin >> eleccion;


                    if (eleccion == 1) {
                        cout << R"(
   _____
  /    /|______________________________________________
 /    // /|                                          /|
(====|/ //   "El asesino conoce los secretos        / |   
(=====|/     de la víctima. No confíes en nadie."  / /|
(====|/                                   \__/    / /||
/________________________________________________/ / ||
|  _____________________________________________  || ||
| ||                                            | ||
| ||                                            | ||
)" << endl;
                    } else {
                        cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡤⠶⠖⠒⠒⢒⣶⣤⠄
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠔⠚⠉⠀⠀⠀⣠⣴⡺⠟⠉⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⠖⠋⠁⠀⠀⠀⣀⠤⣶⠽⠛⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⢶⢶⣖⠋⠁⠀⠀⠀⣀⠤⢒⡩⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⠚⠉⣯⣷⢸⣷⢹⣿⣄⡤⢒⣩⠴⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠔⠊⠉⠀⠀⠀⠀⣀⣵⠿⠿⣸⣿⡯⠖⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠚⠁⠀⠀⠀⠀⠀⠀⣴⣞⣭⡴⠾⠛⠛⠿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⡠⠖⠉⢰⣻⡷⠀⠀⠀⠀⢀⡔⣠⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣠⠴⠚⠁⠀⠀⠀⠀⠀⠉⠁⠀⠀⢀⡴⢋⣼⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣠⡶⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⠟⣡⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢠⠞⣧⣤⠀⠀⠀⠀⠀⠀⠀⠀⣀⣚⣿⣯⠴⠞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣾⡄⠛⠛⣠⡶⠒⣊⡥⠖⠋⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣿⣶⡿⠃⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⣞⠿⢣⣾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢉⣛⣛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)" << endl;
       

cout << "El cuchillo tiene huellas. Alguien actuó apresuradamente." << endl; 

                    // PANTALLA 3

                    cout << "En un cuaderno viejo encontrás anotaciones de amenazas contra la víctima." << endl;
                    cout << "La hija del dueño y el mayordomo aparecen mencionados." << endl;
                    cout << "Ambos tenían motivos, pero sólo uno estaba en la casa esa noche." << endl;

                    // PANTALLA 4

                    float temperatura;
                    cout << R"(
  ________________
  |     _    ^C  |
  |  - | | -  40 |
  |  - | | -  30 |
  |  - | | -  25 |
  |  - | | -  20 |
  |  - | | -  15 |
  |  - | | -  10 |
  |  - | | -   5 |
  |  - | | -   0 |
  |  - | | -  -5 |
  |  - | | - -10 |
  |  - | | - -20 |
  |   '***`      |
  |  (*****)     |
  |______________|
)" << endl;
cout << "Medís la temperatura del cuerpo. Ingresá el valor: ";
                    cin >> temperatura;
                    if (temperatura < 30.0) {
                        cout << "La muerte fue hace varias horas." << endl;
                    } else {
                        cout << "La víctima murió recientemente." << endl;
                    }


                    // PANTALLA 5. 
                    //Aca nos gustaria que luego de ingresar la temperatura se limpie la pantalla anterior pero intentamos con system clear y nos borra la respuesta del if else, como podriamos hacer?
                  cout << R"(
                   .-._.--._                                       _____
                  /         /                                     //)))))
                  -.       |                                      )))@_@)
                    \      |__                                   (((  = )
                  ,-'______.-'                                    ))) -(_   __
                   '( c-(_)(_)__                                 /   `-'\\ /,\\\`
                     \    .._ . )                               /__|     )y |
                      \  /   `-'                                 < \     (\_/
                      /\-|\_                                      `.\     \
                     /-. \ /                                      {>>>`   |
                    (  , o)\                                     /`-'\____|
                     | |  o)\                                   /   c \\ /
                     c -  _/\\                                 (C \_ _))\
                    / \ \=====|                                 `-'-._/  \
                   |  //======|                                    /  /\  \
                   | / =====_/                                    / ,'  `. \
                   |/\===/=/                                     / /      \ \
                      )==)=)                                    <\_\_      \ \
                     (==|=|                                      `---`    (_`-\_
                      | |=|______                                           `---'
                     (_.-.    )  )  
                          '--''-'  

                    )";
                    int sospechoso;
                    cout << "¿A quién acusás?" << endl;
                    cout << "1. El mayordomo" << endl;
                    cout << "2. La hija del dueño" << endl;
                    cin >> sospechoso;

                    if (sospechoso == 1) {
                        cout << "¡Correcto! El mayordomo era culpable. ¡Caso resuelto!" << endl;
                    } else {
                        cout << "Incorrecto. La hija del dueño era inocente..." << endl;

cout << "De repente, sentís un frío recorrer tu espalda..." << endl;

     // En esta parte nos gustaria que la pantalla se limpie tambien pero nos borra lo anterior, tenemos la misma duda.

cout << "Fuiste apuñalad@ por el verdadero asesino. Morís en la escena del crimen." << endl;
                        cout << R"(
⣿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣿
⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿
⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿
⣿⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⣿
⣿⠀⢠⣶⢰⠀⢸⣿⣿⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣷⠀⠀⣤⡄⠀⣿
⣿⠀⠘⣿⣛⢀⣸⣿⣿⢈⠀⢸⣿⡆⢀⡀⢰⣿⣷⠀⢸⣿⣿⡏⡀⠀⣿⣷⠀⣿
⣿⠀⠀⢸⣿⣿⣿⣿⣿⢸⠀⢸⣿⣿⣶⣶⣿⣿⣿⠀⢸⣿⣿⣧⣭⣥⣿⡿⡆⣿
⣿⣶⣶⣿⣿⣿⣿⣿⡇⡏⠀⠀⢿⣿⣿⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣿⣿⢳⠁⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣧⡑⠀⣠⣿⣿⣿⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣿⣯⣿⠀⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⣿⣿⣿⣿⣿⣿⣿⣶⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡇⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠂⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣘⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
)" << endl;
cout << "Presione ENTER para continuar..." << endl;
cin.ignore(); cin.get();
break;
                        break;
                    }

                    cout << "Presione ENTER para continuar..." << endl;
                    cin.ignore(); cin.get();
                    break;
            }
            case 2:
                system("clear");
                cout << "Créditos:\nBarby y Nacho" << endl;
                cout << "Presione ENTER para volver al menú." << endl;
                cin.ignore(); cin.get();
                break;
        }
    }

    return 0;
}