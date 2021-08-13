/*Este código fue escrito por:
Cadena Luna Iván Adrián*/

// En este programa se ha implementado la estructura "Lista Enlazada" para realizar varias tareas.

#include<stdio.h>//Este archivo de cabecera proporciona operaciones básicas de I/O (Input/Output) ó E/S (Entrada/Salida) para el programa
#include<stdlib.h>//Este archivo de cabecera incluye funciones de asignación de memoria, control de procesos, conversiones y otras.
#include<string.h>//Este archivo de cabecera incluye funciones de cadena.

struct nodo//Esta es la estructura que proporciona una plantilla para el nodo de la lista enlazada. Muestra una representación de un artículo de comida en el menú.
// Contiene diferentes atributos del nodo, como el nombre del alimento, la cantidad, el precio, los datos, el puntero al nodo siguiente y el puntero al nodo anterior.
//Aquí, con el fin de realizar varias tareas de gestión/administración, así como de los clientes, utilizando una sola estructura, se crea una sola estructura que provee los artículos del menú, así como la orden del cliente.
{
    char comida[50];
    int cantidad;
    float precio;
    int datos;
    struct nodo *prev;
    struct nodo *next;
};

//apuntadores estructurales globales que se utilizan en todo el programa para crear la lista enlazada y mantenerla.
struct nodo *head_cli = NULL,*nuevonodo,*cola_cli = NULL;
struct nodo *head_ges = NULL, *cola_ges = NULL;
struct nodo *head_s;

//Esta función imprime las opciones disponibles para que el administrador elija
void menugestion()
{
    printf("\n\t\t\t\t\t\t\t1. Ver las ventas totales\n");
    printf("\t\t\t\t\t\t\t2. Anadir nuevos articulos en el menu de pedidos\n");
    printf("\t\t\t\t\t\t\t3. Eliminar articulos del menu de pedidos\n");
    printf("\t\t\t\t\t\t\t4. Mostrar el menu de pedidos\n");
    printf("\t\t\t\t\t\t\t5. Volver al menu principal\n");
    printf("\t\t\t\t\t\t\t   Ingrese su eleccion ---> ");
}

//Esta función imprime las opciones disponibles para que el cliente elija
void menucliente()
{
    printf("\n\t\t\t\t\t\t\t1. Realice su pedido\n");
    printf("\t\t\t\t\t\t\t2. Ver los articulos que ha pedido\n");
    printf("\t\t\t\t\t\t\t3. Eliminar un articulo del pedido\n");
    printf("\t\t\t\t\t\t\t4. Mostrar la factura final\n");
    printf("\t\t\t\t\t\t\t5. Volver al menu principal \n\n");
    printf("\t\t\t\t\t\t\t   Ingrese su eleccion ---> ");
}

//Esta función crea un nodo para la Lista Enlazada del administrador
struct nodo* creargestion(struct nodo *head,int datos, char comida[25], float precio)
{
    nuevonodo = (struct nodo*)malloc(sizeof(struct nodo));

    nuevonodo->datos = datos;
    nuevonodo->precio = precio;
    nuevonodo-> cantidad = 0;
    strcpy(nuevonodo->comida,comida);
    nuevonodo->next = NULL;
    nuevonodo->prev = NULL;

    struct nodo *temp = head;

    if(temp==NULL)
        head_ges = cola_ges = nuevonodo;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=nuevonodo;
        nuevonodo->prev = cola_ges;
        cola_ges = nuevonodo;
    }

    return head_ges;
}

//Esta función crea un nodo para la Lista Enlazada del cliente
struct nodo* crearcliente(struct nodo *head,int datos,int cantidad)
{
    nuevonodo = (struct nodo*)malloc(sizeof(struct nodo));

    struct nodo *temp1 = head_ges;
    int flag = 0;
    while(temp1!=NULL)
    {
        if(temp1->datos==datos)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if(flag==1)
    {
        nuevonodo->datos = datos;
        nuevonodo->precio = cantidad *(temp1->precio);
        nuevonodo-> cantidad = cantidad;
        strcpy(nuevonodo->comida,temp1->comida);
        nuevonodo->next = NULL;
        nuevonodo->prev = NULL;

        struct nodo *temp = head;

        if(temp==NULL)
            head_cli = cola_cli = nuevonodo;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=nuevonodo;
            nuevonodo->prev = cola_cli;
            cola_cli = nuevonodo;
        }


    }
    else
    {
        printf("\n\t\t\t\t\t\t\tiEste articulo no se encuentra en el menu!\n");
    }
    return head_cli;
}

//Esta función muestra la respectiva Lista Enlazada entera cuyo puntero de cabecera se encuentra vacío
void mostrarlista(struct nodo *head)
{
    struct nodo *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tiiLa lista esta vacia!!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->cantidad==0)
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n",temp1->datos,temp1->comida,temp1->precio);
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n",temp1->datos,temp1->comida,temp1->cantidad,temp1->precio);
            }

            temp1 = temp1->next;
        }
        printf("\n");
    }

}

