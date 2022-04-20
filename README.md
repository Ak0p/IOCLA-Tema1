*Baroiu Andrei - 312CB*   
# IOCLA-Tema1 

## Parsare  

Am citit input-ul de la tastatura cu fgets in "comanda", dupa care am folosit un
vector de char pointeri care pointeaza la fiecare cuvant format din strtok.   
In functie de primul cuvant din input am folosit operatia care se cuvine.  

## Inserare la final  

La inserare am folosit functia add_last pentru a copia informatiile din   
structura alocata cu tot cu header direct in vector, in ordinea urmatoare:   
struct type, struct len, nume dedicator, valoare bancnota 1, valoare bancnota 2  
si respectiv numele celui care primeste dedicatia. La final am adaugat la   
len (numarul total de byti din vector) numarul de byti al structurii inserate.  

## Inserare pe pozitie   

In mare am folosit codul de functia add_last, cu modificarea ca am folosit   
functia getPos(arr(ptr), index, len) pentru a afla pozitia in vector a   
elementului cu indexul cerut iar inainte de inserare am dat realloc vectorului  
cu len + structlen si am mutat cu memmove bytii de dupa pozitia din vector   
aflata de getPos cu structlen pozitii la dreapta.


##  Delete_at   


Am folosit functia getPos pentru a afla pozitia in vector a elementului cu  
indexul cerut, dupa care aflat lungimea in byti a elementului si am mutat   
cu memmove toti bytii dupa structura pe pozitia de inceput a acesteia, astfel  
suprascriind-o. In final am dat realloc vectorului cu lungimea len - structlen.


## Find  


Am folosit functia getPos pentru a afla pozitia in vector a elementului si am  
parcurs element cu element structura si am afisat-o.


## Print  


Asemenea ca la find doar ca am iterat print toate elementele vectorului de la  
inceput.  


**Obs**   
*Functiile sunt scrise pentru toate tipurile de date*

