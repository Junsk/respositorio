#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>



char *apellidos[]= {"Aguilar","Alonso","�lvarez","Arias","Ben�tez",
                    "Blanco","Blesa","Bravo","Caballero","Cabrera","Calvo",
                    "Cambil","Campos","Cano","Carmona","Carrasco",
                    "Castillo","Castro","Cort�s","Crespo","Cruz",
                    "Delgado","D�az","D�ez","Dom�nguez",
                    "Dur�n","Esteban","Fern�ndez","Ferrer",
                    "Flores","Fuentes","Gallardo",
                    "Gallego","Garc�a","Garrido","Gil",
                    "Gim�nez","G�mez","Gonz�lez","Guerrero","Granados"
                    "Guti�rrez","Hern�ndez","Herrera","Herrero",
                    "Hidalgo","Ib��ez","Iglesias","Jim�nez",
                    "Le�n","L�pez","Lorenzo","Lozano",
                    "Mar�n","M�rquez","Mart�n","Mart�nez",
                    "Medina","M�ndez","Molina","Montero",
                    "Montoro","Mora","Morales","Moreno",
                    "Moya","Mu�oz","Navarro","Nieto",
                    "N��ez","Ortega","Ortiz","Parra",
                    "Pascual","Pastor","Pe�a","P�rez",
                    "Prieto","Ram�rez","Ramos","Rey",
                    "Reyes","Rodr�guez","Rom�n","Romero",
                    "Rubio","Ruiz","S�ez","S�nchez",
                    "Santana","Santiago","Santos","Sanz",
                    "Serrano","Soler","Soto","Su�rez",
                    "Torres","Vargas","V�zquez","Vega",
                    "Velasco","Vicente","Vidal"
                   };
