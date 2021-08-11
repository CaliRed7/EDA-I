import os   #Importamos el módulo os que proporciona los detalles y la funcionalidad del sistema operativo
os.system("cls")    #Limpiamos pantalla

#Declaramos variables
op='0'  #Proporcionamos funcionalidad al menú
ind=[]    #Matriz con la que almacenaremos los indicadores
infect=[]    #Matriz con la que almacenaremos el número de contagios
data=[]    #Matriz con la que almacenaremos los datos
sem=[]  #Matriz con la que almacenaremos el color del semáforo
avg=[] #Matriz con la que almacenaremos el promedio

print("\nSistema indicador de color de semáforo COVID")

#---------------------------------------------------------------------------------------------------------------------------------------------------------
#DIAGNÓSTICO DE COVID

while(op!='2'):
    print("\n1) Ingresar datos\n2) Mostrar semáforo")
    op=input("\nSeleccione una opción: ")
    if op=='1': #Opción con la que ingresaremos los datos de los individuos en la base de datos
        age=float(input("\nIngrese la edad del individuo: "))    #Solicitamos los datos tipo edad
        ind=float(input("Ingrese el indicador del individuo: "))   #Solicitamos los datos tipo indicador
        if (ind)>=0.8 and (ind)<=1.0:   #Determinamos si el individuo tiene COVID (POSITIVO)
            ind=str(ind)
            age=str(age)
            pos=age+','+ind+'\n'    #Declaramos un registro en la base de datos de los individuos con edad e indicador COVID [Positivo]
            ind=float(ind)
            data.append(pos)
            avg.append(float(age))
            print("\nSÍ tiene COVID\n")
            print("\n----------------------------------------\n")
            sem.append(str(ind))
            
        elif (ind)<0.8 and (ind)>=0:   #Determinamos si el individuo tiene COVID (Negativo)
            print("\nNO tiene COVID\n")
            print("\n----------------------------------------\n")
            ind=str(ind)
            age=str(age)
            neg=age+','+ind+','+'\n'    #Declaramos un registro en la base de datos de los individuos con edad e indicador COVID [Negativo]
            ind=float(ind)
            data.append(neg) 

        else:   #Condicionamos un valor numérico de indicador inválido
            print("\nIngrese un valor válido")

    elif op=='2':   #Salimos del menú
        print("\nGracias por usar mi programa :)")

    else:   #Condicionamos una opción numérica inválida
        print("\nIngrese una opción válida")

#---------------------------------------------------------------------------------------------------------------------------------------------------------
#CALCULADOR DEL COLOR DEL SEMÁFORO

infect=len(sem)  #Declaramos una variable para imprimir el semáforo de acuerdo a los individuos contagiados

if infect==0:  #Condicionamos el semáforo dadas 0 personas contagiadas de COVID
    print("\nSemáforo epidemiológico: Verde")
elif infect>=1 and infect<=30:    #Condicionamos el semáforo dadas de 1 a 30 personas contagiadas de COVID
    print("\nSemáforo epidemiológico: Amarillo")
elif infect>=31 and infect<=70:   #Condicionamos el semáforo dadas de 31 a 70 personas contagiadas de COVID
    print("\nSemáforo epidemiológico: Naranja")
else:   #Condicionamos el semáforo dadas de 71 a 100 o más personas contagiadas de COVID
    print("\nSemáforo epidemiológico: Rojo")

#---------------------------------------------------------------------------------------------------------------------------------------------------------
#EDAD PROMEDIO DE LOS CONTAGIADOS

if sum(avg)!=0:    #Mostramos el promedio de la suma de edades de los individuos contagiados
    print("\nLa edad promedio en años de las personas con COVID es: ",sum(avg)/len(avg))

#---------------------------------------------------------------------------------------------------------------------------------------------------------
#BASE DE DATOS

#Almacenamos/escribimos en la base de datos db.csv
a=open ("db.csv","a") 
a.writelines(data)
a.close()

#Leemos la base de datos db.csv
a=open("db.csv",'r')
content=a.readlines()
a.close()

print(content)    #Nombramos una función para ingresar a los datos guardados en la base de datos db.csv