//Esta función mantiene el valor total de las ventas realizadas mediante el establecimiento de otra Lista Enlazada que mantiene un registro de las ventas totales realizadas a cada cliente representado por cada nodo
struct nodo* ventastotales(int datos,int cantidad)
{
    nuevonodo = (struct nodo*)malloc(sizeof(struct nodo));
    int flag = 0;

    struct nodo *temp1 = head_ges;
    while(temp1->datos!=datos)
    {
        temp1 = temp1->next;
    }

    nuevonodo->datos = datos;
    nuevonodo->precio = cantidad*(temp1->precio);
    nuevonodo-> cantidad = cantidad;
    strcpy(nuevonodo->comida,temp1->comida);
    nuevonodo->next = NULL;
    nuevonodo->prev = NULL;

    struct nodo *temp = head_s;

    if(temp==NULL)
        head_s = nuevonodo;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->datos==datos)
            {
                flag = 1;
                break;
            }
            temp=temp->next;
        }

        if(flag==1)
        {
            temp->cantidad += nuevonodo-> cantidad;
            temp->precio += nuevonodo->precio;
        }
        else
        {
            temp->next=nuevonodo;
        }
    }

    return head_s;
}

//Esta función realiza la tarea de calcular las ventas totales de cada cliente
void calcularventastotales()
{
    struct nodo *temp = head_cli;
    while(temp!=NULL)
    {
        head_s = ventastotales(temp->datos, temp->cantidad);
        temp=temp->next;
    }
}