char *nombres[] = {"Aar�n",	"Abd�n",	"Abel",	"Abelardo",	"Abrah�n",	"Absal�n",	"Acacio",	"Adalberto",	"Ad�n",	"Adela",	"Adelaida",	"Adolfo",	"Ad�n",	"Adri�n",	"Agust�n",	"Aitor",	"Alba",	"Albert",	"Alberto",	"Albina",	"Alejandra",	"Alejandro",	"Alejo",	"Alfonso",	"Alfredo",	"Alicia",	"Alipio",	"Almudena",	"Alonso",	"�lvaro",	"Amadeo",	"Amaro",	"Ambrosio",	"Amelia",	"Amparo",	"Ana",	"Anan�as",	"Anastasia",	"Anatolio",	"Andrea",	"Andr�s",
                   "�ngel",	"�ngela",	"�ngeles",	"Aniano",	"Anna",	"Anselmo",	"Antero",	"Antonia",	"Antonio",	"Aquiles",	"Araceli",	"Ar�nzazu",	"Arcadio",	"Aresio",	"Ariadna",	"Aristides",	"Arnaldo",	"Artemio",	"Arturo",	"Ascensi�n",	"Asunci�n",	"Atanasio",	"Augusto",	"�urea",	"Aurelia",	"Aureliano",	"Aurelio",	"Aurora",	"Baldomero",	"Balduino",	"Baltasar",	"B�rbara",	"Bartolom�",	"Basileo",	"Beatriz",	"Bego�a",	"Bel�n",	"Beltr�n",	"Benedicto",	"Benigno",	"Benito",
                   "Benjam�n",	"Bernab�",	"Bernarda",	"Bernardo",	"Blanca",	"Blas",	"Bonifacio",	"Borja",	"Bruno",	"Calixto",	"Camilo",	"C�ndida",	"Carina",	"Carlos",	"Carmelo",	"Carmen",	"Carolina",	"Casiano",	"Casimiro",	"Casio",	"Catalina",	"Cayetano",	"Cayo",	"Cecilia",	"Ceferino",	"Celia",	"Celina",	"Celso",	"C�sar",	"Ces�reo",	"Cipriano",	"Cirilo",	"Cirino",	"Ciro",	"Clara",	"Claudia",	"Claudio",	"Cleof�s",	"Clotilde",	"Colombo",	"Columba",
                   "Columbano",	"Concepci�n",	"Conrado",	"Constancio",	"Constantino",	"Consuelo",	"Cosme",	"Cristian",	"Cristina",	"Crist�bal",	"Daciano",	"Dacio",	"D�maso",	"Dami�n",	"Daniel",	"Dario",	"David",	"Dem�crito",	"Diego",	"Dimas",	"Dolores",	"Domingo",	"Donato",	"Dorotea",	"Edgar",	"Edmundo",	"Eduardo",	"Eduvigis",	"Efr�n",	"Elena",	"El�as",	"Elisa",	"Eliseo",	"Elvira",	"Emilia",	"Emiliano",	"Emilio",	"Encarnaci�n",	"Enrique",	"Epifan�a",	"Erico",
                   "Ernesto",	"Esdras",	"Esiquio",	"Esperanza",	"Esteban",	"Ester",	"Esther",	"Eugenia",	"Eugenio",	"Eulalia",	"Eusebio",	"Eva",	"Evaristo",	"Ezequiel",	"Fabi�n",	"Fabio",	"Fabiola",	"Facundo",	"F�tima",	"Faustino",	"Fausto",	"Federico",	"Feliciano",	"Felipe",	"F�lix",	"Ferm�n",	"Fernando",	"Fidel",	"Fortunato",	"Francesc",	"Francisca",	"Francisco",	"Fulgencio",	"Gabriel",	"Gema",	"Genoveva",	"Gerardo",	"Germ�n",	"Gertrudis",	"Gisela",	"Gloria",
                   "Godofredo",	"Gonzalo",	"Gregorio",	"Guadalupe",	"Guido",	"Guillermo",	"Gustavo",	"Guzm�n",	"H�ctor",	"Heliodoro",	"Heraclio",	"Heriberto",	"Hilari�n",	"Hildegarda",	"Homero",	"Honorato",	"Honorio",	"Hugo",	"Humberto",	"Ifigenia",	"Ignacio",	"Ildefonso",	"In�s",	"Inmaculada",	"Inocencio",	"Irene",	"Ireneo",	"Isaac",	"Isabel",	"Isa�as",	"Isidro",	"Ismael",	"Iv�n",	"Jacinto",	"Jacob",	"Jacobo",	"Jaime",	"Jaume",	"Javier",	"Jerem�as",	"Jer�nimo",
                   "Jes�s",	"Johan",	"Joaqu�m",	"Joaqu�n",	"Joel",	"Jon�s",	"Jonathan",	"Jordi",	"Jorge",	"Josafat",	"Jos�",	"Josefa",	"Josefina",	"Josep",	"Josu�",	"Juan",	"Juana",	"Julia",	"Juli�n",	"Julio",	"Justino",	"Juvenal",	"Ladislao",	"Laura",	"Laureano",	"L�zaro",	"Leandro",	"Leocadia",	"Le�n",	"Leonardo",	"Leoncio",	"Leonor",	"Leopoldo",	"Lidia",	"Liduvina",	"Lino",	"Lorena",	"Lorenzo",	"Lourdes",	"Lucano",	"Lucas",
                   "Luc�a",	"Luciano",	"Lucrecia",	"Luis",	"Luisa",	"Luz",	"Macario",	"Magdalena",	"Manuel",	"Manuela",	"Mar",	"Marc",	"Marcelino",	"Marcelo",	"Marcial",	"Marciano",	"Marcos",	"Margarita",	"Mar�a",	"Mariano",	"Marina",	"Mario",	"Marta",	"Mart�n",	"Mateo",	"Mat�as",	"Matilde",	"Mauricio",	"Maximiliano",	"Melchor",	"Mercedes",	"Miguel",	"Milagros",	"Miqueas",	"M�riam",	"Mohamed",	"Mois�s",	"M�nica",	"Montserrat",	"Narciso",	"Natalia",
                   "Natividad",	"Nazario",	"Nemesio",	"Nicanor",	"Nicodemo",	"Nicol�s",	"Nicomedes",	"Nieves",	"No�",	"Noelia",	"Norberto",	"Nuria",	"Octavio",	"Od�n",	"Olga",	"On�simo",	"Orestes",	"Oriol",	"Oscar",	"�scar",	"Oseas",	"Oswaldo",	"Otilia",	"Oto",	"Pablo",	"Pancracio",	"Pascual",	"Patricia",	"Patricio",	"Paula",	"Pedro",	"Petronila",	"Pilar",	"P�o",	"Poncio",	"Porfirio",	"Primo",	"Priscila",	"Probo",	"Purificaci�n",	"Rafael",
                   "Raimundo",	"Ramiro",	"Ram�n",	"Raquel",	"Ra�l",	"Rebeca",	"Reinaldo",	"Remedios",	"Renato",	"Ricardo",	"Rigoberto",	"Rita",	"Roberto",	"Roc�o",	"Rodrigo",	"Rogelio",	"Rom�n",	"Romualdo",	"Roque",	"Rosa",	"Rosalia",	"Rosario",	"Rosendo",	"Rub�n",	"Rufo",	"Ruperto",	"Salom�",	"Salom�n",	"Salvador",	"Salvio",	"Samuel",	"Sandra",	"Sans�n",	"Santiago",	"Sara",	"Sebasti�n",	"Segismundo",	"Sergio",	"Severino",	"Silvia",	"Sime�n",
                   "Sim�n",	"Siro",	"Sixto",	"Sof�a",	"Soledad",	"Sonia",	"Susana",	"Tadeo",	"Tarsicio",	"Teodora",	"Teodosia",	"Te�fanes",	"Te�fila",	"Teresa",	"Timoteo",	"Tito",	"Tob�as",	"Tomas",	"Tom�s",	"Toribio",	"Trinidad",	"Ubaldo",	"Urbano",	"�rsula",	"Valent�n",	"Valeriano",	"Vanesa",	"Velerio",	"Venancio",	"Ver�nica",	"Vicenta",	"Vicente",	"V�ctor",	"Victoria",	"Victorino",	"Victorio",	"Vidal",	"Virgilio",	"Virginia",	"Vladimiro",	"Wilfredo",
                   "Xavier",	"Yolanda",	"Zacar�as",	"Zaqueo"
                  };

