/*Cada semestre, a la materia de Programacion se inscriben una cantidad constante de 23 alumnos. El semestre esta dividido en 3 progresos.
 Utilice los conceptos de Arreglos y Funciones para escribir un programa en lenguaje C que permita realizar los siguientes calculos:
1- Obtener el promedio de calificaciones de cada alumno durante el semeste.
2- La nota promedio del grupo de estudiantes para cada progreso
3- El alumno que obtuvo el mayor promedio de calificacion durante el semestre*/
#include <stdio.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

void calcularPromedioAlumno(float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS]);
void calcularPromedioGrupo(float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS]);
int obtenerMayorPromedio(float promedios[NUM_ALUMNOS]);

int main() {
    float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];
    
    // Obtener las calificaciones de los alumnos
    printf("Ingrese las calificaciones de los alumnos:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Alumno %d:\n", i + 1);
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            printf("Proceso %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }
    
    calcularPromedioAlumno(calificaciones);
    calcularPromedioGrupo(calificaciones);
    
    int indiceMayorPromedio = obtenerMayorPromedio(calificaciones);
    printf("El alumno con el mayor promedio es el Alumno %d.\n", indiceMayorPromedio + 1);
    
    return 0;
}

void calcularPromedioAlumno(float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS]) {
    float promedios[NUM_ALUMNOS];
    
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        float suma = 0;
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            suma += calificaciones[i][j];
        }
        promedios[i] = suma / NUM_PROGRESOS;
        printf("El promedio del Alumno %d es: %.2f\n", i + 1, promedios[i]);
    }
}

void calcularPromedioGrupo(float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS]) {
    float promedios[NUM_PROGRESOS];
    
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        float suma = 0;
        for (int j = 0; j < NUM_ALUMNOS; j++) {
            suma += calificaciones[j][i];
        }
        promedios[i] = suma / NUM_ALUMNOS;
        printf("El promedio del grupo para el Progreso %d es: %.2f\n", i + 1, promedios[i]);
    }
}

int obtenerMayorPromedio(float promedios[NUM_ALUMNOS]) {
    int indiceMayor = 0;
    
    for (int i = 1; i < NUM_ALUMNOS; i++) {
        if (promedios[i] > promedios[indiceMayor]) {
            indiceMayor = i;
        }
    }
    
    return indiceMayor;
}