//Esta función realiza la tarea de borrar los datos de la Lista Enlazada cuyo puntero de cabecera se encuentra vacío
//Aquí, los datos que se van a borrar se pasan como parámetro.
struct nodo* eliminar(int datos,struct nodo *head, struct nodo* cola)
{
    if(head==NULL)
    {
        printf("\n\t\t\t\t\t\t\tLa lista esta vacia\n");
    }
    else
    {
        struct nodo* temp;
        if(datos==head->datos)
        {
            temp = head;
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
        }
        else if(datos==cola->datos)
        {
            temp = cola;
            cola = cola->prev;
            cola->next = NULL;
            free(temp);
        }
        else
        {
            temp = head;
            while(datos!=temp->datos)
            {
                temp = temp->next;
            }
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}

//Esta función realiza la tarea de borrar los alimentos de la lista vinculada del administrador.
int eliminargestion()
{
    printf("\n\t\t\t\t\tIngrese el numero de serie del articulo de comida que desea eliminar: ");
    int num;
    scanf("%d",&num);

    struct nodo* temp=head_ges;
    while(temp!=NULL)
    {
        if (temp->datos == num)
        {
            head_ges = eliminar(num, head_ges, cola_ges);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

//Esta función realiza la tarea de eliminar los alimentos de la lista vinculada del cliente, es decir, los alimentos pedidos por el cliente.
int eliminarcliente()
{
    printf("\n\t\t\t\t\tIngrese el numero de serie del articulo de comida que desea eliminar: ");
    int num;
    scanf("%d",&num);

    struct nodo* temp=head_cli;
    while(temp!=NULL)
    {
        if (temp->datos == num)
        {
            head_cli = eliminar(num, head_cli, cola_cli);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

//Esta función muestra la factura total de los alimentos pedidos por el cliente.
void mostrarfactura()
{
    mostrarlista(head_cli);
    struct nodo *temp = head_cli;
    float total_precio = 0;
    while (temp!=NULL)
    {
        total_precio +=temp->precio;
        temp = temp->next;
    }

    printf("\t\t\t\t\t\t\tPrecio total: %0.02f\n",total_precio);

}

//Esta función realiza la tarea de borrar toda la Lista Enlazada.
struct nodo* eliminarlista(struct nodo* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct nodo* temp = head;
        while(temp->next!=0)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }

    return head;
}

//Esta función abre la sección de gestión y proporciona su interfaz y funcionalidades
void gestion()
{
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t   SECCION DE GESTION\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1)
    {
        menugestion(); //imprime la lista de funciones para el administrador

        int opt;
        scanf("%d",&opt); //escanea la elección del usuario

        if(opt==5)
            break;

        switch (opt)//bloque switch-case que se ejecuta según la opción seleccionada por el usuario
        {
            case 1:
                mostrarlista(head_s);
                break;
            case 2:

                printf("\n\t\t\t\t\t\t\tIngrese el numero de serie del articulo de comida: ");
                int num,flag = 0;
                char nombre[50];
                float precio;
                scanf("%d",&num);

                struct nodo *temp = head_ges;

                while(temp!=NULL)
                {
                    if(temp->datos==num)
                    {
                        printf("\n\t\t\t\t\t\tiiEl articulo de comida con el numero de serie ingresado ya existe!!\n\n");
                        flag = 1;
                        break;
                    }
                    temp = temp->next;
                }

                if(flag==1)
                    break;

                printf("\t\t\t\t\t\t\tIntroduzca el nombre del articulo de comida: ");
                scanf("%s",nombre);
                printf("\t\t\t\t\t\t\tIngrese el precio: ");
                scanf("%f",&precio);
                head_ges = creargestion(head_ges, num, nombre, precio);
                printf("\n\t\t\t\t\t\t\tiiNueva comida anadida a la lista!!\n\n");
                break;
            case 3:
                if(eliminargestion())
                {
                    printf("\n\t\t\t\t\t\t### Lista del menu de comida actualizada ###\n");
                    mostrarlista(head_ges);
                }
                else
                    printf("\n\t\t\t\t\t\tiEl producto de comida con el numero de serie ingresado no existe!\n\n");

                break;
            case 4:
                printf("\n\t\t\t\t\t\t\t   ### Menu de pedidos ###\n");
                mostrarlista(head_ges);
                break;

            default:
                printf("\n\t\t\t\t\t\tiiEntrada incorrecta!! Por favor, elija una opcion valida\n");
                break;
        }
    }
}

//Esta función abre la sección de clientes y proporciona su interfaz y funcionalidades
void cliente()
{
    int flag=0,j=1;
    char ch;
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t   SECCION DE CLIENTES\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1)
    {
        menucliente();//imprime la lista de funciones para el cliente

        int opt;
        scanf("%d",&opt);//escanea la elección del usuario

        if(opt==5)
            break;

		//bloque switch-case que se ejecuta según la opción seleccionada por el usuario
        switch (opt)
        {
            case 1:
                mostrarlista(head_ges);
                printf("\n\t\t\t\t\t\tIngrese el numero correspondiente al articulo que desea ordenar: ");
                int n;
                scanf("%d",&n);
                printf("\t\t\t\t\t\tIngrese la cantidad: ");
                int cantidad;
                scanf("%d",&cantidad);
                head_cli = crearcliente(head_cli, n, cantidad);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t  ### Lista de articulos ordenados ###\n");
                mostrarlista(head_cli);
                break;
            case 3:
                if(eliminarcliente())
                {
                    printf("\n\t\t\t\t\t\t### Lista de articulos ordenados actualizada ###\n");
                    mostrarlista(head_cli);
                }
                else
                    printf("\n\t\t\t\t\t\tiiEl articulo de comida con el numero de serie ingresado no existe!!\n");
                break;
            case 4:
                calcularventastotales();
                printf("\n\t\t\t\t\t\t\t  ### Factura final ###\n");
                mostrarfactura();
                head_cli = eliminarlista(head_cli);
                printf("\n\t\t\t\t\t\tPulse cualquier tecla para volver al menu principal:\n\t\t\t\t\t\t");
                fflush(stdin);
                ch=fgetc(stdin);
                flag=1;
                break;

            default:
                printf("\n\t\t\t\t\t\tiiEntrada incorrecta!! Por favor, elija una opcion valida\n");
                break;
        }
        if(flag==1)
            break;
    }
}

//Esta función imprime la interfaz de bienvenida y abre el menú principal donde se puede seleccionar la opción a la que se quiere ir.
void mainnenu()
{
    printf("\n                                 **************************************************************************\n");
    printf("                                              BIENVENIDO AL SISTEMA DE GESTION DE RESTAURANTES\n");
    printf("                                 **************************************************************************\n\n\n");
    printf("\t\t\t\t\t\t\t1. SECCION DE GESTION \n");
    printf("\t\t\t\t\t\t\t2. SECCION DE CLIENTES \n");
    printf("\t\t\t\t\t\t\t3. Salir \n\n");
    printf("\t\t\t\t\t\t\tIngrese su eleccion ---> ");
}

int main()//A partir de aquí comienza la ejecución real del programa
{
	//Aquí hemos inicializado la Lista Vinculada del administrador, es decir, el Menú de Comida con 5 artículos
    head_ges = creargestion(head_ges,1,"Tacos",100);
    head_ges = creargestion(head_ges,2,"Pozole",200);
    head_ges = creargestion(head_ges,3,"Tamales",150);
    head_ges = creargestion(head_ges,4,"Pastel",180);
    head_ges = creargestion(head_ges,5,"Enchiladas",80);

    while(1)
    {
        mainnenu();
        int eleccion;
        scanf("%d",&eleccion);//escanea la elección del usuario

        if(eleccion==3)
        {
            printf("\n\n\t\t\t\t\t\t\t**********iiGracias!!**********\n");
            break;
        }
		
		//bloque switch-case que se ejecuta según la opción seleccionada por el usuario
        switch (eleccion)
        {
            case 1:
                gestion();
                break;
            case 2:
                cliente();
                break;
            case 3:
                break;

            default:
                printf("\n\t\t\t\t\t\tiiEntrada incorrecta!! Por favor, elija una opcion valida\n");
                break;
        }
    }
}
