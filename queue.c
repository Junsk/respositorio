#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define DEBUG 0  // 1 con impresion , 0 no imprime nada

typedef struct alumno
{
    char nombre[50];
    char apPaterno[50];
    char apMaterno[50];
    int edad;
    asignatura_t mat;
    asignatura_t esp;
} alumno_t;

typedef struct nodo
{
    alumno_t *alu;
    struct nodo *sig;
} nodo_t;

typedef struct queue
{
    nodo_t *head;
    nodo_t *tail;
} queue_t;

void enqueue( queue_t *q , int v);
int dequeue( queue_t *q );

queue_t *crearQueue()
{
    queue_t *q = (queue_t *)malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

typedef struct asignatura
{
    float calificacionXBimestre[5];
    float promedio;

} asignatura_t;


char *apellidos[]= {"Aguilar","Alonso","Álvarez","Arias","Benítez",
                    "Blanco","Blesa","Bravo","Caballero","Cabrera","Calvo",
                    "Cambil","Campos","Cano","Carmona","Carrasco",
                    "Castillo","Castro","Cortés","Crespo","Cruz",
                    "Delgado","Díaz","Díez","Domínguez",
                    "Durán","Esteban","Fernández","Ferrer",
                    "Flores","Fuentes","Gallardo",
                    "Gallego","García","Garrido","Gil",
                    "Giménez","Gómez","González","Guerrero","Granados"
                    "Gutiérrez","Hernández","Herrera","Herrero",
                    "Hidalgo","Ibáñez","Iglesias","Jiménez",
                    "León","López","Lorenzo","Lozano",
                    "Marín","Márquez","Martín","Martínez",
                    "Medina","Méndez","Molina","Montero",
                    "Montoro","Mora","Morales","Moreno",
                    "Moya","Muñoz","Navarro","Nieto",
                    "Núñez","Ortega","Ortiz","Parra",
                    "Pascual","Pastor","Peña","Pérez",
                    "Prieto","Ramírez","Ramos","Rey",
                    "Reyes","Rodríguez","Román","Romero",
                    "Rubio","Ruiz","Sáez","Sánchez",
                    "Santana","Santiago","Santos","Sanz",
                    "Serrano","Soler","Soto","Suárez",
                    "Torres","Vargas","Vázquez","Vega",
                    "Velasco","Vicente","Vidal"
                   };
char *nombres[] = {"Aarón",	"Abdón",	"Abel",	"Abelardo",	"Abrahán",	"Absalón",	"Acacio",	"Adalberto",	"Adán",	"Adela",	"Adelaida",	"Adolfo",	"Adón",	"Adrián",	"Agustín",	"Aitor",	"Alba",	"Albert",	"Alberto",	"Albina",	"Alejandra",	"Alejandro",	"Alejo",	"Alfonso",	"Alfredo",	"Alicia",	"Alipio",	"Almudena",	"Alonso",	"Álvaro",	"Amadeo",	"Amaro",	"Ambrosio",	"Amelia",	"Amparo",	"Ana",	"Ananías",	"Anastasia",	"Anatolio",	"Andrea",	"Andrés",
                   "Ángel",	"Ángela",	"Ángeles",	"Aniano",	"Anna",	"Anselmo",	"Antero",	"Antonia",	"Antonio",	"Aquiles",	"Araceli",	"Aránzazu",	"Arcadio",	"Aresio",	"Ariadna",	"Aristides",	"Arnaldo",	"Artemio",	"Arturo",	"Ascensión",	"Asunción",	"Atanasio",	"Augusto",	"Áurea",	"Aurelia",	"Aureliano",	"Aurelio",	"Aurora",	"Baldomero",	"Balduino",	"Baltasar",	"Bárbara",	"Bartolomé",	"Basileo",	"Beatriz",	"Begoña",	"Belén",	"Beltrán",	"Benedicto",	"Benigno",	"Benito",
                   "Benjamín",	"Bernabé",	"Bernarda",	"Bernardo",	"Blanca",	"Blas",	"Bonifacio",	"Borja",	"Bruno",	"Calixto",	"Camilo",	"Cándida",	"Carina",	"Carlos",	"Carmelo",	"Carmen",	"Carolina",	"Casiano",	"Casimiro",	"Casio",	"Catalina",	"Cayetano",	"Cayo",	"Cecilia",	"Ceferino",	"Celia",	"Celina",	"Celso",	"César",	"Cesáreo",	"Cipriano",	"Cirilo",	"Cirino",	"Ciro",	"Clara",	"Claudia",	"Claudio",	"Cleofás",	"Clotilde",	"Colombo",	"Columba",
                   "Columbano",	"Concepción",	"Conrado",	"Constancio",	"Constantino",	"Consuelo",	"Cosme",	"Cristian",	"Cristina",	"Cristóbal",	"Daciano",	"Dacio",	"Dámaso",	"Damián",	"Daniel",	"Dario",	"David",	"Demócrito",	"Diego",	"Dimas",	"Dolores",	"Domingo",	"Donato",	"Dorotea",	"Edgar",	"Edmundo",	"Eduardo",	"Eduvigis",	"Efrén",	"Elena",	"Elías",	"Elisa",	"Eliseo",	"Elvira",	"Emilia",	"Emiliano",	"Emilio",	"Encarnación",	"Enrique",	"Epifanía",	"Erico",
                   "Ernesto",	"Esdras",	"Esiquio",	"Esperanza",	"Esteban",	"Ester",	"Esther",	"Eugenia",	"Eugenio",	"Eulalia",	"Eusebio",	"Eva",	"Evaristo",	"Ezequiel",	"Fabián",	"Fabio",	"Fabiola",	"Facundo",	"Fátima",	"Faustino",	"Fausto",	"Federico",	"Feliciano",	"Felipe",	"Félix",	"Fermín",	"Fernando",	"Fidel",	"Fortunato",	"Francesc",	"Francisca",	"Francisco",	"Fulgencio",	"Gabriel",	"Gema",	"Genoveva",	"Gerardo",	"Germán",	"Gertrudis",	"Gisela",	"Gloria",
                   "Godofredo",	"Gonzalo",	"Gregorio",	"Guadalupe",	"Guido",	"Guillermo",	"Gustavo",	"Guzmán",	"Héctor",	"Heliodoro",	"Heraclio",	"Heriberto",	"Hilarión",	"Hildegarda",	"Homero",	"Honorato",	"Honorio",	"Hugo",	"Humberto",	"Ifigenia",	"Ignacio",	"Ildefonso",	"Inés",	"Inmaculada",	"Inocencio",	"Irene",	"Ireneo",	"Isaac",	"Isabel",	"Isaías",	"Isidro",	"Ismael",	"Iván",	"Jacinto",	"Jacob",	"Jacobo",	"Jaime",	"Jaume",	"Javier",	"Jeremías",	"Jerónimo",
                   "Jesús",	"Johan",	"Joaquím",	"Joaquín",	"Joel",	"Jonás",	"Jonathan",	"Jordi",	"Jorge",	"Josafat",	"José",	"Josefa",	"Josefina",	"Josep",	"Josué",	"Juan",	"Juana",	"Julia",	"Julián",	"Julio",	"Justino",	"Juvenal",	"Ladislao",	"Laura",	"Laureano",	"Lázaro",	"Leandro",	"Leocadia",	"León",	"Leonardo",	"Leoncio",	"Leonor",	"Leopoldo",	"Lidia",	"Liduvina",	"Lino",	"Lorena",	"Lorenzo",	"Lourdes",	"Lucano",	"Lucas",
                   "Lucía",	"Luciano",	"Lucrecia",	"Luis",	"Luisa",	"Luz",	"Macario",	"Magdalena",	"Manuel",	"Manuela",	"Mar",	"Marc",	"Marcelino",	"Marcelo",	"Marcial",	"Marciano",	"Marcos",	"Margarita",	"María",	"Mariano",	"Marina",	"Mario",	"Marta",	"Martín",	"Mateo",	"Matías",	"Matilde",	"Mauricio",	"Maximiliano",	"Melchor",	"Mercedes",	"Miguel",	"Milagros",	"Miqueas",	"Míriam",	"Mohamed",	"Moisés",	"Mónica",	"Montserrat",	"Narciso",	"Natalia",
                   "Natividad",	"Nazario",	"Nemesio",	"Nicanor",	"Nicodemo",	"Nicolás",	"Nicomedes",	"Nieves",	"Noé",	"Noelia",	"Norberto",	"Nuria",	"Octavio",	"Odón",	"Olga",	"Onésimo",	"Orestes",	"Oriol",	"Oscar",	"Óscar",	"Oseas",	"Oswaldo",	"Otilia",	"Oto",	"Pablo",	"Pancracio",	"Pascual",	"Patricia",	"Patricio",	"Paula",	"Pedro",	"Petronila",	"Pilar",	"Pío",	"Poncio",	"Porfirio",	"Primo",	"Priscila",	"Probo",	"Purificación",	"Rafael",
                   "Raimundo",	"Ramiro",	"Ramón",	"Raquel",	"Raúl",	"Rebeca",	"Reinaldo",	"Remedios",	"Renato",	"Ricardo",	"Rigoberto",	"Rita",	"Roberto",	"Rocío",	"Rodrigo",	"Rogelio",	"Román",	"Romualdo",	"Roque",	"Rosa",	"Rosalia",	"Rosario",	"Rosendo",	"Rubén",	"Rufo",	"Ruperto",	"Salomé",	"Salomón",	"Salvador",	"Salvio",	"Samuel",	"Sandra",	"Sansón",	"Santiago",	"Sara",	"Sebastián",	"Segismundo",	"Sergio",	"Severino",	"Silvia",	"Simeón",
                   "Simón",	"Siro",	"Sixto",	"Sofía",	"Soledad",	"Sonia",	"Susana",	"Tadeo",	"Tarsicio",	"Teodora",	"Teodosia",	"Teófanes",	"Teófila",	"Teresa",	"Timoteo",	"Tito",	"Tobías",	"Tomas",	"Tomás",	"Toribio",	"Trinidad",	"Ubaldo",	"Urbano",	"Úrsula",	"Valentín",	"Valeriano",	"Vanesa",	"Velerio",	"Venancio",	"Verónica",	"Vicenta",	"Vicente",	"Víctor",	"Victoria",	"Victorino",	"Victorio",	"Vidal",	"Virgilio",	"Virginia",	"Vladimiro",	"Wilfredo",
                   "Xavier",	"Yolanda",	"Zacarías",	"Zaqueo"
                  };



void debug(char *str)
{
    if(DEBUG){ //  Similar a  if( DEBUG == 1 )
        printf(str);
    }
}

void printQ(queue_t *q)
{
    nodo_t *aux = q->head;
    //printf("\t HEAD <<< ");
    while(aux != NULL)
    {
        //printf(" %d ",aux->valor);
	imprimirDatos(aux->alu);
        aux = aux->sig;
    }
    //printf(" <<< TAIL  \n\n");
}
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

    printf("Calificaciones Español: \n\n");

    for(b=0; b<5; b++)
    {
        printf("%2.1f ",alu->esp.calificacionXBimestre[b]);
    }
    printf("\n");
    printf("Promedio Español: %f \n\n",alu->esp.promedio);

    printf("Calificaciones Matemática: \n\n");

    for(b=0; b<5; b++)
    {
        printf("%2.2f ",alu->mat.calificacionXBimestre[b]);
    }

    printf("\n");
    printf("Promedio Matemática: %f \n\n",alu->mat.promedio);

}
void enqueue( queue_t *q , alumno_t *alumno)
{
    nodo_t *nuevo = (nodo_t *)malloc(sizeof(nodo_t));

    nuevo->alu = alumno;
    nuevo->sig   = NULL;

    if(q->head == NULL && q->tail== NULL)
    {
        //primer elemento de q
        debug("Primer elemento de la cola \n");
        q->head = nuevo;
        q->tail = nuevo;
    }
    else
    {
        debug("Nodo siguiente \n");
        q->tail->sig = nuevo;  // Enlazar el nuevo nodo
        q->tail       = nuevo;  // Recorre Tail al ultimo nodo
    }
}

int dequeue( queue_t *q  )
{
    int v_retorno = 0;
    nodo_t *aux;

    if(q->head != NULL && q->tail != NULL )
    {
        v_retorno = (q->head)->valor;
        aux  = q->head;

        if(q->head == q->tail)
        {
            debug("Desencolar ultimo nodo \n");
            // coloca los apuntadores a nulo
            // debido a que se trata del ultimo elemento
            q->head = NULL;
            q->tail = NULL;

        }
        else
        {
            debug("Desencolar nodo \n");
            // mover el apuntador head
            q->head = aux->sig;   // q->head = ( q->head )->sig;
        }
        free(aux);
    }
    else
    {
        printf("Q vacia, error de  underflow \n");
    }

    return v_retorno;
}

int main()
{

    // inicio del queue
    queue_t *q = crearQueue();
	int i=0;
	
	
	printf("%d \n",dequeue(q));

	for(i=0;i<50;i++){
	alumno_t *alu = creaDatos();
	imprimirDatos(alu);
}

    return 0 ;
}
