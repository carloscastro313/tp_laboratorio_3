#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char empleo[128];
    int edad;
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* Empleo,char* horasTrabajadasStr,char* salarioStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setEmpleo(Employee* this,char* empleo);
int employee_getEmpleo(Employee* this,char* empleo);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setEdad(Employee* this,int sueldo);
int employee_getEdad(Employee* this,int* sueldo);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_IngresarDatos(Employee* this,int opcion,char* mensaje);
int employee_checkStr(char* ingreso);

int employee_chooseMod(Employee* this, char* mensaje);

int employee_list(Employee* this );
int employee_listSalary(Employee* this);

int employee_compareByName(void*, void*);

int laQueMapea(void*);

int laQuefiltra(void*);

#endif // employee_H_INCLUDED
