// Benitez Barbara
// Morales Ignacio

#include <iostream>
#include <limits>

using namespace std;

int main() {
    bool salirDelJuego = false;
    string decision;
    string nombreJugador;
    int juegoActivo = 1;
    int opcion;

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
            cout << R"( 1.
   ___  ___   _ __ ___    ___  _ __   ____ __ _  _ __ 
  / __|/ _ \ | '_ ` _ \  / _ \| '_ \ |_  // _` || '__|
 | (__| (_) || | | | | ||  __/| | | | / /| (_| || |   
  \___|\___/ |_| |_| |_| \___||_| |_|/___|\__,_||_|   
                                                      )" << endl;
            cout << R"(2. 
                       _  _  _              
                      | |(_)| |             
   ___  _ __  ___   __| | _ | |_  ___   ___ 
  / __|| '__|/ _ \ / _` || || __|/ _ \ / __|
 | (__ | |  |  __/| (_| || || |_| (_) |\__ \
  \___||_|   \___| \__,_||_| \__|\___/ |___/
                                            
)" << endl;
            cout << R"(3. 
                _   _        
               | | (_)       
  ___    __ _  | |  _   _ __ 
 / __|  / _` | | | | | | '__|
 \__ \ | (_| | | | | | | |   
 |___/  \__,_| |_| |_| |_|   
                             
)" << endl;
            cout << "Seleccione una opción: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                opcion = 0;
            }

        } while (opcion < 1 || opcion > 3);

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
                     while (true) {
                cout << "Te llamaron urgentemente a una vieja mansión." << endl;
                cout << "Hace horas encontraron un cadáver en la biblioteca." << endl;
                cout << "Detective " << nombreJugador << ", ¿Querés entrar a investigar? (SI/NO): ";
                cin >> decision;

                if (!(decision == "SI" || decision == "Si" || decision == "si" || decision == "sI")) {
                    cout << "Decidiste no intervenir. El misterio queda sin resolver." << endl;
                    cout << "Presione ENTER para continuar..." << endl;
                    cin.ignore(); cin.get();
                    break;
                }

                    // PANTALLA 2

                    system("clear");
                cout << "Al entrar ves dos objetos: una nota y un cuchillo. ¿Cuál querés inspeccionar?" << endl;
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

 cout << "1.Nota" << endl;
 cout << "2.Cuchillo" << endl;
                int eleccion;
                cin >> eleccion;

 if (cin.fail() || (eleccion != 1 && eleccion != 2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Opción no válida. Presione ENTER para continuar..." << endl;
                    cin.get();
                    break;
                }

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
)" << endl; }
       {

cout << "El cuchillo tiene huellas. Alguien actuó apresuradamente." << endl; 

                    // PANTALLA 3

                cout << "Encontrás un cuaderno con anotaciones de amenazas..." << endl;
                for (int i = 1; i <= 3; i++) {
                    cout << "Leyendo página " << i << "..." << endl;
                    }

                    cout << "La hija del dueño y el mayordomo aparecen mencionados." << endl;
                    cout << "Ambos tenían motivos, pero sólo uno estaba en la casa esa noche." << endl;

                cout << "Presione ENTER para continuar..." << endl;
                cin.ignore(); cin.get();

                    
                    // PANTALLA 4
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
//system("clear");
                float temperatura;
                cout << "Medís la temperatura del cuerpo. Ingresá el valor: ";
                cin >> temperatura;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    temperatura = 0;
                }

                if (temperatura < 30.0)
                    cout << "La muerte fue hace varias horas." << endl;
                     else
                    cout << "La víctima murió recientemente." << endl;

                cout << "Presione ENTER para continuar..." << endl;
                cin.ignore(); cin.get();

                    // PANTALLA 5. 
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
                   
                   // system("clear");
                int sospechoso;
                cout << "¿A quién acusás?\n1. El mayordomo\n2. La hija del dueño\nOpción: ";
                cin >> sospechoso;

                if (sospechoso == 1) {
                    cout << "¡Correcto! El mayordomo era culpable. ¡Caso resuelto!" << endl;
                } else {
                    cout << "Incorrecto. La hija del dueño era inocente..." << endl;
                    cout << "De repente, sentís un frío recorrer tu espalda..." << endl;


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
                }


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
        case 3:
            salirDelJuego = true;
            break;
        }
    }

    return 0;
}