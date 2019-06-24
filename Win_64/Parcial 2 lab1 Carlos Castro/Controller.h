int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee);
int controller_salary(LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee ,int* idMax);
LinkedList* controller_programadoresList(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee, char* tabla, int flag);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path,char* pathIdMax, LinkedList* pArrayListEmployee ,int* idMax);