typedef struct asignatura
{
    float calificacionXBimestre[5];
    float promedio;

} asignatura_t;



typedef struct alumno
{
    char nombre[50];
    char apPaterno[50];
    char apMaterno[50];
    int edad;
    asignatura_t mat;
    asignatura_t esp;
} alumno_t;


alumno_t *creaDatos()
{

    int numNombres = sizeof(nombres)/sizeof(char*);
    int numApellidos = sizeof(apellidos)/sizeof(char*);
    int n1,ap1, ap2,i;
    float prom1=0, prom2=0;

    time_t t;
    srand((unsigned) time(&t));

    alumno_t *nuevoAlumno = (alumno_t*)malloc(sizeof(alumno_t));

    n1=rand()%numNombres ;
    ap1=rand()%numApellidos;
    ap2=rand()%numApellidos;


    strcpy(nuevoAlumno->nombre,nombres[n1]);
    strcpy(nuevoAlumno->apPaterno,apellidos[ap1]);
    strcpy(nuevoAlumno->apMaterno,apellidos[ap2]);

    nuevoAlumno->edad = 6 +rand()%20;

    for(i=0; i<5; i++)
    {
        nuevoAlumno->esp.calificacionXBimestre[i]=5+rand()%5;
        nuevoAlumno->mat.calificacionXBimestre[i]=5+rand()%5;
        prom1+=nuevoAlumno->esp.calificacionXBimestre[i];
        prom2+=nuevoAlumno->mat.calificacionXBimestre[i];
    }


    nuevoAlumno->esp.promedio = prom1/5;

    nuevoAlumno->mat.promedio = prom2/5;

}
void imprimirDatos(alumno_t *alu)
{
    int b;
    printf("nom: %s %s %s\n",alu->nombre,alu->apPaterno,alu->apMaterno);
    printf("edad: %d\n",alu->edad);

    printf("Calificaciones Espa�ol: \n\n");

    for(b=0; b<5; b++)
    {
        printf("%2.1f ",alu->esp.calificacionXBimestre[b]);
    }
    printf("\n");
    printf("Promedio Espa�ol: %f \n\n",alu->esp.promedio);

    printf("Calificaciones Matem�tica: \n\n");

    for(b=0; b<5; b++)
    {
        printf("%2.2f ",alu->mat.calificacionXBimestre[b]);
    }

    printf("\n");
    printf("Promedio Matem�tica: %f \n\n",alu->mat.promedio);

}


int main()
{

    alumno_t *alu = creaDatos();

    imprimirDatos(alu);

    return 0;
}
